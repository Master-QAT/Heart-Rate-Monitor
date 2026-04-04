# Bill of Materials (BOM)

## Overview
Complete list of all hardware components needed to build the Heart Rate Monitor system.

## Components List

| Component | Model | Qty | Cost (USD) | Supplier | Notes |
|-----------|-------|-----|-----------|----------|-------|
| **Microcontroller** |
| ESP32 DevKit V1 | ESP32-DEVKITC-32D | 1 | $8-12 | Amazon, AliExpress | 240MHz, WiFi/Bluetooth capable |
| **Sensor** |
| Pulse Oximeter | MAX30100 | 1 | $15-20 | Amazon, Adafruit | I2C interface, measures HR & SpO2 |
| **Display** |
| OLED Display | SSD1306 (0.96") | 1 | $3-5 | Amazon, eBay | 128x64 pixels, I2C interface |
| **Indicators** |
| LED (Red) | 5mm, bright red | 1 | $0.20 | Local electronics | Abnormal alert indicator |
| LED (Green) | 5mm, bright green | 1 | $0.20 | Local electronics | Normal status indicator |
| Buzzer | Active 5V Buzzer | 1 | $1-2 | Amazon | Audio alert (85dB) |
| **Control** |
| Push Button | 6mm momentary | 1 | $0.30 | Local electronics | Reset button |
| **Passive Components** |
| Resistor | 220Ω (1/4W) | 2 | $0.10 | Local electronics | Current limiting for LEDs |
| **Prototyping** |
| Breadboard | Half-size 400 holes | 1 | $2-3 | Amazon | Solderless prototyping |
| Jumper Wires | 22AWG male-male | 40 | $2-3 | Amazon | Various colors for clarity |
| USB Cable | Micro-USB | 1 | $2-3 | Amazon | For programming ESP32 |
| **Optional (For Real PCB)** |
| PCB Board | Custom designed | 1 | $5-10 | PCBWay, JLCPCB | For permanent installation |
| Solder | Lead-free 60/40 | 1 | $3-5 | Local electronics | For soldering components |

## Total Cost Estimate
- **Basic Build (Breadboard):** $35-55 USD
- **Permanent Build (PCB):** $50-75 USD

## Sourcing Recommendations

### Budget-Friendly ($25-35)
- AliExpress (longer shipping, cheapest)
- eBay (medium shipping, good prices)

### Fast Shipping ($40-50)
- Amazon (2-3 day shipping)
- Adafruit (premium products, quick shipping)

### Local Suppliers (Varies)
- Electronics stores in your area
- University electronics lab

## Assembly Notes
- All components use standard 5V or 3.3V logic (compatible)
- I2C devices (OLED + MAX30100) share same data/clock lines
- Use different colored jumper wires for clarity (power, ground, data)

## Required Software
- Arduino IDE 1.8.13+ (free)
- ESP32 Board Support (free)
- Libraries (free):
  - Adafruit_SSD1306
  - Adafruit_GFX
  - MAX30100_PulseOximeter

---
**Created by:** Qasim Aisha (Master-QAT)  
**Last Updated:** April 2026