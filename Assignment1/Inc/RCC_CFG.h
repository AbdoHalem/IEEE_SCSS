/*
 * RCC_CFG.h
 *
 *  Created on: May 8, 2024
 *      Author: Abdo Halem
 */

#ifndef RCC_CFG_H_
#define RCC_CFG_H_

/* Includes Section */
#include "Std_types.h"

/* Macros Declarations Section */
#define RCC_BASE_ADDRESS	0X40021000

#define HSI_OSCILLATOR	0
#define HSE_OSCILLATOR	1
#define SYSTEM_CLOCK_SOURCE		HSI_OSCILLATOR

#define AHB_PRESCALER  1	// (1, 2, 4, 8, 16, 32, 64, 128, 256, 512)
#define APB1_PRESCALER 1	// (1, 2, 4, 8, 16)
#define APB2_PRESCALER 1	// (1, 2, 4, 8, 16)

#define RCC_PLL_MODE		0

#define HIGH 1
#define LOW 0
/* Function like Macros Section */

/* Data Type Declarations Section */
typedef struct{
	uint32 CR;
	uint32 CFGR;
	uint32 CIR;
	uint32 APB2RSTR;
	uint32 APB1RSTR;
	uint32 AHBENR;
	uint32 APB2ENR;
	uint32 APB1ENR;
	uint32 BDCR;
	uint32 CSR;
}RCC_t;
#define RCC  ((RCC_t*)RCC_BASE_ADDRESS)

typedef struct{
	uint8 source_oscillator : 1;
	uint8 PLL_mode : 1;
	uint8 PLL_factor : 1;
	uint8 HSE_PLL_divider : 1;
	uint8 AHB_prescaler : 1;
	uint8 APB1_prescaler : 1;
	uint8 APB2_prescaler : 1;
	uint8 clock_security : 1;		// Reserved
}SYSCLK_t;

/* Software Interfaces Section */

#endif /* RCC_CFG_H_ */
