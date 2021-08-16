#ifndef EarMethods
#define EarMethods

#include "EarDefines.h"
#include "EarPoses.h"
#include "SystemBot.h"

uint16_t ProgressPose (const uint16_t poseaddress[], const uint16_t posedelay[], uint16_t &frameref){
  rightEar = earIndex[poseaddress[frameref]];
  uint16_t to_return = posedelay[frameref];
  if (to_return == 0) {
    frameref = 0;
  }
  else {
    frameref++;
  }
  return to_return;
}

void UpdateEars(const uint16_t RGTEAR[], const uint16_t LFTEAR[]){
  uint16_t tyr = pgm_read_word(&RGTEAR[0]);
  uint16_t tpr = pgm_read_word(&RGTEAR[1]);
  uint16_t trr = pgm_read_word(&RGTEAR[2]);
  uint16_t tyl = pgm_read_word(&LFTEAR[0]);
  uint16_t tpl = pgm_read_word(&LFTEAR[1]);
  uint16_t trl = pgm_read_word(&LFTEAR[2]);
  yawRight.write(tyr);
  pitchRight.write(tpr);
  rollRight.write(trr);
  yawLeft.write(tyl);
  pitchLeft.write(tpl);
  rollLeft.write(trl);
}

void UpdateEar(const uint16_t RGTEAR[]){
  uint16_t ty = pgm_read_word(&RGTEAR[0]);
  uint16_t tp = pgm_read_word(&RGTEAR[1]);
  uint16_t tr = pgm_read_word(&RGTEAR[2]);
  Serial.println("MoveAll");
  Serial.println(ty);
  Serial.println(tp);
  Serial.println(tr);
  yawRight.write(ty);
  pitchRight.write(tp);
  rollRight.write(tr);
}

void SetupEars(){
  yawRight.attach(yawPinR, 470, 2250);
  pitchRight.attach(pitchPinR);
  rollRight.attach(rollPinR, 590, 2550);
//  yawLeft.attach(yawPinL);
//  pitchLeft.attach(pitchPinL);
//  rollLeft.attach(rollPinL);
  pinMode(yawUp, INPUT_PULLUP);
  pinMode(pitchUp, INPUT_PULLUP);
  timer_ears_last_active = millis();
  state_ears = NEUTRAL;

  rightEar = earIndex[0];
  is_going_to_move_ears = true;
}

void EarSwitch(){
  Serial.println("--- Begin EarSwitch ---");
  switch(state_ears)
  {
    case NEUTRAL:
    if(!(rightEar = earIndex[0]))
    {
    rightEar = earIndex[0];
    is_going_to_move_ears = true;
    }
    break;
    break;
    case FEAR:
    if(CompareTime(timer_cycle, timer_ears_last_active) > delay_ears)
    {
      delay_ears = ProgressPose(fear_anim, fear_animdelay, ear_frame);
      Serial.println("Fear: Progress");
      timer_ears_last_active = millis();
    }
    if (delay_ears==0)
     {
      state_ears = NEUTRAL;
      Serial.println("ear_state: STARE");
     }
    is_going_to_move_ears = true;
    break;
    case TWITCH:
    if(CompareTime(timer_cycle, timer_ears_last_active) > delay_ears)
    {
      delay_ears = ProgressPose(twitch_anim, twitch_animdelay, ear_frame);
      Serial.println("Twitch: Progress");
      is_going_to_move_ears = true;
      timer_ears_last_active = millis();
    }
    if (delay_ears ==0)
    {
      state_ears = NEUTRAL;
      Serial.println("ear_state: STARE");
    }
    is_going_to_move_ears = true;
    break;
  }
  Serial.println("--- Finishing EarSwitch ---");
}

void CycleEndEars(){
Serial.println("CycleEndEars");
    if(digitalRead(yawUp) == LOW && delay_ears == 0) 
  {
   state_ears = FEAR;
   Serial.println("ear_state: FEAR");
  }

  else if(digitalRead(pitchUp) == LOW && delay_ears == 0)
  {
    state_ears = TWITCH;
    Serial.println("ear_state: TWITCH");
  }
  
  if(is_going_to_move_ears){
  Serial.println("Moving Ear");
  UpdateEar(*rightEar);
  is_going_to_move_ears = false;
 }
}

#endif
