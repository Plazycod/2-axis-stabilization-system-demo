#include <Arduino.h>
#include <Wire.h>
#include <MPU6050_tockn.h>
#include <Servo.h>

MPU6050 mpu6050(Wire);

Servo servoX; // Pitch servo
Servo servoY; // Roll servo

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  mpu6050.begin();
  
  // Keep the sensor still during setup!
  Serial.println("Calibrating... do not move the MPU6050");
  mpu6050.calcGyroOffsets(true); 
  
  servoX.attach(3);
  servoY.attach(5);
  
  // Center the servos initially
  servoX.write(90);
  servoY.write(90);
}

void loop() {
  mpu6050.update();

  // Get Angle values (-90 to 90 degrees typically)
  int angleX = mpu6050.getAngleX();
  int angleY = mpu6050.getAngleY();

  // Map the sensor tilt to servo movement (0-180)
  // We subtract the angle from 90 to create the "counter-movement"
  int servoXPos = 90 - angleX;
  int servoYPos = 90 + angleY;

  // Constrain values to prevent servo damage
  servoXPos = constrain(servoXPos, 0, 180);
  servoYPos = constrain(servoYPos, 0, 180);

  // Write to servos
  servoX.write(servoXPos);
  servoY.write(servoYPos);

  // Debugging
  Serial.print("X: "); Serial.print(angleX);
  Serial.print(" | Y: "); Serial.println(angleY);
  
  delay(10); // Small delay for stability
}