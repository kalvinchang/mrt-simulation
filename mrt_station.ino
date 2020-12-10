#include <WiFi.h>
#include <ArduinoHttpClient.h>
#include "arduino_secrets.h"
#include <tinyxml2.h>
using namespace tinyxml2;

// adapted from https://github.com/CliffLin/TaipeiMRT/blob/master/flask/mrt.py (Flask)
char serverAddress[] = "ws.metro.taipei";
int port = 80;
WiFiClient wifi;
HttpClient client = HttpClient(wifi, serverAddress, port);
int status = WL_IDLE_STATUS;

const int APPROACHING_STATION = 30; // seconds

// WiFi code adapted from https://github.com/arduino-libraries/ArduinoHttpClient/blob/master/examples/SimplePost/SimplePost.ino
void setup() {
  Serial.begin(230400);
  
  while (status != WL_CONNECTED) {
    Serial.println("Connecting to WiFi..");
    status = WiFi.begin(SECRET_SSID, SECRET_PASS);
    delay(1000);
  }

  Serial.println("Connected to the WiFi network");
}

// adapted from https://github.com/arduino-libraries/ArduinoHttpClient/blob/master/examples/PostWithHeaders/PostWithHeaders.ino
void loop() {
	String station_id = "010";

  Serial.println("Fetching data from API");

  // TODO: modularize
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

    // TODO: modularize
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

    int numTrains = 0;
    for (XMLElement* train = trainElement->FirstChildElement(); train != NULL; train = train->NextSiblingElement())
    {
        // TODO: modularize
        const char *countdown = "MM:SS";
        train->QueryStringAttribute("countdown", &countdown);

        int minutes = 0;
        int seconds = 0;
        sscanf(countdown, "%d:%d", &minutes, &seconds);
        
        seconds += minutes * 60;

        if (seconds < APPROACHING_STATION) {
          // TODO: check that the train is on the Bannan line
          
          Serial.println("train arriving!");
          // TODO: play music
          // TODO: human speech: announce that a train is coming and headed toward some destination
          // TODO: human speech: mind the gap
          // TODO: doesn't the song last a long time?
          // TODO: wait 10 seconds for the doors to close (sound an alarm)
          // TODO: human speech: doors closing

          const char *destination = "OOOOOOO";
          train->QueryStringAttribute("destination", &destination);

          Serial.println("headed towards");
          Serial.println(destination);
        }
        
        numTrains++;
    }
    Serial.print(numTrains);
    Serial.println(" trains");

  } else {
    Serial.println("Error on HTTP request. Status: ");
    Serial.println(responseStatusCode);
  }

  delay(5000);
}
