int potPin = A0;
int ledPin = 5;

int r = 9;
int g = 10;
int b = 11;

unsigned long prevTime = 0;
bool ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);

  int red = map(potValue, 0, 1023, 0, 255);
  int green = map(potValue, 0, 1023, 255, 0);
  int blue = 128;

  analogWrite(r, red);
  analogWrite(g, green);
  analogWrite(b, blue);

  int interval = map(potValue, 0, 1023, 100, 1000);

  if (millis() - prevTime >= interval) {
    prevTime = millis();
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}