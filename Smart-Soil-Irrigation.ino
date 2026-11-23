
const int SOIL_SENSOR = A0;
const int RELAY_PIN = 7;

int moistureValue = 0;

// Adjust this after testing your sensor
const int DRY_THRESHOLD = 600;

void setup() {
  Serial.begin(9600);

  pinMode(SOIL_SENSOR, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Assumes active LOW relay module
  digitalWrite(RELAY_PIN, HIGH);

  Serial.println("Smart Soil Irrigation Started");
}

void loop() {
  moistureValue = analogRead(SOIL_SENSOR);

  Serial.print("Soil Moisture: ");
  Serial.println(moistureValue);

  if (moistureValue > DRY_THRESHOLD) {
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Soil is Dry - Pump ON");
  }
  else {
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Soil is Wet - Pump OFF");
  }

  delay(1000);
}
