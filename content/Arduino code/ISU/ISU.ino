int sensorPin=A4;
int sensorValue=0;
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
  int row = 0, col = 0, layer = 0;
  //obtain sensor value from photocell
  sensorValue = analogRead(sensorPin);
  //assign restrictions for which layer, rows, and columns to light up based on sensor value 
  if (sensorValue <= 200) {
    layer = 4;
    row = 4;
    col = 4;
  } else if(sensorValue <= 400) {
    layer = 3;
    row = 3;
    col = 3;
  } else if(sensorValue <= 600) {
    layer = 2;
    row = 2;
    col = 2;
  } else {
    layer = 1;
    row = 1;
    col = 1;
  }
  //turn on LEDs based on restrictions
  for (int x = 1; x < row+1; x++){
    for (int y = 1; y < col+1; y++){
      digitalWrite(x+1, LOW);
      digitalWrite(10-y, HIGH);
      digitalWrite(layer+13, LOW);
    }
  }
  //turn off all LEDs
  low();
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
