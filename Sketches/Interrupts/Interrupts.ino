
/*
 * Interrupts
 * An interrupt is a section of hardware on microcontroller which is capable of 
 * monitoring the state of an input pin by itself and can interrrupt microcontroller 
 * that there is an interrupt vector ready, i.e, that state of an input pin has changed. 
 * 
 * It frees us up to do other things. 
 * 
 * 3 basic types of interrupt : change, rising and falling. 
 * The conditions which to trigger to interrupt.
 * 
 * When interrupt is triggered, program will jump from wherever it is to complete 
 * function associated with interrupt. (ISR- Interrupt Service routine). 
 * So that function should be as short as possible. 
 * 
 * If we poll, check like normally, it can causes issues for more complicated programs
 * when using interrutps. 
 * Ex : when we check state of buttons.
 * 
 * DOs:
 * Keep ISR functions = short. To set a flag or change start. 
 * ISR functions do not return values or take parameters. 
 * Delays, millis will not work inside ISR.
 * Delaymicroseconds  will work - because it is not interrupted-based. 
 * 
 * Any variable which is declard inside ISR should be declared with the "volatile"
 * modifier. 
 * 
 * Only certain pins: 2,3 for Arduino UNO.
 * Some chips are only capable of detecing Change.
 * 
 */
 
//pin defintions
int ledPin = 3;
int buttonPin = 2;

//global variables
int toggleState;
int lastButtonState = 1;
long unsigned int lastPress;
volatile int buttonFlag;
int debounceTime = 20;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(20),ISR_button, CHANGE);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - lastPress)> debounceTime && buttonFlag)
  {
    lastPress = millis(); //update lastPress
    if(digitalRead(buttonPin) == 0 && lastButtonState ==1) // if button is pressed and was released last change
    {
      toggleState =! toggleState; //toggle the LED state
      digitalWrite(ledPin,toggleState);
      lastButtonState = 0; //record lasButtonState
    }
    else if(digitalRead(buttonPin) == 1 && lastButtonState == 0) //if  button is not pressed and was pressed last change
    {
      lastButtonState = 1; //record lastButtonStatte
    }
    buttonFlag = 0;
  }

}

void ISR_button()
{
  buttonFlag = 1;
}
