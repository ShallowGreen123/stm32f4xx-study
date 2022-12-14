/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : FMC.h
 * Description        : This file provides code for the configuration
 *                      of the FMC peripheral.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FMC_H
#define __FMC_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#define SDRAM_TIMEOUT ((uint32_t)0xFFFF) //??????
#define SDRAM_BANK_ADDR ((uint32_t)0xC0000000)
#define Bank5_SDRAM_ADDR ((u32)(0XC0000000)) // SDRAM???始地???

  /* SDRAM配置参数 */
#define SDRAM_MODEREG_BURST_LENGTH_1 ((u16)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2 ((u16)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4 ((u16)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8 ((u16)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL ((u16)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED ((u16)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2 ((u16)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3 ((u16)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD ((u16)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((u16)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE ((u16)0x0200)

  void
  SDRAM_Init(void);
  void SDRAM_MPU_Config(void);
  u8 SDRAM_Send_Cmd(u8 bankx, u8 cmd, u8 refresh, u16 regval);
  void FMC_SDRAM_WriteBuffer(u8 *pBuffer, u32 WriteAddr, u32 n);
  void FMC_SDRAM_ReadBuffer(u8 *pBuffer, u32 ReadAddr, u32 n);
  void SDRAM_Initialization_Sequence(SDRAM_HandleTypeDef *hsdram);
/* USER CODE END Includes */

extern SDRAM_HandleTypeDef hsdram1;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_FMC_Init(void);
void HAL_SDRAM_MspInit(SDRAM_HandleTypeDef* hsdram);
void HAL_SDRAM_MspDeInit(SDRAM_HandleTypeDef* hsdram);

/* USER CODE BEGIN Prototypes */
  void FMC_SDRAM_WriteBuffer(uint8_t *pBuffer, uint32_t WriteAddr, uint32_t n);
  void FMC_SDRAM_ReadBuffer(u8 *pBuffer, u32 ReadAddr, u32 n);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__FMC_H */

/**
  * @}
  */

/**
  * @}
  */
