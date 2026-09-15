int BUZZ = 8;

void setup() {
  pinMode(BUZZ, OUTPUT);
  
  melody();
}

void loop() {
}

void melody() {
  tone(BUZZ, 584, 150);
  delay(150);
  tone(BUZZ, 459, 150);
  delay(150);
  tone(BUZZ, 323, 150);
  delay(250);
  
  noTone(BUZZ);
}