#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Define the pins that we will use
#define SENSOR 33
#define LED 26

DHT_Unified dht(SENSOR, DHT11);

void setup() {
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
   sensor_t sensor;
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
    esp_sleep_enable_timer_wakeup(5 * 1000000); // 5 seconds in microseconds
  Serial.println(F("Entering Deep Sleep mode for 5 seconds..."));
  delay(100); // Ensure Serial output is completed
  esp_deep_sleep_start();
}

void loop() {
  
}