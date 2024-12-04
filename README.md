## Mobile Medical Robot Movement

This part of the project adds mobility to the medical robot using **Bluetooth control** via the **HC-05 Bluetooth Module**, **L298N Motor Driver**, and **4 BO motors**. The robot can be controlled wirelessly from a smartphone using a Bluetooth terminal app.

## Components for Movement
- **4 BO Motors**
- **L298N Motor Driver**
- **HC-05 Bluetooth Module**
- **Arduino Uno**

## Wiring for Movement Control
The wiring for the Bluetooth communication and motor control remains as described above.

## Bluetooth Commands:
- **F**: Move Forward
- **B**: Move Backward
- **L**: Turn Left
- **R**: Turn Right
- **S**: Stop

## Usage
Once the Bluetooth connection is established, use the terminal app to control the robot. The robot will move according to the commands sent via Bluetooth.




# MAX30100 Bluetooth Health Monitor

This project uses an **Arduino Uno** along with the **MAX30100 Pulse Oximeter** and **Heart Rate Sensor**, an **OLED I2C display**, and a **HC-05 Bluetooth Module** to monitor and display the heart rate (BPM) and SpO2 levels of a patient. The data is also sent wirelessly via Bluetooth to a connected device.

## Features
- Measures **SpO2** (blood oxygen saturation) and **BPM** (heart rate).
- Displays data on a 0.96" OLED I2C display.
- Sends real-time data over Bluetooth to a connected device (e.g., smartphone or computer).

## Components
- Arduino Uno
- MAX30100 Pulse Oximeter and Heart Rate Sensor
- OLED I2C Display (SSD1306)
- HC-05 Bluetooth Module
- Jumper Wires

## Wiring
- **MAX30100 Sensor**:  
  - VCC -> 5V (Arduino)
  - GND -> GND (Arduino)
  - SDA -> A4 (Arduino)
  - SCL -> A5 (Arduino)

- **OLED Display**:  
  - VCC -> 5V (Arduino)
  - GND -> GND (Arduino)
  - SDA -> A4 (Arduino)
  - SCL -> A5 (Arduino)

- **HC-05 Bluetooth Module**:  
  - VCC -> 5V (Arduino)
  - GND -> GND (Arduino)
  - TX -> Pin 10 (Arduino)
  - RX -> Pin 11 (Arduino)

## Libraries Required
- Adafruit MAX30100
- Adafruit SSD1306
- SoftwareSerial

## Installation
1. Clone this repository.
2. Install the necessary libraries from the Arduino Library Manager.
3. Open the `MAX30100_Bluetooth_Health_Monitor.ino` file in Arduino IDE.
4. Upload the code to your Arduino Uno.

## Usage
1. Open a Bluetooth terminal app (e.g., **Bluetooth Terminal** on Android).
2. Pair with the **HC-05 Bluetooth Module**.
3. View the real-time **BPM** and **SpO2** data being sent from the Arduino.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
