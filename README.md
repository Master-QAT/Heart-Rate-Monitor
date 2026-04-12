# ❤️ Heart Rate Monitor

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Arduino IDE Compatible](https://img.shields.io/badge/Arduino%20IDE-Compatible-brightgreen)](https://www.arduino.cc/)
[![ESP32 Ready](https://img.shields.io/badge/ESP32-Ready-blue)](https://www.espressif.com/en/products/socs/esp32)

**Qasim Aisha (Master-QAT)** | AI & Robotics Enthusiast | Future KAIST Robotics Engineer 🚀

A real-time heart rate and oxygen saturation monitoring system built with ESP32. Uses Wokwi simulation for rapid prototyping and includes a professional web dashboard for data visualization.

---

## 📸 Screenshots & Gallery

### 🔌 Circuit Design (Wokwi Simulation)
![Circuit Diagram](hardware/real-circuit.png)

| 📟 OLED – Normal Condition | ⚠️ OLED – Abnormal Condition |
|:---:|:---:|
| ![Normal Output](hardware/normal.png) | ![Abnormal Output](hardware/abnormal.png) |

---

## 🚀 Quick Start

### Try the Simulation (No Hardware)
🔗 **[Open Live Simulation](https://wokwi.com/projects/460302863710109697)**

### Run the Web Dashboard
```bash
git clone [https://github.com/Master-QAT/Heart-Rate-Monitor.git](https://github.com/Master-QAT/Heart-Rate-Monitor.git)
cd Heart-Rate-Monitor/web-dashboard
npm install
npm start
# Open http://localhost:3000


⚙️ How It Works

Signal Acquisition The MAX30100 sensor detects changes in light absorption caused by blood flow in the fingertip using infrared and red LEDs.

Data Processing (ESP32) The ESP32 reads sensor data via the I2C protocol and processes it to calculate Heart Rate (BPM) and Blood Oxygen Level (SpO2).

Real-Time Display The processed data is displayed instantly on the SSD1306 OLED screen for user feedback.

Health Status Detection The system compares readings against predefined thresholds:

Normal → Green LED ON

Abnormal → Red LED + Buzzer activated

Data Transmission The ESP32 sends real-time data to the web dashboard using WebSocket communication.

🎯 Features
✅ Real-time monitoring (50-130 BPM / 85-100% SpO2)

✅ Professional web dashboard with historical trending

✅ Smart alert system (Visual & Audio feedback)

✅ Production-ready documentation & Safety guides

🎓 Connection to Physical AI & KAIST Dream
Inspired by the Physical AI explosion (NVIDIA GR00T, Isaac Lab), I see this project as a foundation for smarter assistive systems.

What I Learned:
Handling noisy analog signals and implementing beat detection.

Navigating the gap between simulated environments (Wokwi) and real-world hardware.

Real-time embedded programming architecture.

Vision: Phase 1 of 3 — Single sensor → Multi-sensor system → AI-powered assistive robotics.

Phase,Focus,Status
Phase 1,Single-sensor health monitoring,✅ Complete
Phase 2,"Multi-sensor wearable (SpO2, EMG, Accel)",🔄 In Progress
Phase 3,AI-powered assistive robotics (Isaac Lab),📋 Planned

🛠️ Technology Stack
Firmware: C++ (ESP32, Arduino IDE)

Backend: Node.js + Express

Frontend: HTML5 + CSS3 + Chart.js

Communication: WebSockets (Real-time)

Simulation: Wokwi

📚 Documentation
Setup Guide | BOM | Calibration | Safety

Author: Qasim Aisha (Master-QAT)

Location: Ijebu-Ode, Nigeria | Status: Production-Ready ✅

