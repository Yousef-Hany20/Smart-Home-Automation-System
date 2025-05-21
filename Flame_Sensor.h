/*
 * Flame_Sensor.h
 *
 *  Created on: Oct 8, 2024
 *      Author: Yousef
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "std_types.h"   /* To use standard data types like uint8 */

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*
 * Flame sensor pin configurations:
 * Define the port and pin where the flame sensor is connected.
 * The user can reconfigure these definitions to match the hardware setup.
 */
#define Flame_Sensor_PORT_ID    PORTD_ID   /* Flame sensor connected to PORTD */
#define Flame_Sensor_PIN_ID     PIN2_ID    /* Flame sensor connected to PIN2 (PD2) */


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * This function initializes the flame sensor pin direction.
 * It sets the flame sensor pin as input to detect fire incidents.
 */
void FlameSensor_init(void);

/*
 * Description:
 * This function reads the value from the flame sensor and returns it.
 * It uses polling to check if a fire incident is detected.
 * Returns:
 * - 1 if the flame is detected (fire incident).
 * - 0 if no flame is detected (no fire incident).
 */
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
