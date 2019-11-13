/***
	***************************************************************************
	*	@file  	led.c
	*	@version V1.0.0
	*	@brief   LED�ӿ���غ���
   ***************************************************************************
   *  @description
	*
	*  ��ʼ��LED��IO�ڣ�����Ϊ����������������ٶȵȼ�2M��
	* 	
	***************************************************************************
***/

#include "led.h"  

// ������LED IO�ڳ�ʼ��
//
void LED_Init(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ��
	RCC_APB2PeriphClockCmd ( LED1_CLK | LED2_CLK, ENABLE); 	//��ʼ��GPIOʱ��	
				
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	
	
	//��ʼ�� LED1 ����
	GPIO_InitStructure.GPIO_Pin = LED1_PIN;	 
	GPIO_Init(LED1_PORT, &GPIO_InitStructure);	

	//��ʼ�� LED2 ����
	GPIO_InitStructure.GPIO_Pin = LED2_PIN;	 
	GPIO_Init(LED2_PORT, &GPIO_InitStructure);	
	
	GPIO_ResetBits(LED1_PORT,LED1_PIN);  //IO������͵�ƽ
	GPIO_ResetBits(LED2_PORT,LED2_PIN);  //IO������͵�ƽ	
}

