#include "mbed.h"
#define version "2.0"

Serial pc(USBTX, USBRX);
I2C i2c(p28, p27); // SDA, SCL 

int main()
{

   wait(1);    
   pc.printf("\n Version = %s \n",version); // Affiche la version du programme sur l'ordinateur (lisible via Putty, HyperTerminal  ou TeraTerm)
   wait(1);

   char cmd[] = {0x00,0x37,0x06,0x5B,0x4F,0x66};
   
   while(1) 
   {
        i2c.write(0x70,cmd,6);
   }
}