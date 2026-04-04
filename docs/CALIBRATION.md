# Sensor Calibration Guide

## Overview
The MAX30100 sensor requires proper calibration to ensure accurate heart rate and SpO2 readings.

## Calibration Steps

### 1. Prepare Environment
- Ensure good lighting (not too bright)
- Stable room temperature (20-25°C)
- Calm, seated position
- Clean hands, no nail polish if possible

### 2. Sensor Placement
**Correct Placement:**
- Place index or middle finger on sensor
- Gentle, steady pressure (not too tight)
- Finger should cover sensor opening completely
- Avoid motion and talking during reading

**Avoid:**
- Cold hands (reduce blood flow)
- Nail polish or artificial nails
- Direct sunlight on sensor
- Movement or vibration

### 3. Wait for Stabilization
- Allow **30-60 seconds** for readings to stabilize
- Watch Serial Monitor for consistent values
- Reading is ready when HR stays constant for 10 seconds

### 4. Verify Against Reference
- Compare with clinical pulse oximeter (if available)
- Normal resting HR: 60-100 BPM
- Normal SpO2: 95-100%

**Reference Readings:**
Activity | Normal HR (BPM) | Normal SpO2 (%) Sleeping | 40-60 | 95-100 At rest | 60-100 | 95-100 Light work | 100-130 | 95-100 Exercise | 130-160 | 95-99

Code

### 5. Adjust Thresholds (if needed)
Edit `src/config.h` based on your measurements:

```cpp
#define MIN_HEART_RATE 60       // Adjust for your baseline
#define MAX_HEART_RATE 110      // Adjust for your activity
#define MIN_SPO2 90             // Lower limit (keep ≥85%)
Accuracy Specifications
Expected Performance
Heart Rate Accuracy: ±2-5% under ideal conditions
SpO2 Accuracy: ±4% under ideal conditions
Response Time: 5-10 seconds after placement
Factors Affecting Accuracy
Skin Tone: Darker skin may require adjustments
Nail Polish: Absorbs light, reduces signal
Ambient Light: Bright light interferes
Motion: Movement causes noise
Temperature: Cold hands = reduced blood flow
Finger Size: May affect sensor contact
NOT Medical Accuracy
This is an educational device. Accuracy is NOT comparable to:

Clinical pulse oximeters
Hospital-grade monitors
Medical diagnostic devices
Validation Protocol
Daily Validation
Before each use:

Place finger on sensor
Wait 30-60 seconds for stabilization
Record 3 readings (10 seconds apart)
Average should match your baseline
Weekly Validation
Compare with reference device (if available)
Test at different times of day
Document results in calibration log
Sample Calibration Log
Code
Date: ___________
Time: ___________
Baseline HR: _____ BPM
Max HR observed: _____ BPM
Min SpO2: _____ %
Reference HR: _____ BPM
Difference: _____ BPM
Status: __ PASS  __ NEEDS ADJUSTMENT
Notes: _________________________________
Troubleshooting Calibration Issues
Reading Too High
Ensure moderate pressure only
Increase wait time
Try different finger
Check ambient light
Reading Too Low
Ensure good contact with sensor
Increase finger pressure
Warm hands first
Remove any obstructions
Readings Vary Wildly
Stabilize position
Hold finger still
Reduce ambient light
Remove nail polish
Consistently Off from Reference
Adjust thresholds in code
Verify sensor is genuine MAX30100
Check sensor cleanliness
Consider environmental factors
Advanced: Custom Calibration Routine
Add this function to calibrate per individual:

C++
void calibrateSensor() {
  Serial.println("CALIBRATION MODE");
  Serial.println("Place finger on sensor, keep steady...");
  
  int readings[10];
  for (int i = 0; i < 10; i++) {
    pox.update();
    readings[i] = pox.getHeartRate();
    delay(1000);
  }
  
  int average = 0;
  for (int i = 0; i < 10; i++) {
    average += readings[i];
  }
  average /= 10;
  
  Serial.print("Average HR: ");
  Serial.print(average);
  Serial.println(" BPM");
}
Created by: Qasim Aisha (Master-QAT)
Last Updated: April 2026