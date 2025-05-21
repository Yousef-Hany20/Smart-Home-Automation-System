/*
 * pwm.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Yousef
 */

#include "avr/io.h" /* To use the Timer and I/O registers */
#include "pwm.h"
#include "common_macros.h" /* To use macros like SET_BIT and CLEAR_BIT */
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * This function configures and starts Timer0 in Fast PWM mode.
 * It uses OC0 (PB3) as the PWM output pin, configured as output.
 * Fast PWM is used with a prescaler of F_CPU/1024.
 */
void PWM_Timer0_Start(void)
{
	TCNT0 = 0; /* Set Timer0 initial count to zero */

	/* Configure Timer0 Control Register (TCCR0):
	 * 1. Clear FOC0 bit, as it's only active in non-PWM modes.
	 * 2. Set WGM01=1 and WGM00=1 to enable Fast PWM mode.
	 * 3. Set COM01=1 to clear OC0 on compare match (non-inverting mode).
	 * 4. Set CS02=1 and CS00=1 for a prescaler of F_CPU/1024, giving us a slower clock for PWM.
	 */
	CLEAR_BIT(TCCR0, FOC0);  /* Clear FOC0 bit */
	SET_BIT(TCCR0, WGM01);   /* Set WGM01 to enable Fast PWM */
	SET_BIT(TCCR0, WGM00);   /* Set WGM00 to enable Fast PWM */
	SET_BIT(TCCR0, COM01);   /* Set COM01 to select non-inverting mode */
	SET_BIT(TCCR0, CS02);    /* Set prescaler (CS02 = 1 and CS00 = 1) */
	SET_BIT(TCCR0, CS00);

	/* Set OC0 (PB3) as output pin for PWM signal */
	GPIO_setupPinDirection(PORTB, PIN3_ID, PIN_OUTPUT);
}

/*
 * Description:
 * This function sets the duty cycle for PWM on Timer0.
 * The duty cycle is provided as a percentage (0-100%) and is converted
 * to a value between 0-255 for Timer0's compare register (OCR0).
 *
 * The formula used is:
 * OCR0 = (duty_cycle * 255) / 100
 * where duty_cycle is a percentage value.
 */
void PWM_SET_Duty_Cycle(uint8 duty_cycle)
{
	/* Calculate the compare match value for the desired duty cycle.
	   The cast to uint16 ensures that the multiplication doesn't overflow.
	   Then, we store the result in OCR0, which controls the duty cycle. */
	OCR0 = (uint8)(((uint16)duty_cycle * 255) / 100);
}
