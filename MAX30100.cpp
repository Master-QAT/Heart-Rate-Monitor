#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// OLED setup
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// MAX30100 setup
PulseOximeter pox;
uint32_t tsLastReport = 0;

// Pin definitions
#define BUZZER_PIN 18
#define RED_LED 19
#define GREEN_LED 23
#define BUTTON_PIN 16

// Alert thresholds
#define SPO2_THRESHOLD 90
#define HR_THRESHOLD 120

bool alertState = false;

void onBeatDetected() {
  Serial.println("♥ Beat!");
}

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  // OLED init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Initializing...");
  display.display();

  // MAX30100 init
  if (!pox.begin()) {
    Serial.println("FAILED to initialize MAX30100");
    for (;;);
  } else {
    Serial.println("MAX30100 ready");
  }

  pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
  pox.update(); // Must be called regularly

  // Read button (reset alerts)
  if (digitalRead(BUTTON_PIN) == HIGH) {
    alertState = false;
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RED_LED, LOW);
    Serial.println("Alert reset");
  }

  // Every second, print results
  if (millis() - tsLastReport > 1000) {
    float hr = pox.getHeartRate();
    float spo2 = pox.getSpO2();

    Serial.print("Heart Rate: ");
    Serial.print(hr);
    Serial.print(" bpm | SpO2: ");
    Serial.print(spo2);
    Serial.println(" %");

    // OLED update
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Health Monitor");
    display.setCursor(0, 20);
    display.print("HR: ");
    display.print(hr);
    display.println(" bpm");
    display.setCursor(0, 40);
    display.print("SpO2: ");
    display.print(spo2);
    display.println(" %");
    display.display();

    // Alerts
    if (spo2 < SPO2_THRESHOLD || hr > HR_THRESHOLD) {
      alertState = true;
    }

    if (alertState) {
      digitalWrite(BUZZER_PIN, HIGH);
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
    } else {
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
    }

    tsLastReport = millis();
  }
}
