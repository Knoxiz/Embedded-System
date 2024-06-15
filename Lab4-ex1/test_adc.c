#include "LPC17xx.h"       // Include LPC17xx library for microcontroller-specific definitions
#include "leds.h"          // Include header file for LED functions
#include "adc.h"           // Include header file for ADC (Analog-to-Digital Converter) functions

int main() {
    leds_init();           // Initialize the LEDs
    ADC_Initialize();      // Initialize the ADC
    int ADC_Value;         // Variable to store ADC value
    char led_value;        // Variable to store value to be sent to LEDs

    while(1) {             // Infinite loop
        ADC_StartConversion();            // Start ADC conversion
        while(ADC_ConversionDone() == 0); // Wait until ADC conversion is done
        ADC_Value = ADC_GetValue();       // Get the ADC conversion result
        led_value = (char) ADC_Value;     // Convert ADC value to a char
        leds_set_value(led_value);        // Set the LEDs with the converted value
    }
}
