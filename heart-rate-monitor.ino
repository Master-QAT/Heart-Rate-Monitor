#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin Definitions
const int potPin = 34;       // Potentiometer simulating sensor
const int buzzerPin = 18;
const int redLEDPin = 19;
const int greenLEDPin = 23;
const int buttonPin = 16;

bool alertActive = false;

void setup() {
  Serial.begin(115200);

  pinMode(buzzerPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  // OLED Initialization
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (true);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  int potValue = analogRead(potPin); // Range: 0-4095

  // Simulate sensor values from pot input
  int heartRate = map(potValue, 0, 4095, 50, 130);    // Simulated HR
  int spo2 = map(potValue, 0, 4095, 85, 100);         // Simulated SpO2

  display.clearDisplay();
  display.setCursor(0, 10);
  display.print("Heart Rate: ");
  display.print(heartRate);
  display.println(" bpm");

  display.print("SpO2: ");
  display.print(spo2);
  display.println(" %");

  display.display();

  // Check health status
  if (heartRate < 60 || heartRate > 110 || spo2 < 90) {
    digitalWrite(redLEDPin, HIGH);
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(buzzerPin, HIGH);
    alertActive = true;
  } else {
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
    if (!alertActive) {
      digitalWrite(buzzerPin, LOW);
    }
  }

  // Button to reset alert/buzzer
  if (digitalRead(buttonPin) == HIGH) {
    digitalWrite(buzzerPin, LOW);
    alertActive = false;
  }

  delay(500);
}
