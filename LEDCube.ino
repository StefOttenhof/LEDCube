#include "Config.h"
#include "ShiftData.h"
#include "Ground.h"
#include "Buttons.h"
#include "upAndDown.h"
#include "leftAndRight.h"
#include "forwardAndBackward.h"
#include "Circle.h"

void setup(){
    pinMode(LATCHPIN, OUTPUT);
    pinMode(DATAPIN,  OUTPUT);  
    pinMode(CLOCKPIN, OUTPUT);
    pinMode(FIRSTGROUND, OUTPUT);
    pinMode(SECONDGROUND, OUTPUT);
    pinMode(THIRDGROUND, OUTPUT);
    pinMode(FOURTHGROUND, OUTPUT);
    pinMode(BUTTONX, INPUT_PULLUP);
    pinMode(BUTTONY, INPUT_PULLUP);
    pinMode(BUTTONZ, INPUT_PULLUP);
    turnAllLayersOff();
    shiftData(MSB);

    PCICR |= 0b00000111;
    PCMSK2 |= 0B00000111;
}

ISR (PCINT2_vect){
  /*
  * Interup Service Routine
  * ----------------------------
  *   Interupt on pin 0, 1 and 2
  *   Switches from mode and controls one LED in cube
  *   
  */
  if(!(digitalRead(BUTTONY)) && !ButtonYState && mode == 1){
    ButtonYState = HIGH;
    mode = 0;
    initialLoad = 1;
     
   } else if(digitalRead(BUTTONY) && ButtonYState){
     ButtonYState = LOW;
   }

   if(!mode && !playing){
      if(!(digitalRead(BUTTONX)) && !ButtonXState){
         ButtonXState = HIGH;
         moveX();
   
       } else if(digitalRead(BUTTONX) && ButtonXState){
          ButtonXState = LOW;
       }

      if(!(digitalRead(BUTTONY)) && !ButtonYState){
          ButtonYState = HIGH;
          moveY();
   
      } else if(digitalRead(BUTTONY) && ButtonYState){
          ButtonYState = LOW;
      }

      if(!(digitalRead(BUTTONZ)) && !ButtonZState){
          ButtonZState = HIGH;
          moveZ();
   
       } else if(digitalRead(BUTTONZ) && ButtonZState){
          ButtonZState = LOW;
       }
   }
}

void playAnimations(){
  /*
  * Function: playAnimations
  * ----------------------------
  *   Plays a list of animations
  *   
  *   returns: none
  */
  playing = true;

  /*
  * Add list of animations below
  * ⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄
  */
  
  leftAndRightAnimation(MSB, YES);
  forwardAndBackwardAnimation(LSB, YES);
  circleAnimation(MSB, NO);
  //twoRowsLeftAndRightAnimation(MSB, YES);
  upAndDownAnimation(MSB, NO);
  
  /*
  * ⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃⌃
  * Add list of animations above
  */
  playing = false;
}

void loop(){
  if(mode){
    playAnimations();
    
    if(!mode && initialLoad){
     configLayout();
     initialLoad = false;
    }
    
    shiftDelay();
  }

}
