#include <LiquidCrystal.h> 
#include <stdio.h>
// initialize the library with the numbers of the interface pins
// LiquidCrystal lcd(5, 4);--------------------------------------------------------1
// These constants won't change. They're used to give names

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

const int analogInPin3 = A3;

const int analogInPin5 = A5;
//const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

int sensorValue3 = 0;        // value read from the pot
int outputValue3 = 0;        // value output to the PWM (analog out)

int sensorValue5 = 0; 
int i=0;
void setup() {
  // initialize serial communications at 9600 bps:
 // lcd.begin(16, 2);----------------------------------------------------------------2
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:


  
  sensorValue = analogRead(analogInPin);
  sensorValue3 = analogRead(analogInPin3);
  sensorValue5 = analogRead(analogInPin5);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  outputValue3 = map(sensorValue3, 0, 1023, 0, 255);
  // change the analog out value:
//analogWrite(analogOutPin, outputValue);
  // print the results to the Serial Monitor:
/**** the following is the code to check if we can print the string directly 
   char buffer[50];
   i=sprintf(buffer, "sensor0 = %s sensor3 = %s",sensorValue,sensorValue3);
   for(int l= 0; l<=i; l++) 
   Serial.print(buffer[l]); ****/
Serial.print("\t");
Serial.print(sensorValue);
Serial.print("\t");
Serial.print(sensorValue3);
Serial.print("\t");
Serial.println(sensorValue5);

//Serial.print("\t");
//Serial.print(sensorValue3);
//Serial.print("\t");
//Serial.println(sensorValue5);
delay(200);
//  char *k=sprintf();
//  Serial.print(k); 
//  Serial.print(sensorValue);
////  Serial.print("\t output = "); 
////  Serial.println(outputValue); 
//  
//  Serial.print(" sensor3 = "); 
//  Serial.println(sensorValue3);
//Serial.print("\t output = "); 
//Serial.println(outputValue); 
  // Prints and move the cursor to the new line. That's the only difference between serial.println and print
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
 
}

/* The following program is for LCD display of the sensor value which is converted after ADC *  
 *  
lcd.clear();
lcd.print("Soil Moisture:");// print the results to the LCD Display:
sensorValue = analogRead(analogInPin);// read the analog in value:
lcd.setCursor(0, 1);
lcd.print(sensorValue);
// wait 300 milliseconds before the next loop for the 
//analog-to-digital converter to settle after the last reading:
delay(300);

lcd.clear();
lcd.print("ADC value:");// print the results to the LCD Display:
sensorValue = analogRead(analogInPin);// read the analog in value:
lcd.setCursor(0, 1);
lcd.print(outputValue);


https://www.baldengineer.com/when-do-you-use-the-arduinos-to-use-serial-flush.html


Serial.flush()
I twill wait for the serial communication such as print statement to send the information and then concludes once the communication is established.


The following is the program whenyou aretrying to clear the receiving  buffer. 

while(Serial.available())
  Serial.read();


Serial.write()

Writes binary data to the serial port. This data is sent as a byte or series of bytes; to send the characters representing the digits of a number use the print() function instead.

Serial.print()

Prints data to the serial port as human-readable ASCII text. 
It's good to use serial.print or println


https://petrimaki.com/2013/04/28/reading-arduino-serial-ports-in-windows-7/


Reading data from the computer and printing that to the system


It may be because the port is busy and reload the program into Arduino board and then perform the python serial read. That should be good enough

  


*/
