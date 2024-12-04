#include <SoftwareSerial.h>

// Motor Pins
#define motorA1 3
#define motorA2 4
#define motorB1 5
#define motorB2 6

// Bluetooth pins
SoftwareSerial BTserial(10, 11); // RX, TX pins for HC-05

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);
  BTserial.begin(9600);

  // Set motor pins as OUTPUT
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  // Initial motor state: stop
  stopMovement();
}

void loop() {
  if (BTserial.available()) {
    char command = BTserial.read(); // Read Bluetooth command

    // Print the command to serial monitor for debugging
    Serial.println(command);

    // Move the robot based on the received Bluetooth command
    switch (command) {
      case 'F': // Forward
        moveForward();
        break;
      case 'B': // Backward
        moveBackward();
        break;
      case 'L': // Left
        turnLeft();
        break;
      case 'R': // Right
        turnRight();
        break;
      case 'S': // Stop
        stopMovement();
        break;
      default:
        break;
    }
  }
}

// Function to move forward
void moveForward() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

// Function to move backward
void moveBackward() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

// Function to turn left
void turnLeft() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

// Function to turn right
void turnRight() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
}

// Function to stop all movement
void stopMovement() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}
