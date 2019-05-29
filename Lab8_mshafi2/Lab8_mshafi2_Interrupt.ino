/*
Name: Mohammed Shafiuddin
 NetId: mshafi2
 UIN# 679816739
//**********************************************************************************************************************************************************************************
Lab 8: Interrupts
//***********************************************************************************************************************************************************************************
Description: This should function as described on the balck board as follows:

"When the inital button is pressed, the display should display “Interrupt received! Press button 2 to continue”

When the user presses button 2 the display goes back to displaying "We have been waiting for X seconds", and restarts the time a 0 seconds."

 
             into 16 columns and 2 rows to diaplay interruptions and reset values. Following is the detail description of connections made:
              
             LCD RS pin to digital pin 12
             LCD Enable pin to digital pin 11
             LCD RW to ground 
             LCD K to ground
             LCD A to 5V with 220 ohms resistor
             LCD D4 pin to digital pin 4
             LCD D5 pin to digital pin 5
             LCD D6 pin to digital pin 6
             LCD D7 pin to digital pin 7
             Vdd to 5V power
             Vss to ground
             V0 to pentiometer
             ground to pentiometer
//***************************************************************************************************************************************************************************************
Assumptions: Connections shown above should connect the power and pins to LCD screen and 
             petiomenter, resulting in the display of the desired message. Relevant pins should set a Serial connection to LCD. Two buttons should work with pin 2 and 3, since these are interrupt buttons of arduino. One button press will and other button will should take it back to initial state. 
            

Reference: UIC blackboard instructions and links directed to arduino website that has generic   instructions.
           https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
           https://www.arduino.cc/reference/en/language/functions/time/millis/
           https://www.arduino.cc/en/Tutorial/LiquidCrystalSetCursor
//*********************************************************************************************************************************************************************************************                                
Lab: Mondays 12 to 12:50 PM

//***************************************************************************************************************************************************************************
  
*/

//Header file
#include <LiquidCrystal.h>


LiquidCrystal lcd(11,12,4,5,6,7); //LCD screen 
int interruptPin3 = 3; //Button to interrupt
int goBack = 2; //Button to interrupt
int count = 0; //count
//**************************************************************************************************************************************************************************
//Begin set up
void setup() {
  
  lcd.begin(16, 2); //Initializing LCD to columns and rows
  pinMode(interruptPin3,INPUT_PULLUP); // Input mode
  pinMode(goBack,INPUT); //input mode
  attachInterrupt(digitalPinToInterrupt(interruptPin3),repeat,CHANGE); // Interrupt is assigned for thet button
  attachInterrupt(digitalPinToInterrupt(goBack),reset,CHANGE); // Reset interrupt is initialize.
  
}
int buttonState = 0; // Initializing variable to keep track of button
int inital = 0;
//*************************************************************************************************************************************************************************
//Begin Loop
void loop()
{
  if(buttonState != 1)
  {
  lcd.setCursor(0,0); // Reposition cursor
  lcd.print("We have been waiting for ");
  lcd.setCursor(0,1); // Reposition cursor
  //lcd.print("Seconds ");
  lcd.setCursor(6,1); // Reposition cursor
  lcd.print(count);
   lcd.print(" Seconds");
  lcd.setCursor(9,1); // Reposition cursor
  
  //Conditional statements
  if(inital == 0)
  {
    buttonState = digitalRead(goBack);
    inital = 1;
  }
  else
  {
    if(buttonState)
    {
  
      lcd.print("Seconds");
    }
  }
  
   //lcd.print(count);
   count++;
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Interrupt received! Press button 2 to continue");
  }
  delay(1000);
  lcd.clear();

}
//***********************************************************************************************************************************************************************
//Resetting the button state
void reset()
{
  lcd.clear();
  count = 0;
  buttonState = 1;
}
//*****************************************************************************************************************************************************************************
void repeat()
{
  buttonState = 0;
}

//**************************************************************************************************************************************************************************

