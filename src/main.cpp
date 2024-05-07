
#include <WebServer.h>
#include <SPI.h>
#include "DHT.h"
#include <WiFi.h>
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

  // Start the WiFi connection
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to the WiFi network");

  // Correct way to print the IP address for WiFi
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

// Temprator project 
// #include <Arduino.h>

// #include "DHT.h"

// #define DHTPIN 25

// #define DHTTYPE DHT11

// DHT dht(DHTPIN, DHTTYPE);

// void setup() {
//   Serial.begin(9600);
//   Serial.println(F("DHT11 test!"));

//   dht.begin();
// }

// void loop() {
//   // Wait a few seconds between measurements.
//   delay(1000);

//   // Reading temperature or humidity takes about 250 milliseconds!
//   // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
//   float h = dht.readHumidity();
//   // Read temperature as Celsius (the default)
//   float t = dht.readTemperature();

//   // Check if any reads failed and exit early (to try again).
//   if (isnan(h) || isnan(t) ){
//     Serial.println(F("Failed to read from DHT sensor!"));
//     return;
//   }

//   Serial.print(F("Humidity: "));
//   Serial.print(h);
//   Serial.print(F("%  Temperature: "));
//   Serial.print(t);
//   Serial.println(F("°C "));

// }


// #include <Arduino.h>
// #include <WiFiMulti.h>
// #include <InfluxDbClient.h>
// #include <InfluxDbCloud.h>
// #include <math.h>

// #include <Arduino.h>

// #include "switchKaKu.h"
// #define TRANSMITTERID1 001750
// #define rfPin 25
// void setup() {
//   Serial.begin(9600);
//   Serial.println(F("setup"));
// }

// void loop() {
//   switchKaku(rfPin, TRANSMITTERID1, 1, 1, true, 3);
//   Serial.println(F("On"));
//   delay(3000);
//   switchKaku(rfPin, TRANSMITTERID1, 1, 1, false, 3);
//   Serial.println(F("Off"));
//   delay(3000);
// }


// Project Controlling the relay

// #include <Arduino.h>
// int pumpPin = 13;

// void setup(){
//   pinMode(pumpPin, OUTPUT);
// }

// void loop(){
// Serial.println("Pump is now on");
// digitalWrite(pumpPin, HIGH);
// delay(500);

// Serial.println("Pump is now off");
// digitalWrite(pumpPin, LOW);
// delay(500);
// }
// #include <Arduino.h>
	
// //Set pin number
// int soilMoistureSensorPin = 36;
// int moistValue = 0;

// const int ldrPin = 39;
// const int ledPin = 2;

// int lightInitial;
// int lightValue;

// void setup() {

//   Serial.begin(9600); //start a serial connection with a baud rate of 9600
//   pinMode(soilMoistureSensorPin, HIGH);
//   pinMode(ldrPin, INPUT);
//   pinMode(ledPin, OUTPUT);
//   lightInitial = analogRead(ldrPin);
// }

// void loop() {
// lightValue = analogRead(ldrPin);
// if(lightInitial - lightValue >= 200) {
//   digitalWrite (ledPin, HIGH); // turn on light
// }else {
//     digitalWrite (ledPin, LOW); // turn off light
// }

// //Save the moisture value to a variable
// moistValue = analogRead(soilMoistureSensorPin);

// //Print the value to the serial output
// Serial.println(moistValue);

// //Wait for one second
// delay(500);
// }

// // Project 1 to get data live fromn Soil Moisture Sensor
// #include <Arduino.h>
	
// //Set pin number
// int soilMoistureSensorPin = 36;
// int moistValue = 0;

// //Part one is here

// void setup() {
//   // Part two is here
//   // put your setup code here, to run once:
// Serial.begin(9600); //start a serial connection with a baud rate of 9600
// pinMode(soilMoistureSensorPin, HIGH);
// }

// void loop() {
//   // Part three is here
//   // put your main code here, to run repeatedly:
// //Save the moisture value to a variable
// moistValue = analogRead(soilMoistureSensorPin);

// //Print the value to the serial output
// Serial.println(moistValue);

// //Wait for one second
// delay(1000);
// }

// #include <Arduino.h>


// Project 1: Led on/off based of the LED Sensor
// const int ldrPin = 39;
// const int ledPin = 2;

// int lightInitial;
// int lightValue;

// void setup() {
//   Serial.begin(9600);
//   pinMode(ldrPin, INPUT);
//   pinMode(ledPin, OUTPUT);
//   lightInitial = analogRead(ldrPin);
// }

// void loop() {
//   lightValue = analogRead(ldrPin);
//   Serial.println(lightValue);
//   if(lightInitial - lightValue >= 200) {
//   digitalWrite (ledPin, HIGH); // turn on light
// }

//   else {
//     digitalWrite (ledPin, LOW); // turn off light
//   }

// }