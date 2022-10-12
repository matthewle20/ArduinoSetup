const int flexPin = A0; // pin connected to voltage divider output

// change these constants according to your hardware
const float VCC = 5;			// voltage at Ardunio 5V line
const float R_DIV = 100000.0;	// resistor used to create a voltage divider
const float flatResistance =  30000.0;	// resistance when flat
const float bendResistance = 100000.0;	// resistance at 90 deg

void setup() {
  Serial.begin(9600);
  pinMode(flexPin, INPUT);
}

void loop() {
  // read the ADC and calculate voltage and resistance from it
  int ADC_flex = analogRead(flexPin);
  float V_flex = ADC_flex * VCC / 1023.0; // actual voltage
  float R_flex = R_DIV * (VCC / V_flex - 1.0);
  Serial.println("Resistance 0: " + String(R_flex) + " ohms");

  // use the calculated resistance to estimate the sensor's bend angle
  float angle = map(R_flex, flatResistance, bendResistance, 0, 90.0); // maps flatResistance - bendResistance to 0-90
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(1000);
}
