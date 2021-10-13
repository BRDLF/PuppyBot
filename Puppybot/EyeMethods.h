#ifndef EyeMethods
#define EyeMethods

#include "EyeDefines.h"
#include "EyePoses.h"
#include "SystemBot.h"

uint16_t XY( uint8_t X, uint8_t Y){
  uint16_t i;

    if( X & 0x01){
      uint8_t reverseY = (kMH - 1) - Y;
      i = kMH*(X) + reverseY;
    }
    else{
      i = kMH*X + Y;
    }

  if (i < kMM){
    return i;}
  else{
    Serial.println(F("error, out of bounds"));
    return i%kMM;
  }
}

uint16_t ProgressAnim ( const byte animaddress[], const uint16_t animdelay[], byte &frameref){
  current_frame = arrayface[animaddress[frameref]];
  uint16_t to_return = animdelay[frameref];
  if (to_return == 0) {
    frameref = 0;
  }
  else {
    frameref++;
  }
  return to_return;
}

void FrameMap(const uint16_t Frame[][51][2]){
  for(int x = 0; pgm_read_word(&Frame[0][x][0]) != 255 /*x<51*/; x++){
//    Serial.print(x);
//    Serial.println();
    uint16_t framex = pgm_read_word(&Frame[0][x][0]);
//    Serial.print("framex is ");
//    Serial.println(framex);
    uint16_t framey = pgm_read_word(&Frame[0][x][1]);
//    Serial.print("framey is ");
//    Serial.println(framey);
    uint16_t p = XY(framex, framey);
//    leds[p].setHSV(255, 102, 32);
    leds[p].setHSV(138, 212, 16);
  }
}

void FrameMap(const uint32_t Frame[][8]){
  uint16_t i;
  for(uint8_t x = 0; x < 8; x++){
    for(uint8_t y = 0; y < 32; y++){
      uint32_t p = pgm_read_word(&Frame[0][x]);
      i = XY(x, 31 - y);  //bitread reads from the rightmost bit. 31-1 to read leftmost bit instead.
      if(bitRead(p, y)){
        leds[i].setHSV(138, 212, 16);
      }
    }
  }
}

void ClearScreen(){
  for (int x = 0; x < kMM; x++){
    leds[x].setHSV(0,0,0);
  }
}



void SetupEyes(){
  FastLED.addLeds<NEOPIXEL, visorPin>(leds, kMM); //Setup LEDS, creates an LED matrix size kMM on DATA_PIN
  timer_last_active_eyes = millis();
  is_going_to_move_eyes = true;
}

void EyesSwitch(){  
  switch ( state_eyes ) 
  {
  case STARE:
    current_frame = arrayface[0];
    if (CompareTime(timer_cycle, timer_last_active_eyes) >= delay_blink){
      state_eyes = BLINK;
      Serial.println("eyes_state: BLINK");
    }  
    break;
  case BLINK:
    if (CompareTime(timer_cycle, timer_last_active_eyes) >= delay_eyes){
      delay_eyes = ProgressAnim( blink_anim, blink_animdelay, anim_frame);
      timer_last_active_eyes = millis();     
      is_going_to_move_eyes = true;
    }
    if (delay_eyes==0){
      state_eyes = STARE;
      Serial.println("eyes_state: STARE");
      delay_blink = random(2300, 5000);
      Serial.print("next blink in ");
      Serial.println(delay_blink);
    }
    break;
  case BLUSHEND:
    if (CompareTime(timer_cycle, timer_last_active_eyes) >= delay_eyes){
      delay_eyes = ProgressAnim( blushend_anim, blushend_animdelay, anim_frame);
      timer_last_active_eyes = millis();        
      is_going_to_move_eyes = true;    
    if (delay_eyes==0){
      state_eyes = STARE;
      Serial.println("eyes_state: STARE");
      was_pushed_nose = false;
    }
    }
    break;
  case BLUSHHOLD:
    if (CompareTime(timer_cycle, timer_last_active_eyes) >= delay_eyes){
      delay_eyes = ProgressAnim( blushhold_anim, blushhold_animdelay, anim_frame);
      timer_last_active_eyes = millis();       
      is_going_to_move_eyes = true;
       
    if (buttons_cycle == LOW) {state_eyes = BLUSHEND; Serial.println(F("eyes_state: BLUSHEND"));} 
    }
   break;
  case BLUSHSTART:
    if (CompareTime(timer_cycle, timer_last_active_eyes) >= delay_eyes){
      delay_eyes = ProgressAnim( blushstart_anim, blushstart_animdelay, anim_frame);
      timer_last_active_eyes = millis();         
      is_going_to_move_eyes = true; 
    }
    if (delay_eyes==0){
      if (buttons_cycle == HIGH)  {state_eyes = BLUSHHOLD; Serial.println(F("eyes_state: BLUSHHOLD"));}
      if (buttons_cycle == LOW) {state_eyes = BLUSHEND; Serial.println(F("eyes_state: BLUSHEND"));}
    }
    break;
  }
}

void CycleEndEyes(){
  Serial.println("CycleEndEyes");
  if(delay_eyes == 0 && buttons_cycle == HIGH && was_pushed_nose == false){
// Pushed
  state_eyes = BLUSHSTART;
  Serial.println("eyes_state: BLUSHSTART");
  was_pushed_nose = true;
  }
  if(is_going_to_move_eyes){
  ClearScreen();
  FrameMap(current_frame);
// Show
  FastLED.show();
  is_going_to_move_eyes = false;
  }
}

#endif
