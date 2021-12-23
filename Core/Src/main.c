/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "string.h"
#include "stdio.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "DS18B20.h"
#include "gps.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
DS18B20_Name DS1;
float Temp;
char msg[50];
char msg1[50];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t Hello[20] = "BC66 with STM32\r\n";
char Rx_Buffer[200];
char Rx_Buffer1[200];
char cmd[50];
char cmd1[50];
char buff[25];

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_TIM4_Init();
	//GPS_Init();
  /* USER CODE BEGIN 2 */
	
	
	
	DS18B20_Init(&DS1, &htim4, DS18B20_GPIO_Port, DS18B20_Pin);
	Temp = DS18B20_ReadTemp(&DS1);
	
		HAL_UART_Transmit(&huart3, Hello, 20, 1000);	
		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
		
		sprintf(cmd,"ATE1\r\n");
		HAL_UART_Transmit(&huart2,(uint8_t *)cmd,strlen(cmd),1000);
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 1000);
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
		
		sprintf(cmd,"ATI\r\n");
		HAL_UART_Transmit(&huart2,(uint8_t *)cmd,strlen(cmd),1000);
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 1000  );
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
		
		sprintf(cmd,"AT+CPSMS=0\r\n");
		HAL_UART_Transmit(&huart2,(uint8_t *)cmd,strlen(cmd),1000);
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 1000  );
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
		
		sprintf(cmd,"AT+QSCLK=0\r\n");
		HAL_UART_Transmit(&huart2,(uint8_t *)cmd,strlen(cmd),1000);
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 1000  );
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
		
		sprintf(cmd,"AT+CEREG=5\r\n");
		HAL_UART_Transmit(&huart2,(uint8_t *)cmd,strlen(cmd),1000);
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 1000  );
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
		
		sprintf(cmd,"AT+CSCON=1\r\n");
		HAL_UART_Transmit(&huart2,(uint8_t *)cmd,strlen(cmd),1000);
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 1000  );
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
		
		sprintf(cmd,"AT+QNBIOTEVENT=1,1\r\n");
		HAL_UART_Transmit(&huart2,(uint8_t *)cmd,strlen(cmd),1000);
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 1000  );
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
		
		sprintf(cmd,"AT+QBAND=1,3\r\n");
		HAL_UART_Transmit(&huart2,(uint8_t *)cmd,strlen(cmd),1000);
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 1000  );
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
		
		sprintf(cmd,"AT+QCGDEFCONT=\"IP\",\"v-internert\"\r\n");
		HAL_UART_Transmit(&huart2,(uint8_t *)cmd,strlen(cmd),1000);
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 1000  );
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
		Temp = DS18B20_ReadTemp(&DS1);
		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
		
		
		HAL_UART_Receive(&huart2, (uint8_t *)Rx_Buffer, 200, 90000);
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
		
		sprintf(cmd,"AT+QMTOPEN=1,\"broker.emqx.io\",1883\r\n");
		HAL_UART_Transmit(&huart2,(uint8_t *)cmd,strlen(cmd),1000);
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 3000);
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
		
		
		sprintf(cmd,"AT+QMTCONN=1,\"Ntap1\"\r\n");
		HAL_UART_Transmit(&huart2,(uint8_t *)cmd,strlen(cmd),1000);
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 3000);
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		Temp = DS18B20_ReadTemp(&DS1);
		HAL_Delay(1000);
		sprintf(msg, "nhiet do hien tai la: %.f\r\n",  Temp);	
		HAL_UART_Transmit(&huart3, (uint8_t*) msg, 30, 100);
	//sprintf(cmd,"AT+QMTPUB=1,0,0,0,\"testtopic/2\",\"{\"name\": \"Xe 2\", \"image\":\"https://files01.danhgiaxe.com/tWhJTvtxHrLNZdRLbnGTxb12NcA=/fit-in/1280x0/20210131/mercedes-benz-s-class-2021-1280-03-172813.jpg\",\"khl\":\"8:30\",\"kht\":\"Ðak Lak\",\"klh\":\"5 tan\",\"sl\":\"4\",\"ten\":\"NTAP\",\"slug\":\"xe-2\",\"vt\":\"12.715888320233693, 108.2441771633039\",\"nd\":\"%.f\"}\"\r\n", Temp);
		sprintf(cmd,"AT+QMTPUB=1,0,0,0,\"nhietdo1\",\"\"%.f\"\"\r\n", Temp);
		HAL_UART_Transmit(&huart2, (uint8_t*) cmd, strlen(cmd), 1000);
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 1000);
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
	
		memset(msg,0,sizeof(msg));
		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
		sprintf(msg, "Gui dia chi:");
		HAL_UART_Transmit(&huart3,(uint8_t *)msg, 50, 1000);
		HAL_UART_Receive(&huart3,(uint8_t *)buff, 25, 10000);
		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
		HAL_UART_Transmit(&huart3,(uint8_t *)buff, 25, 1000);
		sprintf(cmd,"AT+QMTPUB=1,0,0,0,\"vitri1\",\"\"%s\"\"\r\n", buff);
		HAL_UART_Transmit(&huart2, (uint8_t*) cmd, strlen(cmd), 1000);			
		HAL_UART_Receive (&huart2,(uint8_t *)Rx_Buffer, 200, 1000);
		HAL_UART_Transmit(&huart3,(uint8_t *)Rx_Buffer, 200, 1000);
		memset(Rx_Buffer,0,sizeof(Rx_Buffer));
		HAL_Delay(1000);
		
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
