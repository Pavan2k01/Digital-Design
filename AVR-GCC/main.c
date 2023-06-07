//Turns LED on and off
#include <avr/io.h>
#include <util/delay.h>

#define INPUT1_PIN  PINB2   // Pin for input 1 (PB2)
#define INPUT2_PIN  PINB3   // Pin for input 2 (PB3)
#define OUTPUT_PIN  PINB5   // Pin for output (PB5)

void setup() {
  DDRB &= ~(1 << INPUT1_PIN) & ~(1 << INPUT2_PIN);  // Set input pins as inputs
  DDRB |= (1 << OUTPUT_PIN);                        // Set output pin as output
}

void loop() {
  uint8_t input1 = PINB & (1 << INPUT1_PIN);  // Read input 1
  uint8_t input2 = PINB & (1 << INPUT2_PIN);  // Read input 2
  
  // Compute the NOR gate output
  uint8_t output = !(input1 || input2);
  
  if (output) {
    PORTB |= (1 << OUTPUT_PIN);   // Set output pin high
  } else {
    PORTB &= ~(1 << OUTPUT_PIN);  // Set output pin low
  }
}

int main() {
  setup();
  
  while (1) {
    loop();
  }

  return 0;
}
