#include <FastLED.h>
#include "faces.h"
#define DATA_PIN 6
#define kMH 8           //height
#define kMW 32          //width
#define kMM 256         //total LEDs
#define BUTTON_PIN 10


byte (*current_frame)[50][2];
byte global_state = 0;
uint16_t current_delay = 0;
uint16_t current_timer;

CRGB leds[kMM];

// functions

uint16_t ProgressAnim ( byte animaddress[], uint16_t animdelay[], byte &frameref){
  //Some diagnostic tests
  Serial.println("Starting animation progress");
  Serial.print("anim address ");
  Serial.print(frameref);
  Serial.print(" is ");
  Serial.println(animaddress[1]);
  Serial.print("animdelay ");
  Serial.print(frameref);
  Serial.print(" is ");
  Serial.println(animdelay[1]);
  current_frame = arrayface[animaddress[frameref]];
  Serial.print("Set frameref "); 
  Serial.println(frameref);
  Serial.println(blinkanim[0]);
  //The actual code
  uint16_t to_return = animdelay[frameref];
  if (to_return == 0) {
    frameref = 0;
  }
  else {
    frameref++;
  }
  Serial.print("frameref is now ");
  Serial.println(frameref);
  return to_return;
}

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

void FrameMap(byte Frame[][2])
{
  for(int x = 0; Frame[x][0] != 255; x++){

    int p = XY(Frame[x][0], Frame[x][1]);
//    leds[p].setHSV(255, 102, 32);
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
  current_frame = arrayface[0];
  current_timer = millis();

}

void loop() {
/*  */

if(digitalRead(BUTTON_PIN)== LOW){
  //when the button is pushed
//  current_frame = arrayface[2];
  ProgressAnim( blinkanim, blinkanimdelay, currentframe);
  //to be replaced with "change to animation mode"
}
// Then we write the screen
  ClearScreen();
  FrameMap(*current_frame);
  FrameMap(Face_freckles);
//Then we show the screen
    FastLED.show();
delay(100);
//uint16_t current_timer
}
