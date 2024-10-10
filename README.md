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
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <PZEM004Tv30.h>

#define BLYNK_PRINT Serial
/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6_Yh3lloY"
#define BLYNK_TEMPLATE_NAME "KontroldanMonitoring"
#define BLYNK_AUTH_TOKEN "CprE21zEKhSN4elWLJWUHs1q-5X7asj2"
#include <BlynkSimpleEsp8266.h>
// Your WiFi credentials.
char ssid[] = "Al-Aadiyaat";
char pass[] = "alaadiyaat23";

PZEM004Tv30 pzem(D4, D3); // D6, D5, (RX,TX) connect to TX,RX of PZEM

#define PIN_RELAY_1  D6 // The ESP8266 pin connected to the IN1 pin of relay module
#define PIN_RELAY_2  D7 // The ESP8266 pin connected to the IN2 pin of relay module


float voltage;
float current;
float power;


void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Configure the ESP8266 pin as an digital output.
  pinMode(PIN_RELAY_1, OUTPUT);
  pinMode(PIN_RELAY_2, OUTPUT);
}

void loop() {

  Blynk.run();

  /*digitalWrite(PIN_RELAY_1, HIGH);
  digitalWrite(PIN_RELAY_2, HIGH);
  delay(2000);

  digitalWrite(PIN_RELAY_1, LOW);
  digitalWrite(PIN_RELAY_2, LOW);
  delay(2000);*/

  voltage = pzem.voltage();
  current = pzem.current();
  power = pzem.power();

   Blynk.virtualWrite(V0, voltage);
   Blynk.virtualWrite(V1, current);
   Blynk.virtualWrite(V2, power);

  /*
  Serial.print("VoltageAC: ");      Serial.print(voltage);      Serial.println("V");
  Serial.print("CurrentAC: ");      Serial.print(current);      Serial.println("A");
  Serial.print("PowerAC: ");        Serial.print(power);        Serial.println("W");
  */
  
  delay(500);
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
