const int led1 = 2;
const int led2 = 3;
const int led3 = 4;

unsigned long prev1 = 0;
unsigned long prev2 = 0;
unsigned long prev3 = 0;

bool state1 = LOW;
bool state2 = LOW;
bool state3 = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  unsigned long current = millis();

  if (current - prev1 >= 500) {
    prev1 = current;
    state1 = !state1;
    digitalWrite(led1, state1);
  }

  if (current - prev2 >= 1000) {
    prev2 = current;
    state2 = !state2;
    digitalWrite(led2, state2);
  }

  if (current - prev3 >= 1500) {
    prev3 = current;
    state3 = !state3;
    digitalWrite(led3, state3);
  }
}