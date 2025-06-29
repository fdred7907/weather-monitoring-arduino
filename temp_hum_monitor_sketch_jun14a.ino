#include "DHT.h"

#define DHTPIN 2         // Digital pin connected to the DHT11
#define DHTTYPE DHT11    // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  delay(1000);
  Serial.println("Temperature\tHumidity"); // Header for Serial Plotter
}

void loop() {
  delay(2000); // Wait 2 seconds between readings

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT11 sensor!");
    return;
  }

  // Print to Serial Monitor (Human-readable)
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Print to Serial Plotter (Tab-separated)
  Serial.print(temperature);
  Serial.print("\t");
  Serial.println(humidity);
}
