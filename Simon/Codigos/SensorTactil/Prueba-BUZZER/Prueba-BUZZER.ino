int touch=3;
int BUZZ=12;
int cerradura;
void setup() {
    Serial.begin(9600);
  pinMode (touch,INPUT);
  pinMode(BUZZ, OUTPUT);
  
  melody();
}

void loop() {
    cerradura=digitalRead (touch);
  if (cerradura==HIGH){
    digitalWrite (BUZZ, HIGH);
    Serial.println ("Prediendo");
      melody();
    digitalWrite(BUZZ, LOW);

  }
}

void melody() {
  tone(BUZZ, 523, 150);
  delay(300);
  tone(BUZZ, 659, 150);
  delay(300);
  tone(BUZZ, 784, 150);
  delay(300);
  tone(BUZZ, 1046, 300);
  delay(500);
  
  noTone(BUZZ);
}