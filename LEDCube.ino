#include "Config.h"
#include "ShiftData.h"
#include "Ground.h"
#include "Buttons.h"
#include "upAndDown.h"
#include "leftAndRight.h"
#include "forwardAndBackward.h"
#include "Circle.h"




void setup(){
    // put your setup code here, to run once:
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

    Serial.begin(9600);
    while (!Serial) {}
}

ISR (PCINT2_vect){
     if(!(digitalRead(BUTTONY)) && !ButtonYState && mode == 1){
     ButtonYState = HIGH;
     mode = 0;
     initialLoad = 1;
     Serial.println(mode);
     
     } else if(digitalRead(BUTTONY) && ButtonYState){
       ButtonYState = LOW;
     }



     ////////////

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
    playing = true;
    
    leftAndRightAnimation(MSB, YES);
    forwardAndBackwardAnimation(LSB, YES);
    circleAnimation(MSB, NO);
    //twoRowsLeftAndRightAnimation(MSB, YES);
    upAndDownAnimation(MSB, NO);
    
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
