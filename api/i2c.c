#include "i2c.h"
#include <em_i2c.h>


void I2C0_init() {
/* Parts copied verbatim from i2c_master_slave.c (an/an0011_efm32_i2c)
    brief I2C Demo Application
    author Silicon Labs
    version 1.06
    (C) Copyright 2014 Silicon Labs, http://www.silabs.com

  Parts copied verbatim from 
    https://github.com/SiliconLabs/peripheral_examples/blob/public/i2c/i2c/src/main_efr.c
    Copyright 2018 Silicon Labs, Inc. http://www.silabs.com
    1509ef8 on Aug 22, silabs-BrianL Summer 2018 update
*/

  CMU_ClockEnable(cmuClock_I2C0, true);
  CMU_ClockEnable(cmuClock_GPIO, true);

 // Using default settings
  I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;

  /* Using PD6 (SDA) and PD7 (SCL) */
  GPIO_PinModeSet(I2C0_SDA_PORT, I2C0_SDA_PIN, gpioModeWiredAndPullUpFilter, 1);
  GPIO_PinModeSet(I2C0_SCL_PORT, I2C0_SCL_PIN, gpioModeWiredAndPullUpFilter, 1);
 
//???
  // Setting up PC0 to indicate transfer direction
//  GPIO_PinModeSet(gpioPortC, 0, gpioModePushPull, 0);

  /* Enable pins at location 1 */
#if 0
  I2C0->ROUTE = I2C_ROUTE_SDAPEN |
                I2C_ROUTE_SCLPEN |
                (1 << _I2C_ROUTE_LOCATION_SHIFT);
#endif
  I2C0->ROUTEPEN = I2C_ROUTEPEN_SDAPEN | I2C_ROUTEPEN_SCLPEN;

  I2C0->ROUTELOC0 = (I2C0->ROUTELOC0 & (~_I2C_ROUTELOC0_SDALOC_MASK)) |
                        I2C0_SDA_LOCATION;

  I2C0->ROUTELOC0 = (I2C0->ROUTELOC0 & (~_I2C_ROUTELOC0_SCLLOC_MASK)) |
                        I2C0_SCL_LOCATION;
        

  /* Initializing the I2C */
  I2C_Init(I2C0, &i2cInit);
 
#if 0
  /* Setting the status flags and index */
  i2c_rxInProgress = false;
  i2c_startTx = false;
  i2c_rxBufferIndex = 0;

  /* Setting up to enable slave mode */
  I2C0->SADDR = I2C_ADDRESS;
  I2C0->CTRL |= I2C_CTRL_SLAVE | I2C_CTRL_AUTOACK | I2C_CTRL_AUTOSN;
  enableI2cSlaveInterrupts();
#endif
  //I2C0->CTRL |= I2C_CTRL_EN; 

}
