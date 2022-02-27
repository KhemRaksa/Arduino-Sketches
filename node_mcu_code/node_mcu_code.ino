//Necessary libraries for wifi modules
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
HTTPClient http;
WiFiClient espclient;

////////////////////////////////////////////////////
//Name and password for wifi at place or personal hotspot
const char* ssid = "hello";
const char* psw = "hellohello";
const char* url = "http://api.flexfloc.com/";
////////////////////////////////////////////////////

//User token
String token;
/////////////

//Library for Communication between Arduino and WifiModule via Nodemcu
#include <SoftwareSerial.h>
//D6 = Rx & D7 = Tx
SoftwareSerial nodemcu(D7,D6);
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
  //////////////////////////////////////

  //Registration
//  DynamicJsonDocument registerForm(1024);
//  deserializeJson(registerForm, nodemcu);
//  registerForm["email"]="chhunheng@gmail.com";
//  registerForm["name"]="chhunheng";
//  registerForm["password"]="admin123";
//  registerForm["confirm_password"]="admin123";
//  String register_URL = "http://api.flexfloc.com/api/register";
  ///////////////////////////////////////////
  String login_URL = "http://api.flexfloc.com/api/login";
  Serial.println("TESTING POST");
   if (WiFi.status() == WL_CONNECTED){
    http.begin(espclient,login_URL);
    http.addHeader("Content-Type", "application/json");
//  String httppost = "{ \"name\":\"G6\", \"email\":\"menghang@gmail.com\", \"password\": \"admin123\", \"confirm_password\":\"admin123\"}";
    String httppost = "{  \"email\":\"menghang@gmail.com\", \"password\": \"admin123\"}";
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

  Serial.println("JSON Object Recieved");
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
  Serial.println(" ms/cm");

//  String measurement_url = "http://api.flexfloc.com/api/measurements/"+"String(tank_id)";
//  http.begin(espclient,measurement_url);
//  http.addHeader("Content-Type","application/json"); 
//  http.addHeader("Authorization:","Bearer ${'token'}", true);
//  String httppost = "{ \"id\":\"1\", \"pH\":"+String(pH)+", \"tds\": "+String(tds)+", \"ec\":"+String(ec)+" ,\"temp\":"+String(temp)+" }";
//  http.POST(httppost);
//  http.end();

  Serial.println("-----------------------------------------");
//  delay(1000);
}
