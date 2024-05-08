/*
 * RCC.h
 *
 *  Created on: May 8, 2024
 *      Author: Abdo Halem
 */

#ifndef RCC_H_
#define RCC_H_

/* Includes Section */
#include "RCC_CFG.h"

/* Macros Declarations Section */

/* Function like Macros Section */
/* ============ RCC_CR ================= */
#define RCC_PLL_ENABLE()	(SET_BIT(RCC->CR, 24))
#define RCC_PLL_DISABLE()	(CLEAR_BIT(RCC->CR, 24))

#define RCC_CLOCK_SECURITY_ENABLE()		(SET_BIT(RCC->CR, 19))
#define RCC_CLOCK_SECURITY_DISABLE()	(CLEAR_BIT(RCC->CR, 19))

#define RCC_HSE_OSCILLATOR_ENABLE()		(SET_BIT(RCC->CR, 16))
#define RCC_HSE_OSCILLATOR_DISABLE()	(CLEAR_BIT(RCC->CR, 16))

#define RCC_HSI_OSCILLATOR_ENABLE()		(SET_BIT(RCC->CR, 0))
#define RCC_HSI_OSCILLATOR_DISABLE()	(CLEAR_BIT(RCC->CR, 0))
/* ============ End ================= */
/* ============ RCC_CFGR ================= */
#define RCC_MCO_SYSCLK_SELECTED()		(RCC->CFGR |= 100 << 24)
#define RCC_MCO_NO_CLOCK_SELECTED()		(RCC->CFGR &= ~(111 << 24))

#define RCC_PLL_FACTOR_BY_2()		((RCC->CFGR |= 0000 << 18))
#define RCC_PLL_FACTOR_BY_3()		((RCC->CFGR |= 0001 << 18))
#define RCC_PLL_FACTOR_BY_4()		((RCC->CFGR |= 0010 << 18))
#define RCC_PLL_FACTOR_BY_5()		((RCC->CFGR |= 0011 << 18))
#define RCC_PLL_FACTOR_BY_6()		((RCC->CFGR |= 0100 << 18))
#define RCC_PLL_FACTOR_BY_7()		((RCC->CFGR |= 0101 << 18))
#define RCC_PLL_FACTOR_BY_8()		((RCC->CFGR |= 0110 << 18))

#define RCC_HSE_PLL_DIVIDED_BY_2()		(SET_BIT(RCC->CFGR, 17))
#define RCC_HSE_PLL_DIVIDED_BY_1()		(CLEAR_BIT(RCC->CFGR, 17))

#define RCC_PLL_INPUT_HSE()		(SET_BIT(RCC->CFGR, 16))
#define RCC_PLL_INPUT_HSI()		(CLEAR_BIT(RCC->CFGR, 16))

#define RCC_APB2_HCLK_DIVIDED_BY_1()	(RCC->CFGR |= 000 << 11)
#define RCC_APB2_HCLK_DIVIDED_BY_2()	(RCC->CFGR |= 100 << 11)
#define RCC_APB2_HCLK_DIVIDED_BY_4()	(RCC->CFGR |= 101 << 11)
#define RCC_APB2_HCLK_DIVIDED_BY_8()	(RCC->CFGR |= 110 << 11)
#define RCC_APB2_HCLK_DIVIDED_BY_16()	(RCC->CFGR |= 111 << 11)

#define RCC_APB1_HCLK_DIVIDED_BY_1()	(RCC->CFGR |= 000 << 8)
#define RCC_APB1_HCLK_DIVIDED_BY_2()	(RCC->CFGR |= 100 << 8)
#define RCC_APB1_HCLK_DIVIDED_BY_4()	(RCC->CFGR |= 101 << 8)
#define RCC_APB1_HCLK_DIVIDED_BY_8()	(RCC->CFGR |= 110 << 8)
#define RCC_APB1_HCLK_DIVIDED_BY_16()	(RCC->CFGR |= 111 << 8)

#define RCC_AHB_PRESCALER_BY_1()	(RCC->CFGR |= 0000 << 4)
#define RCC_AHB_PRESCALER_BY_2()	(RCC->CFGR |= 1000 << 4)
#define RCC_AHB_PRESCALER_BY_4()	(RCC->CFGR |= 1001 << 4)
#define RCC_AHB_PRESCALER_BY_8()	(RCC->CFGR |= 1010 << 4)
#define RCC_AHB_PRESCALER_BY_16()	(RCC->CFGR |= 1011 << 4)
#define RCC_AHB_PRESCALER_BY_64()	(RCC->CFGR |= 1100 << 4)
#define RCC_AHB_PRESCALER_BY_128()	(RCC->CFGR |= 1101 << 4)
#define RCC_AHB_PRESCALER_BY_256()	(RCC->CFGR |= 1110 << 4)
#define RCC_AHB_PRESCALER_BY_512()	(RCC->CFGR |= 1111 << 4)

#define RCC_SYSTEM_CLOCK_HSI()	(RCC->CFGR |= 00 << 0)
#define RCC_SYSTEM_CLOCK_HSE()	(RCC->CFGR |= 01 << 0)
#define RCC_SYSTEM_CLOCK_PLL()	(RCC->CFGR |= 10 << 0)
/* ============ End ================= */
/* Data Type Declarations Section */

/* Software Interfaces Section */
/**
 * @Ref: Initializing the system clock
 */
void Clock_Init(const SYSCLK_t *clock_source);

#endif /* RCC_H_ */
