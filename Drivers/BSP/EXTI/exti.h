#ifndef __EXTI_H__
#define __EXTI_H__  
#include "sys/sys.h"

//KEY_0引脚定义
#define KEY_0_GPIO_PORT            GPIOE
#define KEY_0_GPIO_PIN             GPIO_PIN_4
//引脚时钟使能
#define KEY_0_INT_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOE_CLK_ENABLE()
#define KEY_0_EXTI_IRQn            EXTI4_IRQn
#define KEY_0_EXTI_IRQHandler      EXTI4_IRQHandler

//KEY_1引脚定义
#define KEY_1_GPIO_PORT            GPIOE
#define KEY_1_GPIO_PIN             GPIO_PIN_3
//引脚时钟使能
#define KEY_1_INT_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOE_CLK_ENABLE()
#define KEY_1_EXTI_IRQn            EXTI3_IRQn
#define KEY_1_EXTI_IRQHandler      EXTI3_IRQHandler

//WAKE_UP引脚定义
#define WAKE_UP_GPIO_PORT          GPIOA
#define WAKE_UP_GPIO_PIN           GPIO_PIN_0
//引脚时钟使能
#define WAKE_UP_INT_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()
#define WAKE_UP_EXTI_IRQn            EXTI0_IRQn
#define WAKE_UP_EXTI_IRQHandler      EXTI0_IRQHandler

void extix_init(void); //EXTI初始化函数声明

#endif /* __EXTI_H__ */