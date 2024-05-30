// const int LED_PIN = 16;
// const int BUTTON_PIN = 12;

// HardwareSerial Serial1(1);

// void setup() {
//   pinMode(LED_PIN, OUTPUT);
//   pinMode(BUTTON_PIN, INPUT_PULLUP);
//   Serial.begin(9600);
//   Serial1.begin(9600, SERIAL_8N1, 2, 4); // RX, TX pins for Serial1
// }
//11
// void loop() {
//   if (Serial1.available() > 0) {
//     char incomingByte = Serial1.read();
//     if (incomingByte == '1') {
//       digitalWrite(LED_PIN, HIGH);
//       Serial.println("LED turned ON by Arduino Uno");
//     } else if (incomingByte == '0') {
//       digitalWrite(LED_PIN, LOW);
//       Serial.println("LED turned OFF by Arduino Uno");
//     }
//   }
//   if (digitalRead(BUTTON_PIN) == LOW) {
//     Serial1.println("1"); // Send signal to Arduino Uno
//     delay(1000); // Debounce delay
//   }
//   delay(100);
// }


// use this 
#include <Arduino.h>

#define LED_PIN 2
const int uartRxpin = 16;

void setup() 
{
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
    if (Serial.available() > 0) 
    {
        String input = Serial.readStringUntil('\n');
        if (input.startsWith("D:"))
         {
            int distance = input.substring(2).toInt();
            if (distance < 20) 
            {
                digitalWrite(LED_PIN, HIGH); // Turn on LED
            } 
            else
             {
                digitalWrite(LED_PIN, LOW); // Turn off LED
             }
        }
    }
}
