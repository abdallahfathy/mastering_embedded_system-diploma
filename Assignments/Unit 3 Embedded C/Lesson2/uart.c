#include "uart.h"
//define uart data register  
#define UARTODR *((volatile unsigned int * const )((unsigned int*)0x101f1000))

void UART_SendString (unsigned char * ptr_string)
{
	while (*ptr_string != '\0')
	{
		UARTODR=(unsigned int)*ptr_string;
		ptr_string ++;		
	}

}