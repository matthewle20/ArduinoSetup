// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // turn off the blinking cursor
  lcd.print("blinking cursor");
  lcd.setCursor(0, 1);
  lcd.print("off");
  lcd.noBlink();
  delay(3000);
  lcd.clear();

  // turn on the blinking cursor
  lcd.print("blinking cursor");
  lcd.setCursor(0, 1);
  lcd.print("on");
  lcd.blink();
  delay(3000);
  lcd.clear();
  
  // turn off the cursor
  lcd.print("underscore");
  lcd.setCursor(0, 1);
  lcd.print("cursor off");
  lcd.noCursor();
  delay(3000);
  lcd.clear();

  // turn on the cursor
  lcd.print("underscore");
  lcd.setCursor(0, 1);
  lcd.print("cursor on");
  lcd.cursor();
  delay(3000);
  lcd.clear();

  // move cursor
  lcd.setCursor(3, 0);
  lcd.print("set cursor");
  delay(1500);    
  lcd.setCursor(0, 0); // top left
  lcd.print("X"); 
  delay(1500);  
  lcd.setCursor(15, 0); // top right
  lcd.print("X"); 
  delay(1500);
  lcd.setCursor(0, 1); // bottom left
  lcd.print("X"); 
  delay(1500);
  lcd.setCursor(15, 1); // bottom right
  lcd.print("X"); 
  delay(1500);
  lcd.clear();
}