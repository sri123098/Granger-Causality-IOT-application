#include <LiquidCrystal.h> 
#include <stdio.h>
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin3 = A3;
const int analogInPin5 = A5;
const int analogInPin2= A2 ;
const int analogInPin1= A1 ;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int sensorValue3 = 0;        // value read from the pot
int outputValue3 = 0;        // value output to the PWM (analog out)
int sensorValue5 = 0; 
int sensorValue1 = 0;
int sensorValue2 = 0; 
int i=0;
int led_in = 12;
char userInput;
void setup() {
  Serial.begin(9600);
   pinMode(led_in, OUTPUT);   
}

void led(){
  digitalWrite(led_in, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(4000);                       // wait for 4 second
  digitalWrite(led_in, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
}
void loop() {
  // read the analog in value:  
sensorValue = analogRead(analogInPin);
sensorValue3 = analogRead(analogInPin3);
sensorValue5 = analogRead(analogInPin5);
sensorValue1= analogRead(analogInPin1);
sensorValue2= analogRead(analogInPin2);
Serial.print("\t");
Serial.print(sensorValue);
Serial.print("\t");
Serial.print(sensorValue3);
Serial.print("\t");
Serial.print(sensorValue5);
Serial.print("\t");
Serial.print(sensorValue1);
Serial.print("\t");
Serial.println(sensorValue2);
delay(300);
// Lights up if any of the sensors are not maintaining the moisture.
// Once it writes all the sensors value on the serial port, then it will wait for the serial.available.
if (Serial.available() > 0){
      userInput = Serial.read(); 
        if(userInput == 'a'){
        led();
        Serial.println("yes");
        delay(300);        
        } 
  }
}
