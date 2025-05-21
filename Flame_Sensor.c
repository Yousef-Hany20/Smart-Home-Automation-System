/*
 * Flame_Sensor.c
 *
 *  Created on: Oct 8, 2024
 *      Author: Yousef
 */

#include "Flame_Sensor.h"
#include "gpio.h"  /* To control GPIO pins */


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * This function initializes the flame sensor pin direction.
 * It configures the flame sensor pin as an input pin.
 */
void FlameSensor_init(void)
{
    /* Set the flame sensor pin as input by configuring the direction */
    GPIO_setupPinDirection(Flame_Sensor_PORT_ID, Flame_Sensor_PIN_ID, PIN_INPUT);
}

/*
 * Description:
 * This function reads the value from the flame sensor and returns it.
 * It checks the state of the sensor and returns:
 * - 1 if the flame is detected (fire incident).
 * - 0 if no flame is detected (no fire incident).
 */
uint8 FlameSensor_getValue(void)
{
    /* Read the pin value, return 1 if flame detected, 0 otherwise */
    return GPIO_readPin(Flame_Sensor_PORT_ID, Flame_Sensor_PIN_ID);
}
