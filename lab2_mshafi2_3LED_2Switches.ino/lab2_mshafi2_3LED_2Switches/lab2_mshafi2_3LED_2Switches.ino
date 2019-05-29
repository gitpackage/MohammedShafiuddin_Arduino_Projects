
/*
 Name: Mohammed Shafiuddin
 NetId: mshafi2
 UIN# 679816739
 
Lab 2: Input and Output
 
Description: Setting up 3 LEDs and 2 switches, and a algorithm that turns on LEDS in binary format.
 
Assumptions: Setting the circuit by connecting two buttons on a bread board to two different PINS(1,2) and a 5V power 
             source and connect a ground along with 220 ohms resistor, similarly, connect three LEDS on a bread board 
             to three different PINS (11,12,13) and supply 5V power and connect a ground. Then, to keep track of the number of button presses,  
             write code which algorithmically converts that number to a binary output. One button increases the output and the other decreases
             output in binary format, this will be identified by reading the LEDs in binary format, such as if button is pressed to 
             increase and if all 3 LEDs are on that can be read as 111 in binary format, then by pressing the decrease button, all 3 LEDs should
             read smaller reading than 111, which could be 001, 110, 100..so on.

Reference: UIC blackboard course link directed to arduino website that has generic instructions.
           Bitwise operation tutorial was real helpful and the link is "https://www.arduino.cc/reference/en/language/structure/bitwise-operators/bitshiftleft/".

Lab: Mondays 12 to 12:50 PM
*/
//********************************************************************************************************************************************************************************************************
//Program begins here

const int PIN_1_ButtonDecrease = 1, PIN_2_ButtonIncrease = 2;    // Initializing PINS to push button variables. 
const int PIN_11 = 11, PIN_12 = 12, PIN_13 = 13;            // LED blue = PIN_11; LED red = PIN_12; LED green = PIN_13.
int  pinTracker = 11, buttonIncrease = LOW, buttonDecrease = LOW, count = 0; // pushbutton status variables.

//****************************************************************************************************************************************************************************
//Setup begins.
void setup() {
 // Conditional initialization of LED output by iterating .
  while(pinTracker > 7){
  pinMode(pinTracker, OUTPUT);
  pinTracker--;
  }
  
  // initializing input as the pushbutton.
  pinMode(PIN_2_ButtonIncrease, INPUT);
  pinMode(PIN_1_ButtonDecrease, INPUT); 
}//End of setup.

//***************************************************************************************************************************************************************************
//Loop begins
void loop() {
  // reads the pushbutton activity.
  while (buttonIncrease == LOW && buttonDecrease == LOW) {
  buttonIncrease = digitalRead(PIN_2_ButtonIncrease);
  buttonDecrease = digitalRead(PIN_1_ButtonDecrease);  
  }

  // iterating button press each time.
  if (buttonIncrease == HIGH) {
    count++;
    }
  if (buttonDecrease == HIGH) {
    count--;
    }

  //All LEDs being reset to LOW.
  digitalWrite(PIN_11, LOW);
  digitalWrite(PIN_12, LOW);
  digitalWrite(PIN_13, LOW);
  
  //LEDs are turned on.
  long led = count;
  if ((led & 1 ) == 1) {
    digitalWrite(PIN_11, HIGH);
  }
  if (((led >> 1) & 1) == 1) {
    digitalWrite(PIN_12, HIGH);
  }
  if (((led >> 2) & 1) == 1) {
    digitalWrite(PIN_13, HIGH);
  }
  delay(100);
  
  while (buttonIncrease == HIGH || buttonDecrease == HIGH) {
    buttonIncrease = digitalRead(PIN_2_ButtonIncrease);
    buttonDecrease = digitalRead(PIN_1_ButtonDecrease);
  }
}// End of Loop.z
