#include "BMX055.h"
#include <Wire.h>
#include <MadgwickAHRS.h>
Madgwick MadgwickFilter;

#define DEBUG_PITCH

void setup() {
  Wire.begin();
  Serial.begin(115200);
  BMX055_Init();
  delay(300);
  MadgwickFilter.begin(10);
}

void loop() {
  BMX055_Gyro();
  BMX055_Accl();
  BMX055_Mag();
  MadgwickFilter.update(xGyro, yGyro, zGyro, xAccl, yAccl, zAccl, xMag, yMag, zMag);
  roll  = MadgwickFilter.getRoll();
  pitch = MadgwickFilter.getPitch();
  yaw   = MadgwickFilter.getYaw();

#ifdef DEBUG_ROLL
  Serial.println(roll);
  delay(50);
#endif

#ifdef DEBUG_PITCH
  Serial.println(pitch);
  delay(50);
#endif

#ifdef DEBUG_YAW
  Serial.println(yaw);
  delay(50);
#endif
}
