/* SHIFTDATA_INO */

void shiftData(bitDirection firstBit){
  /*
  * Function: shiftData
  * ----------------------------
  *   Shfits data into shift register
  *
  *   firstBit: Most or Least Significant Bit First
  *   
  *   returns: none
  */
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
  /*
  * Function: shiftDelay
  * ----------------------------
  *   Delay based on defined SHIFTDELAY time in ms
  *   
  *   returns: none
  */
  delay(SHIFTDELAY);
}

/* END SHIFTDATA_INO */
