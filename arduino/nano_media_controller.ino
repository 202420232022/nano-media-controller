// Arduino Nano main sketch

const int PlayPin = 2; // Pin for Play/Pause button
const int VolUPin = 3; // Pin for Volume Up button
const int VolDPin = 4; // Pin for Volume Down button
const int NextPin = 5; // Pin for Next Track button
bool PlayState = HIGH;
unsigned long lastTime = 0;
const unsigned long debounceMs = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(PlayPin, INPUT_PULLUP);
  pinMode(VolUPin, INPUT_PULLUP);
  pinMode(VolDPin, INPUT_PULLUP);
  pinMode(NextPin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Arduino ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  bool currentState = digitalRead(PlayPin);
  unsigned long now = millis();

  if (PlayState == HIGH && currentState == LOW) {
    if (now - lastTime > debounceMs) {
      Serial.println("PLAY");
      lastTime = now;
    }
  }
  
  PlayState = currentState;
}
