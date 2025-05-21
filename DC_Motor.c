/*
 * DC_Motor.c
 *
 *  Created on: Oct 8, 2024
 *      Author: Yousef
 */

#include "DC_Motor.h"
#include "gpio.h"
#include "pwm.h"  /* Including the PWM driver to control motor speed */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description:
 * Initializes the DC motor by setting the motor direction control pins (IN1 and IN2)
 * as output and stopping the motor initially. Also sets up the Enable1 pin (PB3) for PWM control.
 */
void DcMotor_Init(void)
{
    /* Setup IN1 and IN2 pins as output to control the motor's direction */
    GPIO_setupPinDirection(IN1_PORT_ID, IN1_PIN_ID, PIN_OUTPUT);
    GPIO_setupPinDirection(IN2_PORT_ID, IN2_PIN_ID, PIN_OUTPUT);

    /* Initially stop the motor by setting both IN1 and IN2 to LOGIC_LOW */
    GPIO_writePin(IN1_PORT_ID, IN1_PIN_ID, LOGIC_LOW);
    GPIO_writePin(IN2_PORT_ID, IN2_PIN_ID, LOGIC_LOW);

    /* Setup the Enable1 pin (PB3/OC0) as output for PWM control of speed */
    GPIO_setupPinDirection(Enable1_PORT_ID, Enable1_PIN_ID, PIN_OUTPUT);
}

/*
 * Description:
 * Controls the motor's direction and speed using PWM.
 * The function accepts the motor's state (Clockwise, Anti-Clockwise, or Stop)
 * and the speed as a percentage (0 to 100%).
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
    /* Switch case to determine the motor's direction */
    switch (state)
    {
        case CW:
            /*
             * Clockwise rotation:
             * - Set IN1 to LOW and IN2 to HIGH.
             * - This will cause the motor to rotate in the clockwise direction.
             */
            GPIO_writePin(IN1_PORT_ID, IN1_PIN_ID, LOGIC_LOW);
            GPIO_writePin(IN2_PORT_ID, IN2_PIN_ID, LOGIC_HIGH);
            break;

        case A_CW:
            /*
             * Anti-clockwise rotation:
             * - Set IN1 to HIGH and IN2 to LOW.
             * - This will cause the motor to rotate in the anti-clockwise direction.
             */
            GPIO_writePin(IN1_PORT_ID, IN1_PIN_ID, LOGIC_HIGH);
            GPIO_writePin(IN2_PORT_ID, IN2_PIN_ID, LOGIC_LOW);
            break;

        case Stop:
            /*
             * Stop the motor:
             * - Set both IN1 and IN2 to LOW to stop any motor movement.
             */
            GPIO_writePin(IN1_PORT_ID, IN1_PIN_ID, LOGIC_LOW);
            GPIO_writePin(IN2_PORT_ID, IN2_PIN_ID, LOGIC_LOW);
            break;

        default:
            /*
             * Default case:
             * - If an invalid state is passed, stop the motor as a safety measure.
             */
            GPIO_writePin(IN1_PORT_ID, IN1_PIN_ID, LOGIC_LOW);
            GPIO_writePin(IN2_PORT_ID, IN2_PIN_ID, LOGIC_LOW);
            break;
    }

    /* Start the PWM signal with the given speed (duty cycle percentage) */
    PWM_Timer0_Start();
    PWM_SET_Duty_Cycle(speed);
}
