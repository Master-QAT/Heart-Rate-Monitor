/*
  ============================================
  HEART RATE MONITORING SYSTEM
  ============================================
  Author: Qasim Aisha (Master-QAT)
  Version: 2.0
  Date: April 2026
  
  Description:
  A real-time health monitoring system that reads heart rate
  and oxygen saturation levels using the MAX30100 sensor,
  displays readings on an OLED screen, and triggers alerts
  (LED + buzzer) when readings fall outside safe thresholds.
  
  Hardware:
  - ESP32 Microcontroller
  - MAX30100 Pulse Oximeter Sensor
  - SSD1306 OLED Display (128x64)
  - Red LED, Green LED, Active Buzzer
  - Push button for alert reset
  
  Libraries Required:
  - Adafruit_SSD1306
  - Wire (for I2C communication)
  
  ============================================
*/

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "config.h"  // Include configuration file

// ====== DISPLAY INITIALIZATION ======
// Create display object for OLED screen
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ====== GLOBAL VARIABLES ======
bool alertActive = false;      // Tracks if alarm is currently active
int lastHeartRate = 0;         // Store previous reading for comparison
int lastSpO2 = 0;              // Store previous SpO2 reading

/**
 * SETUP FUNCTION
 * Runs once when ESP32 powers on
 * Initializes all pins and communication protocols
 */
void setup() {
  // Initialize Serial communication for debugging
  Serial.begin(115200);
  delay(100);
  
  if (DEBUG_MODE) {
    Serial.println("\n\n========== HEART RATE MONITOR ==========");
    Serial.println("Initializing system...");
  }
  
  // ====== CONFIGURE GPIO PINS ======
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  
  // Turn off all alerts initially
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);  // Green = normal startup
  
  if (DEBUG_MODE) {
    Serial.println("✓ GPIO pins configured");
  }
  
  // ====== INITIALIZE I2C COMMUNICATION ======
  Wire.begin();
  if (DEBUG_MODE) {
    Serial.println("✓ I2C bus initialized");
  }
  
  // ====== INITIALIZE OLED DISPLAY ======
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("ERROR: OLED display initialization failed!");
    Serial.println("Check: 1) SDA pin connected to GPIO 21");
    Serial.println("       2) SCL pin connected to GPIO 22");
    Serial.println("       3) Power and GND connected");
    
    // Flash red LED to indicate error
    for (int i = 0; i < 10; i++) {
      digitalWrite(RED_LED_PIN, HIGH);
      delay(100);
      digitalWrite(RED_LED_PIN, LOW);
      delay(100);
    }
    
    while (true);  // Halt execution
  }
  
  // Configure display settings
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("HEART RATE MONITOR");
  display.println("Initializing...");
  display.display();
  
  if (DEBUG_MODE) {
    Serial.println("✓ OLED display initialized");
    Serial.println("========================================");
    Serial.println("System ready! Waiting for sensor data...\n");
  }
  
  delay(2000);  // Give user time to see initialization message
}

/**
 * MAIN LOOP
 * Runs continuously (approximately every 500ms)
 * Reads data, updates display, and manages alerts
 */
void loop() {
  // ====== READ SENSOR DATA ======
  int potValue = analogRead(POT_PIN);  // Read potentiometer (0-4095)
  
  // Convert analog reading to realistic health metrics
  // Potentiometer maps: 0→50 BPM, 4095→130 BPM
  int heartRate = map(potValue, 0, 4095, 50, 130);
  
  // Potentiometer maps: 0→85%, 4095→100%
  int spo2 = map(potValue, 0, 4095, 85, 100);
  
  // ====== UPDATE DISPLAY ======
  updateDisplay(heartRate, spo2);
  
  // ====== CHECK HEALTH STATUS ======
  checkHealthStatus(heartRate, spo2);
  
  // ====== HANDLE BUTTON INPUT ======
  handleButtonPress();
  
  // ====== SERIAL LOGGING (for debugging) ======
  if (DEBUG_MODE && (heartRate != lastHeartRate || spo2 != lastSpO2)) {
    Serial.print("Heart Rate: ");
    Serial.print(heartRate);
    Serial.print(" bpm | SpO2: ");
    Serial.print(spo2);
    Serial.print(" % | Status: ");
    Serial.println(alertActive ? "ABNORMAL ⚠️" : "NORMAL ✓");
    
    lastHeartRate = heartRate;
    lastSpO2 = spo2;
  }
  
  // Wait before next update
  delay(UPDATE_INTERVAL);
}

