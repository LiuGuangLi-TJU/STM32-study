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
  MX_GPIO_Init();// 初始化所有配置的外设GPIO
  led_init();// LED初始化
  extix_init();    // EXTI初始化
  lcd_init();  // LCD初始化

  while (1)
  {
    lcd_show_string(10, 10, 240, 32, 32, "OK", RED);
    delay_ms(1000);
  }
  
}

