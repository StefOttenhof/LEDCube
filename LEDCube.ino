#define SHIFTDELAY 500
#define DATAPIN 7
#define LATCHPIN 6
#define CLOCKPIN 5
#define FIRSTGROUND 10
#define SECONDGROUND 11
#define THIRDGROUND 12
#define FOURTHGROUND 13
#define BUTTONX 2
#define BUTTONY 1
#define BUTTONZ 0

uint8_t firstLedsData = 0B00000000;
uint8_t secondLedsData = 0B00000000;

// Indexes for circle animation
int indexesLsb[14] = { 0B10000000, 0B11000000, 0B11100000, 0B01110000, 0B00110001, 0B00010001, 0B00000001, 0B00000000, 0B00000000, 0B00000000, 0B00000000, 0B00001000, 0B10001000, 0B10001000};
int indexesMsb[14] = { 0B00000000, 0B00000000, 0B00000000, 0B00000000, 0B00000000, 0B00010000, 0B00010001, 0B00010011, 0B00000111, 0B00001110, 0B10001100, 0B10001000, 0B10000000, 0B00000000};

// Ground layers for up and down animation
int groundUpArray[7] = { FIRSTGROUND, SECONDGROUND, THIRDGROUND, FOURTHGROUND, THIRDGROUND, SECONDGROUND, FIRSTGROUND };
int groundDownArray[7] = { FOURTHGROUND, THIRDGROUND, SECONDGROUND, FIRSTGROUND, SECONDGROUND, THIRDGROUND, FOURTHGROUND };

// Select mode
int mode = 0;

// Select direction of shifting bits
enum bitDirection {
  LSB = 0,
  MSB = 1
};

enum lastCicle {
  NO = 0,
  YES = 1
};

void shiftLedsData(bitDirection firstBit){
    if(firstBit == 0){
        digitalWrite(LATCHPIN, LOW);
        shiftOut(DATAPIN, CLOCKPIN, LSBFIRST, firstLedsData);
        shiftOut(DATAPIN, CLOCKPIN, LSBFIRST, secondLedsData);
        digitalWrite(LATCHPIN, HIGH);
    } else if(firstBit == 1){
        digitalWrite(LATCHPIN, LOW);
        shiftOut(DATAPIN, CLOCKPIN, MSBFIRST, firstLedsData);
        shiftOut(DATAPIN, CLOCKPIN, MSBFIRST, secondLedsData);
        digitalWrite(LATCHPIN, HIGH);
    }
}

void upAndDownAnimation(bitDirection animationDirection, lastCicle cicle){
  // Set all layer to low
  digitalWrite(FIRSTGROUND, LOW);
  digitalWrite(SECONDGROUND, LOW);
  digitalWrite(THIRDGROUND, LOW);
  digitalWrite(FOURTHGROUND, LOW);

  int animationArray[7];
  
  // Set all bits to high
  firstLedsData = 0B11111111;
  secondLedsData = 0B11111111;
  // Shift bits into register
  shiftLedsData(MSB);

  // Select direction
  if(animationDirection == LSB){
    memcpy(animationArray, groundUpArray, sizeof(groundUpArray[0])*7);
  } else {
    memcpy(animationArray, groundDownArray, sizeof(groundDownArray[0])*7);
  }
  // Loop through ground layers
  for(int i = 0; i < 6 + cicle; i++){
    if(i == 0){
      digitalWrite(animationArray[i], HIGH);
    } else {
      digitalWrite(animationArray[i-1], LOW);
      digitalWrite(animationArray[i], HIGH);
    }

    delay(SHIFTDELAY);
  }
}

void leftAndRightAnimation(bitDirection animationDirection, lastCicle cicle){
  // Set all layers to high
  digitalWrite(FIRSTGROUND, HIGH);
  digitalWrite(SECONDGROUND, HIGH);
  digitalWrite(THIRDGROUND, HIGH);
  digitalWrite(FOURTHGROUND, HIGH);

  // Set bit pattern
  firstLedsData = 0B00010001;
  secondLedsData = 0B00010001;

  // Loop to the left or right depending on direction
  for(int i = 0; i < 4; i++){
    // Shift bits into register
    shiftLedsData(animationDirection);

    // Bitshift data values
    firstLedsData = firstLedsData << 1;
    secondLedsData = secondLedsData << 1;

    delay(SHIFTDELAY);
  }

  // Set bit pattern
  firstLedsData = 0B01000100;
  secondLedsData = 0B01000100;

  // Loop to the left or right depending on direction
  for(int i = 0; i < 2 + cicle; i++){
    // Shift bits into register
    shiftLedsData(animationDirection);

    // Bitshift data values
    firstLedsData = firstLedsData >> 1;
    secondLedsData = secondLedsData >> 1;

    delay(SHIFTDELAY);
  }
}

void forwardAndBackwardAnimation(bitDirection animationDirection, lastCicle cicle){
  // Set all layers to high
  digitalWrite(FIRSTGROUND, HIGH);
  digitalWrite(SECONDGROUND, HIGH);
  digitalWrite(THIRDGROUND, HIGH);
  digitalWrite(FOURTHGROUND, HIGH);

  if(animationDirection == MSB){
    // Set bit pattern
    firstLedsData = 0B00001111;
    secondLedsData = 0B00000000;

    // Loop 
    for(int i = 0; i < 4; i++){
      shiftLedsData(animationDirection);

      if(firstLedsData == 0B11110000){
        firstLedsData = 0B00000000;
        secondLedsData = 0B00001111;
      } else {
        secondLedsData = secondLedsData << 4;
        firstLedsData = firstLedsData << 4;
      }

      delay(SHIFTDELAY);
    }

    // Set bit pattern
    firstLedsData = 0B00000000;
    secondLedsData = 0B00001111;

    // Loop 
    for(int i = 0; i < 2 + cicle; i++){
      shiftLedsData(animationDirection);

      if(secondLedsData == 0B00001111){
        secondLedsData = 0B00000000;
        firstLedsData = 0B11110000;
      } else {
        secondLedsData = secondLedsData >> 4;
        firstLedsData = firstLedsData >> 4;
      }

      delay(SHIFTDELAY);
    }
  } else {
    // Set bit pattern
    firstLedsData = 0B00000000;
    secondLedsData = 0B00001111;

    // Loop 
    for(int i = 0; i < 4; i++){
      shiftLedsData(animationDirection);

      if(secondLedsData == 0B11110000){
        secondLedsData = 0B00000000;
        firstLedsData = 0B00001111;
      } else {
        secondLedsData = secondLedsData << 4;
        firstLedsData = firstLedsData << 4;
      }

      delay(SHIFTDELAY);
    }

    // Set bit pattern
    firstLedsData = 0B11110000;
    secondLedsData = 0B00000000;

    // Loop 
    for(int i = 0; i < 2; i++){
      shiftLedsData(animationDirection);

      if(firstLedsData == 0B00001111){
        firstLedsData = 0B00000000;
        secondLedsData = 0B11110000;
      } else {
        secondLedsData = secondLedsData >> 4;
        firstLedsData = firstLedsData >> 4;
      }

      delay(SHIFTDELAY);
    }
  }
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
    digitalWrite(FIRSTGROUND, HIGH);
    digitalWrite(SECONDGROUND, HIGH);
    digitalWrite(THIRDGROUND, HIGH);
    digitalWrite(FOURTHGROUND, HIGH);

}

void loop(){
  //upAndDownAnimation(MSB, YES);
  //leftAndRightAnimation(MSB, NO);
  forwardAndBackwardAnimation(MSB, YES);
}
