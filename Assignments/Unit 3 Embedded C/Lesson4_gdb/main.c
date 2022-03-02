
#include <stdint.h>
#include<platform_types.h>


#define SYSCTL_RCGC2_R	        (*(vuint64 *)(0x400FE108))
#define GPIOA_PORTF_DIR_R		(*(vuint64 *)(0x40025400))
#define GPIOA_PORTF_DEN_R		(*(vuint64 *)(0x4002551C))
#define GPIOA_PORTF_DATA_R		(*(vuint64 *)(0x400253FC))
	
int main(){
	vuint32 delay_count ;
	SYSCTL_RCGC2_R=0x20;
	// delay to make sure GPIO is initiliazed and running 
	for (delay_count=0 ; delay_count < 200000 ; delay_count++);
	GPIOA_PORTF_DIR_R |= 1<<3 ;
	GPIOA_PORTF_DEN_R |= 1<<3 ;
	while (1)
	{
		GPIOA_PORTF_DATA_R  |= 1<<3 ;
		for (delay_count=0 ; delay_count < 200000 ; delay_count++);
		GPIOA_PORTF_DATA_R &= ~(1<<3) ;
		for (delay_count=0 ; delay_count < 200000 ; delay_count++);
	}
	
	return 0;
}
