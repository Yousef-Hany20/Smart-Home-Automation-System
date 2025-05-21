/*
 * Buzzer.h
 *
 *  Created on: Oct 8, 2024
 *      Author: Yousef
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Buzzer Port and Pin Configurations */
#define Buzzer_PORT_ID    PORTD_ID  /* The port to which the buzzer is connected */
#define Buzzer_PIN_ID     PIN3_ID   /* The pin number where the buzzer is connected */


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Initializes the buzzer pin direction as output and ensures the buzzer is initially off.
 */
void Buzzer_init(void);

/*
 * Description:
 * Activates the buzzer by writing a high signal to the buzzer pin.
 */
void Buzzer_on(void);

/*
 * Description:
 * Deactivates the buzzer by writing a low signal to the buzzer pin.
 */
void Buzzer_off(void);

#endif /* BUZZER_H_ */
