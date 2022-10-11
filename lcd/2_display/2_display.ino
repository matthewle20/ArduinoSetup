// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// make some custom characters
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

void setup() {
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(0, heart);
  // create a new character
  lcd.createChar(1, smiley);
}

void loop() {
  // print a message to the LCD with custom character
  lcd.setCursor(0, 0);
  lcd.print("I ");
  lcd.write(byte(0)); // when calling lcd.write() '0' must be cast as a byte
  lcd.print(" Arduino! ");
  lcd.setCursor(0, 1);  
  lcd.write((byte)1);  
  delay(3000);
  lcd.clear();

  // turn off the display
  lcd.print("turning off");
  lcd.setCursor(0, 1);
  lcd.print("display in ...");
  for (int i = 3; i >= 0; i--) {
    lcd.setCursor(15, 1);
    lcd.print(i);
    delay(1500);
  }
  lcd.noDisplay();
  delay(3000);
  
  // turn on the display
  lcd.clear();
  lcd.display();

  // autoscroll
  lcd.setCursor(0, 0);
  lcd.print("autoscroll");
  delay(3000);
  // set the cursor
  lcd.setCursor(16, 1);
  // set the display to automatically scroll:
  lcd.autoscroll();
  // print from 0 to 9:
  for (int thisChar = 0; thisChar <= 9; thisChar++) {
    lcd.print(thisChar);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();
  lcd.clear();

  // scrolling direction
  lcd.setCursor(0, 0);
  lcd.print("hello world!");
  delay(1000);  
  // scroll 16 positions (string length (16)) to the right
  // to move it offscreen right
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position right
    lcd.scrollDisplayRight();
    delay(500);
  }
  // scroll 28 positions (string length (12) + display length (16)) to the left
  // to move it offscreen left
  for (int positionCounter = 0; positionCounter < 28; positionCounter++) {
    // scroll one position left
    lcd.scrollDisplayLeft();
    delay(500);
  }
  // scroll 12 positions (string length (12)) to the right
  // to move it back to center
  for (int positionCounter = 0; positionCounter < 12; positionCounter++) {
    // scroll one position right
    lcd.scrollDisplayRight();
    delay(500);
  }  
  // delay at the end of the full loop
  delay(1000);
  lcd.clear();
}