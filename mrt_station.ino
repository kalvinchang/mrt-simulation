#include <Arduino.h>
#ifdef ESP32
    #include <WiFi.h>
#else
    #include <ESP8266WiFi.h>
#endif

#include "arduino_secrets.h"
#include <tinyxml2.h>
#include <ArduinoJson.h>

// need to go into ESP8266Audio source and comment out src/AudioFileSourceHTTPStream.{cpp,h} and src/AudioFileSourceICYStream.{cpp,h}
// ESP8266Audio uses HTTPClient, which is the outdated repor ArduinoHttpClient was based off of
#include <ESP8266SAM.h>
#include <AudioOutputI2S.h>
#include <ArduinoHttpClient.h>

using namespace tinyxml2;

// adapted from https://github.com/CliffLin/TaipeiMRT/blob/master/flask/mrt.py (Flask)
char serverAddress[] = "ws.metro.taipei";
int port = 80;
WiFiClient wifi;
HttpClient client = HttpClient(wifi, serverAddress, port);
int status = WL_IDLE_STATUS;

// station info
const int APPROACHING_STATION = 30; // seconds
const int NUM_STATIONS = 8;
int curr_station = 2; // Zhongxiao Dunhua, corresponds to index in stations array
extern JsonArray stations;

// hardware info
int speakerPin = 26;
byte ledPins[NUM_STATIONS] = {27, 33, 32, 25, 2, 12, 13, 15};
AudioOutputI2S *out = NULL;
ESP8266SAM *sam = NULL;

// WiFi code adapted from https://github.com/arduino-libraries/ArduinoHttpClient/blob/master/examples/SimplePost/SimplePost.ino
void setup() {
  Serial.begin(230400);

  for (int i = 0; i < NUM_STATIONS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(speakerPin, OUTPUT);

  // uses internal DAC of the ESP32
  out = new AudioOutputI2S(0, 1);
  out->begin();
  sam = new ESP8266SAM;
  
  while (status != WL_CONNECTED) {
    Serial.println("Connecting to WiFi..");
    status = WiFi.begin(SECRET_SSID, SECRET_PASS);
    delay(1000);
  }

  Serial.println("Connected to the WiFi network");
}

// adapted from https://github.com/arduino-libraries/ArduinoHttpClient/blob/master/examples/PostWithHeaders/PostWithHeaders.ino
void loop() {
  Serial.println("Currently at station");
  Serial.println((const char *)stations[curr_station]["english"]);
	String station_id = stations[curr_station]["id"];
  
  digitalWrite(ledPins[curr_station], HIGH);

  Serial.println("Fetching data from API");

  String contentType = "text/xml";
  String reqBody = "<?xml version='1.0' encoding='UTF-8'?><soap:Envelope xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/SMLSchema\"><soap:Body><GetNextTrain2 xmlns=\"http://tempuri.org/\"><stnid>"""+station_id+"""</stnid></GetNextTrain2></soap:Body></soap:Envelope>";

  client.beginRequest();
  client.post("/trtcappweb/Traintime.asmx"); // Make the request
  client.sendHeader("Content-Type", contentType);
  client.sendHeader("Content-Length", reqBody.length());
  client.sendHeader("SOAPAcrion", "http://tempuri.org/GetNextTrain2");
  client.beginBody();
  client.print(reqBody);
  client.endRequest();

  int responseStatusCode = client.responseStatusCode();
  Serial.println(responseStatusCode);

  if (responseStatusCode > 0) { //Check for the returning code
    String responseStr = client.responseBody();
    Serial.println(responseStr);

    // add 1 for the NUL terminator
    char * response = (char *)malloc(responseStr.length() + 1);
    responseStr.toCharArray(response, responseStr.length() + 1);

    XMLDocument document;
    XMLError err = document.Parse(response);
    if (err != XML_SUCCESS) {
      Serial.println("Error parsing response: ");
      Serial.println(err);
      return;
    }
    Serial.println("Success parsing response");

    free(response);

    XMLElement* trainElement = document.FirstChildElement( "soap:Envelope" )->FirstChildElement( "soap:Body" )->FirstChildElement("GetNextTrain2Response")->FirstChildElement("GetNextTrain2Result")->FirstChildElement("root");

    for (XMLElement* train = trainElement->FirstChildElement(); train != NULL; train = train->NextSiblingElement())
    {
        const char *countdown = "MM:SS";
        train->QueryStringAttribute("countdown", &countdown);

        int minutes = 0;
        int seconds = 0;
        sscanf(countdown, "%d:%d", &minutes, &seconds);

        seconds += minutes * 60;

        if (seconds < APPROACHING_STATION) {
          digitalWrite(ledPins[curr_station], LOW);
          flicker();
          digitalWrite(ledPins[curr_station], HIGH); // turn light back on
          enterStationTune(speakerPin); // takes 15 seconds

          const char *destination = "OOOOOOO";
          train->QueryStringAttribute("destination", &destination);
          sam->Say(out, "Mind the gap.");
          
          delay(3000);
          doorsClosing(speakerPin); // takes 9 seconds
          sam->Say(out, "Doors closing.");
          break;
        }
    }
  } else {
    Serial.println("Error on HTTP request. Status: ");
    Serial.println(responseStatusCode);
  }

  delay(5000);
}

void flicker() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(ledPins[curr_station], HIGH);
    delay(100);
    digitalWrite(ledPins[curr_station], LOW);
    delay(100);
  }
}
