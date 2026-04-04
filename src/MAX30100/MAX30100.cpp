/*
  ============================================
  MAX30100 PULSE OXIMETER IMPLEMENTATION
  ============================================
  Author: Qasim Aisha (Master-QAT)
  Version: 2.0
  Date: April 2026
  
  Description:
  Full implementation using real MAX30100 sensor
  for accurate heart rate and SpO2 measurements.
  This version uses the actual sensor, not simulation.
  
  Sensor Specifications:
  - I2C Interface (0x57)
  - Measures: Heart Rate (BPM) and SpO2 (%)
  - Sampling Rate: Up to 100 Hz
  - Resolution: 16-bit
  
  ============================================
*/

#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"

// ====== DISPLAY SETUP ======
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ====== MAX30100 SENSOR SETUP ======
PulseOximeter pox;
uint32_t tsLastReport = 0;  // Timestamp for last data report

// ====== ALERT STATE TRACKING ======
bool alertState = false;
int beatCount = 0;

/**
 * BEAT DETECTION CALLBACK
 * Called automatically when sensor detects a heartbeat
 * Increments beat counter for statistics
 */
void onBeatDetected() {
  beatCount++;
  if (DEBUG_MODE) {
    Serial.println("♥ Beat detected!");
  }
}

/**
 * SETUP FUNCTION
 * Initializes display, I2C, and MAX30100 sensor
 */
void setup() {
  Serial.begin(115200);
  delay(100);
  
  if (DEBUG_MODE) {
    Serial.println("\n========== MAX30100 INITIALIZATION ==========");
  }
  
  // ====== CONFIGURE GPIO PINS ======
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  
  // Initialize all outputs to OFF
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);
  
  if (DEBUG_MODE) {
    Serial.println("✓ GPIO pins configured");
  }
  
  // ====== INITIALIZE I2C COMMUNICATION ======
  Wire.begin();
  delay(100);
  
  if (DEBUG_MODE) {
    Serial.println("✓ I2C initialized (SDA: GPIO21, SCL: GPIO22)");
  }
  
  // ====== INITIALIZE OLED DISPLAY ======
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("ERROR: OLED initialization failed!");
    while (true);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("MAX30100 Sensor");
  display.println("Initializing...");
  display.display();
  
  if (DEBUG_MODE) {
    Serial.println("✓ OLED display initialized");
  }
  
  // ====== INITIALIZE MAX30100 SENSOR ======
  if (DEBUG_MODE) {
    Serial.print("Checking MAX30100 sensor (address 0x57)... ");
  }
  
  if (!pox.begin()) {
    Serial.println("FAILED to initialize MAX30100");
    Serial.println("CHECK: 1) Sensor plugged in properly");
    Serial.println("       2) SDA connected to GPIO 21");
    Serial.println("       3) SCL connected to GPIO 22");
    Serial.println("       4) VCC and GND connected");
    
    // Flash red LED to indicate error
    for (int i = 0; i < 10; i++) {
      digitalWrite(RED_LED_PIN, HIGH);
      delay(200);
      digitalWrite(RED_LED_PIN, LOW);
      delay(200);
    }
    
    while (true);  // Halt
  }
  
  if (DEBUG_MODE) {
    Serial.println("SUCCESS!");
    Serial.println("✓ MAX30100 ready");
  }
  
  // Set sensor LED brightness (0-255, where 255 is maximum)
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  
  // Register beat detection callback
  pox.setOnBeatDetectedCallback(onBeatDetected);
  
  if (DEBUG_MODE) {
    Serial.println("✓ Beat detection callback registered");
    Serial.println("============================================");
    Serial.println("System ready! Place finger on sensor...\n");
  }
  
  delay(2000);  // Give time to read initialization message
}

/**
 * MAIN LOOP
 * Runs continuously
 * Updates sensor readings every ~1000ms (1 second)
 */
void loop() {
  
  // ====== CONTINUOUSLY UPDATE SENSOR ======
  // This must be called frequently (ideally in a loop)
  // for accurate beat detection
  pox.update();
  
  // ====== CHECK BUTTON FOR RESET ======
  if (digitalRead(BUTTON_PIN) == HIGH) {
    alertState = false;
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    
    if (DEBUG_MODE) {
      Serial.println("🔴 Alert reset by user");
    }
    
    delay(BUTTON_DEBOUNCE);
    
    // Wait for button release
    while (digitalRead(BUTTON_PIN) == HIGH) {
      delay(10);
    }
  }
  
  // ====== REPORT DATA EVERY 1 SECOND ======
  if (millis() - tsLastReport > 1000) {
    
    // Get readings from sensor
    float heartRate = pox.getHeartRate();
    float spo2 = pox.getSpO2();
    
    if (DEBUG_MODE) {
      Serial.print("Heart Rate: ");
      Serial.print(heartRate, 1);  // 1 decimal place
      Serial.print(" bpm | SpO2: ");
      Serial.print(spo2, 1);
      Serial.print(" % | Beats: ");
      Serial.println(beatCount);
    }
    
    // ====== UPDATE OLED DISPLAY ======
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Health");
    
    display.setTextSize(1);
    display.setCursor(0, 20);
    display.print("HR: ");
    display.print(heartRate, 1);
    display.println(" bpm");
    
    display.setCursor(0, 35);
    display.print("SpO2: ");
    display.print(spo2, 1);
    display.println("%");
    
    display.setCursor(0, 50);
    display.print("Beats: ");
    display.println(beatCount);
    
    display.display();
    
    // ====== CHECK ALERT CONDITIONS ======
    // Alert if SpO2 is critical OR heart rate is dangerously high
    if (spo2 < MIN_SPO2 || heartRate > HR_THRESHOLD) {
      
      if (!alertState) {  // Only log when alert first triggered
        Serial.print("⚠️  ALERT! ");
        
        if (spo2 < MIN_SPO2) {
          Serial.print("SpO2 CRITICAL (");
          Serial.print(spo2, 1);
          Serial.print("%) | ");
        }
        
        if (heartRate > HR_THRESHOLD) {
          Serial.print("HR HIGH (");
          Serial.print(heartRate, 1);
          Serial.print(" bpm)");
        }
        
        Serial.println();
      }
      
      // ====== ACTIVATE ALERT OUTPUTS ======
      alertState = true;
      digitalWrite(BUZZER_PIN, HIGH);
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, LOW);
      
    } else {
      // All readings normal
      alertState = false;
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, HIGH);
    }
    
    tsLastReport = millis();  // Reset report timer
  }
}