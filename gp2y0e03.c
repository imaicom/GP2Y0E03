//cc -o "gp2y0e03" "gp2y0e03.c" -lwiringPi -lm

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>
 
int main() {
	
  int fd = wiringPiI2CSetup(0x40);
  int dat;
  
  while(1) {
    dat = wiringPiI2CReadReg8(fd, 0x5E) << 4 | wiringPiI2CReadReg8(fd, 0x5F);
    printf("%d(%x)\n", dat, dat);
    delay(1000);  // wait for 1sec
  };
    
}
