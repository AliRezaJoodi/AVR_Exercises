#include <avr/io.h>
#include <util/delay.h>
#include "utility_bit.h"

int main(void){
	SET_BIT(DDRA, 0);

	while (1){
		TOGGLE_BIT(PORTA, 0);
		_delay_ms(500);
	}
}