#ifndef EyePoses
#define EyePoses
//enum global_state {STARE, BLINK, BLUSHEND, BLUSHHOLD, BLUSHSTART, SMILE};
                    
static const uint32_t PROGMEM adj_face_stare[8] = {
0x00F81F00,
0x01042080,
0x00300C00,
0x00300C00,
0x00300C00,
0x00700E00,
0x24300C24,
0x48700E12,
};

static const uint32_t PROGMEM adj_face_blink1[8] = {
0x00F81F00,
0x01042080,
0x00000000,
0x00000000,
0x00300C00,
0x00700E00,
0x24300C24,
0x48700E12,
};

static const uint32_t PROGMEM adj_face_blink2[8] = {
0x00000000,
0x00000000,
0x00000000,
0x01FC3F80,
0x01FC3F80,
0x00000000,
0x24000024,
0x48000012,
};

static const uint32_t PROGMEM face_happy[8] = {
0x00100800,
0x00381C00,
0x006C3600,
0x00C66300,
0x00824100,
0x00000000,
0x12000048,
0x24000024,
};

static const uint32_t PROGMEM face_blush1[8] = {
0x00000000,
0x003E7C00,
0x00000000,
0x00000000,
0x00300C00,
0x00381C00,
0x121C3848,
0x243C3C24,
};
                    
static const uint32_t PROGMEM face_blush2[8] = {
0x00000000,
0x00000000,
0x00C00300,
0x00600600,
0x00300C00,
0x14181828,
0x0A0C3050,
0x00FE7F00,
};

static const uint32_t PROGMEM face_blush3[8] = {
0x00000000,
0x00000000,
0x00C00300,
0x00600600,
0x00300C00,
0x0A181850,
0x140C3028,
0x00FE7F00,
};

const uint32_t  (*arrayface[7])[8] = {&adj_face_stare, &adj_face_blink1, &adj_face_blink2, &face_happy, &face_blush1, &face_blush2, &face_blush3};
const byte blink_anim [4] = {1, 2, 1, 0};
const uint16_t blink_animdelay [4] = {100,100,100, 0};
const byte blushstart_anim [3] = {4, 5, 5};
const uint16_t blushstart_animdelay [3] = {83, 83, 0};
const byte blushhold_anim [3] = {5, 6, 5};
const uint16_t blushhold_animdelay [3] = { 166, 166, 0};
const byte blushend_anim [4] = {6 ,5, 4, 0};
const uint16_t blushend_animdelay [4] = {83, 83, 83, 0};

byte anim_frame = 0; 


#endif
