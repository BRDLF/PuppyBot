#include <FastLED.h>
#include "faces.h"
#define DATA_PIN 6
#define kMH 8           //height
#define kMW 32          //width
#define kMM 256         //total LEDs
#define BUTTON_PIN 10

//byte eyes_state = 0;
//#define STARE 0
//#define BLINK 1
//#define BLUSHEND 2
//#define BLUSHHOLD 3
//#define BLUSHSTART 4
//#define SMILE 5

enum global_state {STARE, BLINK, BLUSHEND, BLUSHHOLD, BLUSHSTART, SMILE}eyes_state;

uint16_t (*current_frame)[51][2] = NULL;

uint32_t current_delay = 0;
uint32_t current_timer;
uint32_t lastactive_timer;
uint32_t blink_delay = 2100;

bool blushbutton_waspushed;

CRGB leds[kMM];

// functions

uint16_t ProgressAnim ( byte animaddress[], uint16_t animdelay[], byte &frameref){
  uint16_t testint = arrayface[animaddress[frameref]];
  current_frame = arrayface[animaddress[frameref]];
//  Serial.println("Starting animation progress");
//  Serial.print("anim address ");
//  Serial.print(frameref);
//  Serial.print(" is ");
//  Serial.println(animaddress[frameref]);
//  Serial.print("animdelay ");
//  Serial.print(frameref);
//  Serial.print(" is ");
//  Serial.println(animdelay[frameref]);
//  Serial.print("testint ");
//  Serial.println(testint);
//  Serial.print("var ");
//  Serial.println(arrayface[testint][0][0][0]);
//  Serial.print("hard code ");
//  Serial.println(arrayface[1][0][0][0]);
//  Serial.print("Set frameref "); 
//  Serial.println(frameref);
  uint16_t to_return = animdelay[frameref];
  if (to_return == 0) {
    frameref = 0;
  }
  else {
    frameref++;
  }
//  Serial.print(F("frameref is now "));
//  Serial.println(F(frameref));
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
  Serial.println(F("error, out of bounds"));
  return i%kMM;
}
}

void FrameMap(uint16_t Frame[][51][2])
{
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

void ClearScreen(){
  for (int x = 0; x < kMM; x++){
    leds[x].setHSV(0,0,0);
  }
}

uint32_t CompareTime(uint32_t current, uint32_t previous){
  uint32_t difference = current - previous;
  return difference;
}

//end fucntions

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, kMM); //Setup LEDS, creates an LED matrix size kMM on DATA_PIN
  Serial.begin(9600); //Set Serial Write for troubleshooting  
  pinMode(BUTTON_PIN, INPUT);   //Test Button PIN Setup
  if(digitalRead(BUTTON_PIN)== LOW) { blushbutton_waspushed = false;}
  lastactive_timer = millis();
}

void loop() {
/*  */
current_timer = millis();
bool current_button = digitalRead(BUTTON_PIN);

switch ( eyes_state ) 
{
  case STARE:
    current_frame = arrayface[0];
    if (CompareTime(current_timer, lastactive_timer) >= blink_delay){
      eyes_state = BLINK;
      Serial.println("blinking");
    }  
    break;
  case BLINK:
    if (CompareTime(current_timer, lastactive_timer) >= current_delay){
      current_delay = ProgressAnim( blink_anim, blink_animdelay, anim_frame);
      lastactive_timer = millis();     
    }
    if (current_delay==0){
      eyes_state = STARE;
      blink_delay = random(2300, 5000);
      Serial.print("next blink in ");
      Serial.println(blink_delay);
    }
    break;
  case BLUSHEND:
    if (CompareTime(current_timer, lastactive_timer) >= current_delay){
      current_delay = ProgressAnim( blushend_anim, blushend_animdelay, anim_frame);
      lastactive_timer = millis();       
    if (current_delay==0){
      eyes_state = STARE;
      blushbutton_waspushed = false;
    }
    }
    break;
  case BLUSHHOLD:
    if (CompareTime(current_timer, lastactive_timer) >= current_delay){
      current_delay = ProgressAnim( blushhold_anim, blushhold_animdelay, anim_frame);
      lastactive_timer = millis();  
       
    if (current_button == 0) {eyes_state = BLUSHEND;}
    }
   break;
  case BLUSHSTART:
    if (CompareTime(current_timer, lastactive_timer) >= current_delay){
      current_delay = ProgressAnim( blushstart_anim, blushstart_animdelay, anim_frame);
      lastactive_timer = millis();     
    }
    if (current_delay==0){
      if (current_button == 1)  {eyes_state = BLUSHHOLD; Serial.println(F("going to hold"));}
      if (current_button== 0) {eyes_state = BLUSHEND; Serial.println(F("going to end"));}
    }
    break;
}





if(current_button == 1 && blushbutton_waspushed == false){
// Pushed
  eyes_state = BLUSHSTART;
  blushbutton_waspushed = true;
  Serial.println(F("starting to blush"));

}

Serial.println(current_button);

// Screen Clear/Write
  ClearScreen();
  FrameMap(current_frame);
// Show
    FastLED.show();
//    delay(1000);
}
