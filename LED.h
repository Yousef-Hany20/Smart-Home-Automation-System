/******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.h
 *
 * Description: Header file for the AVR LED driver
 *
 * Author: Yousef
 *
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "std_types.h" /* To use standard types like uint8 */

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Define the LED IDs for red, green, and blue LEDs */
typedef enum
{
    RED_LED,
    GREEN_LED,
    BLUE_LED
} LED_ID;

/* Define logic types for the LEDs */
#define POSITIVE_LOGIC 1
#define NEGATIVE_LOGIC 0

/* Define the logic type to be used for the LEDs (can be POSITIVE_LOGIC or NEGATIVE_LOGIC) */
#define LED_LOGIC POSITIVE_LOGIC

/* Define the microcontroller port and pin for each LED */
#define RED_LED_PORT   PORTB_ID
#define RED_LED_PIN    PIN5_ID

#define GREEN_LED_PORT PORTB_ID
#define GREEN_LED_PIN  PIN6_ID

#define BLUE_LED_PORT  PORTB_ID
#define BLUE_LED_PIN   PIN7_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initializes all LEDs (red, green, blue) pins as output.
 * Turns off all the LEDs.
 */
void LEDS_init(void);

/*
 * Description :
 * Turns on the specified LED based on its ID (red, green, or blue).
 * The function handles both positive and negative logic configurations.
 */
void LED_on(LED_ID id);

/*
 * Description :
 * Turns off the specified LED based on its ID (red, green, or blue).
 * The function handles both positive and negative logic configurations.
 */
void LED_off(LED_ID id);

#endif /* LED_H_ */
