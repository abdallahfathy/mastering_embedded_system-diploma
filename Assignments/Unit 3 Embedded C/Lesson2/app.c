#include "uart.h"
unsigned char str [100] = "learn in depth : Abdallah "; 
void main ()
{ 
	UART_SendString (str);
}