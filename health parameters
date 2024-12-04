#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MAX30100.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>

// Pin Definitions
#define OLED_RESET -1
#define MAX30100_SDA_PIN A4
#define MAX30100_SCL_PIN A5

// Initialize the MAX30100 sensor
Adafruit_MAX30100 max30100;
Adafruit_SSD1306 display(OLED_RESET);

// Initialize SoftwareSerial for Bluetooth communication
SoftwareSerial BTserial(10, 11); // RX, TX pins for HC-05 module

void setup() {
  // Start Serial communication for debugging
  Serial.begin(9600);
  BTserial.begin(9600);

  // Initialize the MAX30100 sensor
  if (!max30100.begin()) {
    Serial.println("Couldn't find MAX30100 sensor");
    while (1);
  }

  // Initialize OLED Display
  if (!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (1);
  }
  display.display();
  delay(2000);  // Pause for 2 seconds

  // Display initial text
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Initializing...");
  display.display();
  delay(1000);
}

void loop() {
  float bpm, spo2;

  // Read the SpO2 and BPM from the MAX30100 sensor
  if (max30100.available()) {
    max30100.getReadings();
    bpm = max30100.getHeartRate();
    spo2 = max30100.getSpO2();
    
    // Display on OLED
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.println("SpO2 & BPM:");
    display.setTextSize(2);
    display.print("BPM: ");
    display.println(bpm);
    display.print("SpO2: ");
    display.println(spo2);
    display.display();

    // Send data over Bluetooth
    BTserial.print("BPM: ");
    BTserial.print(bpm);
    BTserial.print(", SpO2: ");
    BTserial.println(spo2);
  }

  // Add a delay to avoid overwhelming the system
  delay(1000);
}
