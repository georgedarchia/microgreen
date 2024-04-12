// Define relay pins
const int relayLED = 2;   // Pin 2
const int relaySmoke = 4; // Pin 4

unsigned long previousMillisLED = 0;    // Stores the previous time LED relay was updated
unsigned long previousMillisSmoke = 0;  // Stores the previous time Smoke relay was updated

const long ledIntervalOn = 18 * 3600000L;        // Interval for LED relay to be ON (in milliseconds)
const long ledIntervalOff = 6 * 3600000L;       // Interval for LED relay to be OFF (in milliseconds)

const long smokeIntervalOn = 1 * 60000L;     // Interval for Smoke relay to be ON (in milliseconds)
const long smokeIntervalOff = 0.5 * 60000L;     // Interval for Smoke relay to be OFF (in milliseconds)

bool ledState = LOW;    // Tracks the state of LED relay
bool smokeState = LOW;  // Tracks the state of Smoke relay

void setup() {
  // Initialize relay pins as outputs
  pinMode(relayLED, OUTPUT);
  pinMode(relaySmoke, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();  // Get the current time
  
  // Toggle LED relay
  if (currentMillis - previousMillisLED >= (ledState ? ledIntervalOff : ledIntervalOn)) {
    ledState = !ledState;
    digitalWrite(relayLED, ledState);
    previousMillisLED = currentMillis;
  }

  // Toggle Smoke relay
  if (currentMillis - previousMillisSmoke >= (smokeState ? smokeIntervalOff : smokeIntervalOn)) {
    smokeState = !smokeState;
    digitalWrite(relaySmoke, smokeState);
    previousMillisSmoke = currentMillis;
  }
}
