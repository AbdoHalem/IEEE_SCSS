/*
 * RCC.c
 *
 *  Created on: May 8, 2024
 *      Author: Abdo Halem
 */


#include "RCC.h"

void Clock_Init(const SYSCLK_t *clock_source){
	if(clock_source->source_oscillator == HSI_OSCILLATOR){
		RCC_HSI_OSCILLATOR_ENABLE();
		RCC_SYSTEM_CLOCK_HSI();
	}
	else if(clock_source->source_oscillator == HSE_OSCILLATOR){
		RCC_HSE_OSCILLATOR_ENABLE();
		RCC_SYSTEM_CLOCK_HSE();
	}

	if(clock_source->PLL_mode == HIGH){
		/* Configure PLL first */
		if(clock_source->source_oscillator == HSI_OSCILLATOR){
			RCC_PLL_INPUT_HSI();	// HSI
		}
		else if(clock_source->source_oscillator == HSE_OSCILLATOR){
			RCC_PLL_INPUT_HSE();
			if(clock_source->HSE_PLL_divider == HIGH){
				RCC_HSE_PLL_DIVIDED_BY_2();
			}
			else if(clock_source->HSE_PLL_divider == LOW){
				RCC_HSE_PLL_DIVIDED_BY_1();
			}
		}
		/* Turn PLL on */
		RCC_PLL_ENABLE();
		/* Select PLL as a clock source */
		RCC_SYSTEM_CLOCK_PLL();
	}
	/* AHB Prescaler */

}
