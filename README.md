# MARS-Recruitment
THE FILES,CODE AND OVERVIEW FOR MARS Recruitment
Question 1
This circuit controls three LEDs such that each LED blinks at a different time interval:
•	LED1 → 500 ms 
•	LED2 → 1000 ms 
•	LED3 → 1500 ms 
All LEDs blink simultaneously but independently, without affecting each other’s timing.
To achieve independent blinking, I avoided using delay() and instead used the millis() function. This allows multiple operations to run at the same time without blocking the program.
Components Used
•	Arduino Uno → main controller 
•	3 LEDs → output indicators 
•	3 × 220Ω Resistors → current limiting 
•	Breadboard & jumper wires
Working Principle
Each LED has its own timer ;The program continuously checks the current time using millis() ;When the required interval is reached, the LED toggles its state 
Since no delay is used, all LEDs operate independently
Code Breakdown 
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
Assigns each LED to a different digital pin
unsigned long prev1 = 0;
unsigned long prev2 = 0;
unsigned long prev3 = 0;
Stores the last time each LED changed state
bool state1 = LOW;
bool state2 = LOW;
bool state3 = LOW;
Keeps track of whether each LED is ON or OFF
pinMode(led1, OUTPUT);
unsigned long current = millis();
Gets the current running time of the program
if (current - prev1 >= 500)
checks if  500 ms passed since last change for led 1
key difference when millis is used is that the second and third led can blink simultaneously along with first instead o waiting for the first led to finish and so on.
what millis does is that it just measures the time from the start of the program
Challenges Faced
•	Avoiding delay-based blocking 
•	Managing multiple timers simultaneously 
•	Ensuring LEDs blink independently 
•	and forgot to add resisttors which destroyed the circuit
Solution:
•	Used separate time variables for each LED 
•	Used millis() for non-blocking execution 
•	Maintained independent states for each LED
•	Add 220 ohm resistors
 
 
Question 2
This circuit uses a potentiometer to control two outputs simultaneously:
•	The color of an RGB LED 
•	The blinking speed of a normal LED 
As the potentiometer is turned, the RGB LED smoothly changes color, and the blinking speed of the LED varies accordingly.
Components Used
•	Arduino Uno → main controller 
•	Potentiometer → analog input device 
•	RGB LED → color output 
•	LED → blinking output 
•	220Ω Resistors → current limiting 
•	Breadboard & jumper wires
Working Principle
•	The potentiometer provides an analog value 
•	This value is mapped to: 
o	RGB color values (0–255) 
o	Blink interval (100–1000 ms) 
•	The RGB LED changes color based on PWM signals 
•	The LED blinks at a speed depending on the potentiometer position
Code- Breakdown
int potPin = A0;
int ledPin = 5;

int r = 9;
int g = 10;
int b = 11;
Potentiometer → analog input 
LED → blinking output 
RGB pins → color control
int potValue = analogRead(potPin);
•	Reads value between 0 and 1023 
•	Depends on knob position 
int red = map(potValue, 0, 1023, 0, 255);
int green = map(potValue, 0, 1023, 255, 0);
int blue = 128;
•	Converts analog input → PWM range (0–255) 
•	Red increases as potentiometer increases 
•	Green decreases → creates color transition 
•	Blue fixed → gives mixed shades 
analogWrite(r, red);
analogWrite(g, green);
analogWrite(b, blue);
 Uses PWM to control brightness of each color 
Combined output → visible color change
int interval = map(potValue, 0, 1023, 100, 1000);
Converts potentiometer value into time interval 
Lower value → faster blinking 
Higher value → slower blinking
if (millis() - prevTime >= interval)
Checks if enough time has passed 
No delay used → system remains responsive
ledState = !ledState;
digitalWrite(ledPin, ledState);
Switches LED ON/OFF 
Creates blinking effect

Challenges Faced
•	Mapping analog values correctly to output ranges 
•	Achieving smooth color transitions 
•	Controlling LED blinking without blocking code 
 Solution:
•	Used map() function for scaling values 
•	Used analogWrite() for PWM control 
•	Used millis() for non-blocking timing 
 
 

