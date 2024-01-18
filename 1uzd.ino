void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}
void loop() {
int digitalVal = digitalRead(3); 

  if(HIGH == digitalVal)
  {
    digitalWrite(2,LOW);
  }
  else
  {
    digitalWrite(2,HIGH);
  }
}
