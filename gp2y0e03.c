//cc -o "gp2y0e03" "gp2y0e03.c" -lwiringPi -lm

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>
 
int main(){
	
  int fd = wiringPiI2CSetup(0x40);
  int upper = 0;  // Upper 8 bit(11～4)
  int lower = 0;  // Lower 4 bit(3～0)
  int value = 0;
  int count = 0;
  
  while(count < 100){
	  
    upper = wiringPiI2CReadReg8(fd, 0x5E);
    lower = wiringPiI2CReadReg8(fd, 0x5F);
    value = upper << 4 | lower;
    printf("%d(%x)\n", value, value);
    delay(1000);  // wait for 1sec
    count++; 
  };
  return 0; 
  
}
