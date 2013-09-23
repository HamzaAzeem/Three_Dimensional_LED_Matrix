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
  
  letteri(1);
}


void letteri(int wait){
  //enable all the LEDs on the front top layer
  //top of of the letter 'I'
  for (int x=1; x<5; x++) {
    light(1, 1, x, wait); 
  }
  //enable the LEDs for the center of the Letter 'I'
  for (int x=2; x<4; x++){
    for (int y=2; y<4; y++) {
      light(x, 1, y, wait);
    }
  }
  //enable all the LEDs on the front bottom layer
  //bottom of the letter 'I'
  for (int x=1; x<5; x++) {
    light(4, 1, x, wait); 
  }
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
