#include "stm32f4xx.h"
#include "stm32f4xx_tim.h"

void gpioConfig(){
	GPIO_InitTypeDef	GPIOInitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);

	GPIOInitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIOInitStructure.GPIO_OType=GPIO_OType_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
	GPIOInitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_Init(GPIOB,&GPIOInitStructure);
}

void timerConfig(){
	TIM_TimeBaseInitTypeDef	TIMERInitStructure;
	NVIC_InitTypeDef	NVICInitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

	TIMERInitStructure.TIM_ClockDivision=1;
	TIMERInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIMERInitStructure.TIM_Period=11999;
	TIMERInitStructure.TIM_Prescaler=3999;
	TIMERInitStructure.TIM_RepetitionCounter=0;

	TIM_TimeBaseInit(TIM3,&TIMERInitStructure);
	TIM_Cmd(TIM3,ENABLE);

	NVICInitStructure.NVIC_IRQChannel=TIM3_IRQn;
	NVICInitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVICInitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVICInitStructure.NVIC_IRQChannelSubPriority=1;

	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	NVIC_Init(&NVICInitStructure);



}

void TIM3_IRQHandler(){
	GPIO_ToggleBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);

}

int main(void){



  while (1){
	  ///

  }
}
