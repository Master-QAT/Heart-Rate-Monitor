# Heart-Rate-Monitor
A smart health monitoring system using ESP32 + MAX30100 sensor with OLED display and buzzer alerts. Built for wearable health applications by Master QAT
# Heart Rate Monitoring System with ESP32 & MAX30100

## Short Description  
This project is a heart rate monitoring system built with an **ESP32** and the **MAX30100 pulse oximeter sensor**.  
It measures heart rate in real time and provides visual/audio feedback using an OLED display and a buzzer.  
The system can be used for basic health tracking and wearable tech applications.  

## Features  
- Real-time heart rate measurement using MAX30100.  
- Displays heart rate on an OLED screen.  
- Adjustable sensitivity using a potentiometer.  
- Buzzer alert with tone when abnormal readings are detected.  
- Portable and low-power, ideal for wearable health monitoring.  

## Components Used  
### Hardware  
- **ESP32** – Microcontroller for processing and connectivity.  
- **MAX30100 Sensor** – Pulse oximeter for heart rate detection.  
- **OLED Display (SSD1306)** – Shows real-time heart rate readings.  
- **Buzzer** – Provides tone alerts for warnings.  
- **Potentiometer** – Adjusts sensitivity or threshold levels.  
- **Jumper wires & breadboard** – For circuit connections.  

### Software  
- **Arduino IDE** – Programming environment.  
- **ESP32 Board Package** – For compiling and uploading code to ESP32.  
- **MAX30100 Library** – Sensor data processing.  
- **Adafruit SSD1306 & GFX Libraries** – For OLED display control.  

##  How It Works  
1. The MAX30100 sensor detects the user’s heart rate via fingertip measurement.  
2. The ESP32 reads and processes the sensor data.  
3. The heart rate value is displayed on the OLED screen.  
4. The buzzer generates a tone when readings exceed set thresholds.  
5. The potentiometer lets the user adjust sensitivity for testing.  

## Author  
**Master QAT** – *Student | AI & Robotics Enthusiast | Future Robotics Engineer 🚀*  
