/*
 * main.c
 *
 *  Created on: Oct 8, 2024
 *      Author: Yousef
 */

#include "Buzzer.h"
#include "LED.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "adc.h"
#include "Flame_Sensor.h"
#include "DC_Motor.h"
#include "LDR.h"

int main(void)
{
    /* Initialize the buzzer, LEDs, ADC, flame sensor, LCD, and DC motor */
    Buzzer_init();
    LEDS_init();
    ADC_init();
    FlameSensor_init();
    LCD_init();
    DcMotor_Init();

    /* Display static text for temperature and light intensity (LDR) readings on LCD */
    LCD_moveCursor(1, 0);
    LCD_displayString("Temp=   LDR=   %");

    while(1) /* Infinite loop to continuously monitor sensors and control peripherals */
    {
        /* Get light intensity value from LDR sensor and temperature from LM35 sensor */
        uint8 intensity = LDR_getLightIntensity();
        uint8 Temperature = LM35_getTemperature();

        /* Display the temperature reading at position (1,5) on the LCD */
        LCD_moveCursor(1, 5);
        LCD_intgerToString(Temperature);

        /* Display the light intensity reading at position (1,12) on the LCD */
        LCD_moveCursor(1, 12);
        LCD_intgerToString(intensity);

        /* Control LEDs based on light intensity (LDR) value */
        if(intensity <= 15) /* Low intensity, all LEDs ON */
        {
            LED_on(RED_LED);
            LED_on(GREEN_LED);
            LED_on(BLUE_LED);
        }
        else if (intensity > 15 && intensity <= 50) /* Medium-low intensity, Red and Green ON, Blue OFF */
        {
            LED_on(RED_LED);
            LED_on(GREEN_LED);
            LED_off(BLUE_LED);
        }
        else if (intensity > 50 && intensity <= 70) /* Medium intensity, Red ON, Green and Blue OFF */
        {
            LED_on(RED_LED);
            LED_off(GREEN_LED);
            LED_off(BLUE_LED);
        }
        else if (intensity > 70) /* High intensity, all LEDs OFF */
        {
            LED_off(RED_LED);
            LED_off(GREEN_LED);
            LED_off(BLUE_LED);
        }

        /* Control DC motor (fan) speed based on temperature */
        if(Temperature >= 40) /* High temperature, fan at 100% speed */
        {
            DcMotor_Rotate(CW, 100);
            LCD_moveCursor(0, 0);  /* Display "FAN is ON" message */
            LCD_displayString("   FAN is ON  ");
        }
        else if (Temperature >= 35 && Temperature < 40) /* Medium-high temperature, fan at 75% speed */
        {
            DcMotor_Rotate(CW, 75);
            LCD_moveCursor(0, 0);
            LCD_displayString("   FAN is ON  ");
        }
        else if (Temperature >= 30 && Temperature < 35) /* Medium temperature, fan at 50% speed */
        {
            DcMotor_Rotate(CW, 50);
            LCD_moveCursor(0, 0);
            LCD_displayString("   FAN is ON  ");
        }
        else if (Temperature >= 25 && Temperature < 30) /* Low temperature, fan at 25% speed */
        {
            DcMotor_Rotate(CW, 25);
            LCD_moveCursor(0, 0);
            LCD_displayString("   FAN is ON  ");
        }
        else if (Temperature < 25) /* Very low temperature, fan OFF */
        {
            DcMotor_Rotate(CW, 0);
            LCD_moveCursor(0, 0);
            LCD_displayString("   FAN is OFF  ");
        }

        /* Check flame sensor and activate buzzer if a flame is detected */
        if(FlameSensor_getValue() == 1) /* Flame detected (sensor output = 1) */
        {
        	while(FlameSensor_getValue() == 1)
        	{
               Buzzer_on();                   /* Turn the buzzer ON */
                LCD_clearPart(1,0,16);
                LCD_moveCursor(0,0);
                LCD_displayString("Critical alert!"); /* Display warning message */

       	}
        }
        else
        {
        /* Turn the buzzer off when no flame is detected */
        Buzzer_off();
        /* Display static text for temperature and light intensity (LDR) readings on LCD */
        LCD_moveCursor(1, 0);
        LCD_displayString("Temp=");
        LCD_moveCursor(1,8);
        LCD_displayString("LDR=");
        LCD_moveCursor(1,15);
        LCD_displayString("%");
        }
    }
}
