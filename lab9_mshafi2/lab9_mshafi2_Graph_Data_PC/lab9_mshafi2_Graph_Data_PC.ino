/*
 Name: Mohammed Shafiuddin
 NetId: mshafi2
 UIN# 679816739
 
Lab 9 - Graphing sensor data on a PC
 
Description: Two analog devices Potentiometer and Photo resistor is connected to Arduino and on another 
             IDE called processing a code is written to graph the readings from the analog devices on 
             Arduino. Changes in the anolge readings should show on the graph implemented using processing.
             
Assumptions: This code should read two prototypes connected and start the port by implementing Serial.begin(900).
             This port is further used by Processing IDE to establish connection betwee this Arduino IDE and 
             then the changes in the readings from prototype are read by Processing IDE and a graphing presentation
             of the variation in prototypes' readings are displayed.

Reference:  https://www.arduino.cc/en/Tutorial/Graph 
            https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing#introduction
            https://www.processing.org/download/?processing
            https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/

Lab: Mondays 12 to 12:50 PM
              
                      
 */
//*******************************************************************************************************************************************************************
//Initializing pins and variables
const int potentiometerPin = A4;
const int photoPin = A5;
int x, y;
//**********************************************************************************************************************************************************************

void setup() {
  // The data data rate is set in bits per second (baud) for serial data transmission
  Serial.begin(9600);
} 
//*************************************************************************************************************************************************************************
void loop() {
  // Reads the value from the specified analog pin
  x = analogRead(potentiometerPin); 
  y = (analogRead(photoPin)/4); 
  //Data will be printed to the serial port as human-readable ASCII text
 // Serial.print("potent:");
  Serial.print(x);
  Serial.print(" ");
  Serial.println(y);
  // wait a bit for the analog-to-digital converter to stabilize after the last
  delay(50); //wait before another loop
}
//End
//*************************************************************************************************************************************************************************
