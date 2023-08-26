// Define the pins for the LED and the switch
const int ledPin = 13;
const int switchPin = 4;

// Default name to be blinked in Morse code
String defaultName = "vanshaj";

// Morse code mappings
const char* morseCodeTable[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  // ... (mappings for other letters)
};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(switchPin) == LOW) {
    blink(defaultName);
  }
}

void blink(String text) {
  for (int i = 0; i < text.length(); i++) {
    char c = toLowerCase(text.charAt(i));
    if (c == ' ') {
      delay(300);
    } else {
      int index = c - 'a'; // Calculate the index based on ASCII value
      if (index >= 0 && index < sizeof(morseCodeTable) / sizeof(morseCodelist[0])) {
        blink(morseCodelist[index]);
      }
    }
    delay(100);
  }
}

void blink(const char* sequence) {
  for (int i = 0; sequence[i] != '\0'; i++) {
    char dotDash = sequence[i];
    digitalWrite(ledPin, HIGH);
    if (dotDash == '.') {
      delay(200);
    } else if (dotDash == '-') {
      delay(600);
    }
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  delay(200);
}