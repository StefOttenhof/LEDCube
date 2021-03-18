/* CONFIG_CPP */
#include <stdint.h>
int SHIFTDELAY = 500;
int DATAPIN = 7;
int LATCHPIN = 6;
int CLOCKPIN = 5;
int FIRSTGROUND = 10;
int SECONDGROUND = 11;
int THIRDGROUND = 12;
int FOURTHGROUND = 13;
int BUTTONX = 2;
int BUTTONY = 1;
int BUTTONZ = 0;

bool ButtonXState = 1;
bool ButtonYState = 1;
bool ButtonZState = 1;

bool playing = true;
bool initialLoad = true;

uint8_t firstLedsData = 0B00000000;
uint8_t secondLedsData = 0B00000000;

int mode = 1;
int groundArray[4] {FIRSTGROUND, SECONDGROUND, THIRDGROUND, FOURTHGROUND};
/* END CONFIG_CPP */
