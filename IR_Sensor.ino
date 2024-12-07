int sensor = 9;

void setup(){
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop(){
  if (digitalRead(sensor)==HIGH){
    Serial.println("1");
  }
  else{
    Serial.println("0");
  }
  delay(1000);
}