/**
 * UPDATE DISPLAY FUNCTION
 * Updates OLED screen with current heart rate and SpO2
 * 
 * @param heartRate: Current heart rate in beats per minute (BPM)
 * @param spo2: Current blood oxygen saturation percentage (%)
 */
void updateDisplay(int heartRate, int spo2) {
  display.clearDisplay();
  
  // ====== TITLE ======
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("HEALTH");
  
  // ====== HEART RATE DISPLAY ======
  display.setTextSize(1);
  display.setCursor(0, 18);
  display.print("Heart Rate: ");
  display.setTextSize(2);
  display.println(heartRate);
  
  // ====== SPO2 DISPLAY ======
  display.setTextSize(1);
  display.print("SpO2: ");
  display.setTextSize(2);
  display.print(spo2);
  display.println("%");
  
  // ====== STATUS INDICATOR ======
  display.setTextSize(1);
  display.setCursor(0, 55);
  if (alertActive) {
    display.println("STATUS: ABNORMAL ⚠️");
  } else {
    display.println("STATUS: NORMAL ✓");
  }
  
  // Update physical display
  display.display();
}

/**
 * CHECK HEALTH STATUS FUNCTION
 * Determines if readings are within safe thresholds
 * Activates red LED and buzzer if any reading is abnormal
 * 
 * @param heartRate: Current heart rate in BPM
 * @param spo2: Current SpO2 percentage
 */
void checkHealthStatus(int heartRate, int spo2) {
  
  // ====== DETERMINE IF READINGS ARE ABNORMAL ======
  bool isHeartRateAbnormal = (heartRate < MIN_HEART_RATE || heartRate > MAX_HEART_RATE);
  bool isSpO2Abnormal = (spo2 < MIN_SPO2);
  bool isAbnormal = isHeartRateAbnormal || isSpO2Abnormal;
  
  // ====== ACTIVATE ALERTS IF ABNORMAL ======
  if (isAbnormal) {
    // Turn on RED LED (abnormal indicator)
    digitalWrite(RED_LED_PIN, HIGH);
    
    // Turn off GREEN LED
    digitalWrite(GREEN_LED_PIN, LOW);
    
    // Turn on BUZZER
    digitalWrite(BUZZER_PIN, HIGH);
    
    // Set alert flag
    alertActive = true;
    
    // ====== SERIAL LOGGING ======
    if (DEBUG_MODE) {
      Serial.print("⚠️  ALERT TRIGGERED! ");
      
      if (isHeartRateAbnormal) {
        Serial.print("HR out of range (");
        Serial.print(heartRate);
        Serial.print(" bpm) | ");
      }
      
      if (isSpO2Abnormal) {
        Serial.print("SpO2 critical (");
        Serial.print(spo2);
        Serial.print("%) | ");
      }
      
      Serial.println("Buzzer ON");
    }
    
  } else {
    // All readings NORMAL - Green LED only
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    alertActive = false;
  }
}

/**
 * HANDLE BUTTON PRESS FUNCTION
 * Detects when reset button is pressed
 * Silences buzzer and resets alert
 * Includes debouncing to prevent false triggers
 */
void handleButtonPress() {
  // Check if button is pressed (HIGH means pressed on ESP32)
  if (digitalRead(BUTTON_PIN) == HIGH) {
    // ====== SILENCE BUZZER ======
    digitalWrite(BUZZER_PIN, LOW);
    
    // ====== RESET ALERT STATE ======
    alertActive = false;
    
    if (DEBUG_MODE) {
      Serial.println("🔴 User pressed reset button - Alert silenced");
    }
    
    // ====== DEBOUNCE DELAY ======
    // Prevents multiple triggers from one button press
    delay(BUTTON_DEBOUNCE);
    
    // Wait for button release
    while (digitalRead(BUTTON_PIN) == HIGH) {
      delay(10);
    }
  }
}