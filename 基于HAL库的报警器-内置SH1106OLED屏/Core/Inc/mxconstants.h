/**
  ******************************************************************************
  * File Name          : mxconstants.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MXCONSTANT_H
#define __MXCONSTANT_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

/*********************OLED Pin define****************/
#define OLED_CLK_Pin GPIO_PIN_1
#define OLED_CLK_GPIO_Port GPIOA

#define OLED_DIN_Pin GPIO_PIN_2
#define OLED_DIN_GPIO_Port GPIOA

#define OLED_RES_Pin GPIO_PIN_3
#define OLED_RES_GPIO_Port GPIOA

#define OLED_DC_Pin GPIO_PIN_4
#define OLED_DC_GPIO_Port GPIOA

#define OLED_CS_Pin GPIO_PIN_5
#define OLED_CS_GPIO_Port GPIOA


/*********************SR602 Pin define*****************/

#define SR602_input_Pin GPIO_PIN_6
#define SR602_input_GPIO_Port GPIOA



/**********************RGB Pin define*/
#define LED3_Pin GPIO_PIN_9
#define LED3_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_8
#define LED2_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_7
#define LED1_GPIO_Port GPIOC

/*LED3 Pin 红色led*/
#define LED3_ON()     HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET)
#define LED3_OFF()    HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET)
#define LED3_Toggle() HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);

/*LED2 Pin 绿色led*/
#define LED2_ON()     HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET)
#define LED2_OFF()    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET)
#define LED2_Toggle() HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);

/*LED1 Pin 蓝色led*/
#define LED1_ON()     HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET)
#define LED1_OFF()    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET)
#define LED1_Toggle() HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t

/*KEY1 Pin configuration*/
#define KEY1_GPIO_PIN                 GPIO_PIN_15
#define KEY1_GPIO                     GPIOA


/*Buzz Pin configuration*/
#define Buzz_GPIO_PIN                 GPIO_PIN_7
#define Buzz_GPIO                     GPIOA
/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MXCONSTANT_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
