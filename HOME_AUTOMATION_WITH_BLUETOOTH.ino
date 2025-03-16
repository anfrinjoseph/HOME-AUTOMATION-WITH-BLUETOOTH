#include <SoftwareSerial.h>

// Create a software serial port for Bluetooth communication
SoftwareSerial BTSerial(10, 11); // RX, TX

// Define relay pins
const int relay1Pin = 2; // Relay 1 connected to pin 2
const int relay2Pin = 3; // Relay 2 connected to pin 3

void setup() {
    // Initialize serial communication
    Serial.begin(9600); // For debugging
    BTSerial.begin(9600); // For Bluetooth communication

    // Set relay pins as output
    pinMode(relay1Pin, OUTPUT);
    pinMode(relay2Pin, OUTPUT);

    // Initialize relays to OFF
    digitalWrite(relay1Pin, LOW);
    digitalWrite(relay2Pin, LOW);
}

void loop() {
    // Check if data is available from Bluetooth
    if (BTSerial.available()) {
        char command = BTSerial.read(); // Read the command

        // Control relays based on command
        switch (command) {
            case '1': // Command to turn ON device 1
                digitalWrite(relay1Pin, HIGH); // Turn ON Relay 1
                break;
            case '0': // Command to turn OFF device 1
                digitalWrite(relay1Pin, LOW); // Turn OFF Relay 1
                break;
            case '2': // Command to turn ON device 2
                digitalWrite(relay2Pin, HIGH); // Turn ON Relay 2
                break;
            case '3': // Command to turn OFF device 2
                digitalWrite(relay2Pin, LOW); // Turn OFF Relay 2
                break;
            default:
                break; // Do nothing for unrecognized commands
        }
    }
}