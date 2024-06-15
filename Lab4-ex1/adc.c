#include "LPC17xx.h"   // Include header file for LPC17xx microcontroller
#include "adc.h"       // Include header file for ADC functions

static unsigned int AD_lastValue;  // Variable to store the last converted ADC value
static unsigned int AD_done;       // Flag indicating if ADC conversion is done

void ADC_Initialize (void)
{
	// Enable power to ADC & IOCON
    LPC_SC->PCONP |= ((1 << 12) | (1 << 15));  // Enable power to ADC (bit 12) and IOCON (bit 15)
  
    // Set PINSEL1[19:18] = 01 to select Function AD0.2 for pin P0.25
    LPC_PINCON->PINSEL1 |= (1 << 18);          // Set bit 18 of PINSEL1 to 1 (select AD0.2 function)
    LPC_PINCON->PINSEL1 &= ~(1 << 19);         // Clear bit 19 of PINSEL1
  
    // Select AD0.2 pin, ADC clock is 25MHz/5, Enable ADC
    LPC_ADC->ADCR = (1 << 2) | (1 << 10) | (1 << 21);  // Enable ADC channel 2 (AD0.2), set ADC clock to 25MHz/5, enable ADC
  
    LPC_ADC->ADINTEN = (1 << 8);  // Enable ADC global interrupt
  
    // Enable ADC Interrupt in the NVIC interrupt controller
    NVIC_EnableIRQ(ADC_IRQn);  // Enable ADC interrupt
}

void ADC_IRQHandler(void)
{
    int adstat = LPC_ADC->ADSTAT;  // Read ADC status register to clear interrupt
  
    // Store converted value
    AD_lastValue = (LPC_ADC->ADGDR >> 8) & 0xFF;  // Read and store the converted ADC value from ADC data register
  
    AD_done = 1;  // Set conversion done flag to indicate ADC conversion is complete
}

void ADC_StartConversion (void)
{
    LPC_ADC->ADCR &= ~(7 << 24);  // Clear bits 26:24 of ADC control register to stop any ongoing conversion
  
    LPC_ADC->ADCR |= (1 << 24);   // Set bit 24 of ADC control register to start a new conversion
}

int ADC_ConversionDone (void)
{
    return AD_done;  // Return the value of the conversion done flag (1 if conversion is complete, 0 otherwise)
}

int ADC_GetValue (void)
{
    return AD_lastValue;  // Return the last converted ADC value stored in AD_lastValue
}
