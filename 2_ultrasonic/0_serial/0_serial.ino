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
  
  delay(1000);
}