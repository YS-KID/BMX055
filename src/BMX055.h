#ifndef _BMX055_h
#define _BMX055_h

#define Addr_Accl 0x19  // (JP1,JP2,JP3 = Open)

#define Addr_Gyro 0x69  // (JP1,JP2,JP3 = Open)

#define Addr_Mag 0x13   // (JP1,JP2,JP3 = Open)
#define GRYO 1
#define ACCL 2
#define MAG 3
#define XYZ_ROTATION 4

extern float xAccl;
extern float yAccl;
extern float zAccl;
extern float xGyro;
extern float yGyro;
extern float zGyro;
extern float   xMag;
extern float   yMag;
extern float   zMag;
extern float  roll;
extern float  pitch;
extern float  yaw;

void BMX055_Init();
void BMX055_Accl();
void BMX055_Gyro();
void BMX055_Mag();

#endif
