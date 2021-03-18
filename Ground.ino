/* GROUND_INO */
void turnAllLayersOn(){
  /*
  * Function: turnAllLayersOn
  * ----------------------------
  *   Enables all four layers in the cube
  *
  *   returns: none
  */
  digitalWrite(FIRSTGROUND, HIGH);
  digitalWrite(SECONDGROUND, HIGH);
  digitalWrite(THIRDGROUND, HIGH);
  digitalWrite(FOURTHGROUND, HIGH);
}
  
void turnAllLayersOff(){
  /*
  * Function: turnAllLayersOff
  * ----------------------------
  *   Moves Disables all four layers in the cube
  *
  *   returns: none
  */
  digitalWrite(FIRSTGROUND, LOW);
  digitalWrite(SECONDGROUND, LOW);
  digitalWrite(THIRDGROUND, LOW);
  digitalWrite(FOURTHGROUND, LOW);
}
  
void turnLayerOn(int layer){
  /*
  * Function: turnLayerOn
  * ----------------------------
  *   Enables ONE layer in the cube
  *
  *   layer: pin number connected to ground layer (defs such as FRISTGROUND can also be used)
  *   
  *   returns: none
  */
  digitalWrite(layer, HIGH);
}
  
void turnLayerOff(int layer){
  /*
  * Function: turnLayerOff
  * ----------------------------
  *   Disables ONE layer in the cube
  *
  *   layer: pin number connected to ground layer (defs such as FRISTGROUND can also be used)
  *   
  *   returns: none
  */
  digitalWrite(layer, LOW);
}

/* END GROUND_INO */
