/*
 * TomLib_SYS.h
 *
 *  Created on: 21. 10. 2017
 *      Author: Tomsik
 */

#ifndef TOMLIB_SYS_H_
#define TOMLIB_SYS_H_

#include "stdint.h"
#include "stm32l4xx.h"


void uDelay(__IO uint32_t time);
void mDelay(__IO uint32_t time);
void TIM6_Init(void);
void TIM6_Delay(uint32_t time);
void SystemClock_Config();



#endif /* TOMLIB_SYS_H_ */
