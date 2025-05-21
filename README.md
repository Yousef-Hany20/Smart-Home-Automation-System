# Smart Environmental Control System 

A smart embedded system that automatically controls lighting and fan speed based on real-time temperature and light intensity readings, with flame detection for critical safety alerts.

---

##  Features

- **Automatic Lighting Control** based on ambient light intensity (LDR sensor).
- **Fan Speed Control** based on temperature readings from the LM35 sensor.
- **Flame Detection & Alert System** using a flame sensor and buzzer for emergencies.
- **Real-Time Monitoring** displayed on an LCD screen:
  - Current Temperature
  - Light Intensity (as a percentage)
  - Fan status (ON/OFF)
  - Flame alerts

---

##  Drivers Used

- **GPIO** – for controlling LEDs, buzzer, and sensors.
- **ADC** – to read analog values from LM35 and LDR.
- **PWM** – for controlling DC motor speed (fan).
- **LM35 Sensor** – for temperature measurement.
- **LDR Sensor** – for ambient light intensity detection.
- **Flame Sensor** – for fire/flame detection.
- **LCD** – for displaying real-time data and alerts.
- **Buzzer** – for flame detection alert.
- **DC Motor** – represents a fan controlled by PWM based on temperature.

---

## Hardware & Tools

- **Microcontroller:** ATmega32
- **Development Tools:** Atmel Studio / AVR-GCC / Proteus for simulation

---

## Logic Summary

### Lighting Logic
| Light Intensity (%) | RED | GREEN | BLUE |
|---------------------|-----|--------|------|
| ≤ 15                | ON  | ON     | ON   |
| 16 – 50             | ON  | ON     | OFF  |
| 51 – 70             | ON  | OFF    | OFF  |
| > 70                | OFF | OFF    | OFF  |

### Fan Speed Logic (Temperature in °C)
| Temperature | Fan Speed | LCD Message |
|-------------|-----------|-------------|
| < 25        | 0%        | FAN is OFF  |
| 25 – 29     | 25%       | FAN is ON   |
| 30 – 34     | 50%       | FAN is ON   |
| 35 – 39     | 75%       | FAN is ON   |
| ≥ 40        | 100%      | FAN is ON   |

### Flame Detection
- If a flame is detected:
  - Buzzer is turned ON
  - LCD displays: **"Critical alert!"**
  - System waits until flame disappears

---

 ## Display Format

- Line 0: [FAN is ON / OFF] ← Fan status or alert
- Line 1: Temp=XX  LDR=YY % ← Sensor readings

 ## File Structure

- main.c              → Main system logic  
- Buzzer.c / Buzzer.h → Buzzer driver  
- LED.c / LED.h       → LED control driver  
- LDR.c / LDR.h       → Light intensity sensor  
- lm35_sensor.c / .h  → Temperature sensor  
- adc.c / adc.h       → Analog-to-digital converter  
- Flame_Sensor.c / .h → Flame detection  
- DC_Motor.c / .h     → Fan (DC motor) control  
- lcd.c / lcd.h       → LCD display  

---

## Author

**Yousef** – Project developed for the **Standard Embedded Diploma** course.

---

## License

This project is open-source and available under the [MIT License](LICENSE).
