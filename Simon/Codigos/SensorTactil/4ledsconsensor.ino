int touch1=3;
int touch2=5;
int touch3=9;
int touch4=4;
int led1=12;
int led2=2;
int led3=7;
int led4=8;
int cerradura1;
int cerradura2;
int cerradura3;
int cerradura4;
void setup() {
  Serial.begin(9600);
  pinMode (touch1,INPUT);
  pinMode (led1, OUTPUT);
  pinMode (touch2,INPUT);
  pinMode (led2, OUTPUT);
  pinMode (touch3,INPUT);
  pinMode (led3, OUTPUT);
  pinMode (touch4,INPUT);
  pinMode (led4, OUTPUT);
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
    cerradura3=digitalRead (touch3);
  if (cerradura3==HIGH){
    digitalWrite (led3, HIGH);
    Serial.println ("Prendiendo");
    digitalWrite(led3, LOW);
  }
  cerradura4=digitalRead (touch4);
  if (cerradura4==HIGH){
    digitalWrite (led4, HIGH);
    Serial.println ("Prendiendo");
    digitalWrite(led4, LOW);
  }
}