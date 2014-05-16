#include "mbed.h"

#define version "1.0 - Bousole" // Bousle avec un MBED NPC1768
// utilisation d'un double Thread

Serial pc(USBTX, USBRX);
I2C i2c(p28, p27); // SDA, SCL 


// NON ESSAYER, aucun idée si sa fonctionne la lecture 
// http://www.st.com/web/en/resource/technical/document/datasheet/CD00260288.pdf
// http://mbed.org/users/bclaus/code/LSM303DLHC/docs/612f7d5a822d/LSM303DLHC_8cpp_source.html
// http://www.adafruit.com/datasheets/LSM303DLHC.PDF

int main()
{

   wait(1);    
   pc.printf("\n Version = %s \n",version); // Affiche la version du programme sur l'ordinateur (lisible via Putty, HyperTerminal  ou TeraTerm)
   wait(1);
   
   char data[5];
   while(1)
   {
        i2c.read(0x03, data,1);
        pc.printf("%s",data);
        wait(0.1);
   }
}