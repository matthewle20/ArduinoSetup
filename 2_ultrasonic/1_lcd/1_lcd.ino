// include the library code
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define echoPin 2 // attach pin D12 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D13 Arduino to pin Trig of HC-SR04

long duration; // variable for the duration of sound wave travel
int distance_cm; // variable for centimeters measurement
int distance_inch; // variable for inches measurement

void setup() {
  // set the echoPin as INPUT, trigPin as OUTPUT
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  
  // initialize the serial communications  
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor HC-SR04");
  Serial.println("with Arduino UNO R3");
  
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
}

void loop() {
  // clear the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // set the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // calculate distance
  distance_cm = duration * 0.034 / 2; // speed of sound wave divided by 2 (go and back)
  distance_inch = duration * 0.0133 / 2; // speed of sound wave divided by 2 (go and back)
  
  // display distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  Serial.print("Distance: ");
  Serial.print(distance_inch);
  Serial.println(" in");
  Serial.println();

  // display distance to LCD
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance_cm);
  lcd.setCursor(14, 0);  
  lcd.print("cm");
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distance_inch);
  lcd.setCursor(14, 1);
  lcd.print("in");
  
  delay(1000);
  lcd.clear();
}