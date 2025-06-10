#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <PubSubClient.h>

#define DHT_PIN 2
#define DHT_TYPE DHT22

DHT dht(DHT_PIN, DHT_TYPE);
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
    Serial.begin(115200);
    Serial.println("Conectando ao Wifi...");
    WiFi.begin("Wokwi-GUEST", "", 6);
    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
    }
    Serial.println("CONECTADO!");
    dht.begin();
}

void loop() {
    float temperatura = dht.readTemperature();
    float umidade = dht.readHumidity();

    if (isnan(temperatura) || isnan(umidade)) {
        Serial.println("Falha ao ler do sensor DHT!");
    } else {
        Serial.print("Temperatura: ");
        Serial.print(temperatura);
        Serial.print(" °C  |  Umidade: ");
        Serial.print(umidade);
        Serial.println(" %");
    }
    delay(2000); // Aguarda 2 segundos para próxima leitura
}

