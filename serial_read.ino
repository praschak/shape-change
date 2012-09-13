// define the maximum length of the string
char input[17];
int length;
         
void setup(){
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
}
