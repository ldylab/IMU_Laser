#include "stdAfx.h"

struct GYROs gyro = {.yaw_init=90};	//起始角度在这里改！从结构体中获取数据

void uart2_init(u32 bound){
	//GPIO端口设置
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	//USART1_TX   GPIOA.2
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //PA.2
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.2
	   
	//USART1_RX	  GPIOA.3初始化
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//PA.3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.3 
	
    //USART 初始化设置
	USART_InitStructure.USART_BaudRate = bound;//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
 
	USART_Init(USART2, &USART_InitStructure); //初始化串口2
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//开启串口接受中断
	USART_Cmd(USART2, ENABLE);                    //使能串口2
}

/*串口3初始化(mpu6050) < uart3_init(填写波特率); >*/
void uart3_init(u32 bound){
	//GPIO端口设置
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	
	//USART3_TX   GPIOB.10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;  
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
    GPIO_Init(GPIOB, &GPIO_InitStructure);  
	   
	//USART3_RX	  GPIOB.11初始化
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
    GPIO_Init(GPIOB, &GPIO_InitStructure); 
	
    //USART 初始化设置
	USART_InitStructure.USART_BaudRate = bound;//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式
 
	USART_Init(USART3, &USART_InitStructure); //初始化串口3
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//开启串口接受中断
	USART_Cmd(USART3, ENABLE);                    //使能串口3
}

/*串口4初始化(Tof) < uart4_init(填写波特率); >*/
void uart4_init(u32 bound){
	//GPIO端口设置
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
	
	//USART4_TX   GPIOC.10
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //PC.10
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
	GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIOC.10
	   
	//USART1_RX	  GPIOC.11初始化
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;//PC.11
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
	GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIOC.11
	
    //USART 初始化设置
	USART_InitStructure.USART_BaudRate = bound;//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

	USART_Init(UART4, &USART_InitStructure); //初始化串口4
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);//开启串口接受中断
	USART_Cmd(UART4, ENABLE);                    //使能串口4
}

void uart5_init(u32 bound){
    //GPIO端口设置
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
        
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);  // GPIO时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5,ENABLE);
    USART_DeInit(UART5);  //复位串口5
     
     //UART5_TX   PC.12
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; //PC.12
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //复用推挽输出
    GPIO_Init(GPIOC, &GPIO_InitStructure); //初始化PC10
   
    //UART5_RX    PD.2
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
    GPIO_Init(GPIOD, &GPIO_InitStructure);  //初始化PD2
  
   //USART 初始化设置
    USART_InitStructure.USART_BaudRate = bound;//一般设置为9600;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
    USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; //收发模式

    USART_Init(UART5, &USART_InitStructure); //初始化串口
    USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);//开启中断
    USART_Cmd(UART5, ENABLE);                    //使能串口 
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
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)//判断接收标志
	{
		rebuf[i++]=USART_ReceiveData(USART2);//读取串口数据，同时清接收标志
		if (rebuf[0]!=0x5a)//帧头不对
			i=0;	
		if ((i==2)&&(rebuf[1]!=0x5a))//帧头不对
			i=0;
	
		if(i>3)//i等于4时，已经接收到数据量字节rebuf[3]
		{
			if(i!=(rebuf[3]+5))//判断是否接收一帧数据完毕
				return;	
			switch(rebuf[2])//接收完毕后处理
			{
				case 0x15:
					if(!Receive_1_ok)//当数据处理完成后才接收新的数据
					{
						memcpy(re_1_Buf_Data,rebuf,8);//拷贝接收到的数据
						Receive_1_ok=1;//接收完成标志
					}
					break;
			
			}
			i=0;//缓存清0
		}
	}
}

u8 re_2_Buf_Data[8]={0},Receive_2_ok=0;

void USART3_IRQHandler(void)
{
	static uint8_t i=0,rebuf[20]={0};
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)//判断接收标志
	{
		rebuf[i++]=USART_ReceiveData(USART3);//读取串口数据，同时清接收标志
		if (rebuf[0]!=0x5a)//帧头不对
			i=0;	
		if ((i==2)&&(rebuf[1]!=0x5a))//帧头不对
			i=0;
	
		if(i>3)//i等于4时，已经接收到数据量字节rebuf[3]
		{
			if(i!=(rebuf[3]+5))//判断是否接收一帧数据完毕
				return;	
			switch(rebuf[2])//接收完毕后处理
			{
				case 0x15:
					if(!Receive_2_ok)//当数据处理完成后才接收新的数据
					{
						memcpy(re_2_Buf_Data,rebuf,8);//拷贝接收到的数据
						Receive_2_ok=1;//接收完成标志
					}
					break;
			}
			i=0;//缓存清0
		}
	}
}

u8 re_3_Buf_Data[8]={0},Receive_3_ok=0;

void UART4_IRQHandler(void)
{
	static uint8_t i=0,rebuf[20]={0};
	if(USART_GetITStatus(UART4, USART_IT_RXNE) != RESET)//判断接收标志
	{
		rebuf[i++]=USART_ReceiveData(UART4);//读取串口数据，同时清接收标志
		if (rebuf[0]!=0x5a)//帧头不对
			i=0;	
		if ((i==2)&&(rebuf[1]!=0x5a))//帧头不对
			i=0;
	
		if(i>3)//i等于4时，已经接收到数据量字节rebuf[3]
		{
			if(i!=(rebuf[3]+5))//判断是否接收一帧数据完毕
				return;	
			switch(rebuf[2])//接收完毕后处理
			{
				case 0x15:
					if(!Receive_3_ok)//当数据处理完成后才接收新的数据
					{
						memcpy(re_3_Buf_Data,rebuf,8);//拷贝接收到的数据
						Receive_3_ok=1;//接收完成标志
					}
					break;
			}
			i=0;//缓存清0
		}
	}
}

u8 re_4_Buf_Data[8]={0},Receive_4_ok=0;

void UART5_IRQHandler(void)
{
	static uint8_t i=0,rebuf[20]={0};
	if(USART_GetITStatus(UART5, USART_IT_RXNE) != RESET)//判断接收标志
	{
		rebuf[i++]=USART_ReceiveData(UART5);//读取串口数据，同时清接收标志
		if (rebuf[0]!=0x5a)//帧头不对
			i=0;	
		if ((i==2)&&(rebuf[1]!=0x5a))//帧头不对
			i=0;
	
		if(i>3)//i等于4时，已经接收到数据量字节rebuf[3]
		{
			if(i!=(rebuf[3]+5))//判断是否接收一帧数据完毕
				return;	
			switch(rebuf[2])//接收完毕后处理
			{
				case 0x15:
					if(!Receive_4_ok)//当数据处理完成后才接收新的数据
					{
						memcpy(re_4_Buf_Data,rebuf,8);//拷贝接收到的数据
						Receive_4_ok=1;//接收完成标志
					}
					break;
			}
			i=0;//缓存清0
		}
	}
}
