#define SHIFTDELAY 200
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
int groundArray[6] = { FIRSTGROUND, SECONDGROUND, THIRDGROUND, FOURTHGROUND, THIRDGROUND, SECONDGROUND };

// Select mode
int mode = 0;

// Select direction of shifting bits
enum bitDirection {
  LSB = 0,
  MSB = 1
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

void upAndDownAnimation(){
  // Set all layer to low
  digitalWrite(FIRSTGROUND, LOW);
  digitalWrite(SECONDGROUND, LOW);
  digitalWrite(THIRDGROUND, LOW);
  digitalWrite(FOURTHGROUND, LOW);
  
  // Set all bits to high
  firstLedsData = 0B11111111;
  secondLedsData = 0B11111111;
  // Shift bits into register
  shiftLedsData(MSB);

  // Loop through ground layers
  for(int i = 0; i < 6; i++){
    if(i == 0){
      digitalWrite(groundArray[i], HIGH);
    } else {
      digitalWrite(groundArray[i-1], LOW);
      digitalWrite(groundArray[i], HIGH);
    }

    delay(SHIFTDELAY);
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
  upAndDownAnimation();
  
}
