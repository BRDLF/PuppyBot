#include <FastLED.h>
#include "faces.h"
#define DATA_PIN 6
#define kMH 8           //height
#define kMW 32          //width
#define kMM 256         //total LEDs
#define BUTTON_PIN 10

struct animation anim_idle;

int (*current_frame)[50][2];

CRGB leds[kMM];

// functions

uint16_t XY( uint8_t X, uint8_t Y)
{
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
  Serial.println("error, out of bounds");
  return i%kMM;
}
}

void FrameMap(int Frame[][2])
{
  for(int x = 0; Frame[x][0] != 666; x++){

    int p = XY(Frame[x][0], Frame[x][1]);
    leds[p].setHSV(138, 212, 32);
    
  }
}

void ClearScreen(){
  for (int x = 0; x < kMM; x++){
    leds[x].setHSV(0,0,0);
  }
}

uint32_t CompareTime(uint32_t base, uint16_t compare){
  return base - compare;
}

//end fucntions

  uint16_t test = CompareTime(10000, 1000);


void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, kMM); //Setup LEDS, creates an LED matrix size kMM on DATA_PIN
  Serial.begin(9600); //Set Serial Write for troubleshooting  
  pinMode(BUTTON_PIN, INPUT_PULLUP);   //Test Button PIN Setup
    


  
/*Filling the animation structs need to go in order of either current-delays-frames or in delays-current-frames
Basically, declaring anything after .frames causes the addressing to skew dramatically.
TBD if this occurs once multiple animations are created
*/
 anim_idle.current   = 0;
 anim_idle.delays[0] = 2000; 
 anim_idle.delays[1] = 100; 
 anim_idle.delays[2] = 100; 
 anim_idle.delays[3] = 100; 
 anim_idle.delays[4] = 1200; 
 anim_idle.delays[5] = 100; 
 anim_idle.delays[6] = 100; 
 anim_idle.delays[7] = 100; 
 anim_idle.delays[8] = 0; 
 anim_idle.frames[0] = &Face_stare; 
 anim_idle.frames[1] = &Face_blink1; 
 anim_idle.frames[2] = &Face_blink2; 
 anim_idle.frames[3] = &Face_blink1; 
 anim_idle.frames[4] = &Face_stare; 
 anim_idle.frames[5] = &Face_blink1; 
 anim_idle.frames[6] = &Face_blink2; 
 anim_idle.frames[7] = &Face_blink1; 
 anim_idle.frames[8] = &Face_stare; 
}

void loop() {
/*  */
if(digitalRead(BUTTON_PIN)== LOW){
  //when the button is pushed
  current_frame = anim_idle.frames[2];
  //to be replaced with "change to animation mode
}
else{
  //display idle frame (to be replaced with "void animate idle"
  current_frame = anim_idle.frames[0];
} 
// Then we write the screen
  ClearScreen();
  FrameMap(*current_frame);
  FrameMap(Face_freckles);
//Then we show the screen
    FastLED.show();
  delay(100); // 1/10 sec delay, but I want to replace this with millis() timers
}
