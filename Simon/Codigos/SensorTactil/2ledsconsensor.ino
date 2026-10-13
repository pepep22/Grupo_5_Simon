int touch1=3;
int touch2=5;
int led1=12;
int led2=2;
int cerradura1;
int cerradura2;
void setup() {
  Serial.begin(9600);
  pinMode (touch1,INPUT);
  pinMode (led1, OUTPUT);
  pinMode (touch2,INPUT);
  pinMode (led2, OUTPUT);
}

void loop() {
  cerradura1=digitalRead (touch1);
  if (cerradura1==HIGH){
    digitalWrite (led1, HIGH);
    Serial.println ("Prendiendo");
    digitalWrite(led1, LOW);
  }
    cerradura2=digitalRead (touch2);
  if (cerradura2==HIGH){
    digitalWrite (led2, HIGH);
    Serial.println ("Prendiendo");
    digitalWrite(led2, LOW);
  }
}