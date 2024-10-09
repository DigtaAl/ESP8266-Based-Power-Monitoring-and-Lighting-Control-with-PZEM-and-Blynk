# ESP8266-Based Power Monitoring and Lighting Control with PZEM and Blynk

## Project Overview
This project demonstrates how to monitor and control electrical parameters such as **current**, **voltage**, and **power (wattage)** using the ESP8266 microcontroller, a PZEM-004T energy meter sensor, and the **Blynk** IoT platform. Additionally, the system can control lighting, making it a versatile solution for smart home or energy monitoring applications.

## Features
- **Real-time monitoring** of current, voltage, and power consumption.
- **Remote control of lighting** using Blynk mobile app.
- **Energy efficiency insights** through real-time data.
- Easy integration with the **ESP8266** and **PZEM-004T** sensor.
- Mobile access via the **Blynk app** for convenience.

## Hardware Requirements
- **ESP8266** (NodeMCU or any compatible variant)
- **PZEM-004T** (Power energy meter sensor)
- **Relay Module** (for controlling lighting)
- LED or light bulb for testing
- Jumper wires
- Power supply (as per ESP8266 requirements)

## Software Requirements
- **Arduino IDE** (with ESP8266 board manager installed)
- **Blynk Library** (installed in Arduino IDE)
- **PZEM-004T Library** (for interfacing with the sensor)

## Circuit Diagram
(Include a circuit diagram here, or describe how to wire the ESP8266 with the PZEM-004T sensor and the relay module for light control.)

## Setup Instructions
### Step 1: Install Libraries
In the Arduino IDE, install the following libraries:
- Blynk library (`BlynkESP8266_Lib`)
- PZEM-004T library (`PZEM004T`)

### Step 2: Blynk Setup
1. Download and install the Blynk app (iOS/Android).
2. Create a new project and choose **ESP8266** as the device.
3. Add widgets for current, voltage, and power (using labeled value displays).
4. Add a button widget for controlling the lighting.

### Step 3: Arduino Sketch
- Configure the ESP8266 to connect to your Wi-Fi network.
- Setup Blynk authentication.
- Code to read data from the PZEM-004T sensor.
- Code for controlling the relay module connected to the lighting system.

```cpp
// Include necessary libraries
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <PZEM004T.h>

// Blynk authentication token
char auth[] = "YourBlynkAuthToken";

// Your WiFi credentials
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

// PZEM sensor
PZEM004T pzem(D1, D2);  // RX, TX for ESP8266

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();

  // Read current, voltage, and power from the PZEM
  float voltage = pzem.voltage();
  float current = pzem.current();
  float power = pzem.power();

  // Send data to Blynk app
  Blynk.virtualWrite(V1, voltage);  // V1 for voltage
  Blynk.virtualWrite(V2, current);  // V2 for current
  Blynk.virtualWrite(V3, power);    // V3 for power

  // Add logic for lighting control here
}
