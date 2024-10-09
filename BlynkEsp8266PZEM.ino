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
