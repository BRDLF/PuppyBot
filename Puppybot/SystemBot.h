#ifndef SystemBot
#define SystemBot

#define kNoseButtonPin 8
#define visorPin 9     

uint32_t timer_cycle;
const uint32_t timer_timeout = 20000;
bool is_awake = true;
bool was_pushed_nose;
bool buttons_cycle;

uint32_t CompareTime(uint32_t current, uint32_t previous){
  uint32_t difference = current - previous;
  return difference;
}

void SystemCycleStart(){
  timer_cycle = millis();
  buttons_cycle = digitalRead(kNoseButtonPin);
}

void SetupSystem(){
  Serial.begin(9600);
  pinMode(kNoseButtonPin, INPUT);
  if(digitalRead(kNoseButtonPin) == LOW) {was_pushed_nose = false;}
  
}

#endif
