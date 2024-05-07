# ESP32 Arduino Projects

This repository contains a collection of Arduino projects utilizing the ESP32. Each project focuses on different applications ranging from environmental monitoring to remote control systems. Here's a brief overview of each project included in this repository.

## Table of Contents
- [ESP32 DHT11 Web Server](#esp32-dht11-web-server)
- [DHT11 Sensor Data Logger](#dht11-sensor-data-logger)
- [Remote Control via 433 MHz RF](#remote-control-via-433-mhz-rf)
- [Automated Pump Control](#automated-pump-control)
- [Soil Moisture Sensor with LED Indicator](#soil-moisture-sensor-with-led-indicator)
- [Light Sensitive LED Control](#light-sensitive-led-control)

---

### ESP32 DHT11 Web Server
- **Description**: This project utilizes an ESP32 to read data from a DHT11 temperature and humidity sensor and display it on a web server.
- **Components Needed**:
  - ESP32 module
  - DHT11 sensor
- **Setup**:
  - Connect the DHT11 sensor to the ESP32.
  - Update the WiFi credentials in the code.
- **Usage**:
  - The ESP32 serves a webpage that shows the temperature and humidity readings.

### DHT11 Sensor Data Logger
- **Description**: Logs temperature and humidity data from a DHT11 sensor to the serial monitor.
- **Components Needed**:
  - ESP32 or any compatible Arduino board
  - DHT11 sensor
- **Setup**:
  - Connect the DHT11 sensor to your Arduino board.
- **Usage**:
  - Open the serial monitor to view the logged data.

### Remote Control via 433 MHz RF
- **Description**: Controls devices remotely using a 433 MHz RF transmitter.
- **Components Needed**:
  - Arduino board
  - 433 MHz RF transmitter
- **Setup**:
  - Attach the RF transmitter to the appropriate pins on the Arduino.
- **Usage**:
  - Send commands to turn devices on or off using RF signals.

### Automated Pump Control
- **Description**: Automatically controls a pump connected to an Arduino board.
- **Components Needed**:
  - Arduino board
  - Relay module
  - Pump
- **Setup**:
  - Connect the pump to the relay, and the relay to the Arduino.
- **Usage**:
  - The system automatically turns the pump on and off.

### Soil Moisture Sensor with LED Indicator
- **Description**: Monitors soil moisture levels and uses an LED as an indicator.
- **Components Needed**:
  - Arduino board
  - Soil moisture sensor
  - LED
- **Setup**:
  - Connect the soil moisture sensor and LED to the Arduino.
- **Usage**:
  - The LED turns on or off based on the moisture level detected.

### Light Sensitive LED Control
- **Description**: Uses an LDR to control an LED based on the ambient light.
- **Components Needed**:
  - Arduino board
  - LDR (Light Dependent Resistor)
  - LED
- **Setup**:
  - Connect the LDR and LED to the Arduino.
- **Usage**:
  - The LED activates depending on the light conditions detected by the LDR.

---

## Installation
1. Clone this repository to your local machine.
2. Open the project files with Arduino IDE.
3. Upload the code to your ESP32 or Arduino board.

## Contributing
Feel free to fork this repository and contribute by submitting a pull request. We appreciate your input!

## License
This project is licensed under the MIT License.
