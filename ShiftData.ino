/* SHIFTDATA_INO */

void shiftData(bitDirection firstBit){
    if(firstBit == 0){
        digitalWrite(LATCHPIN, LOW);
        shiftOut(DATAPIN, CLOCKPIN, LSBFIRST, firstByte);
        shiftOut(DATAPIN, CLOCKPIN, LSBFIRST, secondByte);
        digitalWrite(LATCHPIN, HIGH);
    } else if(firstBit == 1){
        digitalWrite(LATCHPIN, LOW);
        shiftOut(DATAPIN, CLOCKPIN, MSBFIRST, firstByte);
        shiftOut(DATAPIN, CLOCKPIN, MSBFIRST, secondByte);
        digitalWrite(LATCHPIN, HIGH);
    }
}

void shiftDelay(){
  delay(SHIFTDELAY);
}
/* END SHIFTDATA_INO */
