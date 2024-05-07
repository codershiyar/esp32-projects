#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"

#define DHTPIN 25
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "iPhone";
const char* password = "12341234";

WebServer server(80);  // Object to handle HTTP requests

// Define handleRoot before setup
void handleRoot() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  String html = "<!DOCTYPE html><html><head><title>ESP32 DHT11 Sensor</title></head><body><h1>DHT11 Sensor Data</h1>";
  html += "<p>Temperature: " + String(t) + "°C</p>";
  html += "<p>Humidity: " + String(h) + "%</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(9600);
  dht.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  server.on("/", handleRoot);      // Define the route for the root URL
  server.begin();                  // Start the server
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
