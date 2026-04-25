# 2-Axis Stabilization Gimbal 🤖

A real-time stabilization system using an Arduino Uno, MPU6050, and two Servo motors.

## ⚙️ How to Use
1. **Physical Build:** Connect the MPU6050 and Servos as per the diagram below.
2. **Library:** Install `MPU6050_tockn` via Library Manager.
3. **Calibration:** Keep the sensor flat and still during power-up for the first 3 seconds.

## 🔌 Wiring
- **MPU6050:** SDA -> A4, SCL -> A5, VCC -> 5V, GND -> GND
- **Pitch Servo (X):** Signal -> Pin 3
- **Roll Servo (Y):** Signal -> Pin 5
