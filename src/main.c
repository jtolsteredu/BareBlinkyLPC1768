#include <LPC17xx.h>

/* system_LPC17xx.c sets up the clock thusly:
 *
 * CLKSRCSEL_Val 0x00000001: use the external oscillator (FIN=12MHz)
 * PLL0CFG_Val   0x00050063: N = 6, M = 100
 * CCLKCFG_Val   0x00000003: CCLK = 4;
 *
 * From pp43 of http://www.nxp.com/documents/user_manual/UM10360.pdf
 * we then see:
 *
 * FCCO = (2*M*FIN)/N
 *      = (2*100*12000000)/6 = 400000000
 *
 * Finally, to get the frequency of the CPU clock, we divide by CCLK to
 * get a frequency of 100000000, or 100MHz. So, we'll roughly call a loop
 * of 10000 a ms.
 */
void delay_ms(unsigned int count) {
	volatile unsigned int j = 0, i = 0;
	for (j = 0; j < count; j++) {
		for (i = 0; i < 10000; i++) {
		};
	}
}

/* http://anhnvnguyen.blogspot.com/2010/04/lpc17xx-gpio-basic_05.html
 * has a good write up of selecting pins. The following correspond to
 * LED1-4 on the NXP LPC1768 mbed development board:
 */
#define P1_18_SEL (1 << 5) | (1 << 4)
#define P1_20_SEL (1 << 9) | (1 << 8)
#define P1_21_SEL (1 << 11) | (1 << 10)
#define P1_23_SEL (1 << 15) | (1 << 14)

#define P18 (1 << 18)
#define P20 (1 << 20)
#define P21 (1 << 21)
#define P23 (1 << 23)

#define ALL (P18 | P20 | P21 | P23)

int main(void) {
	SystemInit();

	/* Set the pins to GPIO
	 */
	LPC_PINCON->PINSEL3 &= ~(P1_18_SEL | P1_20_SEL | P1_21_SEL | P1_23_SEL);

	/* Set the direction as output
	 */
	LPC_GPIO1->FIODIR |= ALL;

	/* Turn the LEDs on and off at roughly 1Hz.
	 */
	while (1) {
		LPC_GPIO1->FIOSET |= ALL;
		delay_ms(500);
		LPC_GPIO1->FIOCLR |= ALL;
		delay_ms(500);
	}
}
