#include "mbed.h"
#define version "2.2"

Serial pc(USBTX, USBRX);
I2C i2c(p28, p27); // SDA, SCL 

int main()
{

   wait(1);    
   pc.printf("\n Version = %s \n",version); // Affiche la version du programme sur l'ordinateur (lisible via Putty, HyperTerminal  ou TeraTerm)
   wait(1);
                        //  1    2    3    4
   //char cmd[] = {0x00,0x37,0x06,0x5B,0x4F,0x66};
   char cmd[] = {0x00,0x37,0x00,0x00,0x00};
   char chiffre[] = { 0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D ,  0x7D , 0x07 , 0x7F, 0x6F};
   int i = 0;
   
   while(1) 
   {
        if(i> 10 )
            i=0;
        strcat(cmd, ",");
        strcat(cmd, chiffre[i]);
        i2c.write(0x70,cmd,6);
        cmd = cmd + chiffre[i];
        wait(1.5);
        i++;
/*
        char cmd2[] = {0x00,0x37,0x00,0x00,0x00,0x5B};
        i2c.write(0x70,cmd2,6);
        wait(1.5);
        
        char cmd3[] = {0x00,0x37,0x00,0x00,0x00,0x4F};
        i2c.write(0x70,cmd3,6);
        wait(1.5);

        char cmd4[] = {0x00,0x37,0x00,0x00,0x00,0x66};
        i2c.write(0x70,cmd4,6);
        wait(1.5);
*/
   }
}

//S 0 1 1 1 0 00 0 A 0 0 0 0 0  001 A X 0 0 0 1 0 0 0 A 00000110 A 01011011 A 01001111 A 01100110  A P