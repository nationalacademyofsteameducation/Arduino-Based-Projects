// Pin Definitions
const int moisturePin = A0;   // Soil moisture sensor analog pin
const int relayPin = 7;       // Relay control pin

int moistureValue = 0;        // Variable to store moisture value
int threshold = 500;          // Adjust this value based on your soil condition

void setup() {
  Serial.begin(9600);        // Start serial communication
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Relay OFF initially (Active LOW relay)
}

void loop() {
  moistureValue = analogRead(moisturePin); // Read sensor value

  Serial.print("Moisture Level: ");
  Serial.println(moistureValue);

  // Condition: Dry Soil → Turn ON Pump
  if (moistureValue > threshold) {
    digitalWrite(relayPin, LOW);  // Relay ON (Pump ON)
    Serial.println("Soil is Dry → Pump ON");
  } 
  // Condition: Wet Soil → Turn OFF Pump
  else {
    digitalWrite(relayPin, HIGH); // Relay OFF (Pump OFF)
    Serial.println("Soil is Wet → Pump OFF");
  }

  delay(2000); // Wait 2 seconds
}