int sensor = A0;

//left motors
int ENB = 10;
int IN4 = 5;
int IN3 = 4;

//right motors 
int ENA = 9;
int IN2 = 2;
int IN1 = 3;


void setup() {
  // put your setup code here, to run once:
  pinMode(ENB, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void loop() {
  // put your main code here, to run repeatedly:

  goBackward();

  delay(1000);

  moveRight();

  delay(1000);

  goStop();

  delay(1000);
  
  goForward();

  delay(1000);

  moveLeft();

  delay(1000);

}

void goForward(){

  digitalWrite(IN4,0);
  digitalWrite(IN3,1);

  digitalWrite(IN1,0);
  digitalWrite(IN2,1); 
}

void goBackward(){

  digitalWrite(IN4,1);
  digitalWrite(IN3,0);

  digitalWrite(IN1,1);
  digitalWrite(IN2,0); 

}

void moveRight(){
  
  digitalWrite(IN4,0);
  digitalWrite(IN3,1);

  digitalWrite(IN1,1);
  digitalWrite(IN2,0); 
}


void moveLeft(){
  
  digitalWrite(IN4,1);
  digitalWrite(IN3,0);

  digitalWrite(IN1,0);
  digitalWrite(IN2,1);   
  
  
}


void goStop(){
  
  digitalWrite(IN4,1);
  digitalWrite(IN3,1);

  digitalWrite(IN1,1);
  digitalWrite(IN2,1);   
  
}
