
/*
 Name: Mohammed Shafiuddin
 NetId: mshafi2
 UIN# 679816739
 
Lab 3: Scrolling output
 
Description: Setting up LCD screen for display, pentiometer to adjust brightness, 220 ohms resistor to restrict power, 
             arduino and bread board to build and connect circuits, and an algorithm that splits screen 
             into 16 columns and 2 rows to diaplay name on top and scrolling message at the bottom. Following is
             the detail description of connections made:
              
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

Assumptions: Connections made shown above should connect the power and pins to LCD screen and 
             petiomenter, resulting in the display of the desired message.

Reference: UIC blackboard course link directed to arduino website that has generic instructions.
           https://www.arduino.cc/en/Tutorial/LiquidCrystalScroll
           
Lab: Mondays 12 to 12:50 PM
*/
//*************************************************************************************************************************************************************************

//Program begins
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initializing pins

//Initializing the variables for string, delay and LCD width.
int stringSize = 0, i = 0, setDelay = 250, screenColumns = 16;
String Name = "Mohammed Shafiuddin", subString[16]; // Initializing variable to place a name.
//*************************************************************************************************************************************************************************
//Initializing screen with 16 columns and 2 rows
void setup() {
  lcd.begin(16, 2); //Assigning screen size to 16 rows and 2 columns.
  
}
//*************************************************************************************************************************************************************************
//Begin loop 
void loop() {
  scroll(1, "Go East or West Professor Theys is Best "); // Assigning postion 1 to display at the first line on LCD.
}
//*************************************************************************************************************************************************************************
// Iterate through the screen columns size 16 to completely scroll the message.
void scroll(int line, String string) {
  stringSize = string.length();
  
  for (i = screenColumns; i >= 0; i--) {
    lcd.setCursor(0, line  -1); // setting row 1 to display name
    lcd.print(Name);
    lcd.setCursor(i, line);
    lcd.print(string.substring(0, 16));//starting and ending point for sentence
    
    delay(setDelay);
  }
  
  i = 0;
  // Condition to start scrolling while the iterator 'i' is not equals to columns stringSize.
  while (i != stringSize) {
    i++;
    lcd.setCursor(0, line);
    lcd.print(string.substring(i,i+16));
    delay(setDelay);
  }
}
//End of program
//******************************************************************************************************************************************************************
