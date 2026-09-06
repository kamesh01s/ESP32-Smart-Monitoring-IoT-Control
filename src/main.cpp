#include <Arduino.h>
#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT11

#define LED_PIN 2

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);

    dht.begin();

    Serial.println("================================");
    Serial.println("ESP32 Smart Monitoring System");
    Serial.println("================================");
}

void loop() {

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Sensor reading failed!");
        delay(2000);
        return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Monitoring and control logic
    if (temperature >= 30.0) {

        digitalWrite(LED_PIN, HIGH);

        Serial.println("Status: ALERT");
        Serial.println("Device Control: ON");

    } else {

        digitalWrite(LED_PIN, LOW);

        Serial.println("Status: NORMAL");
        Serial.println("Device Control: OFF");
    }

    Serial.println("--------------------------------");

    delay(2000);
}
