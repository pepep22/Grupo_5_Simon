int touch1 = 3;
int touch2 = 5;
int touch3 = 9;
int touch4 = 4;
int touch5 = 37;
int touch6 = 45;
int touch7 = 32;

int BUZZ = 31;

int led1 = 12;
int led2 = 2;
int led3 = 7;
int led4 = 8;
int led5 = 41;
int led6 = 51;
int led7 = 52;

int cerradura1;
int cerradura2;
int cerradura3;
int cerradura4;
int cerradura5;
int cerradura6;
int cerradura7;

int secuencia[100];
int nivel = 1;
int respuesta;
int i;

void setup() {
  Serial.begin(9600);

  pinMode(touch1, INPUT);
  pinMode(touch2, INPUT);
  pinMode(touch3, INPUT);
  pinMode(touch4, INPUT);
  pinMode(touch5, INPUT);
  pinMode(touch6, INPUT);
  pinMode(touch7, INPUT);
  
  pinMode(BUZZ, OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);

  randomSeed(analogRead(A0));

  secuencia[0] = random(1, 5);
}

void melody1() {
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

void melody2() {
  tone(BUZZ, 584, 150);
  delay(150);
  tone(BUZZ, 459, 150);
  delay(150);
  tone(BUZZ, 323, 150);
  delay(250);
  
  noTone(BUZZ);
}

void loop() {
  for (i = 0; i < nivel; i++) {
    prenderLed(secuencia[i]);
    delay(500);
    apagarLeds();
    delay(300);
  }

  for (i = 0; i < nivel; i++) {
    respuesta = esperarSensor();

    if (respuesta != secuencia[i]) {
      Serial.println("Incorrecto. Volviendo a empezar");
      melody2();
      nivel = 1;
      secuencia[0] = random(1, 7);
      delay(1000);
      return;
    }
  }

  Serial.println("Correcto");
  melody1();
  delay(1000);

  nivel++;

  if (nivel > 100) {
    nivel = 1;
  }

  secuencia[nivel - 1] = random(1, 7);
}

void prenderLed(int numero) {
  if (numero == 1) {
    digitalWrite(led1, HIGH);
  }

  if (numero == 2) {
    digitalWrite(led2, HIGH);
  }

  if (numero == 3) {
    digitalWrite(led3, HIGH);
  }

  if (numero == 4) {
    digitalWrite(led4, HIGH);
  }

  if (numero == 5) {
    digitalWrite(led5, HIGH);
  }

  if (numero == 6) {
    digitalWrite(led6, HIGH);
  }

  if (numero == 7) {
    digitalWrite(led7, HIGH);
  }
}

void apagarLeds() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
}

int esperarSensor() {
  while (true) {
    cerradura1 = digitalRead(touch1);
    cerradura2 = digitalRead(touch2);
    cerradura3 = digitalRead(touch3);
    cerradura4 = digitalRead(touch4);
    cerradura5 = digitalRead(touch5);
    cerradura6 = digitalRead(touch6);
    cerradura7 = digitalRead(touch7);

    if (cerradura1 == HIGH) {
      prenderLed(1);
      delay(300);
      apagarLeds();
      while (digitalRead(touch1) == HIGH) {}
      return 1;
    }

    if (cerradura2 == HIGH) {
      prenderLed(2);
      delay(300);
      apagarLeds();
      while (digitalRead(touch2) == HIGH) {}
      return 2;
    }

    if (cerradura3 == HIGH) {
      prenderLed(3);
      delay(300);
      apagarLeds();
      while (digitalRead(touch3) == HIGH) {}
      return 3;
    }

    if (cerradura4 == HIGH) {
      prenderLed(4);
      delay(300);
      apagarLeds();
      while (digitalRead(touch4) == HIGH) {}
      return 4;
    }

    if (cerradura5 == HIGH) {
      prenderLed(5);
      delay(300);
      apagarLeds();
      while (digitalRead(touch4) == HIGH) {}
      return 5;
    }

    if (cerradura6 == HIGH) {
      prenderLed(6);
      delay(300);
      apagarLeds();
      while (digitalRead(touch4) == HIGH) {}
      return 6;
    }

    if (cerradura7 == HIGH) {
      prenderLed(7);
      delay(300);
      apagarLeds();
      while (digitalRead(touch4) == HIGH) {}
      return 7;
    }
  }
}