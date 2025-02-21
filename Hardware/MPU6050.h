#ifndef __MPU6050_H__
#define __MPU6050_H__

void MPU6050_Init(void);
void MPU6050_WriteReg(uint8_t RegAddress,uint8_t Data);
uint8_t MPU6050_ReadReg(uint8_t RegAddress);
void MPU6050_GetValue(int16_t *ACCEL_X,int16_t *ACCEL_Y,int16_t *ACCEL_Z,
						int16_t *GYRO_X,int16_t *GYRO_Y,int16_t *GYRO_Z);

#endif
