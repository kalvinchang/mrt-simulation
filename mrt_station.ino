#include <WiFi.h>
#include <ArduinoHttpClient.h>
#include "arduino_secrets.h"

// adapted from https://github.com/CliffLin/TaipeiMRT/blob/master/flask/mrt.py (Flask)
char serverAddress[] = "ws.metro.taipei";
int port = 80;
WiFiClient wifi;
HttpClient client = HttpClient(wifi, serverAddress, port);
int status = WL_IDLE_STATUS;

// WiFi code adapted from https://github.com/arduino-libraries/ArduinoHttpClient/blob/master/examples/SimplePost/SimplePost.ino
void setup() {
  Serial.begin(115200);
  
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
    String response = client.responseBody();
    Serial.println(response);

    // TODO: parsing response ; modularize
    // <?xml version="1.0" encoding="utf-8"?><soap:Envelope xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema"><soap:Body><GetNextTrain2Response xmlns="http://tempuri.org/"><GetNextTrain2Result><root station="010" stationname="忠孝復興站" noservice="YES       " ErrStatement="" xmlns=""><Detail flag="0  " priority="510" platform="BL1" stnid="BL10 " tripno="" destination="南港展覽館站" countdown="59:50*    " updatetime="2020-12-09 04:09:36 " nowtime="2020-12-09 04:09:40 " diffsec="4" /><Detail flag="0  " priority="530" platform="BL1" stnid="BL10 " tripno="" destination="頂埔站" countdown="59:50*    " updatetime="2020-12-09 04:09:36 " nowtime="2020-12-09 04:09:40 " diffsec="4" /><Detail flag="0  " priority="535" platform="BL1" stnid="BL10 " tripno="" destination="亞東醫院站" countdown="59:50*    " updatetime="2020-12-09 04:09:36 " nowtime="2020-12-09 04:09:40 " diffsec="4" /><Detail flag="0  " priority="999" platform="BL1" stnid="BL10 " tripno="" destination="昆陽站" countdown="59:50*    " updatetime="2020-12-09 04:09:36 " nowtime="2020-12-09 04:09:40 " diffsec="4" /></root></GetNextTrain2Result></GetNextTrain2Response></soap:Body></soap:Envelope>

//    xml = r.content
//		xmltree = ET.ElementTree()
//		xmltree = ET.fromstring(xml)
//		result = []
//		for elem in xmltree.iter('Detail'):
//			result.append({'destination':elem.get('destination'),"countdown":elem.get("countdown").replace(" ",'')})
//		return result
  } else {
    
    Serial.println("Error on HTTP request");
  }

  delay(30000);
}
