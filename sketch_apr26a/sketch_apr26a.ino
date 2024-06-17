// Define the pin connected to the soil moisture sensor
const int soilMoisturePin = A0;
const int waterLevelSensorPin = A1; // Analog pin A1

// Define the threshold value for considering water present
const int waterThreshold = 500;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the soil moisture value
  int soilMoistureValue = analogRead(soilMoisturePin);

  // Convert the analog value to voltage (0-5V)
  float voltage = soilMoistureValue * (5.0 / 1023.0);
  int moisturePercentage = map(soilMoistureValue, 0, 1023, 0, 100);
int Temp=0;
 for (int i = 0; i < 5; i++) {
  float Temperature = random(20, 30);
  Temp=Temp+Temperature;
    
  }
 

  // Convert voltage to percentage (assuming the sensor outputs 0V when dry and 5V when wet)
  // You may need to adjust these values based on your sensor's specifications
  
  int NEWMOISTURE=0;
 for (int i = 0; i < 5; i++) {
   int moisturePercentage = map(soilMoistureValue, 0, 1023, 0, 100);
    NEWMOISTURE= moisturePercentage+NEWMOISTURE;
  }
  int NEWHUMIDITY=0;
 for (int i = 0; i < 5; i++) {
  int humidityPercentage = map(soilMoistureValue, 0, 1023, 100, 0);
    NEWHUMIDITY= humidityPercentage + NEWHUMIDITY;
  }
  NEWHUMIDITY=(NEWHUMIDITY/5);
  NEWMOISTURE=(NEWMOISTURE/5);
  // Print the humidity percentage
  Serial.print("Soil Humidity: ");
  
  Serial.print(NEWHUMIDITY);
   Temp=(Temp/5);
  // Print random temperature value
  Serial.print("Temperature: ");
  Serial.print(Temp);
  Serial.println("°C");
  
Serial.println("%");
    Serial.print("Soil Moisture: ");
    Serial.print(moisturePercentage);
  Serial.println("%");
  int sensorValue = analogRead(waterLevelSensorPin);

  // Print the sensor value to the serial monitor
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // Check if the water level is above the threshold
  if (sensorValue >= waterThreshold) {
    Serial.println("Water Detected!"); // Water is present
  } else {
    Serial.println("No Water Detected"); // No water is present
  }

  // Delay before taking the next reading
  delay(4000); // Adjust as needed
}