/* CONFIG_CPP */
#include <stdint.h>
int SHIFTDELAY = 500;int DATAPIN = 7;
int LATCHPIN = 6;
int CLOCKPIN = 5;
int FIRSTGROUND = 10;
int SECONDGROUND = 11;
int THIRDGROUND = 12;
int FOURTHGROUND = 13;
int BUTTONX = 2;
int BUTTONY = 1;
int BUTTONZ = 0;

int mode = 0;
int groundArray[4] {FIRSTGROUND, SECONDGROUND, THIRDGROUND, FOURTHGROUND};
/* END CONFIG_CPP */