int touch1 = 3;
int touch2 = 5;
int touch3 = 9;
int touch4 = 4;

int led1 = 12;
int led2 = 2;
int led3 = 7;
int led4 = 8;

int cerradura1;
int cerradura2;
int cerradura3;
int cerradura4;

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

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  randomSeed(analogRead(A0));

  secuencia[0] = random(1, 5);
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
      nivel = 1;
      secuencia[0] = random(1, 5);
      delay(1000);
      return;
    }
  }

  Serial.println("Correcto");
  delay(1000);

  nivel++;

  if (nivel > 100) {
    nivel = 1;
  }

  secuencia[nivel - 1] = random(1, 5);
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
}

void apagarLeds() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

int esperarSensor() {
  while (true) {
    cerradura1 = digitalRead(touch1);
    cerradura2 = digitalRead(touch2);
    cerradura3 = digitalRead(touch3);
    cerradura4 = digitalRead(touch4);

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
  }
}
