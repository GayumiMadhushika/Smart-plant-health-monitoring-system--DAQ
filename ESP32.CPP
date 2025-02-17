int moistureAnalogPin = 34;   // Soil Moisture Sensor Analog Pin 
int lightSensorPin = 35;     // TEMT6000 Light Sensor Analog Pin

int pHSensorPin = 32;  // Analog pin for simulated pH sensor
int pHAnalogValue = 0; // Variable to store raw analog reading
float pHPercentage = 0; // Variable to store pH value as percentage

int ledPinG1 = 23;
int ledPinG2 = 22; 
int ledPinG3 = 21;

int ledPinR1 = 13;
int ledPinR2 = 12; 
int ledPinR3 = 14;

// Variables for Soil Moisture Sensor
int moistureAnalogValue = 0;  
int soilMoisturePercent = 0;  

// Variables for Light Sensor
int lightAnalogValue = 0;  
float lightLux = 0;        

void setup() {
  Serial.begin(115200); // Start Serial Communication
   
  pinMode(ledPinR1, OUTPUT);
  pinMode(ledPinR2, OUTPUT);
  pinMode(ledPinR3, OUTPUT);
  
  pinMode(ledPinG1, OUTPUT);
  pinMode(ledPinG2, OUTPUT);
  pinMode(ledPinG3, OUTPUT);
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
  

  if (soilMoisturePercent >= 35 && soilMoisturePercent <= 100) {
    digitalWrite(ledPinR1, HIGH);  // Turn ON LED when moisture level is higher than the 35
  } else {
    digitalWrite(ledPinR1, LOW);   // Turn OFF LED when moisture level is lower than the 35
  }

    if (pHPercentage >= 7.5 && pHPercentage <= 14.5) {
    digitalWrite(ledPinR2, HIGH);  // Turn ON LED when pH is greater than 7 (neutral range)
  } else {
    digitalWrite(ledPinR2, LOW);   // Turn OFF LED when pH is lower than the neutral range
  }

  
   if (lightLux >= 25000 && lightLux <= 100000) {
    digitalWrite(ledPinR3, HIGH);  // Ideal light for Aloe Vera is 10000lux to 15000lux
  } else {
    digitalWrite(ledPinR3, LOW);
  }

  if (soilMoisturePercent >= 0 && soilMoisturePercent <= 10) {
    digitalWrite(ledPinG1, HIGH);  // Turn ON LED when moisture level is higher than the 35
  } else {
    digitalWrite(ledPinG1, LOW);   // Turn OFF LED when moisture level is lower than the 35
  }

    if (pHPercentage >= 0 && pHPercentage <= 6.5) {
    digitalWrite(ledPinG2, HIGH);  // Turn ON LED when pH is greater than 7 (neutral range)
  } else {
    digitalWrite(ledPinG2, LOW);   // Turn OFF LED when pH is lower than the neutral range
  }

  
   if (lightLux >= 0 && lightLux <= 10000) {
    digitalWrite(ledPinG3, HIGH);  // Ideal light for Aloe Vera is 10000lux to 15000lux
  } else {
    digitalWrite(ledPinG3, LOW);
  }
  delay(1000); // Wait 1 second before the next loop
}