int BUZZ = 8;

void setup() {
  pinMode(BUZZ, OUTPUT);
  
  melody();
}

void loop() {
}

void melody() {
  tone(BUZZ, 523, 150);
  delay(150);
  tone(BUZZ, 659, 150);
  delay(150);
  tone(BUZZ, 784, 150);
  delay(150);
  tone(BUZZ, 1046, 300);
  delay(250);
  
  noTone(BUZZ);
}