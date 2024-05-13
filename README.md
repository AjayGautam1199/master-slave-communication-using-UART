# Master-Slave Communication using UART

This project demonstrates master-slave communication using UART (Universal Asynchronous Receiver-Transmitter), with an Arduino Mega acting as the master device and an ESP32 as the slave device. The master and slave communicate with each other over UART serial communication protocol.

## Overview

The objective of this project is to establish communication between the master and slave devices and trigger an action on the master device based on sensor data received from the slave. In this specific implementation, an ultrasonic sensor connected to the ESP32 slave detects objects within a certain range. When the distance to an object is measured to be 5 cm or less, the slave transmits a signal to the master. Upon receiving this signal, the master turns on an LED connected to it.

## Installation

1. Clone the repository:


2. Set up the Arduino Mega and ESP32 devices with the necessary firmware provided in the `arduino` and `esp32` directories, respectively.

## Usage

1. Upload the firmware to the Arduino Mega and ESP32 devices.
2. Connect the devices.
3. Power on both the master and slave devices.
4. Place an object within 5 cm of the ultrasonic sensor connected to the ESP32.
5. Observe the LED connected to the Arduino Mega turning on in response to the transmitted signal.

## Demo

![Master-Slave Communication Demo](masterslave.gif)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
