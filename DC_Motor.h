/*
 * DC_Motor.h
 *
 *  Created on: Oct 8, 2024
 *      Author: Yousef
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Define the motor states for clockwise, anti-clockwise, and stop */
typedef enum
{
    CW,     /* Clockwise rotation */
    A_CW,   /* Anti-clockwise rotation */
    Stop    /* Motor stopped */
} DcMotor_State;

/* Motor control pin definitions */
#define IN1_PORT_ID    PORTB_ID      /* IN1 pin port (H-Bridge control) */
#define IN2_PORT_ID    PORTB_ID      /* IN2 pin port (H-Bridge control) */

#define IN1_PIN_ID     PIN0_ID    /* IN1 pin number */
#define IN2_PIN_ID     PIN1_ID    /* IN2 pin number */

/* Enable pin (PWM signal for speed control) */
#define Enable1_PORT_ID  PORTB_ID    /* Enable pin port (PWM control) */
#define Enable1_PIN_ID   PIN3_ID  /* Enable pin number (OC0 - Timer/Counter0 PWM output) */

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Initializes the DC motor by setting the direction for the motor control pins (IN1, IN2)
 * and configuring the enable pin (PWM) to control speed.
 * The motor is stopped initially after initialization.
 */
void DcMotor_Init(void);

/*
 * Description:
 * Controls the motor's state (Clockwise, Anti-clockwise, or Stop) and adjusts the speed
 * based on the input duty cycle. The speed parameter is a percentage (0 to 100%).
 *
 * Parameters:
 * - state: Specifies the motor's rotation direction (CW, A_CW, or Stop).
 * - speed: Motor speed as a percentage (0 to 100%).
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DC_MOTOR_H_ */
