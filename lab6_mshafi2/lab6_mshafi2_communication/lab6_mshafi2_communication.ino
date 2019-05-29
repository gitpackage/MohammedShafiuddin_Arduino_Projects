
/*
 Name: Mohammed Shafiuddin
 NetId: mshafi2
 UIN# 679816739
//**********************************************************************************************************************************************************************************
Lab 6: Communication
//***********************************************************************************************************************************************************************************
Description: Setting up LCD screen for display, pentiometer to adjust brightness, 220 ohms resistor to restrict power to LCD, 
             arduino and bread board to build and connect circuits, and an algorithm that splits screen 
             into 16 columns and 2 rows to diaplay date on top and time at the bottom. Following is the detail description of connections made:
              
             LCD RS pin to digital pin 12
             LCD Enable pin to digital pin 11
             LCD RW to ground 
             LCD K to ground
             LCD A to 5V with 220 ohms resistor
             LCD D4 pin to digital pin 5
             LCD D5 pin to digital pin 4
             LCD D6 pin to digital pin 3
             LCD D7 pin to digital pin 2
             Vdd to 5V power
             Vss to ground
             V0 to pentiometer
             ground to pentiometer
//***************************************************************************************************************************************************************************************
Assumptions: Connections shown above should connect the power and pins to LCD screen and 
             petiomenter, resulting in the display of the desired message. Relevant pins should set a Serial connection to LCD. 
             Communication port should postition the LCD cursor to column and row, based on the command. Should read the user
             data and write on LCD. This should result in the display of date on date on time on LCD as desired.

Reference: UIC blackboard instructions and links directed to arduino website that has generic instructions.
           http://arduino.cc/en/Reference/Serial#.UwYyzfldV8E
           http://arduino.cc/en/Serial/Available#.UwYy2PldV8E
           http://arduino.cc/en/Serial/ReadBytesUntil#.UwYy6_ldV8E
           Further References:  https://www.arduino.cc/en/serial/begin
                                https://playground.arduino.cc/Code/DateTime
                                https://www.arduino.cc/en/Serial/ReadString
                                https://www.arduino.cc/en/serial/available
                                https://www.arduino.cc/en/Tutorial/StringSubstring
                                https://www.arduino.cc/reference/en/language/variables/data-types/string/functions/toint/
                                https://www.youtube.com/watch?v=X5u2qCzcPn8 
                                https://www.arduino.cc/reference/en/language/variables/data-types/string/functions/indexof/
                                https://www.arduino.cc/en/Serial/ReadString
//*********************************************************************************************************************************************************************************************                                
Lab: Mondays 12 to 12:50 PM
*/
//**********************************************************************************************************************************************************************************************

//Program begins
//Header files with .h extension
#include <TimeLib.h>
#include <Time.h>
#include <LiquidCrystal.h>
//************************************************************************************************************************************************************************
//Begin Initilizing variables
// Initializing LCD to arduino pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal LCD(rs, en, d4, d5, d6, d7);

//Initializing calendar and time variables
int days, months, years, Hours ,Minutes, Seconds;

//Initializing String for Date and Time for user input instructions
String Date = "Please enter date as shown ->  MM/DD/YYYY ";
String Time = "Enter time as shown ->  HH:MM:SS ";

