#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
//#include <DHTesp.h>

#define debug Serial

//DHTesp dht;

//const char* ssid = "S-home";
//const char* psw = "Dalin126188";
//const char* url = "http://arrowdot.io:1880/api";

HTTPClient http;
WiFiClient espclient;

void setup() {
  debug.begin(115200);
//  dht.setup(D1,DHTesp::DHT22);
//  WiFi.begin(ssid,psw);
  debug.println("Trying connection...");
  while(WiFi.status() != WL_CONNECTED) {
    debug.print("*");
    delay(500);
  }
  debug.println();
  debug.println("Connected");
  
}

void loop() {
//  float tem = dht.getTemperature();
//  float hum = dht.getHumidity();
//  debug.println("Tem: " + String(tem) + "°C");
//  debug.println("Hum: "+ String(hum)) + "%";
//  debug.println("-------------------");
//  http.begin(espclient,url);
//  http.addHeader("Content-Type","application/json");
//  String httppost = "{ \"id\":\"G6\", \"tem\":"+String(tem)+", \"hum\": "+String(hum)+" }";
//  http.POST(httppost);
//  http.end();

    debug.println("Hi");
 //get data from arduino

  delay(2000);

}
