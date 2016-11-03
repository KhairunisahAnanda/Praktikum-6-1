boolean dataLed = 0;
unsigned int overflowCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 34286;
  TCCR1B |= (1<< CS12);
  TIMSK1 |= (1<< TOIE1);
  sei();
}
ISR(TIMER1_OVF_vect) {
  TCNT1 = 34286;
  if(dataLed == 0) {
    dataLed = 1;
  }
  else {
    dataLed = 0;
  }
  digitalWrite(12, dataLed);
  overflowCount++;
}

void loop() {
  Serial.print("Overflow count = ");
  Serial.println(overflowCount, DEC);
  delay(100);
}
