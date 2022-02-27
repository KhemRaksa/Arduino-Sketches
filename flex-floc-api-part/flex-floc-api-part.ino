//Necessary libraries for wifi modules
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
HTTPClient http;
WiFiClient espclient;

////////////////////////////////////////////////////
//Name and password for wifi at place or personal hotspot
const char* ssid = "hello";
const char* psw = "hellohello";\
//Careful here, our esp module has no access to local host
const char* url = "http://api.flexfloc.com/api"; 
////////////////////////////////////////////////////

//User token
String token;
/////////////

//Library for Communication between Arduino and WifiModule via Nodemcu
#include <SoftwareSerial.h>
SoftwareSerial nodemcu(D6,D7);
/////////////////////////////////////////////////////
//Library for working with JSON objects
#include <ArduinoJson.h>
/////////////////////////////////////////////////////

void setup() {
  // Initialize serial and nodemcu ports
  Serial.begin(115200);
  nodemcu.begin(115200);
  //////////////////////////////////////
  while (!Serial) continue;
  //Wifi connection
  WiFi.begin(ssid, psw);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting... ");
  }
  ///////////////////////////////////////////

  String login_URL = "http://api.flexfloc.com/api/login";
  
  Serial.println("TESTING POST");
   if (WiFi.status() == WL_CONNECTED){
    http.begin(espclient,login_URL);
    http.addHeader("Content-Type", "application/json");

    String httppost = "{  \"email\":\"khenpheakdey@gmail.com\", \"password\": \"admin123\"}";
    int httpCode = http.POST(httppost);
    String payload = http.getString();

    // Converting payload from string to JSON object (docc) to easily access Token
    StaticJsonDocument<256> docc;
    DeserializationError error = deserializeJson(docc, payload);

    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }
    token = String(docc["data"]["token"]);
    Serial.println(token);
    http.end();
    Serial.println(httpCode);
    ///////////////////////////////////////////////////////////////////////////////
    }
}
void loop() {
  
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, nodemcu);
//  delay(1600);

  Serial.println("Measurements Recieved");
  Serial.print("Recieved pH:  ");
  float pH = doc["pH"];
  Serial.println(pH);
  
  Serial.print("Recieved Temperature:  ");
  float temp = doc["temperature"];
  Serial.print(temp);
  Serial.println(" Celcius");

  Serial.print("Recieved TDS:  ");
  float tds = doc["tds"];
  Serial.print(tds);
  Serial.println(" ppm");

  Serial.print("Recieved EC: ");
  float ec = doc["ec"];
  Serial.print(ec);
  Serial.println(" micros/cm");

//  String post_measurement_URL = "http://api.flexfloc.com/api/measurements";
//  
//  static unsigned long timepoint = millis();
//  if (millis() - timepoint > 300000U){
//  timepoint = millis();
//  http.begin(espclient,post_measurement_URL);
  
//  String bearerToken = String("Bearer ") + token;
//  http.addHeader("Content-Type","application/json"); 
//  http.addHeader("Authorization:",bearerToken, true);
//
//  String httppost = "{ \"tank_id\":\"1\", \"ph_level\":"+String(pH)+", \"tds_level\": "+String(tds)+", \"ec_level\":"+String(ec)+"}";
//  
//  int httpCode = http.POST(httppost);
//  String payload = http.getString();
//  http.end();
//  Serial.println(httpCode);
  
//  Serial.println(bearerToken);
//    }
  Serial.println("-----------------------------------------");
//  delay(1000);
}
