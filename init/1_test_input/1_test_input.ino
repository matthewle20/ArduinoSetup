int input1Digit3 = 3;	// first binary number's 3rd digit (4's place)
int input1Digit2 = 4;	// first binary number's 2nd digit (2's place)
int input1Digit1 = 5;	// first binary number's 1st digit (1's place)

int input2Digit3 = 6;	// second binary number's 3rd digit (4's place)
int input2Digit2 = 7;	// second binary number's 2nd digit (2's place)
int input2Digit1 = 8;	// second binary number's 1st digit (1's place)

int outputDigit4 = 9;  // third binary number's 4th digit (8's place)
int outputDigit3 = 10; // third binary number's 3rd digit (4's place)
int outputDigit2 = 11; // third binary number's 2nd digit (2's place)
int outputDigit1 = 12; // third binary number's 1st digit (1's place)

int accumulator;

void setup() {
	pinMode(input1Digit3, INPUT);
	pinMode(input1Digit2, INPUT);
	pinMode(input1Digit1, INPUT);
  
	pinMode(input2Digit3, INPUT);
	pinMode(input2Digit2, INPUT);
	pinMode(input2Digit1, INPUT);
  
	pinMode(outputDigit4, OUTPUT);
	pinMode(outputDigit3, OUTPUT);
	pinMode(outputDigit2, OUTPUT);
	pinMode(outputDigit1, OUTPUT);
}

void loop() {
  accumulator = 0;

	if(digitalRead(input1Digit3) == HIGH)
	{	
		accumulator += 4;
	}
	delay(100);

	if(digitalRead(input1Digit2) == HIGH)
	{
		accumulator += 2;
	}
	delay(100);

	if(digitalRead(input1Digit1) == HIGH)
	{
		accumulator += 1;
	}
	delay(100);

	if(digitalRead(input2Digit3) == HIGH)
	{
		accumulator += 4;
	}
	delay(100);

	if(digitalRead(input2Digit2) == HIGH)
	{
		accumulator += 2;
	}
	delay(100);

	if(digitalRead(input2Digit1) == HIGH)
	{
		accumulator += 1;
	}
	delay(100);

	if(accumulator%2 == 1)
	{
		digitalWrite(outputDigit1, HIGH);
	}
	else
	{
		digitalWrite(outputDigit1, LOW);
	}

	if((accumulator/2)%2 == 1)
	{
		digitalWrite(outputDigit2, HIGH);
	}
	else
	{
		digitalWrite(outputDigit2, LOW);
	}

	if((accumulator/4)%2 == 1)
	{
		digitalWrite(outputDigit3, HIGH);
	}
	else
	{
		digitalWrite(outputDigit3, LOW);
	}

	if((accumulator/8)%2 == 1)
	{
		digitalWrite(outputDigit4, HIGH);
	}
	else
	{
		digitalWrite(outputDigit4, LOW);
	}
	delay(100);
}
