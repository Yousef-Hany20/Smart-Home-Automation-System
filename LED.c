/*
 * LED.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Yousef
 */

#include "LED.h"
#include "gpio.h"      /* To control GPIO pins */

/*
 * Description:
 * Initializes all LED pins (red, green, blue) as output and turns them off.
 */
void LEDS_init(void)
{
	/* Set the direction of the LED pins to output */
	GPIO_setupPinDirection(RED_LED_PORT, RED_LED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT, GREEN_LED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT, BLUE_LED_PIN, PIN_OUTPUT);

	/* Turn off all LEDs initially */
	LED_off(RED_LED);
	LED_off(GREEN_LED);
	LED_off(BLUE_LED);
}

/*
 * Description:
 * Turns on the specified LED based on the logic configuration (positive or negative logic).
 */
void LED_on(LED_ID id)
{
	switch (id)
	{
		case RED_LED:
			if (LED_LOGIC == POSITIVE_LOGIC)
			{
				/* For positive logic, turning on means writing HIGH */
				GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_HIGH);
			}
			else
			{
				/* For negative logic, turning on means writing LOW */
				GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_LOW);
			}
			break;

		case GREEN_LED:
			if (LED_LOGIC == POSITIVE_LOGIC)
			{
				GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_HIGH);
			}
			else
			{
				GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_LOW);
			}
			break;

		case BLUE_LED:
			if (LED_LOGIC == POSITIVE_LOGIC)
			{
				GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_HIGH);
			}
			else
			{
				GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_LOW);
			}
			break;

		default:
			/* Handle invalid LED ID */
			/* Do nothing or add an error handling mechanism here */
			break;
	}
}

/*
 * Description:
 * Turns off the specified LED based on the logic configuration (positive or negative logic).
 */
void LED_off(LED_ID id)
{
	switch (id)
	{
		case RED_LED:
			if (LED_LOGIC == POSITIVE_LOGIC)
			{
				/* For positive logic, turning off means writing LOW */
				GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_LOW);
			}
			else
			{
				/* For negative logic, turning off means writing HIGH */
				GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_HIGH);
			}
			break;

		case GREEN_LED:
			if (LED_LOGIC == POSITIVE_LOGIC)
			{
				GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_LOW);
			}
			else
			{
				GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_HIGH);
			}
			break;

		case BLUE_LED:
			if (LED_LOGIC == POSITIVE_LOGIC)
			{
				GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_LOW);
			}
			else
			{
				GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_HIGH);
			}
			break;

		default:
			/* Handle invalid LED ID */
			/* Do nothing or add an error handling mechanism here */
			break;
	}
}
