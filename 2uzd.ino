int pirPin = 4; 
int buttonOnPin = 3; 
int buttonOffPin = 2; 
int speakerPin = 5; 
int alarmState = 0; 
int lastButtonOnState = LOW;
int lastButtonOffState = LOW;
int on = 0;
int melody[] = {262, 294, 330}; 
int noteDurations[] = {4, 4, 4, 4, 4, 4, 4, 4}; 

void setup() {
  pinMode(13, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(buttonOnPin, INPUT);
  pinMode(buttonOffPin, INPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  int pirValue = digitalRead(pirPin);
  int buttonOnState = digitalRead(buttonOnPin);
  int buttonOffState = digitalRead(buttonOffPin);

  if (buttonOnState == HIGH) {    
    playMelody();
  }

  //Signalizacija
  if (buttonOffState == HIGH) {
    if (on == 1){
    on = 0;
    pirValue = LOW;
    delay(300);
    }
    else {
      pirValue = LOW;
          on = 1;
          delay(300);
    }
  }
     if (on == 1){
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    }
    else {
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    }

  if (pirValue == HIGH && on == 1) {
       alarmState = 1;
       if (on == 1){
        playMelody();
       }      
  }
  //Signalizacija baigta   

}

void playMelody() {
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int noteDuration = 200 / noteDurations[i];
    tone(speakerPin, melody[i], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(speakerPin);
  }
}