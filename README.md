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
```
## Step 4: Wiring the Circuit
- **PZEM-004T Connections**:
  - Connect the **TX pin** of the PZEM sensor to the **D1 pin** of the ESP8266.
  - Connect the **RX pin** of the PZEM sensor to the **D2 pin** of the ESP8266.
  - Connect the **GND** and **VCC** pins of the PZEM sensor to the **GND** and **3.3V** pins of the ESP8266.

- **Relay Module Connections**:
  - Connect the **IN pin** of the relay module to a **digital pin** of the ESP8266 (e.g., D5).
  - Connect the **VCC** and **GND** pins of the relay to the corresponding pins on the ESP8266.
  - The relay’s **NO (Normally Open)** pin should be connected to one side of the lighting system.
  - The other side of the lighting system should be connected to the power supply.
  
- **Power Supply**:
  Ensure the ESP8266 and the lighting system have proper power supply connections.

### Step 5: Flash the Code
1. Connect the ESP8266 to your computer via USB.
2. In the Arduino IDE, select the **ESP8266** board and the appropriate port.
3. Compile and upload the sketch provided in **Step 3** to the ESP8266.

### Step 6: Blynk App Configuration
1. Open the **Blynk** app on your mobile device.
2. Monitor the **current**, **voltage**, and **power** values in real-time via the **labeled value** widgets.
3. Use the **button widget** to control the lighting system remotely.

## Usage
- Once the system is up and running, you can remotely monitor and control your electrical system.
- Open the Blynk app to see real-time data for voltage, current, and power.
- Press the **control button** to turn the lighting on or off.
  
This system allows easy monitoring of power consumption and gives you control over lighting through a simple interface.

## Future Enhancements
- **Power Usage History**: Implement a feature to store and analyze historical power usage trends.
- **Abnormal Consumption Alerts**: Add notifications to alert users when power consumption exceeds predefined limits.
- **Advanced Control**: Expand the system to control multiple devices or add automation based on energy consumption data.

## Troubleshooting
- Ensure that the ESP8266 is properly connected to Wi-Fi and Blynk is connected.
- Double-check the wiring between the ESP8266, PZEM sensor, and relay module if values are not showing correctly.
- Verify the correct power supply for both the ESP8266 and lighting system.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
