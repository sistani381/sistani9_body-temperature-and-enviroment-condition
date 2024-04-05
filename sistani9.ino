#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  float temp = analogRead(A0);//read analog volt from sensor and save to variable temp
  float temp1 = temp * 0.48828125;//convert the analog volt to its temperature equivalent
  lcd.setCursor(0, 0);//set the cursor to column 0,line 1
  lcd.print("temp=");//write "temp=" on the lcd
  lcd.print(temp1);// write the value of temp1 on the lcd
  lcd.print("*C");//write "*c" on the lcd
  if (temp1 > 28) {
    digitalWrite(1, HIGH);
    digitalWrite(0, LOW);
    lcd.setCursor(0, 1);
    lcd.print("warm");
  }
  else {
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    lcd.setCursor(0, 1);
    lcd.print("cold");
  }
  delay(1000);
  lcd.clear();
}
