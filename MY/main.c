/***
	***************************************************************************
	*	@file  	 main.c
	*	@version V1.0
	* @date    2017-8-1		
	*	@author  Henry
	*	@brief   �Ŷ����ܰ����
   ***************************************************************************
   *  @description
	***************************************************************************
***/

#include "stdAfx.h"

float angleZ_init_state = 1;
float angleZ_init = 0;
float angleZ_turning = 0;
float angleZ_now;
extern float angle_sum;
extern float angle_rate;

int main(void)
{
	u8 sum=0,i=0;
	u8 RangeStatus=0,Time=0,Mode=0;
	int16_t data=0;
	uint16_t distance_1=0;
	uint16_t distance_2=0;
	uint16_t distance_3=0;
	uint16_t distance_4=0;
	float X_dis, Y_dis;
	
	Delay_Init(); //��ʱ����
  Usart_Config(); //���ڴ򿪣�֧��ֱ��ʹ�ùٷ���DAP��
	LED_Init(); //һ����������(LED1_ON, LED2_OFF)
  KEY_Init(); //��������
	uart2_init(9600);	            //=====���ڳ�ʼ��
	uart3_init(9600);	            //=====���ڳ�ʼ��
	uart4_init(9600);	            //=====���ڳ�ʼ��
	uart5_init(9600);
	NVIC_Configuration();
	TIM6_Int_Init(19, 7199);

	while(1)
	{		
		if(Receive_1_ok)//���ڽ������
		{
			for(sum=0,i=0;i<(re_1_Buf_Data[3]+4);i++)//rgb_data[3]=3
			sum+=re_1_Buf_Data[i];
			if(sum==re_1_Buf_Data[i])//У����ж�
			{
				distance_1 = re_1_Buf_Data[4]<<8|re_1_Buf_Data[5];
				//printf("Distance1 is = %d\r\n", distance_1);
				//printf("Angle_Z = %f\r\n", angleZ_now);
			}
			Receive_1_ok=0;//����������ϱ�־
		}
		
		if(Receive_2_ok)//���ڽ������
		{
			for(sum=0,i=0;i<(re_2_Buf_Data[3]+4);i++)//rgb_data[3]=3
			sum+=re_2_Buf_Data[i];
			if(sum==re_2_Buf_Data[i])//У����ж�
			{
				distance_2 = re_2_Buf_Data[4]<<8|re_2_Buf_Data[5];
				//printf("Distance2 is = %d\r\n", distance_2);
				//printf("RATE = %f\r\n", fabs(cos(angleZ_now*3.14156/(float)180)));
			}
			Receive_2_ok=0;//����������ϱ�־
		}
		
		if(Receive_3_ok)//���ڽ������
		{
			for(sum=0,i=0;i<(re_3_Buf_Data[3]+4);i++)//rgb_data[3]=3
			sum+=re_3_Buf_Data[i];
			if(sum==re_3_Buf_Data[i])//У����ж�
			{
				distance_3 = re_3_Buf_Data[4]<<8|re_3_Buf_Data[5];
				//printf("Distance3 is = %d\r\n", distance_3);
				//printf("RATE = %f\r\n", fabs(cos(angleZ_now*3.14156/(float)180)));
			}
			Receive_3_ok=0;//����������ϱ�־
		}
		
		if(Receive_4_ok)//���ڽ������
		{
			for(sum=0,i=0;i<(re_4_Buf_Data[3]+4);i++)//rgb_data[3]=3
			sum+=re_4_Buf_Data[i];
			if(sum==re_4_Buf_Data[i])//У����ж�
			{
				distance_4 = re_4_Buf_Data[4]<<8|re_4_Buf_Data[5];
				//printf("Distance4 is = %d\r\n", distance_4);
				//printf("RATE = %f\r\n", fabs(cos(angleZ_now*3.14156/(float)180)));
			}
			Receive_4_ok=0;//����������ϱ�־
		}
		printf("[%d,%d,%d,%d,%d]", distance_1, distance_2, distance_3, distance_4, (distance_1+distance_2+distance_3+distance_4));
		Delay_ms(10);
	}
}

