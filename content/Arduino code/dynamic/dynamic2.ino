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

  dynamic2(100);
}

void dynamic2(int wait){
  //cycle through top 2 layers
  for(int l=4; l>2;l--){
    //light up LEDs on the border in sequence clockwise
    for(int x=1; x<5; x++){
      for(int y=1; y<5; y++){
        light(l, x, y, wait);
      }
      x++;
      light(l,x,4,wait);
      x++;
      light(l,x,4,wait);
      x++;
      for(int y=4; y>0; y--){
        light(l, x, y, wait);
      }
    }
    light(l,3,1,wait);
    light(l,2,1,wait);
  }
  //light up bottom 2 layers
  //inner LEDs turn on in clockwise sequence
  for(int l=2;l>0;l--){
    light(l,2,2,wait);
    light(l,2,3,wait);
    light(l,3,3,wait);
    light(l,3,2,wait);
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
  //disable negative rows by providing the pins a HIGH voltage
  for (int i=2; i<6; i++) {
    digitalWrite(i, HIGH);
  }
  //disable positive columns by providing the pins a LOW voltage
  for (int i=6; i<10; i++) {
    digitalWrite(i, LOW);
  }
  //disable all 74LS245 by providing the Enablers a HIGH voltage
  for (int i=14; i<18; i++) {
    digitalWrite(i, HIGH);
  }
}
