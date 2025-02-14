int moistureAnalogPin = 34;   // Soil Moisture Sensor Analog Pin 
int lightSensorPin = 35;     // TEMT6000 Light Sensor Analog Pin

int pHSensorPin = 32;  // Analog pin for simulated pH sensor
int pHAnalogValue = 0; // Variable to store raw analog reading
float pHPercentage = 0; // Variable to store pH value as percentage

int ledPinG = 12;
int ledPinR = 13; 
int ledPinB = 14;

// Variables for Soil Moisture Sensor
int moistureAnalogValue = 0;  
int soilMoisturePercent = 0;  

// Variables for Light Sensor
int lightAnalogValue = 0;  
float lightLux = 0;        

void setup() {
  Serial.begin(115200); // Start Serial Communication
   
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinB, OUTPUT);// Set the digital pin for soil moisture sensor
}

void loop() {
  // Read Soil Moisture Sensor Data
  moistureAnalogValue = analogRead(moistureAnalogPin); // Analog value 
  soilMoisturePercent = map(moistureAnalogValue, 4095, 1743, 0, 100); // Map to percentage
  soilMoisturePercent = constrain(soilMoisturePercent, 0, 100); // Clamp to 0-100

  pHAnalogValue = analogRead(pHSensorPin);
  pHPercentage = map(pHAnalogValue, 0, 4095, 0, 14);

  // Read TEMT6000 Light Sensor Data
  lightAnalogValue = analogRead(lightSensorPin); // Analog value
  lightLux = map(lightAnalogValue, 0, 4095, 0, 100000); // Approximate mapping to lux
  
  // Print Data to Serial Monitor
  Serial.print("Soil Moisture Sensor: ");
  Serial.print("Analog Value: ");
  Serial.print(moistureAnalogValue);
  Serial.print(" | Soil Moisture: ");
  Serial.print(soilMoisturePercent);
  Serial.println("%");
  
  Serial.print("Light Sensor: ");
  Serial.print("Analog Value: ");
  Serial.print(lightAnalogValue);
  Serial.print(" | Light Intensity: ");
  Serial.print(lightLux);
  Serial.println(" lux");

  Serial.print("Analog Value: ");
  Serial.print(pHAnalogValue);
  Serial.print(" | Simulated pH Level: ");
  Serial.println(pHPercentage);


  Serial.println("---------------------------------------------");
  
    if (pHPercentage >= 5.5 && pHPercentage <= 7.5) {
    digitalWrite(ledPinR, HIGH);  // Turn ON LED when pH is around 7 (neutral range)
  } else {
    digitalWrite(ledPinR, LOW);   // Turn OFF LED when pH is outside the neutral range
  }

   if (lightLux >= 10000 && lightLux <= 15000) {
    digitalWrite(ledPinG, HIGH);  // Ideal light for Aloe Vera
  } else {
    digitalWrite(ledPinG, LOW);
  }

  if (soilMoisturePercent >= 10 && soilMoisturePercent <= 30) {
    digitalWrite(ledPinB, HIGH);  // Turn ON LED when pH is around 7 (neutral range)
  } else {
    digitalWrite(ledPinB, LOW);   // Turn OFF LED when pH is outside the neutral range
  }

  delay(1000); // Wait 1 second before the next loop
}