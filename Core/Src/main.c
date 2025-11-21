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
  uint8_t len ;  
  uint16_t times = 0; 
  while (1)
  {
    if(g_usart_rx_sta & 0x8000){
      len = g_usart_rx_sta & 0x3fff;
      printf("\r\nmessage:\r\n");
      HAL_UART_Transmit(& g_uart1_handle, (uint8_t *)g_usart_rx_buf, len, 1000);
      while(__HAL_UART_GET_FLAG(& g_uart1_handle, UART_FLAG_TC)!= SET);
      printf("\r\n");
      g_usart_rx_sta = 0;

    }
    else{
      times++;
      if(times % 50 == 0){
        printf("\r\n 实验 \r\n");
      }
      if(times % 20 ==0)  LED0_TOGGLE();
      delay_ms(10);
    }

  }
  
}
