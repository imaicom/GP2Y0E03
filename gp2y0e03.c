#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>
 
int main(void){
  int fd = wiringPiI2CSetup(0x40);
  int upper = 0;  // 上位8ビット(11～4)
  int lower = 0;  // 下位4ビット(3～0)
  int value = 0;
  int count = 0;
  while(count < 100){
    upper = wiringPiI2CReadReg8(fd, 0x5E);
    lower = wiringPiI2CReadReg8(fd, 0x5F);
    value = upper << 4 | lower;
    printf("%d(%x)\n", value, value);
    delay(1000);  // 1000ミリ秒待機
    count++; 
  }
  return 0;
}
