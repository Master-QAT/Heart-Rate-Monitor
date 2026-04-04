#ifndef CONFIG_H
#define CONFIG_H

// ============================================
// CONFIGURATION FILE FOR HEART RATE MONITOR
// Author: Qasim Aisha (Master-QAT)
// Date: April 2026
// ============================================

// ====== PIN CONFIGURATION ======
// These pins connect to ESP32 GPIO pins
#define POT_PIN 34              // Analog input: potentiometer (0-4095)
#define BUZZER_PIN 18           // Digital output: buzzer alert
#define RED_LED_PIN 19          // Digital output: abnormal status indicator
#define GREEN_LED_PIN 23        // Digital output: normal status indicator
#define BUTTON_PIN 16           // Digital input: alert reset button

// ====== OLED DISPLAY CONFIGURATION ======
#define SCREEN_WIDTH 128        // OLED width in pixels
#define SCREEN_HEIGHT 64        // OLED height in pixels
#define OLED_ADDRESS 0x3C       // I2C address of SSD1306 display

// ====== MAX30100 SENSOR CONFIGURATION ======
#define MAX30100_ADDRESS 0x57   // I2C address of MAX30100 sensor

// ====== HEALTH THRESHOLDS (in BPM and %) ======
// When heart rate or SpO2 falls outside these ranges, an alert is triggered
#define MIN_HEART_RATE 60       // BPM - abnormal if below this
#define MAX_HEART_RATE 110      // BPM - abnormal if above this
#define MIN_SPO2 90             // % - abnormal if below this (dangerous)

// ====== TIMING CONFIGURATION (in milliseconds) ======
#define UPDATE_INTERVAL 500     // How often to read and display data
#define BUTTON_DEBOUNCE 200     // Delay to prevent multiple button presses
#define BUZZER_DURATION 2000    // How long buzzer sounds for each alert

// ====== DEBUG MODE ======
// Set to 1 to enable Serial monitor output for debugging
// Set to 0 to disable (saves memory)
#define DEBUG_MODE 1

#endif  // End of CONFIG_H