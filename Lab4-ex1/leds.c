#include "LPC17xx.h"   // Include header file for LPC17xx microcontroller
#include "leds.h"      // Include header file for LEDs functions
#include "os_tick.h"   // Include header file for OS tick functions

volatile uint32_t msTicks;  // Volatile variable to store milliseconds ticks, for SysTick interrupt

void SysTick_Handler(void) 
{
    msTicks++;  // Increment msTicks in SysTick interrupt handler
}

void my_Delay (uint32_t dlyTicks) {
    uint32_t curTicks;
    curTicks = msTicks;  // Capture current value of msTicks
    while ((msTicks - curTicks) < dlyTicks) { __NOP(); }  // Wait until msTicks exceeds curTicks + dlyTicks
}

void leds_init(void)
{
    POWER_CONTROL |= (1 << 15);  // Enable power to GPIO block (bit 15 in PCONP)
    IO2_DIR = (LED1_BIT | LED2_BIT | LED3_BIT | LED4_BIT | LED5_BIT);  // Set GPIO2 pins as output for LEDs 1-5
    IO1_DIR = (LED6_BIT | LED7_BIT | LED8_BIT);  // Set GPIO1 pins as output for LEDs 6-8
}

void led_on(unsigned int index)
{
    switch(index)
    {
        case 1: 
            IO2_SET = LED1_BIT;  // Turn on LED 1 (GPIO2 pin 6)
            break;
        case 2: 
            IO2_SET = LED2_BIT;  // Turn on LED 2 (GPIO2 pin 5)
            break;
        case 3: 
            IO2_SET = LED3_BIT;  // Turn on LED 3 (GPIO2 pin 4)
            break;
        case 4: 
            IO2_SET = LED4_BIT;  // Turn on LED 4 (GPIO2 pin 3)
            break;
        case 5: 
            IO2_SET = LED5_BIT;  // Turn on LED 5 (GPIO2 pin 2)
            break;
        case 6: 
            IO1_SET = LED6_BIT;  // Turn on LED 6 (GPIO1 pin 31)
            break;
        case 7: 
            IO1_SET = LED7_BIT;  // Turn on LED 7 (GPIO1 pin 29)
            break;
        case 8: 
            IO1_SET = LED8_BIT;  // Turn on LED 8 (GPIO1 pin 28)
            break;
        default: 
            break;
    }
}

void led_off(unsigned int index)
{
    switch(index)
    {
        case 1: 
            IO2_CLR = LED1_BIT;  // Turn off LED 1 (GPIO2 pin 6)
            break;
        case 2: 
            IO2_CLR = LED2_BIT;  // Turn off LED 2 (GPIO2 pin 5)
            break;
        case 3: 
            IO2_CLR = LED3_BIT;  // Turn off LED 3 (GPIO2 pin 4)
            break;
        case 4: 
            IO2_CLR = LED4_BIT;  // Turn off LED 4 (GPIO2 pin 3)
            break;
        case 5: 
            IO2_CLR = LED5_BIT;  // Turn off LED 5 (GPIO2 pin 2)
            break;
        case 6: 
            IO1_CLR = LED6_BIT;  // Turn off LED 6 (GPIO1 pin 31)
            break;
        case 7: 
            IO1_CLR = LED7_BIT;  // Turn off LED 7 (GPIO1 pin 29)
            break;
        case 8: 
            IO1_CLR = LED8_BIT;  // Turn off LED 8 (GPIO1 pin 28)
            break;
        default: 
            break;
    }
}

void Led_Style_OnOffEachLed(void)
{
    int i;
    for(i = 1; i <= 8; i++)
    {
        led_on(i);         // Turn on LED i
        my_Delay(2000);    // Delay 2000ms
        led_off(i);        // Turn off LED i
    }
}

void Led_Stye_LedChasing(void)
{
    int i;
    for (i = 1; i <= 8; i++)
    {
        led_on(i);         // Turn on LED i
        my_Delay(2000);    // Delay 2000ms
    }
    for (i = 8; i >= 1; i--)
    {
        led_off(i);        // Turn off LED i
        my_Delay(2000);    // Delay 2000ms
    }
}

void Led_Style_3LedChasing(void)
{
    int i;
    for (i = 1; i <= 9; i++)
    {
        led_off(i-1);     // Turn off previous LEDs
        led_off(i-2);
        led_off(i-3);
        led_on(i);        // Turn on new LEDs
        led_on(i+1);
        led_on(i+2);
        my_Delay(1000);   // Delay 1000ms
    }
}

void leds_set_value(char led_Value)
{
    int i;
    for(i = 0; i < 8; i++)
    {
        if(led_Value & (1 << i))
        {
            led_on(i+1);   // Turn on LED i+1 if corresponding bit is set in led_Value
        }
        else
        {
            led_off(i+1);  // Turn off LED i+1 if corresponding bit is not set in led_Value
        }
    }
}
