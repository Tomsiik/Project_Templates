/*
 * TomLib_USART.c
 *
 *  Created on: 9. 11. 2017
 *      Author: Tomsik
 */


#include "tm_USART.h"
#include "string.h"
#include "stm32l4xx.h"
#include "stm32l4xx_ll_usart.h"


void USART_putByte(USART_TypeDef *USARTx,char charr){
	while(LL_USART_IsActiveFlag_TXE(USARTx)==0){}
	LL_USART_TransmitData8(USARTx,charr);
}

void USART_printf(USART_TypeDef *USARTx,char charr[]){
	for(int i=0;i<strlen(charr);i++){
		USART_putByte(USARTx,charr[i]);
	}
}

void USART_putBuffer(USART_TypeDef *USARTx,uint8_t data[],uint8_t size){
	for(int i=0;i<size;i++){
		USART_putByte(USARTx,data[i]);
	}
}

USART_result USART_Available(USART_TypeDef *USARTx){
	if (LL_USART_IsActiveFlag_RXNE(USARTx)==1){
		return TRUE;
	}
	else{
		return FALSE;
	}

}

uint8_t USART_ReadByte(USART_TypeDef *USARTx){
	return LL_USART_ReceiveData8(USARTx);

}
