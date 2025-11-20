#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "sys/sys.h"
#include "exti.h"
#include "LED/led.h"
#include "KEY/key.h"

void extix_init(){
    GPIO_InitTypeDef GPIO_InitStruct;

    /* 使能GPIO时钟 */
    KEY_0_INT_GPIO_CLK_ENABLE();
    KEY_1_INT_GPIO_CLK_ENABLE();
    WAKE_UP_INT_GPIO_CLK_ENABLE();

    /* 配置KEY_0引脚为输入模式，带上拉电阻 */
    GPIO_InitStruct.Pin = KEY_0_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING; // 下降沿触发中断
    GPIO_InitStruct.Pull = GPIO_PULLUP;          // 上拉电阻
    HAL_GPIO_Init(KEY_0_GPIO_PORT, &GPIO_InitStruct);

    /* 配置KEY_1引脚为输入模式，带上拉电阻 */
    GPIO_InitStruct.Pin = KEY_1_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING; // 下降沿触发中断
    GPIO_InitStruct.Pull = GPIO_PULLUP;          // 上拉电阻
    HAL_GPIO_Init(KEY_1_GPIO_PORT, &GPIO_InitStruct);

    /* 配置WAKE_UP引脚为输入模式，带下拉电阻 */
    GPIO_InitStruct.Pin = WAKE_UP_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING; // 上升沿触发中断
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;       // 下拉电阻
    HAL_GPIO_Init(WAKE_UP_GPIO_PORT, &GPIO_InitStruct);

    /* 配置并使能EXTI中断 */
    HAL_NVIC_SetPriority(KEY_0_EXTI_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(KEY_0_EXTI_IRQn);

    HAL_NVIC_SetPriority(KEY_1_EXTI_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(KEY_1_EXTI_IRQn);

    HAL_NVIC_SetPriority(WAKE_UP_EXTI_IRQn, 3, 0);
    HAL_NVIC_EnableIRQ(WAKE_UP_EXTI_IRQn);
}
void KEY_0_EXTI_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY_0_GPIO_PIN);
}

void KEY_1_EXTI_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY_1_GPIO_PIN);
}

void WAKE_UP_EXTI_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(WAKE_UP_GPIO_PIN);
}
/**
 * @brief       EXTI中断回调函数
 * @param       GPIO_Pin: 触发中断的引脚编号
 * @retval      无
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    switch (GPIO_Pin) {
        case KEY_0_GPIO_PIN:
            /* 处理KEY_0中断事件 */
            if( KEY0 == 0 ){
                /* KEY0按下处理代码 */
                LED0_TOGGLE(); // 切换LED0状态
            }
            break;
        case KEY_1_GPIO_PIN:
            /* 处理KEY_1中断事件 */
            if( KEY1 == 0 ){
                /* KEY1按下处理代码 */
                LED1_TOGGLE(); // 切换LED1状态
            }
            break;
        case WAKE_UP_GPIO_PIN:
            /* 处理WAKE_UP中断事件 */
            if( WK_UP == 1 ){
                LED0_TOGGLE(); // 切换LED0状态
                LED1_TOGGLE(); // 切换LED1状态
            }
            break;
    }
}