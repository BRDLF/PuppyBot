#include <FastLED.h>
#include "faces.h"
#define DATA_PIN 6
#define kMH 8           //height
#define kMW 32          //width
#define kMM 256         //total LEDs
#define BUTTON_PIN 10



int (*ptr)[50][2];
//a pointer for eyeball reference

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

unsigned long CompareTime(unsigned long base, int compare){
  return base - compare*10;
}

//end fucntions

int test = CompareTime(10000, 100);



void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, kMM);                     //Setup LEDS
  Serial.begin(9600);                                                 //Set Serial Write for troubleshooting  
  pinMode(BUTTON_PIN, INPUT); digitalWrite(BUTTON_PIN, HIGH);         //Test Button PIN Setup
  ptr = &Face_stare;                                                  //Set initial state of eyes pointer
  
  Serial.println("test");
  Serial.println(test);

 idle.delays[0] = 2000; 
 idle.delays[1] = 100; 
 idle.delays[2] = 100; 
 idle.delays[3] = 100; 
 idle.delays[4] = 1200; 
 idle.delays[5] = 100; 
 idle.delays[6] = 100; 
 idle.delays[7] = 100; 
 idle.delays[8] = 0;


}

void loop() {
 idle.frames[0] = &Face_stare; 
 idle.frames[1] = &Face_blink1; 
 idle.frames[2] = &Face_blink2; 
 idle.frames[3] = &Face_blink1; 
 idle.frames[4] = &Face_stare; 
 idle.frames[5] = &Face_blink1; 
 idle.frames[6] = &Face_blink2; 
 idle.frames[7] = &Face_blink1; 
 idle.frames[8] = &Face_stare;                                            //if these go in setup the addresses are all wrong. but when they're here, there's extraneous work for the cpu and there's too much delay
/*  */
if(digitalRead(BUTTON_PIN)){
 // ptr = anim[0][0];
  ptr = idle.frames[0];
}
else{                                                                     //when button pushed
  ptr = &Face_shy;
  delay(5);
} 
// Then we write the screen
  ClearScreen();
  FrameMap(*ptr);
  FrameMap(Face_freckles);
//Then we show the screen
    FastLED.show();
    Serial.println(test);
  delay(100); //delay, but I want to replace this with millis() timers
}
