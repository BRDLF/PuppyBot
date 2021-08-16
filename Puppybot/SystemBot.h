#ifndef SystemBot
#define SystemBot

#define noseButtonPin 8 // Pin for nose
#define visorPin 9     //pin for Visor

uint32_t timer_cycle;
const uint32_t timer_timeout = 20000;
bool is_awake = true;
bool wasPushed_nose;
bool buttons_cycle;

uint32_t CompareTime(uint32_t current, uint32_t previous){
  uint32_t difference = current - previous;
  return difference;
}

void SystemCycleStart(){
  timer_cycle = millis();
  buttons_cycle = digitalRead(noseButtonPin);
}

void SetupSystem(){
  Serial.begin(9600);
  pinMode(noseButtonPin, INPUT);
  if(digitalRead(noseButtonPin) == LOW) {wasPushed_nose = false;}
  
}

#endif
