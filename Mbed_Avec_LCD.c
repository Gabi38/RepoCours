#include "mbed.h"
#define version "4.0 - Freebox" // affichage Freebox en initialisation sur un SAA1064 avec un MBED NPC1768

Serial pc(USBTX, USBRX);
I2C i2c(p28, p27); // SDA, SCL 

int main()
{

   wait(1);    
   pc.printf("\n Version = %s \n",version); // Affiche la version du programme sur l'ordinateur (lisible via Putty, HyperTerminal  ou TeraTerm)
   wait(1);
   

   while(1) 
   {
        // boucle d'affichage lors de l'initialisation de la Freebox.
        char cmd1[] = {0x00,0x37,0x01,0x0,0x0,0x0}; 
        char cmd2[] = {0x00,0x37,0x0,0x01,0x0,0x0};
        char cmd3[] = {0x00,0x37,0x0,0x0,0x01,0x0}; 
        char cmd4[] = {0x00,0x37,0x0,0x0,0x0,0x01}; 
        char cmd5[] = {0x00,0x37,0x0,0x0,0x0,0x02};
        char cmd6[] = {0x00,0x37,0x0,0x0,0x0,0x04};
        char cmd7[] = {0x00,0x37,0x0,0x0,0x0,0x08};
        char cmd8[] = {0x00,0x37,0x0,0x0,0x08,0x0};
        char cmd9[] = {0x00,0x37,0x0,0x08,0x0,0x0};
        char cmd10[] = {0x00,0x37,0x08,0x0,0x0,0x0};
        char cmd11[] = {0x00,0x37,0x10,0x0,0x0,0x0};
        char cmd12[] = {0x00,0x37,0x20,0x0,0x0,0x0};
        
        int i;
        for(i=0;i<12;i++)
        {
            i2c.write(0x70,cmd1,6); // envoie sur le SAA Nouvelle Génération et sur l'ancien : Car Switch entre les 2. 
            wait(0.5);
            i2c.write(0x70,cmd2,6);
            wait(0.5);
            i2c.write(0x70,cmd3,6);
            wait(0.5);
            i2c.write(0x70,cmd4,6);
            wait(0.5);
            i2c.write(0x70,cmd5,6);
            wait(0.5);
            i2c.write(0x70,cmd6,6);
            wait(0.5);  
            i2c.write(0x70,cmd7,6);
            wait(0.5);  
            i2c.write(0x70,cmd8,6);
            wait(0.5);  
            i2c.write(0x70,cmd9,6);
            wait(0.5);  
            i2c.write(0x70,cmd10,6);
            wait(0.5);  
            i2c.write(0x70,cmd11,6);
            wait(0.5);  
            i2c.write(0x70,cmd12,6);
            wait(0.5);        
        }
        
        wait(1);
   }
}