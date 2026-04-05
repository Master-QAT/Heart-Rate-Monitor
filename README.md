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
⚙️ How It WorksSignal Acquisition: The MAX30100 sensor detects light absorption changes in the fingertip using IR and Red LEDs.Data Processing: ESP32 reads data via I2C to calculate BPM and SpO2 levels.Real-Time Display: Instant feedback provided via SSD1306 OLED screen.Health Status Detection: System triggers Green LED (Normal) or Red LED + Buzzer (Abnormal) based on config thresholds.Data Transmission: ESP32 streams data to the Node.js dashboard using WebSockets.Simulation Mode: A potentiometer mimics pulse signals in Wokwi for hardware-free testing.🎯 Features✅ Real-time monitoring (50-130 BPM / 85-100% SpO2)✅ Professional web dashboard with historical trending✅ Smart alert system (Visual & Audio)✅ Production-ready documentation & Safety guides🎓 Connection to Physical AI & KAIST DreamInspired by the Physical AI explosion (NVIDIA GR00T, Isaac Lab), I see this project as a foundation for smarter assistive systems.What I Learned:Handling noisy analog signals and implementing beat detection.The gap between simulated environments (Wokwi) and real-world hardware noise/calibration.Real-time embedded programming architecture.Vision: Phase 1 of 3 — Single sensor → Multi-sensor system → AI-powered assistive robotics.🔄 Development RoadmapPhaseFocusStatusPhase 1Single-sensor health monitoring✅ CompletePhase 2Multi-sensor wearable (SpO2, EMG, Accel)🔄 In ProgressPhase 3AI-powered assistive robotics (Isaac Lab)📋 Planned🛠️ Technology StackFirmware: C++ (ESP32, Arduino IDE)Backend: Node.js + ExpressFrontend: HTML5 + CSS3 + Chart.jsCommunication: WebSockets (Real-time)Simulation: Wokwi📚 DocumentationSetup Guide | BOM | Calibration | SafetyAuthor: Qasim Aisha (Master-QAT)Location: Ijebu-Ode, Nigeria | Status: Production-Ready ✅
---

### 📤 How to Push the Final Update
Run these commands in your VS Code terminal (from the `Heart-Rate-Monitor` folder):

```bash
# 1. Stage the final README
git add README.md

# 2. Commit the massive update
git commit -m "docs: complete professional README with KAIST vision and technical details"

# 3. Final sync and push
git pull origin main --rebase
git push origin main