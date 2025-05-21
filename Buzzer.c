/*
 * Buzzer.c
 *
 *  Created on: Oct 8, 2024
 *      Author: Yousef
 */

#include "Buzzer.h"
#include "gpio.h" /* To use GPIO functions for controlling the buzzer pin */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Initializes the buzzer pin direction as output.
 * The buzzer is initially turned off by writing a low signal to the buzzer pin.
 */
void Buzzer_init(void)
{
    /* Set the buzzer pin as an output pin */
    GPIO_setupPinDirection(Buzzer_PORT_ID, Buzzer_PIN_ID, PIN_OUTPUT);

    /* Ensure the buzzer is off initially by writing a low signal to the pin */
    GPIO_writePin(Buzzer_PORT_ID, Buzzer_PIN_ID, LOGIC_LOW);
}

/*
 * Description:
 * Activates the buzzer by writing a high signal (logic high) to the buzzer pin.
 */
void Buzzer_on(void)
{
    /* Turn the buzzer on by setting the buzzer pin to high */
    GPIO_writePin(Buzzer_PORT_ID, Buzzer_PIN_ID, LOGIC_HIGH);
}

/*
 * Description:
 * Deactivates the buzzer by writing a low signal (logic low) to the buzzer pin.
 */
void Buzzer_off(void)
{
    /* Turn the buzzer off by setting the buzzer pin to low */
    GPIO_writePin(Buzzer_PORT_ID, Buzzer_PIN_ID, LOGIC_LOW);
}
