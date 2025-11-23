/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
---------------------------------------------*/
#include "main.h"
#include "LED/led.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LCD/lcd.h"
#include "EXTI/exti.h"
#include "delay/delay.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal_uart.h"
#include "usart/usart.h"
#include <stdint.h>
#include <stdio.h>
/* USER CODE END Includes */


void SystemClock_Config(void);

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{


  HAL_Init();//HAL库初始化
  sys_stm32_clock_init(RCC_PLL_MUL9);// 配置系统时钟
  delay_init(72);// 延时函数初始化,时钟72MHz

  led_init();// LED初始化
  lcd_init();  // LCD初始化
  usart_init(115200);
  uint16_t len =0;
  while (1)
  {
    if(g_usart_rx_sta & 0x8000){
      len = g_usart_rx_sta & 0x3fff;
      if(len==0){
        g_usart_rx_sta = 0;
      }
      if (len < USART_REC_LEN)                     /* 确保以 '\0' 结束（可作为字符串处理） */
         g_usart_rx_buf[len] = '\0';
      if (len == 1 && g_usart_rx_buf[0] == 'A') {
        LED0_TOGGLE();
        printf("ok,toggle led 0\r\n");
      }
      else if (len == 1 && g_usart_rx_buf[0] == 'B') {
        LED1_TOGGLE();
        printf("ok,toggle led 1\r\n");
      }   
      else {
        printf("message wrong\r\n");
      }
    g_usart_rx_sta = 0;
    }

  }
  
}
