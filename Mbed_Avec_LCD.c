#include "mbed.h"
#define version "2.8"

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
            i = 0;
       
        
        char autre[] = {0x00,0x37,0x00,0x00,0x00,chiffre[i]};
        pc.printf("\n COMMANDE = %c",autre);
        
        i2c.write(0x70,cmd,5);
        //i2c.write(0x70,autre,1);
        
        wait(1);
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