unsigned long intervaltrigger=43200000;
unsigned long intervalmotorOn=16000;
int motoroffFlag=0;
// Tracks the time since last watered the plants
unsigned long previousMillis=0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW); 
}
void loop() {

   unsigned long currentMillis = millis();   // Get snapshot of time

   if ((unsigned long)(currentMillis - previousMillis) >= intervaltrigger) { 
      
      digitalWrite(4, HIGH);   // toggle the Motor ON
      delay(600);    
      digitalWrite(4, LOW);    
      previousMillis = currentMillis;
      motoroffFlag = 1;
   }
   if ( motoroffFlag == 1){
      if ((unsigned long)(currentMillis - previousMillis) >= intervalmotorOn) { 
        digitalWrite(4, HIGH);   // toggle the Motor OFF
        delay(600);    
        digitalWrite(4, LOW); 
        motoroffFlag = 0; 
      }
   }
}
