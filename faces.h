#ifndef faces.h
#define faces.h

byte Face_stare[50][2] 
                  = {{8,1},  {9,0}, {10,0}, {11,0}, {12,0}, {13,0} ,{14,1} ,{17,1} ,{18,0} ,{19,0}, {20,0}, {21,0}, {22,0} ,{23,1}, //eyebrows 14
/* II */            {10,5}, {10,7}, {11,2}, {11,3}, {11,4}, {11,5} ,{11,6} ,{11,7} ,{12,2}, {12,3}, {12,4}, {12,5} ,{12,6} ,{12,7}, //left eye  14
                    {21,5}, {21,7}, {19,2}, {19,3}, {19,4}, {19,5} ,{19,6} ,{19,7} ,{20,2}, {20,3}, {20,4}, {20,5} ,{20,6} ,{20,7}, //right eye 14
                    {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}};                                //KILL + Buffer 8
                    

byte Face_blink1 [50][2]  
                   = {{8,1},  {9,1}, {10,1}, {11,1}, {12,1}, {13,1} ,{14,1} ,{17,1} ,{18,1} ,{19,1}, {20,1}, {21,1}, {22,1} ,{23,1}, //eyebrows 14
/* II */             {10,5}, {10,7}, {11,4}, {11,5}, {11,6}, {11,7} ,{12,4}, {12,5} ,{12,6} ,{12,7},                                 //left eye 10
                     {21,5}, {21,7}, {19,4}, {19,5}, {19,6}, {19,7} ,{20,4}, {20,5} ,{20,6} ,{20,7},                                 //right eye 10
                     {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0},                                 //KILL + Buffer 8
                     {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}};                                 //KILL + Buffer 8      

byte Face_blink2 [50][2] 
                    = {{8,3}, {9,3}, {10,3}, {11,3}, {12,3}, {13,3}, {14,3}, {17,3}, {18,3}, {19,3}, {20,3}, {21,3}, {22,3}, {23,3},  // Topline 14
                      {8,4}, {9,4}, {10,4}, {11,4}, {12,4}, {13,4}, {14,4}, {17,4}, {18,4}, {19,4}, {20,4}, {21,4}, {22,4}, {23,4},   // Bottomline 14
                      {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0},                                 //KILL + Buffer 8
                      {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0},                                 //KILL + Buffer 6
                      {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}};                                                    //KILL + Buffer 8   

byte Face_happy[50][2] 
                  = {{8,4},  {9,3}, {10,2}, {11,1}, {12,2}, {13,3} ,{14,4} ,{17,4} ,{18,3} ,{19,2}, {20,1}, {21,2}, {22,3}, {23,4},   //14
/* ^^ */            {8,3},  {9,2}, {10,1}, {11,1}, {12,1}, {13,2} ,{14,3} ,{17,3} ,{18,2} ,{19,1}, {20,1}, {21,1}, {22,2}, {23,3},    //14
                    {8,4},  {9,3}, {10,2}, {11,1}, {12,2}, {13,3} ,{14,4} ,{17,4} ,{18,3} ,{19,2}, {20,1}, {21,2}, {22,3}, {23,4},    //14
                    {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}};                                  //KILL + Buffer 8};   

byte Face_blush1[50][2]    
                  = {{10,1},  {11,1},   {12,1}, {13,1}, {14,1}, {17,1}, {18,1}, {19,1}, {20,1}, {21,1},                       //10
/* >< */            {10,4}, {11,4}, {10,5}, {11,5}, {12,5}, {11,6}, {12,6}, {13,6}, {10,7}, {11,7}, {12,7},  {13,7},          //12
                    {20,4}, {21,4}, {20,5}, {21,5}, {19,5}, {20,6}, {19,6}, {18,6}, {21,7}, {20,7}, {19,7},  {18,7},          //12
                    {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0},                           //KILL + Buffer 8
                    {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}};                          //KILL + Buffer 8  
                    
byte Face_blush2[50][2]    
                  = {{8,2},  {9,2},   {9,3}, {10,3}, {10,4}, {11,4}, {11,5}, {12,5}, {12,6}, {13,6},                                //10
/* >< */            {23,2}, {22,2}, {22,3}, {21,3}, {21,4}, {20,4}, {20,5}, {19,5}, {19,6}, {18,6},                                 //10
                    {8,7},  {9,7},  {10,7}, {11,7}, {12,7}, {13,7}, {14,7}, {17,7}, {18,7}, {19,7}, {20,7}, {21,7}, {22,7}, {23,7}, //14
                    {12,2}, {13,2}, {14,1}, {14,2}, {17,1}, {17,2}, {18,2}, {19,2},                                                 //8
                    {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}, {255, 0}};                                //KILL + Buffer 8  


byte Face_freckles[9][2] 
                        = {{3,6}, {6,6}, {25,6}, {28,6},                                             //Top row
                           {2,7}, {5,7}, {26,7}, {29,7},                                             //Bot row
//                           {3,5}, {6,5}, {25,5}, {28,5},                                           //Topest row
                           {255,0}                                                                }; //KILL

byte Face_blush_freckles[13][2] 
                        = {{4,5}, {6,5}, {25,5}, {27,5},                                        //Top row
                           {3,6}, {5,6}, {26,6}, {28,6},                                        //Bot row
                           {4,4}, {6,4}, {25,4}, {27,4},
                           {255,0}                                                                };  //KILL

int arrayface[6] = {&Face_stare, &Face_blink1, &Face_blink2, &Face_happy, &Face_blush1, &Face_blush2}; //old method of indexing frames, takes up a ton of memory for some reason?
byte blinkanim [4] = {1, 2, 1, 0};
uint16_t blinkanimdelay [4] = {100,100,100, 0};
byte currentframe = 0; 


#endif
