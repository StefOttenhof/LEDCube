/* CONFIG_H */
#ifndef CONFIG_H 
#define CONFIG_H

/*
* Delay and pins CAN be changed in Config.cpp
*/
extern int SHIFTDELAY;
extern int DATAPIN;
extern int LATCHPIN;
extern int CLOCKPIN;
extern int FIRSTGROUND;
extern int SECONDGROUND;
extern int THIRDGROUND;
extern int FOURTHGROUND;
extern int BUTTONX;
extern int BUTTONY;
extern int BUTTONZ;


/*
* Helper variables CAN'T be changed in Config.cpp
*/
extern bool ButtonXState;
extern bool ButtonYState;
extern bool ButtonZState;


extern uint8_t firstByte;
extern uint8_t secondByte;

extern int mode;
extern bool playing;
extern bool initialLoad;
extern int groundArray[4];


/*
* Enums
* 
* bitDirection: Least Significant Bit First or Most Significant Bit First
* 
* lastCycle: Makes animations smoother when played multiple times
* 
*/
enum bitDirection {
  LSB = 0,
  MSB = 1
};

enum lastCycle {
  NO = 0,
  YES = 1
};

#endif
/*END CONFIG_H */
