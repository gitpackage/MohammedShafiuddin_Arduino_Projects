
/*
 Name: Mohammed Shafiuddin
 NetId: mshafi2
 UIN# 679816739
 
 Lab 1: Get Started with Arduino
 
 Description: Turn on and off onboard LED, red LED, and green LED alternatively. 
 
Assumptions: When arduio is powered, PIN 11, 12, and 13 gets the power and this power is output to the board by connecting a wire coming out 
    of the pin 13 and also connecting a ground between them. Ground and positive is connected to the cathode and anode side of the LED repectively,
    along with the 220 ohms resistor between the anode side, this will allow the charge to flow safely without breaking the circuit. Then by writing 
    a algorithm shown below will turns the LEDs onboard red, green, and red alternatively.
    
Reference: UIC blackboard course link directed to arduino website that has generic instructions.

 Lab: Mondays 12 to 12:50 PM
*/


//Program begins
// Output pins are initialized
int LED1 = 11;
int LED2 = 12;
int LED3 = 13;

// Setup for power output
void setup() {
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
}

// Loop begins and continuous forever
void loop() {
  digitalWrite(LED1, HIGH);    // turn on LED1 
  delay(1000);                  // wait for 1000ms
  digitalWrite(LED1, LOW);     // turn off LED1
  delay(1000);                  // wait for 1000ms
  
  digitalWrite(LED2, HIGH);    // turn on LED2
  delay(1000);                  // wait for 1000ms       
   digitalWrite(LED2, LOW);     // turn off LED2
  delay(1000);                  // wait for 1000ms
  
  digitalWrite(LED3, HIGH);    // turn on LED3 
  delay(1000);                  // wait for 1000ms
  digitalWrite(LED3, LOW);     // turn off LED3
  delay(1000);                  // wait for 1000ms before running program all over again
}
