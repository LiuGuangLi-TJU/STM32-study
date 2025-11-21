
#ifndef __USART_H
#define __USART_H

#include "stdio.h"
#include "sys/sys.h"
#include "stm32f1xx_hal_uart.h"

/******************************************************************************************/

#define USART_TX_GPIO_PORT                  GPIOA
#define USART_TX_GPIO_PIN                   GPIO_PIN_9
#define USART_TX_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOA_CLK_ENABLE();    /* PA时钟使能 */

#define USART_RX_GPIO_PORT                  GPIOA
#define USART_RX_GPIO_PIN                   GPIO_PIN_10
#define USART_RX_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOA_CLK_ENABLE();   /* PA时钟使能 */

#define USART_UX                            USART1
#define USART_UX_IRQn                       USART1_IRQn
#define USART_UX_IRQHandler                 USART1_IRQHandler
#define USART_UX_CLK_ENABLE()              __HAL_RCC_USART1_CLK_ENABLE() /* USART1 时钟使能 */

/******************************************************************************************/

#define USART_REC_LEN               200         /* 接收缓冲区长度 200 */
#define USART_EN_RX                 1           /* 使能接收 1启用/停止接收0禁用 */
#define RXBUFFERSIZE   1                        /* 缓冲区大小 */

extern UART_HandleTypeDef g_uart1_handle;       /* HAL UART句柄 */

extern uint8_t  g_usart_rx_buf[USART_REC_LEN];  /* 接收缓冲区,长度为USART_REC_LEN。末尾为结束符 */
extern uint16_t g_usart_rx_sta;                 /* 接收状态标志 */
extern uint8_t g_rx_buffer[RXBUFFERSIZE];       /* HAL库USART接收Buffer */


void usart_init(uint32_t bound);                /* 初始化串口 */

#endif


