#include "stdAfx.h"

struct GYROs gyro = {.yaw_init=90};	//��ʼ�Ƕ�������ģ��ӽṹ���л�ȡ����

void uart2_init(u32 bound){
	//GPIO�˿�����
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	//USART1_TX   GPIOA.2
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //PA.2
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.2
	   
	//USART1_RX	  GPIOA.3��ʼ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//PA.3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.3 
	
    //USART ��ʼ������
	USART_InitStructure.USART_BaudRate = bound;//���ڲ�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
 
	USART_Init(USART2, &USART_InitStructure); //��ʼ������2
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
	USART_Cmd(USART2, ENABLE);                    //ʹ�ܴ���2
}

/*����3��ʼ��(mpu6050) < uart3_init(��д������); >*/
void uart3_init(u32 bound){
	//GPIO�˿�����
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	
	//USART3_TX   GPIOB.10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;  
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
    GPIO_Init(GPIOB, &GPIO_InitStructure);  
	   
	//USART3_RX	  GPIOB.11��ʼ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
    GPIO_Init(GPIOB, &GPIO_InitStructure); 
	
    //USART ��ʼ������
	USART_InitStructure.USART_BaudRate = bound;//���ڲ�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
 
	USART_Init(USART3, &USART_InitStructure); //��ʼ������3
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
	USART_Cmd(USART3, ENABLE);                    //ʹ�ܴ���3
}

/*����4��ʼ��(Tof) < uart4_init(��д������); >*/
void uart4_init(u32 bound){
	//GPIO�˿�����
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
	
	//USART4_TX   GPIOC.10
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //PC.10
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIOC.10
	   
	//USART1_RX	  GPIOC.11��ʼ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;//PC.11
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIOC.11
	
    //USART ��ʼ������
	USART_InitStructure.USART_BaudRate = bound;//���ڲ�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ

	USART_Init(UART4, &USART_InitStructure); //��ʼ������4
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
	USART_Cmd(UART4, ENABLE);                    //ʹ�ܴ���4
}

void uart5_init(u32 bound){
    //GPIO�˿�����
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
        
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);  // GPIOʱ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5,ENABLE);
    USART_DeInit(UART5);  //��λ����5
     
     //UART5_TX   PC.12
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; //PC.12
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�����������
    GPIO_Init(GPIOC, &GPIO_InitStructure); //��ʼ��PC10
   
    //UART5_RX    PD.2
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
    GPIO_Init(GPIOD, &GPIO_InitStructure);  //��ʼ��PD2
  
   //USART ��ʼ������
    USART_InitStructure.USART_BaudRate = bound;//һ������Ϊ9600;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; //�շ�ģʽ

    USART_Init(UART5, &USART_InitStructure); //��ʼ������
    USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);//�����ж�
    USART_Cmd(UART5, ENABLE);                    //ʹ�ܴ��� 
}

void NVIC_Configuration(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
    NVIC_SetPriority (SysTick_IRQn, 0);
   
//    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
//		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
//		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
//		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
//		NVIC_Init(&NVIC_InitStructure);  
//   
//    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  
//		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  
//		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  
//		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
//		NVIC_Init(&NVIC_InitStructure); 

//		NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
//		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//		NVIC_Init(&NVIC_InitStructure);          

		NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;         
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;   
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;    
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;     
		NVIC_Init(&NVIC_InitStructure);                            

		NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;         
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;    
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;     
		NVIC_Init(&NVIC_InitStructure);  
		
		NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;         
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;    
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;     
		NVIC_Init(&NVIC_InitStructure);  
		
		NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;         
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;    
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;     
		NVIC_Init(&NVIC_InitStructure); 

		NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;         
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;    
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;     
		NVIC_Init(&NVIC_InitStructure);  
//		
//		NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;         
//		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   
//		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;    
//		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;     
//		NVIC_Init(&NVIC_InitStructure);  

//    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn ;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);

//    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);   
}

u8 re_1_Buf_Data[8]={0},Receive_1_ok=0;

