#ifndef __I2C_H__
#define __I2C_H__


//accelerometer interface
#define I2C0_SDA_LOCATION    16 //PC11 - EXP header #16
#define I2C0_SCL_LOCATION    14 //PC10 - EXP header #15
#define ACCELEROMETER_CS     PF5 //TDB
#define ACCELEROMETER_INT1   PF4 //TDB

void I2C0_init();

#endif
