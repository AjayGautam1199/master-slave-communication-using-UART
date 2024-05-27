// const int LED_PIN = 13;
// const int BUTTON_PIN = A0;

// void setup() {
//   pinMode(LED_PIN, OUTPUT);
//   pinMode(BUTTON_PIN, INPUT_PULLUP);
//   Serial.begin(9600);
// }
//11
// void loop() {
//   if (Serial.available() > 0) {
//     char incomingByte = Serial.read();
//     if (incomingByte == '1') {
//       digitalWrite(LED_PIN, HIGH);
//       Serial.println("LED turned ON by ESP32");
//     } else if (incomingByte == '0') {
//       digitalWrite(LED_PIN, LOW);
//       Serial.println("LED turned OFF by ESP32");
//     }
//   }
//   if (digitalRead(BUTTON_PIN) == LOW) {
//     Serial.println("1"); // Send signal to ESP32
//     delay(1000); // Debounce delay
//   }
//   delay(100);
// }


#include <Arduino.h>

const int trigPin = 5; // Trig pin of ultrasonic sensor
const int echoPin = 18; // Echo pin of ultrasonic sensor
const int uartTxPin = 17; // UART TX pin

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, uartTxPin); // Initialize UART2
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Convert to centimeters

  Serial.print("D:");
  Serial.println(distance);

  // Transmit distance over UART2
  Serial2.print("D:");
  Serial2.println(distance);

  delay(3000); // Adjust delay as needed
}
