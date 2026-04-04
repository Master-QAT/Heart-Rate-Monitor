# ❤️ Heart Rate Monitor

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Arduino IDE Compatible](https://img.shields.io/badge/Arduino%20IDE-Compatible-brightgreen)](https://www.arduino.cc/)
[![ESP32 Ready](https://img.shields.io/badge/ESP32-Ready-blue)](https://www.espressif.com/en/products/socs/esp32)

**Qasim Aisha (Master-QAT)** | Aspiring KAIST Student | Nigeria

A real-time heart rate and oxygen saturation monitoring system built with ESP32. Uses Wokwi simulation for rapid prototyping and includes a professional web dashboard for data visualization.

---

## 🚀 Quick Start

### Try the Simulation (No Hardware)
🔗 **[Open Live Simulation](https://wokwi.com/projects/460302863710109697)**

Adjust the potentiometer to simulate heart rate changes and see real-time OLED display updates.

### Run the Web Dashboard
```bash
git clone https://github.com/Master-QAT/Heart-Rate-Monitor.git
cd Heart-Rate-Monitor/web-dashboard
npm install
npm start
# Open http://localhost:3000
Displays real-time heart rate, SpO2, and status indicators with historical trending.

📋 What's Included
File	Purpose
src/heart-rate-monitor/heart-rate-monitor.ino	Main embedded code (ESP32 firmware)
src/MAX30100/MAX30100.cpp	Real sensor implementation
src/config.h	Centralized configuration
web-dashboard/	Node.js dashboard with Chart.js
docs/	Setup, BOM, Calibration, Safety
hardware/	Circuit diagrams and output images

🎯 Features
✅ Real-time heart rate (50-130 BPM) and SpO2 (85-100%) monitoring
✅ OLED display with instant visual feedback
✅ Smart alerts: Green LED (normal), Red LED + buzzer (abnormal)
✅ Professional web dashboard with real-time charting
✅ Production-ready code with comprehensive documentation
✅ Wokwi simulation for testing without hardware

💻 Hardware (When Available)
ESP32 Microcontroller
MAX30100 Pulse Oximeter Sensor
SSD1306 OLED Display (128x64)
Red & Green LEDs + Buzzer
Button for alert reset
Cost Estimate: $35-55 USD (Full BOM)

📊 Dashboard Preview
Real-time metrics:

Heart Rate (BPM) with live updates
Oxygen Saturation (SpO2 %)
Status indicator (Normal/Abnormal)
60-second historical chart
Professional responsive UI

🎓 Application to KAIST
This project demonstrates the technical foundation required for KAIST's Robotics & Mechatronics program:

✅ Embedded Systems: ESP32 programming, I2C protocol, real-time processing
✅ Full-Stack IoT: Firmware + Backend (Node.js) + Frontend (Web)
✅ Sensor Integration: Pulse oximetry, signal processing, thresholding
✅ Professional Practices: Documentation, safety considerations, open-source standards
✅ Scalability: Foundation for multi-sensor wearables and assistive robotics

Vision: Phase 1 of 3 - Single sensor → Multi-sensor system → AI-powered assistive robotics

📚 Documentation
Setup Guide - Wiring, Arduino IDE setup, troubleshooting
Bill of Materials - Complete parts list with costs
Calibration - Sensor accuracy tuning
Safety & Disclaimer - Medical disclaimer & important notices
Contributing - How to contribute

⚠️ Safety Notice
This is NOT a medical device. It is an educational prototype for learning embedded systems. Do not use for medical diagnosis or patient monitoring. See SAFETY.md for details.

🛠️ Technology Stack
Layer	Technology
Firmware	C++ (ESP32, Arduino IDE)
Sensor	MAX30100 (I2C)
Display	SSD1306 OLED
Backend	Node.js + Express
Frontend	HTML5 + CSS3 + Chart.js
Communication	WebSocket (real-time)
Simulation	Wokwi

📁 Project Structure
Code
Heart-Rate-Monitor/
├── src/
│   ├── heart-rate-monitor/heart-rate-monitor.ino
│   ├── MAX30100/MAX30100.cpp
│   └── config.h
├── web-dashboard/
│   ├── server.js
│   ├── public/index.html
│   └── package.json
├── docs/
│   ├── SETUP_GUIDE.md
│   ├── BOM.md
│   ├── CALIBRATION.md
│   └── SAFETY.md
├── hardware/
│   ├── abnormal.png
│   ├── normal.png
│   └── real-circuit.png
└── README.md

🔄 Development Roadmap
Phase	Focus	Status
Phase 1	Single-sensor health monitoring	✅ Complete
Phase 2	Multi-sensor wearable (SpO2, EMG, Accel)	🔄 In Progress
Phase 3	AI-powered assistive robotics (Isaac Lab)	📋 Planned
Related projects in development: Blood Oxygen Monitor, Smart Gloves, EMG Sensor, Fall Detection

📄 License
MIT License - See LICENSE for details. Free for personal, educational, and commercial use.

👤 Author
Qasim Aisha (Master-QAT)
Applying for KAIST Robotics & Mechatronics Program
Ijebu-Ode, Nigeria
GitHub: @Master-QAT

Last Updated: April 4, 2026 | Version: 1.0.0 | Status: Production-Ready ✅
