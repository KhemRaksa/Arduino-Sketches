//Arduino to NodeMCU
#include <SoftwareSerial.h>
///////////////////////////////

//Library for JSON objects
#include <ArduinoJson.h>
//////////////////////////

//Initialise Arduino to WifiModule Communication (12=Rx & 11=Tx)
SoftwareSerial nodemcu(12,11);
////////////////////////////////

// Start EC Libraries
#include <DFRobot_EC.h>
#include <EEPROM.h>
#include <OneWire.h>

#include <time.h>
// End EC Libraries

// Start EC Calibration CMD
// enterec -> enter calibration mode
// calec -> start calibration calucation
// exitec -> saved the parameters and exit calibration mode
// End EC Calibration CMD

// Start PH Values
const int phPin = A13;
int sensorValue = 0;
unsigned long int avgValue;
float b;
int buf[10], temp;
// End PH Values

// Start EC Values
const int EC_PIN = A1;
byte DS18B20_Pin = 2; //DS18B20 signal, pin on digital 2
#define StartConvert 0
#define ReadTemperature 1
float voltage, ecValue, temperature = 25;
DFRobot_EC ec;
unsigned long tempSampleTime;
unsigned int tempSampleInterval = 850; //analog sample interval;serial print interval;temperature sample interval
// End EC Values

// Start Temperature chip i/o
OneWire ds(DS18B20_Pin);  // on digital pin 2
// End Temperature chip i/o

void setup()
{
  Serial.begin(115200);
  nodemcu.begin(115200);
  ec.begin();
  TempProcess(StartConvert);   //let the DS18B20 start the convert
  tempSampleTime = millis();
//  srand(time(0));
}

void loop()
{
  
  DynamicJsonDocument doc(1024);
  

 // Start PH Logic
  for (int i = 0; i < 10; i++) {
    buf[i] = analogRead(phPin);
    delay(30);
  }
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (buf[i] > buf[j]) {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }
  avgValue = 0;
  for (int i = 2; i < 8; i++){
    avgValue += buf[i];
  }
   float pHVol = (float)avgValue * 5.00 / 1024 / 6;
//   float pHVol =  (float)((rand()%2));
  
  float pHValue = -5.70 * pHVol + 21.34; //originally 21.34
//  Serial.print("pH sensor = ");
//  Serial.println(pHValue);

//  delay(3000);
// End PH Logic

  // Start EC Logic
  static unsigned long timepoint = millis();
  if (millis() - timepoint > 1000U) //time interval: 1s
  {
    timepoint = millis();
//    voltage = analogRead(EC_PIN) / 1024.0 * 5000; // read the voltage
      voltage = pHVol;
//    temperature = readTemperature();          // read your temperature sensor to execute temperature compensation
      ecValue =  ec.readEC(voltage, temperature); // convert voltage to EC with temperature compensation
    
  }
  if (millis() - tempSampleTime >= tempSampleInterval)
  {
    tempSampleTime = millis();
    temperature = TempProcess(ReadTemperature);  // read the current temperature from the  DS18B20
    
    TempProcess(StartConvert);                   //after the reading,start the convert for next reading
  }
  ec.calibration(voltage, temperature);       // calibration process by Serial CMD
  // End EC Logic

   float tdsValue = ecValue * 550;
//  Serial.print("TDS: ");
//  Serial.print(tdsValue);
//  Serial.println(" ppm");  
// End TDS Logic

//  doc["ec"] = (float)((rand()%100)/100.0)+749;
   doc["ec"] = ecValue;
   doc["tds"] = tdsValue;
//  doc["tds"] = (float)((rand()%100)/100.0)+369;
//  doc["pH"] = (float)((rand()%10)/100.0)+6.5;
  doc["pH"] = pHValue;
  doc["temperature"] = temperature;
//  doc["phVol"] = pHVol;
  //Send JSON results to Serial Monitor-2
  serializeJson(doc, Serial);
  //Send results to Wifi Module
  serializeJson(doc, nodemcu);
  Serial.println("");
}
// void loop ends here

// Start TDS GetMedian
int getMedianNum(int bArray[], int iFilterLen)
{
  int bTab[iFilterLen];
  for (byte i = 0; i < iFilterLen; i++)
    bTab[i] = bArray[i];
  int i, j, bTemp;
  for (j = 0; j < iFilterLen - 1; j++)
  {
    for (i = 0; i < iFilterLen - j - 1; i++)
    {
      if (bTab[i] > bTab[i + 1])
      {
        bTemp = bTab[i];
        bTab[i] = bTab[i + 1];
        bTab[i + 1] = bTemp;
      }
    }
  }
  if ((iFilterLen & 1) > 0)
    bTemp = bTab[(iFilterLen - 1) / 2];
  else
    bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;
  return bTemp;
}
// End TDS GetMedian
/*
  ch=0,let the DS18B20 start the convert;ch=1,MCU read the current temperature from the DS18B20.
*/
// Start Temperature Reading from DS18B20
float TempProcess(bool ch)
{
  //returns the temperature from one DS18B20 in DEG Celsius
  static byte data[12];
  static byte addr[8];
  static float TemperatureSum;
  if (!ch) {
    if ( !ds.search(addr)) {
      Serial.println("no more sensors on chain, reset search!");
      ds.reset_search();
      return 0;
    }
    if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return 0;
    }
    if ( addr[0] != 0x10 && addr[0] != 0x28) {
      Serial.print("Device is not recognized!");
      return 0;
    }
    ds.reset();
    ds.select(addr);
    ds.write(0x44, 1); // start conversion, with parasite power on at the end
  }
  else {
    byte present = ds.reset();
    ds.select(addr);
    ds.write(0xBE); // Read Scratchpad
    for (int i = 0; i < 9; i++) { // we need 9 bytes
      data[i] = ds.read();
    }
    ds.reset_search();
    byte MSB = data[1];
    byte LSB = data[0];
    float tempRead = ((MSB << 8) | LSB); //using two's compliment
    TemperatureSum = tempRead / 16;
  }
  return TemperatureSum;
}
// End Temperature Reading from DS18B20
