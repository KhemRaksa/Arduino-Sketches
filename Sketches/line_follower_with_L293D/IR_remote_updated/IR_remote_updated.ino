#include <IRremote.h>

IRrecv irrecv(13);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
      Serial.println(results.value, HEX);
      
      irrecv.resume(); // Receive the next value
  }
  
}
