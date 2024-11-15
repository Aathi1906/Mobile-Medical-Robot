// Mobile-Medical-Robot/
│
├── src/
│   └── MobileMedicalRobot.ino     # Arduino code
│
├── README.md                       # Project documentation
├── LICENSE                         # License file (optional, add as needed)
└── images/                         # Folder for images/screenshots (optional)
//


// Mobile Medical Robot - Measures Heart Rate and SpO2
// Dependencies: MAX30100, Adafruit GFX, Adafruit SSD1306

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "MAX30100_PulseOximeter.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

PulseOximeter pox;
uint32_t lastReportTime = 0;
#define REPORTING_PERIOD_MS 1000

void onBeatDetected() {
    Serial.println("Beat detected!");
}

void setup() {
    Serial.begin(9600);

 // Initialize the OLED display
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.display();
    // Initialize MAX30100 sensor
    Serial.print("Initializing Pulse Oximeter...");
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }
    // Set the onBeatDetected function as a callback
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
    // Update the sensor readings
    pox.update();
    // Display heart rate and SpO2 every second
    if (millis() - lastReportTime > REPORTING_PERIOD_MS) {
        float heartRate = pox.getHeartRate();
        float SpO2 = pox.getSpO2();
        Serial.print("Heart rate (BPM): ");
        Serial.print(heartRate);
        Serial.print(" | SpO2: ");
        Serial.println(SpO2);
        // Update OLED display
        display.clearDisplay();
        display.setCursor(0, 10);
        display.setTextSize(2);
        display.print("BPM: ");
        display.println(heartRate);
        display.setCursor(0, 35);
        display.print("SpO2: ");
        display.println(SpO2);
        display.display();
        lastReportTime = millis();
    }
}
