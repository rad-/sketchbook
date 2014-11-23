#include <SPI.h>
#include <nRF24L01.h>
#include <RF24_config.h>
#include <RF24.h>


RF24 radio(9,10);

const uint8_t num_channels = 128;
uint8_t values[num_channels];


void setup(void)
{
  
  fdevopen(&serial_putc,0);
  //
  // Print preamble
  //

  Serial.begin(57600);
  printf("\n\rRF24/examples/scanner/\n\r");

  //
  // Setup and configure rf radio
  //

  radio.begin();
  radio.setAutoAck(false);

  // Get into standby mode
  radio.startListening();
  radio.stopListening();

  // Print out header, high then low digit
  int i = 0;
  while ( i < num_channels )
  {
    printf("%x",i>>4);
    ++i;
  }
  printf("\n\r");
  i = 0;
  while ( i < num_channels )
  {
    printf("%x",i&0xf);
    ++i;
  }
  printf("\n\r");
}


