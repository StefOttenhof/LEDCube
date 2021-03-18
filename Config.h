/* CONFIG_H */
#ifndef CONFIG_H 
#define CONFIG_H

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
extern int mode;
extern int groundArray[4];


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
