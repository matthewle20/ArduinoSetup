const int flexPin0 = A0; // pin connected to voltage divider output
const int flexPin1 = A1; // pin connected to voltage divider output
const int flexPin2 = A2; // pin connected to voltage divider output

// change these constants according to your hardware
const float VCC = 5;			// voltage at Ardunio 5V line
const float R_DIV = 100000.0;	// resistor used to create a voltage divider
const float flatResistance =  30000.0; // resistance when flat
const float bendResistance = 100000.0; // resistance at 90 deg

void setup() {
  Serial.begin(9600);
  pinMode(flexPin0, INPUT);
  pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
}

void loop() {
  // read the ADC and calculate voltage and resistance from it
  int ADC_0 = analogRead(flexPin0);
  float V_0 = ADC_0 * VCC / 1023.0;
  float R_0 = R_DIV * (VCC / V_0 - 1.0);
  //Serial.println("Resistance 0: " + String(R_0) + " ohms");

  // read the ADC and calculate voltage and resistance from it
  int ADC_1 = analogRead(flexPin1);
  float V_1 = ADC_1 * VCC / 1023.0;
  float R_1 = R_DIV * (VCC / V_1 - 1.0);
  //Serial.println("Resistance 1: " + String(R_1) + " ohms");

  // read the ADC and calculate voltage and resistance from it
  int ADC_2 = analogRead(flexPin2);
  float V_2 = ADC_2 * VCC / 1023.0;
  float R_2 = R_DIV * (VCC / V_2 - 1.0);
  //Serial.println("Resistance 2: " + String(R_2) + " ohms");

  // use the calculated resistance to estimate the sensor's bend angle
  float angle0 = map(R_0, flatResistance, bendResistance, 0, 90.0);
  float angle1 = map(R_1, flatResistance, bendResistance, 0, 90.0);
  float angle2 = map(R_2, flatResistance, bendResistance, 0, 90.0);
  Serial.println("Bend 0: " + String(angle0) + " degrees");
  Serial.println("Bend 1: " + String(angle1) + " degrees");
  Serial.println("Bend 2: " + String(angle2) + " degrees");
  Serial.println("Avg Bend: " + String((angle0+angle1+angle2)/3) + " degrees");  
  Serial.println();

  delay(1000);
}
