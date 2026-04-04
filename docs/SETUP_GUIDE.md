# Hardware Setup Guide

## Prerequisites
- All components from BOM.md
- Arduino IDE installed on your computer
- USB cable and appropriate drivers

## Wiring Diagram

ESP32 PINOUT: GND ──────────────── Breadboard GND Rail 3.3V ─────────────── Breadboard Power Rail

I2C DEVICES (OLED + MAX30100): GPIO 21 (SDA) ────── OLED SDA, MAX30100 SDA GPIO 22 (SCL) ────── OLED SCL, MAX30100 SCL 3.3V ──────────────── OLED VCC, MAX30100 VCC GND ──────────────── OLED GND, MAX30100 GND

GPIO 18 ──── [Buzzer +] (negative to GND) GPIO 19 ──┬─ [Red LED +] └─ [220Ω Resistor] to GND

GPIO 23 ──┬─ [Green LED +] └─ [220Ω Resistor] to GND

GPIO 16 ────┬─ [Push Button] └─ GND

Code

## Step-by-Step Instructions

### Step 1: Prepare the Breadboard
1. Place breadboard on flat surface
2. Identify power rails (usually red/blue strips on sides)
3. Connect GND (black wire) from ESP32 to negative (blue) rail
4. Connect 3.3V (red wire) from ESP32 to positive (red) rail

### Step 2: Connect OLED Display
**OLED has 4 pins:** VCC, GND, SDA, SCL

OLED Pin → ESP32 GPIO VCC → 3.3V (power rail) GND → GND (ground rail) SDA → GPIO 21 SCL → GPIO 22

Code

**Action:**
- Use 4 jumper wires
- Connect each pin as shown above
- Double-check connections before powering

### Step 3: Connect MAX30100 Sensor
**MAX30100 has 4 pins:** VCC, GND, SDA, SCL

MAX30100 Pin → Connection VCC → 3.3V rail (same as OLED) GND → GND rail (same as OLED) SDA → GPIO 21 (SAME as OLED!) SCL → GPIO 22 (SAME as OLED!)

Code

**Important:** Both devices share the I2C bus (same GPIO 21 & 22)

### Step 4: Connect LEDs with Resistors
**Red LED:**
- Longer leg (anode +) → GPIO 19 via 220Ω resistor
- Shorter leg (cathode -) → GND

**Green LED:**
- Longer leg (anode +) → GPIO 23 via 220Ω resistor
- Shorter leg (cathode -) → GND

**Why resistor?** Protects LEDs from excess current

### Step 5: Connect Buzzer
- Positive wire (+) → GPIO 18
- Negative wire (-) → GND

### Step 6: Connect Push Button
- One side → GPIO 16
- Other side → GND

### Step 7: Connect USB Cable
1. Plug USB cable into ESP32 micro-USB port
2. Connect to computer
3. Wait for drivers to install (Windows)
4. Check Device Manager for COM port (Windows) or /dev/ttyUSB0 (Linux/Mac)

---

## Software Setup

### Install Arduino IDE
1. Download from https://www.arduino.cc/en/software
2. Install on your computer
3. Launch Arduino IDE

### Install ESP32 Board Support
1. File → Preferences
2. Under "Additional Boards Manager URLs", paste:
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

Code
3. Click OK
4. Tools → Board → Boards Manager
5. Search "ESP32"
6. Install "ESP32 by Espressif Systems"
7. Tools → Board → Choose "ESP32 Dev Module"

### Install Required Libraries
1. Sketch → Include Library → Manage Libraries
2. Search and install:
- "Adafruit SSD1306" by Adafruit
- "Adafruit GFX Library" by Adafruit
- "MAX30100lib" by OXullo Intersecans

### Upload Code
1. Open `src/heart-rate-monitor/heart-rate-monitor.ino`
2. Tools → Port → Select your COM port
3. Sketch → Upload (Ctrl+U)
4. Wait for "Upload complete" message

### Test the System
1. Open Tools → Serial Monitor
2. Set baud rate to 115200
3. See initialization messages
4. Place finger on MAX30100 sensor
5. Watch heart rate readings on OLED and Serial Monitor

---

## Troubleshooting

### OLED Display Not Working
**Symptom:** "OLED initialization failed"
- Check I2C address (should be 0x3C)
- Verify SDA connected to GPIO 21, SCL to GPIO 22
- Look for I2C devices: Tools → Serial Monitor, see device list

### MAX30100 Not Working
**Symptom:** "FAILED to initialize MAX30100"
- Ensure finger placed properly on sensor
- Check power and ground connections
- Verify I2C address (0x57)
- Try sensor in different light conditions

### Buzzer Always On
**Symptom:** Buzzer won't stop
- Check GPIO 18 connection
- Verify button press works
- Restart ESP32

### LEDs Not Lighting
**Symptom:** Red/Green LEDs don't turn on
- Verify resistors connected (220Ω)
- Check LED polarity (longer leg to GPIO)
- Test with different GPIO pins

---

**Need Help?**
- Check serial monitor for error messages
- Refer to component datasheets
- Contact: Master-QAT on GitHub

