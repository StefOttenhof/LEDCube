/* GROUND_INO */

  void turnAllLayersOn(){
    digitalWrite(FIRSTGROUND, HIGH);
    digitalWrite(SECONDGROUND, HIGH);
    digitalWrite(THIRDGROUND, HIGH);
    digitalWrite(FOURTHGROUND, HIGH);
  }
  
  void turnAllLayersOff(){
    digitalWrite(FIRSTGROUND, LOW);
    digitalWrite(SECONDGROUND, LOW);
    digitalWrite(THIRDGROUND, LOW);
    digitalWrite(FOURTHGROUND, LOW);
  }
  
  void turnLayerOn(int layer){
    digitalWrite(layer, HIGH);
  }
  
  void turnLayerOff(int layer){
    digitalWrite(layer, LOW);
  }
/* END GROUND_INO */
