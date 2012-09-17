#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
char input[17]; // define the maximum length of the string
int length;
         
void setup(){
  Serial.begin(115200);  // set baud-rate
  myservo.attach(9);    // attaches the servo on pin 9 to the servo object 
}
         
void loop(){
  
  length = 0;
  
  while(true){
    
    // wait for input
    while (!Serial.available());
    
    // get input
    input[length] = Serial.read();       
    
    // wait for termination ascii character (13 == Space)
    if (input[length] == 13) break;
  }
  
  // null terminate the string
  input[++length] = 0;

  // convert the string to an int
  int motorAngle = atoi(input);
  
  // scale it to use it with the servo (value between 1 and 180) 
  int val = map(motorAngle, 1, 100, 0, 179);
  
  // sets the servo position according to the scaled value
  myservo.write(val);
  
  // waits for the servo to get there
  delay(15);
}
