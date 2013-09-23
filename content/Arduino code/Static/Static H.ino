void setup() {
  //set digital pin 2-9 to be outputs
  for (int i=2; i<10; i++) {
    pinMode(i, OUTPUT);
  }
  //set analog pin A0 - A3 to be outputs
  for (int i=14; i<18; i++) {
    pinMode(i, OUTPUT);
  }
}
void loop(){
  
  letterh(1); //multiplex code
  letterh2(1); //non-multiplex code
}

void letterh2(int wait){
  //non-multiplex code for Letter 'I'
  
  //enable layer 1 and 4
  digitalWrite(14, LOW);
  digitalWrite(17, LOW);
  
  //enable all rows (negative)
  for(int x=2;x<6;x++){
    digitalWrite(x,LOW);
    x++;
    x++;
  }

  //enable column 1 and 4 (positive)
  digitalWrite(6, HIGH);
  digitalWrite(9, HIGH);
  delay(wait);
  //disable all LEDs
  low();
  
  //enable layer 2 and 3
  digitalWrite(15,LOW);
  digitalWrite(16,LOW);
  //enable all rows
  for (int i=2; i<6; i++) {
    digitalWrite(i, LOW);
    i++;
    i++;
  }
  //enable all columns
  for (int i=6; i<10; i++) {
    digitalWrite(i, HIGH);
  }
  delay(wait);
  low();
  
}
void letterh(int wait){
  //multiplex code for letter 'H'
  //enable all the LEDs for the front left column
  for (int a=1; a<5; a++){
    light(a, 1, 1, wait);
  }
  //enable all LEDs for the front right column
  for (int a=1; a<5; a++){
    light(a, 1, 4, wait);
  }
  //enable the front LEDs of layers 2 and 3 for the center of the 'H'
  light(3, 1, 2, wait);
  light(3, 1, 3, wait);
  light(2, 1, 2, wait);
  light(2, 1, 3, wait);
}

void light(int layer, int row, int col, int wait){
  low(); //default reset all outputs
  row++; //set the row number to match pin number
  col=10-col; //set the column number to match pin number
  layer = layer + 13; //set the layer number to match pin number
  digitalWrite(layer, LOW); //enable designated 74LS245
  digitalWrite(row, LOW); //send LOW voltage to coresponding negative row
  digitalWrite(col, HIGH); //send HIGH voltage to coresponding positive column
  delay(wait);
}
void low(){
  //disable all 74LS245 by providing the Enablers a HIGH voltage
  for (int i=14; i<18; i++) {
    digitalWrite(i, HIGH);
  }
  //disable negative rows by providing the pins a HIGH voltage
  for (int i=2; i<6; i++) {
    digitalWrite(i, HIGH);
  }
  //disable positive columns by providing the pins a LOW voltage
  for (int i=6; i<10; i++) {
    digitalWrite(i, LOW);
  }

}