void USART2_IRQHandler(void)
{
	static uint8_t i=0,rebuf[20]={0};
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)//�жϽ��ձ�־
	{
		rebuf[i++]=USART_ReceiveData(USART2);//��ȡ�������ݣ�ͬʱ����ձ�־
		if (rebuf[0]!=0x5a)//֡ͷ����
			i=0;	
		if ((i==2)&&(rebuf[1]!=0x5a))//֡ͷ����
			i=0;
	
		if(i>3)//i����4ʱ���Ѿ����յ��������ֽ�rebuf[3]
		{
			if(i!=(rebuf[3]+5))//�ж��Ƿ����һ֡�������
				return;	
			switch(rebuf[2])//������Ϻ���
			{
				case 0x15:
					if(!Receive_1_ok)//�����ݴ�����ɺ�Ž����µ�����
					{
						memcpy(re_1_Buf_Data,rebuf,8);//�������յ�������
						Receive_1_ok=1;//������ɱ�־
					}
					break;
			
			}
			i=0;//������0
		}
	}
}

u8 re_2_Buf_Data[8]={0},Receive_2_ok=0;

void USART3_IRQHandler(void)
{
	static uint8_t i=0,rebuf[20]={0};
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)//�жϽ��ձ�־
	{
		rebuf[i++]=USART_ReceiveData(USART3);//��ȡ�������ݣ�ͬʱ����ձ�־
		if (rebuf[0]!=0x5a)//֡ͷ����
			i=0;	
		if ((i==2)&&(rebuf[1]!=0x5a))//֡ͷ����
			i=0;
	
		if(i>3)//i����4ʱ���Ѿ����յ��������ֽ�rebuf[3]
		{
			if(i!=(rebuf[3]+5))//�ж��Ƿ����һ֡�������
				return;	
			switch(rebuf[2])//������Ϻ���
			{
				case 0x15:
					if(!Receive_2_ok)//�����ݴ�����ɺ�Ž����µ�����
					{
						memcpy(re_2_Buf_Data,rebuf,8);//�������յ�������
						Receive_2_ok=1;//������ɱ�־
					}
					break;
			}
			i=0;//������0
		}
	}
}

u8 re_3_Buf_Data[8]={0},Receive_3_ok=0;

void UART4_IRQHandler(void)
{
	static uint8_t i=0,rebuf[20]={0};
	if(USART_GetITStatus(UART4, USART_IT_RXNE) != RESET)//�жϽ��ձ�־
	{
		rebuf[i++]=USART_ReceiveData(UART4);//��ȡ�������ݣ�ͬʱ����ձ�־
		if (rebuf[0]!=0x5a)//֡ͷ����
			i=0;	
		if ((i==2)&&(rebuf[1]!=0x5a))//֡ͷ����
			i=0;
	
		if(i>3)//i����4ʱ���Ѿ����յ��������ֽ�rebuf[3]
		{
			if(i!=(rebuf[3]+5))//�ж��Ƿ����һ֡�������
				return;	
			switch(rebuf[2])//������Ϻ���
			{
				case 0x15:
					if(!Receive_3_ok)//�����ݴ�����ɺ�Ž����µ�����
					{
						memcpy(re_3_Buf_Data,rebuf,8);//�������յ�������
						Receive_3_ok=1;//������ɱ�־
					}
					break;
			}
			i=0;//������0
		}
	}
}

u8 re_4_Buf_Data[8]={0},Receive_4_ok=0;

void UART5_IRQHandler(void)
{
	static uint8_t i=0,rebuf[20]={0};
	if(USART_GetITStatus(UART5, USART_IT_RXNE) != RESET)//�жϽ��ձ�־
	{
		rebuf[i++]=USART_ReceiveData(UART5);//��ȡ�������ݣ�ͬʱ����ձ�־
		if (rebuf[0]!=0x5a)//֡ͷ����
			i=0;	
		if ((i==2)&&(rebuf[1]!=0x5a))//֡ͷ����
			i=0;
	
		if(i>3)//i����4ʱ���Ѿ����յ��������ֽ�rebuf[3]
		{
			if(i!=(rebuf[3]+5))//�ж��Ƿ����һ֡�������
				return;	
			switch(rebuf[2])//������Ϻ���
			{
				case 0x15:
					if(!Receive_4_ok)//�����ݴ�����ɺ�Ž����µ�����
					{
						memcpy(re_4_Buf_Data,rebuf,8);//�������յ�������
						Receive_4_ok=1;//������ɱ�־
					}
					break;
			}
			i=0;//������0
		}
	}
}
