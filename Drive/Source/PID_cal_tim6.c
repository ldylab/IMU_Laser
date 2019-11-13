#include "stdAfx.h"

int timer_count = 0; 
float increase_angle, angle_sum;
float angle_last = 0;
float angle_rate;
int sum_init = 1;
extern float angleZ_init;

void TIM6_IRQHandler(void)  //TIM6中断 编码器电机计数 PID计算
{
	if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源 
	{
		TIM_ClearITPendingBit(TIM6, TIM_IT_Update);  //清除TIMx的中断待处理位:TIM 中断源 
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
