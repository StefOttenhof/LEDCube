/* UPANDDOWN_INO */

void leftAndRightAnimation(bitDirection animationDirection, lastCycle cycle){
  // Set all layers to high
  turnAllLayersOn();
  firstLedsData = 0B00010001;
  secondLedsData = 0B00010001;

  // Loop to the left or right depending on direction
  for(int i = 0; i < 4; i++){
    // Shift bits into register
    shiftData(animationDirection);

    // Bitshift data values
    firstLedsData = firstLedsData << 1;
    secondLedsData = secondLedsData << 1;

    shiftDelay();
  }

  // Set bit pattern
  firstLedsData = 0B01000100;
  secondLedsData = 0B01000100;

  // Loop to the left or right depending on direction
  for(int i = 0; i < 2 + cycle; i++){
    // Shift bits into register
    shiftData(animationDirection);

    // Bitshift data values
    firstLedsData = firstLedsData >> 1;
    secondLedsData = secondLedsData >> 1;

    shiftDelay();
  }
}
/* END UPANDDOWN_INO */
