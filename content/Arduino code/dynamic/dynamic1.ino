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
  dynamic1(100);
}
void dynamic1(int wait){
  //snake through each layer
  for(int l=1;l<5;l++){
    //run through each layer
    for(int x=1;x<5;x++){
      //cycle through all the rows
      for(int y=4;y>0;y--){
        light(l, x, y, wait);
        //Turns on each LED in corresponding row in order
      }
      //goes to next row
      x++;
      //turns on each LED in reverse order than previously
      for(int y=1;y<5;y++){
        light(l, x, y, wait);
      }
    }
    //go up a layer
    l++;
    //cycle through all rows reverse order from previous
    for(int x=4;x>0;x--){
      //cycle through LEDs  turning them on in corresponding row
      for(int y=4;y>0;y--){
        light(l, x, y, wait);
      }
      //goes to next row
      x--;
      //cycle through LEDs in reverse order turning them on in corresponding row
      for(int y=1;y<5;y++){
        light(l, x, y, wait);
      }
    }
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
