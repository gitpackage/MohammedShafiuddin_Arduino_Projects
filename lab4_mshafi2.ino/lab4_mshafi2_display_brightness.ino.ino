/*
Name: Mohammed Shafiuddin
 NetId: mshafi2
 UIN# 679816739

Lab 4 - More complicated input

Description: Setting up LCD screen for display, pentiometer to adjust brightness, 220 ohms resistor to restrict power,
             and a photoresistor with the anologue pin, 10K resistor, and 5V power, is connected to read the brightness, 
             this readings are compared in the algorithm, to display the output for the desired brightness, with message 
             'dark' if there is no light or brightness, 'partial light' if the brightness is not bright, medium if brightness is 'moderate', 
             and 'full lit' if enough brightness.
       
             Below is the description of connections made:
              
             LCD RS pin to digital pin 12
             LCD Enable pin to digital pin 11
             LCD D4 pin to digital pin 5
             LCD D5 pin to digital pin 4
             LCD D6 pin to digital pin 3
             LCD D7 pin to digital pin 2
             Vdd to 5V power
             Vss to ground
             V0 to pentiometer
             ground to pentiometer
             photoresistor connected to 10K resistor with ground along with
             analogue pin (A0) on one end.
             photoresistor is also supplied wit 5V power on the other end.

Assumptions: Connections made shown above should connect the power and pins to LCD screen, pentiomenter, 
             and to photoresistor, resulting in the display of message based on the readings from 
             photoresiter and the assigned levels for brightness in the algorithm.

Reference: http://playground.arduino.cc/Learning/PhotoResistor
           https://learn.adafruit.com/photocells/using-a-photocell  
       
Lab: Mondays 12 to 12:50 PM
 
*/
//************************************************************************************************************************************************************************
//Program begins
#include <LiquidCrystal.h> // Header file
const int Photo_Resistor = A0, LCD_Row = 0; // Analog pins are initialized to photo resistor
int Amount_Of_Light = 0, i = 0; // variables are initialized for amount of light
LiquidCrystal LCD_Display(12, 11, 5, 4, 3, 2); // Pins are initialized to LCD
//***************************************************************************************************************************************************************************
//Setting up the LCD and intializing photoresistor.
void setup() {
  Serial.begin(9600); // data rate being set for bits per second
  LCD_Display.begin(16, 2); // LCD is set to 16 columns and 2 rows
  pinMode(Photo_Resistor, INPUT); // Photo Resistor behavior is set as Input 
}
//**************************************************************************************************************************************************************************

//Loop begins with conditional statements being initialized based on the reading from photoresistor.
void loop() {
  Amount_Of_Light = analogRead(Photo_Resistor); // Read the value fromt this pin
  Serial.println(Amount_Of_Light); // Prints data to serial port to screen
  Amount_Of_Brightness(Amount_Of_Light); // Detects and records amount of brightness
}
//**************************************************************************************************************************************************************************
void Amount_Of_Brightness(int Amount_Of_Light) {
  LCD_Display.setCursor(0, LCD_Row); // setting LCD display column and row starting at (0,0)
  
  //Below are the conditional statements to print LCD statement based on the amount of brightness. 
  if (Amount_Of_Light <= 215) {
    LCD_Display.print("dark");
  }
  
  else if (Amount_Of_Light <= 420) {
    LCD_Display.print("partially dark");
  }
  
  else if (Amount_Of_Light <= 625) {
    LCD_Display.print("medium");
  }
  
  else if (Amount_Of_Light <= 830) {
    LCD_Display.print("partially light");
  }
  
  else if (Amount_Of_Light <= 1030) {
    LCD_Display.print("fully lit");
  }
  
  LCD_Display.setCursor(0, LCD_Row);
  delay(500);
  
  for (i  = 0; i < 16; i++) {
    LCD_Display.print(" ");
  }
}
//End of program
//****************************************************************************************************************************************************************************
