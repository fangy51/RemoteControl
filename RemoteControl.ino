
#include <IRremote.h>

int REC_PIN = 6; // where you connect the output pin of IR reciever module
int led1 = 5; 
int led2 = 4;
int led3 = 3
IRrecv irrecv(REC_PIN);
decode_results results;
int itsONled[] = {0,0,0,0};
    #define code1  FF30CF // code received from button 1
    #define code2  FF18E7 // code received from button 2
    #define code3  FF7A85 // code received from button 3
void setup()
{
  Serial.begin(9600);   
  irrecv.enableIRIn();  // Start receiver
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch(value) {
       case code1: // push button 1 to let led1 on/off
            if(itsONled[1] == 1) {        
                digitalWrite(led1, LOW);   
                itsONled[1] = 0;          
             } else {                     
                 digitalWrite(led1, HIGH); 
                 itsONled[1] = 1;          
             }
              break;
          
       case code2: // push button 2 to let led2 on/off
            if(itsONled[2] == 1) {        
                digitalWrite(led1, LOW);   
                itsONled[2] = 0;          
             } else {                     
                 digitalWrite(led1, HIGH); 
                 itsONled[2] = 1;          
             }
              break;
              
              case code3: // push button 3 to let led3 on/OFF
            if(itsONled[3] == 1) {        
                digitalWrite(led1, LOW);   
                itsONled[3] = 0;          
             } else {                     
                 digitalWrite(led1, HIGH); 
                 itsONled[3] = 1;          
             }
              break;
    }
    Serial.println(value); // test botton 
    irrecv.resume(); // obtain next value
  }
}
