/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the AVR PWM driver
 *
 * Author: Yousef
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h" /* Include the standard types header file */

/*
 * Description :
 * Function to start Timer0 in Fast PWM mode with a specific duty cycle.
 * The duty cycle should be passed as a parameter (Percentage (0 to 100%)).
 * This function configures the timer in Fast PWM mode, sets the duty cycle,
 * and enables the output on the OC0 pin (PB3).
 */
void PWM_Timer0_Start(void);
void PWM_SET_Duty_Cycle(uint8 duty_cycle);

#endif /* PWM_H_ */
