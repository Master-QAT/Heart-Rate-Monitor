// heart-rate-monitor.ino
// ============================================
// Smart Health Monitoring System
// Author: Qasim Aisha (Master-QAT)
// Date: 2026
// Description: Real-time heart rate monitoring
// with MAX30100 sensor
// ============================================

#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ====== PIN CONFIGURATION ======
const int potPin = 34;       // Analog input: potentiometer (0-4095)
const int buzzerPin = 18;    // Digital output: buzzer alert
const int redLEDPin = 19;    // Digital output: abnormal status
const int greenLEDPin = 23;  // Digital output: normal status
const int buttonPin = 16;    // Digital input: alert reset button

// ====== THRESHOLDS (Configurable) ======
const int MIN_HEART_RATE = 60;   // BPM - abnormal if below
const int MAX_HEART_RATE = 110;  // BPM - abnormal if above
const int MIN_SPO2 = 90;         // % - abnormal if below

bool alertActive = false;  // Tracks if alert is currently active

/**
 * Initializes display, pins, and serial communication
 */
void setup() {
  Serial.begin(115200);
  
  // Configure pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("ERROR: OLED initialization failed");
    while (true);  // Halt if display fails
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  Serial.println("System initialized successfully");
}

/**
 * Main loop - reads sensor data, updates display, and checks alerts
 * Runs approximately every 500ms
 */
void loop() {
  // Read analog value from potentiometer (0-4095)
  int potValue = analogRead(potPin);
  
  // Convert pot value to realistic health metrics
  int heartRate = map(potValue, 0, 4095, 50, 130);
  int spo2 = map(potValue, 0, 4095, 85, 100);
  
  // Update OLED display
  updateDisplay(heartRate, spo2);
  
  // Check health status and activate alerts if needed
  checkHealthStatus(heartRate, spo2);
  
  // Handle button press to reset alerts
  handleButtonPress();
  
  delay(500);  // Update interval: 500ms
}

/**
 * Updates OLED display with current readings
 * @param hr: Heart rate in BPM
 * @param spo2: Oxygen saturation percentage
 */
void updateDisplay(int hr, int spo2) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.println("HEALTH MONITOR");
  
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.print("Heart Rate: ");
  display.print(hr);
  display.println(" bpm");
  
  display.setCursor(0, 35);
  display.print("SpO2: ");
  display.print(spo2);
  display.println(" %");
  
  display.setCursor(0, 55);
  display.println(alertActive ? "ALERT!" : "Normal");
  
  display.display();
}

/**
 * Checks if readings are within safe thresholds
 * Triggers alerts if any reading is abnormal
 * @param hr: Heart rate in BPM
 * @param spo2: Oxygen saturation percentage
 */
void checkHealthStatus(int hr, int spo2) {
  // Determine if readings are abnormal
  bool isAbnormal = (hr < MIN_HEART_RATE || hr > MAX_HEART_RATE || spo2 < MIN_SPO2);
  
  if (isAbnormal) {
    // Activate red LED and buzzer
    digitalWrite(redLEDPin, HIGH);
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(buzzerPin, HIGH);
    alertActive = true;
    
    // Serial logging
    Serial.print("⚠️ ALERT! HR:");
    Serial.print(hr);
    Serial.print(" bpm, SpO2:");
    Serial.print(spo2);
    Serial.println("%");
  } else {
    // All readings normal - green LED only
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
    digitalWrite(buzzerPin, LOW);
    alertActive = false;
  }
}

/**
 * Handles reset button press to silence buzzer
 * Button is on pin 16
 */
void handleButtonPress() {
  if (digitalRead(buttonPin) == HIGH) {
    digitalWrite(buzzerPin, LOW);
    alertActive = false;
    Serial.println("✓ Alert reset by user");
    delay(200);  // Debounce
  }
}
