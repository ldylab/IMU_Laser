#include "stdAfx.h"

int timer_count = 0; 
float increase_angle, angle_sum;
float angle_last = 0;
float angle_rate;
int sum_init = 1;
extern float angleZ_init;

void TIM6_IRQHandler(void)  //TIM6�ж� ������������� PID����
{
	if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET) //���ָ����TIM�жϷ������:TIM �ж�Դ 
	{
		TIM_ClearITPendingBit(TIM6, TIM_IT_Update);  //���TIMx���жϴ�����λ:TIM �ж�Դ 
//		if(sum_init == 1)
//		{
//			angle_last = angle_z;
//			sum_init = 0;
//		}
//		increase_angle = angle_z - angle_last;
//		if(increase_angle >= 300)
//		{
//			increase_angle = increase_angle - 360;
//		}
//		else if(increase_angle <= -300)
//		{
//			increase_angle = increase_angle + 360;
//		}
//		else
//		{
//			increase_angle = increase_angle;
//		}
//		angle_sum = angle_sum + increase_angle;
//		angle_rate = angle_sum / 360;
//		angle_last = angle_z;
	}
}
