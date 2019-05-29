/* Name: Mohammed Shafiuddin
 NetId: mshafi2
 UIN# 679816739
 
Lab 5:  Multiple inputs and outputs
 
Description: This lab is to experiment inputs and outputs from 2 sources, input from photosensor and output to LEDs and potentiometer to passive buzzer. All 4LEDs should 
             should turn on when the photosensor does not recieve or sense any (zero) brightness, if the brightness sensed half, then 2 LEDS should turn on, if brightness is reduced less
             than half then 3 LEDs should turned on.
              
Assumptions: Set up should read inputs from photo resistor and pentiometer that are connected to analog pins 0 and 1 respectively, photo resistor sends signal to 4 LEDS based on intensity of brightness that photosensor is exposed to. When the photoresistor receives the half the amount of light, 2 LEDS should be lit up, and when there is no light, all 4 LEDs should be lit up. The other input is the pentiometer that send signal to passive buzzer, amount of volume to change sent by petiometer, buzzer will increase or decrease the sound. Connections are made as follows:
              - LED3, LED4, LED5, LED6 are connected to digital pins 3,4,5,6 respectively, along with 220 Ohms resistor to each LED
              - Photo resistor and Pentiometer is connected to Analog pins 0 and 1 repectively.
              - 5V power supplied to Photo resistor and Pentiometer.
              - Ground is connected to Pentiometer and to passive Buzzer. 
              
Reference:  https://www.arduino.cc/en/Reference/AnalogWrite
            https://www.arduino.cc/en/Reference/Map
            https://www.arduino.cc/en/Reference/AnalogRead

Lab: Mondays 12 to 12:50 PM

 */
//******************************************************************************************************************************************************************
const int potentioMeter = A1, photoResistor = A0; // potentiometer and photoresistor are initialized ot analog pins 1 and 0 respectively.
int value = 0;         // Variable value is initialized to store value from photoresitor.

int LED3 = 3, LED4 = 4, LED5 = 5, LED6 =  6; // LEDs are initialized to respective pins.

int buzzer = 9; // Passive buzzer initialized

int potentioMeterValue = 0; // variable for potentiometer initialized
//****************************************************************************************************************************************************************
//Begin set up
void setup() { 
  Serial.begin(9600);
  pinMode(photoResistor, INPUT);// Photo resistor set up as input
  pinMode(buzzer, OUTPUT); // buzzzer setup as out put
 //Below  LEDs are set up as out put.
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
} // End of set up.
//*******************************************************************************************************************************************************************
//Begin of loop
void loop() { 
  value = analogRead(photoResistor); // read photo resistor and stores its value
  potentioMeterValue = analogRead(potentioMeter)/4; // stores potentiontiometer value 
  analogWrite(buzzer, potentioMeterValue); // Buzzer and potentiometer values are written 
  displayBrightness(value);  // function call with value argument based on the brightness detected.
}

// Below are the conditional statements that turns LEDS on based on the value of brightness.
void displayBrightness(int value) { 
  if (value <= 205) {
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, HIGH);
  }
  
  else if (value <= 420) {
    digitalWrite(LED3, LOW);
  }
  
  else if (value <= 620) {
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, HIGH);
  }
  
  else if (value <= 830) {
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, HIGH);
  }
  
  else if (value <= 10202) {
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
  }
}
//End of loop
//************************************************************************************************************************************************************

