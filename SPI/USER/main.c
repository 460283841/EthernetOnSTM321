/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ����3.5.0�汾���Ĺ���ģ�塣         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "stm32f10x_spi.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"

#define SPI_Writedate  0x7A	  //д����ָ��
#define SPI_Raeaddate  0x3A	  //������ָ��

void USART1_Config(void);
void SPI_enc28j60_Init(void);
void EXIT_PC2_config(void);

/* 
 * ��������main
 * ����  : ������
 * ����  ����
 * ���  : ��
 */
int main(void)
{   USART1_Config();
    SPI_enc28j60_Init();
    EXIT_PC2_config();

	 SPI_SendData(SPI1, SPI_Writedate);
	 SPI_SendData(SPI1, 0xA5);
   /*if(FlagStatus SPI_GetFlagStatus(SPI1, SPI_FLAG_RXNE)=1)
   	 {
	 SPI_SendData(SPI1, SPI_Raeaddate);
	 u16 ReceivedData;
     ReceivedData = SPI_ReceiveData(SPI1);
  	 USART_SendData(USART1, ReceivedData );
	 SPI_ClearFlag(SPI2, SPI_FLAG_OVR);
	 } */
	 while(1)
          {
          }

}

void EXIT_PC2_config(void)
{GPIO_InitTypeDef GPIO_InitStructure;
 EXIT_InitTypeDef EXIT_InitStructure;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
 NVIC_Configuration();
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
 GPIO_Init(GPIOC, &GPIO_InitStructure);


 GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource2);
 EXTI_InitStructure.EXTI_Line = EXTI_Line2;
 EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
 EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½����ж�
 EXTI_InitStructure.EXTI_LineCmd = ENABLE;
 EXTI_Init(&EXTI_InitStructure);
 
}

   static void NVIC_Configuration(void)
   {
 NVIC_InitTypeDef NVIC_InitStructure;
 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
 NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
 NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
 NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
 NVIC_Init(&NVIC_InitStructure);
 }
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/


