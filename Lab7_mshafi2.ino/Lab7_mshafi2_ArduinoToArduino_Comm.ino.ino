/*
 Name: Mohammed Shafiuddin
 NetId: mshafi2
 UIN# 679816739
 
Lab 7: Arduino to Arduino Communication
 
Description: Setting connection between 2 arduinos,2 buttons, 2 LEDs. Pin 5, 5V power and ground from both arduinos
             is connected to each button on the bread board. Pin 6, ground from both arduinos is connected to LEDs on 
             the bread board. 
             
Assumptions: By using pins 0(RX) and 1(TX) should enable serial communication between 2 arduinos. By pressing the 
             button on one arduino the LED connected to other arduino should turned on, vice versa with the other arduino.

Reference:             //https://www.arduino.cc/en/serial/begin
                      // https://www.arduino.cc/en/Tutorial/MasterWriter
                     //  https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/
                    //   https://www.arduino.cc/en/Serial/Write
                   //    https://www.arduino.cc/en/Serial/Read
                  //     https://www.arduino.cc/en/Serial/Available
                 //      https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/
                //       https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/

Lab: Mondays 12 to 12:50 PM
              
                      
 */
//*******************************************************************************************************************************************************************

//Initializing buttonPin and ledPin.
const int buttonPin = 5;
const int ledPin = 6; 
//*******************************************************************************************************************************************************************

// Initializing Button and LED status.
int initialState = 0, ledHigh = 0;
//*******************************************************************************************************************************************************************

// Initializing Serial monitor to communicate between arduios sending and receiving. 
void setup(){
  Serial.begin(9600); //// opens serial port, sets data rate to 9600 bps.
  pinMode(ledPin, OUTPUT); // sets output for the designated pin on arduino board.
}
//*******************************************************************************************************************************************************************

// Begin loop to transmit and receive command between arduinos
void loop(){
  transCommand(); // To transmit or send signal 
  receiveCommand(); // To receive signal
 
}

/* Function to read the button status, and a condition to write, if the button's present state is different from previous, then when button is pressed it will update the previous status. */
void transCommand(){
  int presentStatus = digitalRead(buttonPin); // read the input pin 5 for button
  if(presentStatus != initialState){            
    if(presentStatus) Serial.write(1); // send a byte with the value 1.      
    initialState = presentStatus; // sets initial state to current state.              
  }
}

// if command recieved then it will be read, if it is LOW then becomes HIGH, vice-a-versa.
void receiveCommand(){
  if(Serial.available() > 0){/* / send data only when data is receive */           
    //// read the incoming byte.
    if(Serial.read()){                   
      ledHigh = !ledHigh;                   
      if(ledHigh)   digitalWrite(ledPin, HIGH); // sets the digital pin 6 ON
      else        digitalWrite(ledPin, LOW);  // sets the digital pin 6 OFF
    }
  }
}
//*******************************************************************************************************************************************************************
