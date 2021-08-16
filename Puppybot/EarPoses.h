//This file is for cataloging different "poses" for the ears to make.
//Also "animations[anims]" which make up multiple poses.

#ifndef EarPoses
#define EarPoses

static const uint16_t PROGMEM earNeutral[3]
                              ={0, 90, 85};

static const uint16_t PROGMEM earTwtich1[3]
                              ={0, 90, 45};

static const uint16_t PROGMEM earTwtich2[3]
                              ={0, 105, 65};

static const uint16_t PROGMEM earFear[3]
                              ={180,60, 180};

uint16_t earVariable[3]
                              ={0, 90, 90};

const uint16_t (*earIndex[5])[3] = {&earNeutral, &earTwtich1, &earTwtich2, &earVariable, &earFear};

const uint16_t twitch_anim[4] = {1, 2, 0, 0};
const uint16_t twitch_animdelay[4] = {83, 83, 300, 0};
const uint16_t fear_anim[2] = {4, 0};
const uint16_t fear_animdelay[2] = {2500, 0};

uint16_t ear_frame = 0;


#endif

/* Old Poses go here to die
 * static const uint16_t PROGMEM earTwitchUp[3]
                              ={0, 90, 105};

static const uint16_t PROGMEM earTwitchDown[3]
                              ={0, 90, 65};
*/
