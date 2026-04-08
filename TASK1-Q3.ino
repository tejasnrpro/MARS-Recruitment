int led = 6;
int button = 7;

unsigned long startTime;
unsigned long waitStart;
unsigned long waitDuration;

bool waiting = true;
bool ledOn = false;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);

  randomSeed(analogRead(0));

  waitStart = millis();
  waitDuration = random(2000, 5000);
}

void loop() {
  unsigned long current = millis();

  // Phase 1: Waiting for random delay (non-blocking)
  if (waiting && (current - waitStart >= waitDuration)) {
    digitalWrite(led, HIGH);
    startTime = current;
    ledOn = true;
    waiting = false;
  }

  // Phase 2: Waiting for user reaction
  if (ledOn && digitalRead(button) == LOW) {
    unsigned long reaction = current - startTime;

    Serial.print("Reaction Time: ");
    Serial.print(reaction);
    Serial.println(" ms");

    digitalWrite(led, LOW);
    ledOn = false;

    // Reset for next round
    waitStart = current;
    waitDuration = random(2000, 5000);
    waiting = true;
  }
}