Question 3
This project measures a user’s reaction time using a non-blocking approach. An LED turns ON after a random delay, and the user must press a pushbutton as quickly as possible. The reaction time is calculated and displayed on the Serial Monitor.
Components Used
•	Arduino Uno → main controller 
•	LED → visual indicator 
•	Pushbutton → user input 
•	220Ω Resistor → protects LED 
•	Breadboard & jumper wires 
Working Principle
•	The system starts and waits for a random delay (2–5 seconds) using millis() 
•	After the delay, the LED turns ON 
•	The user presses the button as fast as possible 
•	The Arduino calculates the time difference between LED ON and button press 
•	Reaction time is displayed in milliseconds 
•	System resets automatically for the next attempt
Code-Breakdown 
unsigned long startTime;
unsigned long waitStart;
unsigned long waitDuration;
waitStart → when waiting begins 
waitDuration → random delay time 
startTime → when LED turns ON
bool waiting = true;
bool ledOn = false;
waiting → system is in delay phase 
ledOn → LED is active, waiting for user input
waitStart = millis();
waitDuration = random(2000, 5000);
Initializes timing 
Generates random delay (2–5 seconds)
unsigned long current = millis();
Keeps track of current time continuously
if (waiting && (current - waitStart >= waitDuration))
If YES: 
o	LED turns ON 
o	Reaction timer starts 
o	Switch to next phase 
if (ledOn && digitalRead(button) == LOW)
Detects button press 
LOW because of INPUT_PULLUP
unsigned long reaction = current - startTime;
Measures time difference
waitStart = current;
waitDuration = random(2000, 5000);
waiting = true;
Starts new cycle without stopping program
Reaction Time = T₂ − T₁
T₁ = time when LED turns ON (startTime) 
T₂ = time when button is pressed (current)
5. Challenges Faced
•	Avoiding blocking delays while maintaining timing accuracy 
•	Managing multiple states (waiting, active, reset) 
•	Ensuring proper button input handling 
Solution:
•	Used millis() for non-blocking timing 
•	Implemented state control using boolean variables 
•	Used INPUT_PULLUP to stabilize button input
 
 
Project(Section B)
Smart Distance Alert System
This project measures the distance between an object and the sensor using an ultrasonic sensor. When an object comes closer than a set threshold (20 cm), the system alerts the user using an LED and a buzzer.
Why I chose this project
I chose this project because distance sensing is an essential feature in robotics, especially for obstacle detection in rovers. This system demonstrates a simple real-world application where a rover can detect nearby objects and respond accordingly.
Components Used
•	Arduino Uno → controls the entire system 
•	Ultrasonic Sensor (HC-SR04) → measures distance 
•	LED → visual alert 
•	Buzzer → sound alert 
•	Resistor (220Ω) → protects LED 
•	Jumper wires & breadboard → connections
Working Principle
The ultrasonic sensor sends out a sound wave and waits for it to reflect back from an object. By measuring the time taken for the echo to return, the distance is calculated.
If the object is too close:
•	LED turns ON 
•	Buzzer produces sound 
If the object is far:
•	LED turns OFF 
•	Buzzer stops 
Code-Breakdown
int trig = 9;
int echo = 10;
int buzzer = 6;
int led = 5;
Trig → sends ultrasonic pulse 
Echo → receives reflected signal 
LED & buzzer → output alerts
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
Defines direction of pins 
Starts Serial Monitor for output
digitalWrite(trig, LOW);
delayMicroseconds(2);

digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
This sends a 10µs pulse
That pulse = “send sound wave now”
duration = pulseIn(echo, HIGH);
Waits until echo pin goes HIGH 
Measures how long it stays HIGH 
This time = travel time of sound wave
distance = duration * 0.034 / 2;
Sound speed ≈ 0.034 cm/µs 
Divide by 2 → because wave goes to object and back
Serial.print("Distance: ");
Serial.println(distance);
Shows real-time distance in Serial Monitor
Challenges Faced
•	Incorrect distance readings due to improper timing 
•	Wiring mistakes (especially Echo and Trig pins) 
•	Handling noise in sensor output 
 Solution:
•	Used proper trigger pulse timing 
•	Verified connections carefully 
•	Added a small delay for stable reading



 
 
