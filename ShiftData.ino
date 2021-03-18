/* SHIFTDATA_INO */

void shiftData(bitDirection firstBit){
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

void shiftDelay(){
  delay(SHIFTDELAY);
}
/* END SHIFTDATA_INO */
