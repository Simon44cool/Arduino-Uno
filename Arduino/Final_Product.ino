#include <Servo.h>
int beepPin=11;
int buttonPin1 = 2;
int buttonPin2 = 13;
int buttonPin3 = 3;
int blue3 =7; int green3 =8; int green2=9;
int blue1 = 5;
int blue2 = 6;
int green1 = 10; 
int value1 = 0;
int value2 = 0;
int value3 = 0;
int player1 = 1;
int player2 = 1; 
int countBlue=0;
int countGreen=0;

void winGreen(){
  while(true){
    analogWrite(beepPin,0);
    digitalWrite(green1,HIGH);
    digitalWrite(green2,HIGH);
    digitalWrite(green3,HIGH);
    delay(500);
    digitalWrite(green1,LOW);
    digitalWrite(green2,LOW);
    digitalWrite(green3,LOW);
    delay(500);
  }
}
void winBlue(){
   while(true){
     analogWrite(beepPin,0);
     digitalWrite(blue1,HIGH);
     digitalWrite(blue2,HIGH);
     digitalWrite(blue3,HIGH);
     delay(500);
     digitalWrite(blue1,LOW);
     digitalWrite(blue2,LOW);
     digitalWrite(blue3,LOW); 
     delay(500);

  }
}
void start(){
  analogWrite(beepPin,20);
  delay(1000);
  analogWrite(beepPin,0);
  delay(1000);
  int randNumber = random(5000,10000);
  Serial.println(randNumber);
  delay(randNumber);
  
  int game = 1;
 while(game==1){
  while(value1==1||value2==1){
  analogWrite(beepPin,20);
  value1 = digitalRead(buttonPin1);
  value2 = digitalRead(buttonPin2);
  if(value1 == 0){
    if(countBlue==0){
    digitalWrite(blue1,HIGH);
    }else if(countBlue==1){
    digitalWrite(blue2,HIGH);
    }else{
    digitalWrite(blue3,HIGH);
    winBlue();
    }
    countBlue++;
    return;
  }
  if(value2 == 0){
    if(countGreen==0){
    digitalWrite(green1,HIGH);
    }else if(countGreen==1){
    digitalWrite(green2,HIGH);
    }else{
    digitalWrite(green3,HIGH);
    winGreen();
    }
    countGreen++;
    return;
  }
  }
 }
}
void setup() {
  // put your setup code here, to run once:
pinMode(buttonPin1, INPUT_PULLUP);
pinMode(buttonPin2, INPUT_PULLUP);
pinMode(buttonPin3, INPUT_PULLUP);
pinMode(blue3, OUTPUT);
pinMode(green3, OUTPUT);
pinMode(green2, OUTPUT);
pinMode(blue1, OUTPUT);
pinMode(blue2, OUTPUT);
pinMode(green1, OUTPUT);
pinMode(beepPin,OUTPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(beepPin,0);
  value1 = digitalRead(buttonPin1);
  value2 = digitalRead(buttonPin2);
  value3 = digitalRead(buttonPin3);
  if (value3 == 0) {
  start();
  }
}
  
