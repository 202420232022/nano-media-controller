// Arduino Nano main sketch

const int PlayPin = 2; // Pin for Play/Pause button
const int VolUPin = 3; // Pin for Volume Up button
const int VolDPin = 4; // Pin for Volume Down button
const int NextPin = 5; // Pin for Next Track button
bool PlayState = HIGH;
bool VolUState = HIGH;
bool VolDState = HIGH;
bool NextState = HIGH;
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
  bool NPlayState = digitalRead(PlayPin);
  bool NVolUState = digitalRead(VolUPin);
  bool NVolDState = digitalRead(VolDPin);
  bool NNextState = digitalRead(NextPin);
  unsigned long now = millis();

  if (PlayState == HIGH && NPlayState == LOW) {
    if (now - lastTime > debounceMs) {
      Serial.println("PLAY");
      lastTime = now;
    }
  }
  
  PlayState = NPlayState;

  if (VolUState == HIGH && NVolUState == LOW) {
    if (now - lastTime > debounceMs) {
      Serial.println("VOL_UP");
      lastTime = now;
    }
  }

  VolUState = NVolUState;

  if (VolDState == HIGH && NVolDState == LOW) {
    if (now - lastTime > debounceMs) {
      Serial.println("VOL_DOWN");
      lastTime = now;
    }
  }

  VolDState = NVolDState;

  if (NextState == HIGH && NNextState == LOW) {
    if (now - lastTime > debounceMs) {
      Serial.println("NEXT");
      lastTime = now;
    }
  }

  NextState = NNextState;
}
