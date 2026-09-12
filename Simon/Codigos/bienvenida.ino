#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 10, 11, 12, 13);

void setup() {
  lcd.begin(16, 2);

  lcd.print("hola");
}

void loop() {
}
