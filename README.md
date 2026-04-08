# Gas Leak Detection System using ESP32

## Introduction

This project is a smart gas leak detection system using ESP32 and MQ2 sensor. It is designed to detect gas leaks in real time and respond automatically by triggering alarms and activating ventilation. The system can also be monitored and controlled remotely via a mobile application.

---

## Objectives

* Detect gas leaks quickly and accurately
* Provide immediate warning using LED and buzzer
* Automatically activate a fan to reduce gas concentration
* Allow remote control through IoT (Blynk)

---

## System Features

### Gas Detection

* Uses MQ2 gas sensor
* Digital output (D0) for fast detection
* Analog output (A0) for monitoring gas levels

### Alarm System

* LED blinking warning
* Buzzer sound alert

### Automatic Ventilation

* Relay module controls a 5V fan
* Fan turns on automatically when gas is detected

### Remote Control

* Integrated with Blynk IoT platform
* Users can manually control the relay

---

## Components Used

| Component              | Quantity |
| ---------------------- | -------- |
| ESP32                  | 1        |
| MQ2 Gas Sensor         | 1        |
| Relay Module           | 1        |
| Buzzer                 | 1        |
| LED                    | 1        |
| Resistor (220–330 ohm) | 1        |
| 5V Fan                 | 1        |
| Jumper Wires           | Several  |
| Breadboard or Model    | 1        |

---

## Wiring

| ESP32 Pin | Connected To         |
| --------- | -------------------- |
| GPIO34    | MQ2 A0               |
| GPIO27    | MQ2 D0               |
| GPIO25    | LED (+) via resistor |
| GPIO32    | Buzzer (+)           |
| GPIO26    | Relay IN             |
| VIN (5V)  | MQ2 VCC, Relay VCC   |
| GND       | All components GND   |

---

## System Workflow

1. MQ2 sensor detects gas
2. ESP32 processes the signal
3. If gas is detected:

   * LED starts blinking
   * Buzzer sounds
   * Relay turns ON and activates the fan
4. User can control the system via Blynk

---

## System Logic

* Auto Mode: system reacts based on sensor input
* Manual Mode: user controls relay through Blynk

---

## Testing and Calibration

* Adjust MQ2 potentiometer to set detection threshold
* Ensure system remains idle without gas
* Ensure system reacts immediately when gas is present

---

## Future Improvements

* Add display for real-time gas values
* Send notifications to mobile devices
* Improve detection accuracy using analog data
* Expand system with multiple sensors

---

## Applications

* Home safety systems
* Kitchen gas leak detection
* Industrial safety monitoring
* IoT environmental monitoring

---

## Author

Quỳnh

---

## Conclusion

This project demonstrates how embedded systems and IoT can be used to build a real-time safety solution. It integrates sensing, processing, and remote control to create an effective gas leak detection system.
