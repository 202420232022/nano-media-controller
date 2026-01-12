// Arduino Nano main sketch

const int buttonPin = 2;
bool lastState = HIGH;
unsigned long lastTime = 0;
const unsigned long debounceMs = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Arduino ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  bool currentState = digitalRead(buttonPin);
  unsigned long now = millis();

  if (lastState == HIGH && currentState == LOW) {
    if (now - lastTime > debounceMs) {
      Serial.println("PLAY");
      lastTime = now;
    }
  }
  
  lastState = currentState;
}