//Initializing variables to read input string
String user_Date, user_Time;
//End of initialization of variables
//*************************************************************************************************************************************************************************
//Begin set up for LCD
void setup()
{
  Serial.begin(9600); //Bridging data communication between Arduino and LCD with baud speed.

 //Initializing LCD with 16 columns and 2 rows
  LCD.begin(16, 2);
  
}//End of LCD setup
//*************************************************************************************************************************************************************************
//Begin loop
void loop()
{
  Serial.println(Date);//Prints message how to enter date format
  
  //Begin while condiiton for date when its true
  while (true)
  {
   if (Serial.available() == 1){ break; }// Checks if date data arrived then break
  }

  if (Serial.available() == 1)// Checks if time data arrived then progress
  {
    user_Date = Serial.readString();// Stores the characters read from the serial buffer to string
    int length = user_Date.length();// Stores the length
    validate_User_Date(user_Date); //Function call with argument to check date to given date

    Serial.println("You have entered Date: " + user_Date); 

    //Conditional statement to check if the date format entered is longer than 10 columns
    if (length > 10){ Serial.println("Incorrect date format, please re-enter!!"); }
  }//End of loop with while condition for date
 //************************************************************************************************************************************************************************
  Serial.println(Time); //Print message to enter time

  //Begin while loop when true for time
  while (true)
  {
    if (Serial.available() == 1){ break;}// Checks if time valid data is arrived then break
  }

  if (Serial.available() == 1) // Progress if time data is available
  {  
    user_Time = Serial.readString(); // Stores the characters read from the serial buffer to string
    validate_User_Time(user_Time); //Function call with argument to check time to the given time
    
    setTime(Hours, Minutes, Seconds, days, months, years); // set the time read from serial communication
    clock(); // set the clock read from serial communication---
  }
}
//End of loop with while loop for time
//*************************************************************************************************************************************************************************
//Begin function to check the date format
void validate_User_Date(String Date)
{ 
  String month, day, year; // Initializing String variables for date
  //Data parsing by checking the condition of date is separated by '/' and converting String to integer
  month = Date.substring(0, Date.indexOf("/"));
  months = month.toInt();
  
  day = Date.substring(5, Date.indexOf("/") + 1); //plus 1 is to ignore the space and reach to the next character
  days = day.toInt();

  year = Date.substring(6);
  years = year.toInt();

  //Coditional statement for range value of months between 1 to 12
  if ((months > 12) || (months < 1))
  {
    Serial.println("Error, Values entered are out of range, please re-enter "); //Notify user for out of range data
    loop(); //restart loop
  }
  //Conditional check for the months with 30 days only
  else if ((months == 4) || (months == 6) || (months == 9) || (months == 11)) 
  {
    if ((days > 30) || (days < 1))
    {
      Serial.println("Entered data is out of range, please re-enter as specified ");
      loop();
    }
  } 
  //Conditional check for months with 31 days
  else if ((months == 1) || (months == 3) || (months == 5) || (months == 7) || (months == 8) || (months == 10) || (months == 12)) 
  {
    if ((days > 31) || (days < 1))
    {
      Serial.println("Entered data is out of range, please re-enter as specified ");
      loop();
    }
  }
  //Considering intercalary year
  else if (years % 4 == 0)
  {
    if (months == 2)
    {
      if (days > 29)
      {
        Serial.println("Entered data is out of range, please re-enter as specified ");
        loop();
      }
    }
  }
  //Not a intercalary year
  else if (months == 2)
  {
    if (days > 28)
    {
      Serial.println("Entered data is out of range, please re-enter as specified ");
      loop();
    }
  }
}//End of function
//****************************************************************************************************************************************************************************
//Begin function for time validation
void validate_User_Time(String input)
{
  String hours, minutes, seconds; //Initializing string variables
  
  //Parsing time starting at index 0 to 10 values, ':' as the end value at each section of time.
  hours = input.substring(0, input.indexOf(":"));
  minutes = input.substring(5, input.indexOf(":") + 1);
  seconds = input.substring(6);
  //Time string variable values are converted to intgers
  Hours = hours.toInt();
  Minutes = minutes.toInt();
  Seconds = seconds.toInt();
  //Conditional statement to check out of range values for time
  if ((Hours < 0) || (Hours > 23) || (Minutes < 0) || (Minutes > 59) || (Seconds < 0) || (Seconds > 59))
  {
    Serial.println("Time Data entered is out of range, Please re-enter valid data ");
    Serial.println(Time); //Prints time string
    while (true)//Condition while true
    {
      if (Serial.available() == 1){ break; } // Checks if time valid data is arrived then break
    }
    if (Serial.available() == 1)
    {
      user_Time = Serial.readString();//reads characters from the serial buffer into a string
      validate_User_Time(user_Time);//---
     
    }
  }
}
//End of function
//************************************************************************************************************************************************************************
//Begin clock function
void clock()
{
  while (true)//Conditon while true
  {
    time_t t = now(); // Returns the number of seconds since Jan 1 1970.
    Serial.print(hour(t));
    Serial.print(minute(t));
    Serial.print(second(t));
    Serial.println();
    Serial.println(day(t));
    Serial.println(month(t));
    Serial.println(year(t));
    delay(1000); 
    LCD.clear();
    printDate(month(t), day(t), year(t)); 
    printTime(hour(t), minute(t), second(t));
  }
}
//End of clock function
//******************************************************************************************************************************************************************************
//Begin Date fucntion
void printDate(int month, int day, int year)
{
  LCD.setCursor(10, 0); //"Position the LCD cursor; that is, set the location at which subsequent text written to the LCD will be displayed."
  LCD.print(year); //print year
  
  LCD.setCursor(8, 0);// Postition the LCD cursor to column and row
  LCD.print("/"); // print '/'
  
  LCD.setCursor(5, 0);// Postion the LCD cursor to column and row
  LCD.print(day); // prints day
  
  LCD.setCursor(3, 0); //Postion the LCD cursor to column and row
  LCD.print("/"); //pints '/'
  
  LCD.setCursor(0, 0); //Postion the LCD cursor to column and row
  LCD.print(month); //prints month
}
//End of function
//*******************************************************************************************************************************************************************************
//Begin function to print time
void printTime(int hour, int minute, int second)
{
  // Postion the LCD cursor to relevant col and row, and prints time
  LCD.setCursor(10, 1);
  if (second < 10){ LCD.print("0"); }
  
  LCD.print(second);
  LCD.setCursor(8, 1);
  LCD.print(":");
  
  LCD.setCursor(5, 1);
  LCD.print(minute);
  LCD.setCursor(3, 1);
  LCD.print(":");
  
  LCD.setCursor(0, 1);
  LCD.print(hour);
}
//End of function
//********************************************************************************************************************************************************************************
