int touch=3;
int led=12;
int cerradura;
void setup() {
  Serial.begin(9600);
  pinMode (touch,INPUT);
  pinMode (led, OUTPUT);
}

void loop() {
  cerradura=digitalRead (touch);
  if (cerradura==HIGH){
    digitalWrite (led, HIGH);
    Serial.println ("Prediendo");
    digitalWrite(led, LOW);

  }

}
