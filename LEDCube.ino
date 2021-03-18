#include "Config.h"
#include "ShiftData.h"
#include "Ground.h"
#include "upAndDown.h"
#include "leftAndRight.h"

bool ButtonXState = HIGH;
bool ButtonYState = HIGH;
bool ButtonZState = HIGH;

int posY = 0;
uint16_t posXZ = 1;


uint8_t firstLedsData = 0B00000000;
uint8_t secondLedsData = 0B00000001;

// Indexes for circle animation
int indexesLsb[12] = { 0B11100000, 0B01110000, 0B00110001, 0B00010001, 0B00000001, 0B00000000, 0B00000000, 0B00000000, 0B00000000, 0B00001000, 0B10001000, 0B11001000};
int indexesMsb[12] = { 0B00000000, 0B00000000, 0B00000000, 0B00010000, 0B00010001, 0B00010011, 0B00000111, 0B00001110, 0B10001100, 0B10001000, 0B10000000, 0B00000000};


void forwardAndBackwardAnimation(bitDirection animationDirection, lastCycle cycle){
  // Set all layers to high
  turnAllLayersOn();

  if(animationDirection == MSB){
    // Set bit pattern
    firstLedsData = 0B00001111;
    secondLedsData = 0B00000000;

    // Loop 
    for(int i = 0; i < 4; i++){
      shiftData(animationDirection);

      if(firstLedsData == 0B11110000){
        firstLedsData = 0B00000000;
        secondLedsData = 0B00001111;
      } else {
        secondLedsData = secondLedsData << 4;
        firstLedsData = firstLedsData << 4;
      }

      shiftDelay();
    }

    // Set bit pattern
    firstLedsData = 0B00000000;
    secondLedsData = 0B00001111;

    // Loop 
    for(int i = 0; i < 2 + cycle; i++){
      shiftData(animationDirection);

      if(secondLedsData == 0B00001111){
        secondLedsData = 0B00000000;
        firstLedsData = 0B11110000;
      } else {
        secondLedsData = secondLedsData >> 4;
        firstLedsData = firstLedsData >> 4;
      }

      shiftDelay();
    }
  } else {
    // Set bit pattern
    firstLedsData = 0B00000000;
    secondLedsData = 0B00001111;

    // Loop 
    for(int i = 0; i < 4; i++){
      shiftData(animationDirection);

      if(secondLedsData == 0B11110000){
        secondLedsData = 0B00000000;
        firstLedsData = 0B00001111;
      } else {
        secondLedsData = secondLedsData << 4;
        firstLedsData = firstLedsData << 4;
      }

      shiftDelay();
    }

    // Set bit pattern
    firstLedsData = 0B11110000;
    secondLedsData = 0B00000000;

    // Loop 
    for(int i = 0; i < 2; i++){
      shiftData(animationDirection);

      if(firstLedsData == 0B00001111){
        firstLedsData = 0B00000000;
        secondLedsData = 0B11110000;
      } else {
        secondLedsData = secondLedsData >> 4;
        firstLedsData = firstLedsData >> 4;
      }

      shiftDelay();
    }
  }
}

void circleAnimation(bitDirection animationDirection, lastCycle cycle){
   // Set all layers to high
  turnAllLayersOn();

  if(animationDirection == MSB){
    for(int i = 0; i < 12 - cycle; i++){
       firstLedsData = indexesMsb[i];
       secondLedsData = indexesLsb[i];
        
       shiftData(MSB);

       shiftDelay();
    }
  } else {
    //Implement for LSB
  }
}

void twoRowsLeftAndRightAnimation(bitDirection animationDirection, lastCycle cycle){
  // Set all layers to high
  turnAllLayersOn();

   // Set bit pattern
   firstLedsData = 0B00000011;
   secondLedsData = 0B11000000;

   for(int i = 0; i < 4; i++){
      shiftData(animationDirection);

      firstLedsData = firstLedsData << 4;
      secondLedsData = secondLedsData >> 4;

      shiftDelay();
   }
}

void moveY(){
      if(posY == 0){
      digitalWrite(groundArray[3], LOW);
      digitalWrite(groundArray[posY], HIGH);
      delay(700);
      posY++;
    } else if(posY == 3){
      digitalWrite(groundArray[posY - 1], LOW);
      digitalWrite(groundArray[posY], HIGH);
      delay(700);
      posY = 0;
    } else {
       digitalWrite(groundArray[posY - 1], LOW);
      digitalWrite(groundArray[posY], HIGH);
      delay(700);
      posY++;
    }

}

void moveX(){
    if(firstLedsData == 0B00001000){
      firstLedsData = 0B00000001;
    } else if(firstLedsData == 0B10000000){
      firstLedsData = 0B00010000;
    } else {
      firstLedsData = firstLedsData << 1;
    }

    if(secondLedsData == 0B00001000){
      secondLedsData = 0B00000001;
    } else if(secondLedsData == 0B10000000){
      secondLedsData = 0B00010000;
    } else {
      secondLedsData = secondLedsData << 1;
    }
    shiftData(MSB);
}

void moveZ(){
  if(firstLedsData >= 0B00010000){
    secondLedsData = firstLedsData >> 4;
    firstLedsData = 0B00000000;
  } else if(secondLedsData >= 0B00010000){
    firstLedsData = secondLedsData >> 4;
    secondLedsData = 0B00000000;
  } else {
    firstLedsData = firstLedsData << 4;
    secondLedsData = secondLedsData << 4;
  }

  shiftData(MSB);
}

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
    //digitalWrite(FIRSTGROUND, HIGH);
    //digitalWrite(SECONDGROUND, HIGH);
    //digitalWrite(THIRDGROUND, HIGH);
    //digitalWrite(FOURTHGROUND, HIGH);

    shiftData(MSB);

    PCICR |= 0b00000111;
    PCMSK2 |= 0B00000111;
}

ISR (PCINT2_vect){
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

void loop(){
  leftAndRightAnimation(MSB, NO);
  //forwardAndBackwardAnimation(MSB, YES);
  //circleAnimation(LSB, YES);
  //twoRowsLeftAndRightAnimation(MSB, YES);
  //upAndDownAnimation(MSB, NO);
}
