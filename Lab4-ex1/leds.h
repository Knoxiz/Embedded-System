#include "LPC17xx.h"                        // Include header file for LPC17xx microcontroller

#define POWER_CONTROL (LPC_SC->PCONP)       // Define for Power Control register access

#define PINCONSEL1 (LPC_PINCON->PINSEL1)    // Define for Pin Function Select register 1 access
#define PINCONSEL2 (LPC_PINCON->PINSEL2)    // Define for Pin Function Select register 2 access

#define IO1_DIR (LPC_GPIO1->FIODIR)         // Define for GPIO1 Direction Control register access
#define IO2_DIR (LPC_GPIO2->FIODIR)         // Define for GPIO2 Direction Control register access

#define IO1_SET (LPC_GPIO1->FIOSET)         // Define for GPIO1 Set register access
#define IO2_SET (LPC_GPIO2->FIOSET)         // Define for GPIO2 Set register access

#define IO1_CLR (LPC_GPIO1->FIOCLR)         // Define for GPIO1 Clear register access
#define IO2_CLR (LPC_GPIO2->FIOCLR)         // Define for GPIO2 Clear register access

#define IO1_PIN (LPC_GPIO1->FIOPIN)         // Define for GPIO1 Pin Value register access
#define IO2_PIN (LPC_GPIO2->FIOPIN)         // Define for GPIO2 Pin Value register access

#define LED1_BIT (1 << 6)                   // Define for LED1 pin (bit 6)
#define LED2_BIT (1 << 5)                   // Define for LED2 pin (bit 5)
#define LED3_BIT (1 << 4)                   // Define for LED3 pin (bit 4)
#define LED4_BIT (1 << 3)                   // Define for LED4 pin (bit 3)
#define LED5_BIT (1 << 2)                   // Define for LED5 pin (bit 2)
#define LED6_BIT (1 << 31)                  // Define for LED6 pin (bit 31)
#define LED7_BIT (1 << 29)                  // Define for LED7 pin (bit 29)
#define LED8_BIT (1 << 28)                  // Define for LED8 pin (bit 28)

void leds_init(void);                      // Function for LEDs initialization
void led_on(unsigned int index);           // Function to turn on LED at specified index
void led_off(unsigned int index);          // Function to turn off LED at specified index
void leds_set_value(char led_Value);       // Function to set LEDs to a specific value
