#ifndef __LASER_H
#define __LASER_H

#include "stdio.h"
#include "stm32f10x.h"

void uart2_init(u32 bound);
void uart3_init(u32 bound);
void uart4_init(u32 bound);
void uart5_init(u32 bound);
void NVIC_Configuration(void);

struct GYROs
{
	float ax;	//���ٶ�
	float ay;
	float az;
	
	float yaw;	//�Ƕ�
	float roll;
	float pitch;
	
	float yaw_init;	//��ʼ�Ƕ�
	float roll_init;
	float pitch_init;
	
	float yaw_bias;	//��ֵ
	float roll_bias;
	float pitch_bias;
};

extern struct GYROs gyro;

#define UART4_REC_LEN  		200  	//�����������ֽ��� 200
#define EN_UART4_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����

extern u8 re_1_Buf_Data[8],Receive_1_ok;
extern u8 re_2_Buf_Data[8],Receive_2_ok;
extern u8 re_3_Buf_Data[8],Receive_3_ok;
extern u8 re_4_Buf_Data[8],Receive_4_ok;
extern float angle_x, angle_y, angle_z;

#endif 
