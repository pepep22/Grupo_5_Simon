#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 10, 11, 12, 13);
int touch=5;
int cerradura;
void setup() {
    Serial.begin(9600);
  pinMode (touch,INPUT);
}

void LCD() {
  lcd.begin(16, 2);
  lcd.print("hola");
}

void loop() {
  cerradura=digitalRead (touch);
  if (cerradura==HIGH){
    LCD();
  }
}