# Heart Rate Monitoring System with ESP32

**Project by Master QAT (Qasim Aisha)**  
SSS3 Student | AI & Robotics Enthusiast, ijebu-ode Nigeria

A low-cost wearable prototype for real-time heart rate monitoring. Built to develop **mechatronics** and embedded systems skills for health applications and assistive robotics.

### Features
- Real-time BPM calculation using simulated pulse signal
- OLED display showing live readings
- Visual alerts: Green LED (normal), Red LED (abnormal)
- Buzzer for audio warning
- Adjustable threshold using potentiometer

### Components (Real Hardware)
- ESP32 microcontroller
- MAX30100 Pulse Oximeter sensor (real design)
- OLED Display (SSD1306)
- Red & Green LEDs
- Buzzer
- Potentiometer

**Note**: In the Wokwi simulation, a potentiometer is used to simulate the pulse signal because the MAX30100 sensor component is not available in the free version of Wokwi. The actual hardware version uses the real MAX30100 sensor (see circuit diagram below).

### Wokwi Simulation (Interactive)
🔗 **Live Simulation**: [https://wokwi.com/projects/460302863710109697](https://wokwi.com/projects/460302863710109697)

### Visuals

![Abnormal Reading](abnormal-simulation.png)  
*Red LED and Buzzer turn ON when reading is abnormal*

![Normal Reading](normal-simulation.png)  
*Green LED turns ON when reading is normal*

![Real Components Wiring](real-components.png)  
*Circuit diagram with actual MAX30100 sensor and components*

### Challenges Faced
- Noisy or unstable readings when simulating pulse signal
- Tuning the threshold to avoid false alerts
- Managing display flicker and timing in the loop
- Difference between simulation (potentiometer) and real MAX30100 sensor behavior

### What I Learned
- How to read analog signals and detect beats on ESP32
- Basic real-time embedded programming and alert systems
- Importance of simulation tools like Wokwi for rapid testing
- The gap between simulated and real hardware (sensor noise, calibration)

### Connection to Physical AI & Future Goals
Inspired by **NVIDIA GTC 2026** and the **Physical AI** wave (GR00T, Isaac Lab, Cosmos), I want to evolve this project into smarter systems.  
Future ideas:
- Use **Isaac Lab** simulation to test wearables on moving bodies
- Generate synthetic data with **Cosmos** to improve accuracy in real conditions
- Combine with Smart Gloves or Muscle EMG projects for intelligent assistive robotics and prosthetics

This project is part of my preparation for **Robotics / Mechatronics** at KAIST.

### Code
Main code: `heart-rate-monitor.ino`  
Real MAX30100 version code is also included in the repository.

### Author
**Master QAT (Qasim Aisha)**  
SSS3 Student preparing for WAEC  
Aspiring KAIST Robotics/Mechatronics Student  
ijebu-ode, Nigeria

**Topics**: esp32, heart-rate-monitor, wearable, mechatronics, physical-ai, student-project
