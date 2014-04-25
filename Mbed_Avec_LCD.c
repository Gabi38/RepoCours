#include "mbed.h"
#define version "6.5 - Blink M" // Allume en vert une Diode LED BlinkM avec un MBED NPC1768

Serial pc(USBTX, USBRX);
I2C i2c(p28, p27); // SDA, SCL 

int main()
{

   wait(1);    
   pc.printf("\n Version = %s \n",version); // Affiche la version du programme sur l'ordinateur (lisible via Putty, HyperTerminal  ou TeraTerm)
   wait(1);
                    //  R      G    B
   char cmd1[] = {'n', 0x00, 0xff, 0x00 }; // Permet d'eclairer en Vert.
   char cmd2[] = {'n', 0x00, 0x00, 0x00 }; // permet d'eteindre toute les LEDS.
     
   char cmd3[] = {'A', 0x01,0xd0,0x0d,0x01 }; // Ecrit la nouvelle adresse de la LED.  ici : 01
   i2c.write(0x00,cmd3,5); // Ecrit l'adresse sur la LED.
   wait(1); // Attend 1 seconde.

   char adresse[] = {'a'}; // Lit l'adresse
   int add =  i2c.read(0x00,adresse,1); // Lit l'adresse de la led sur toute les adresses (broadcast sur 0x00)
   pc.printf("\n ADRESSE = %d ",add); // retourne a l'ecran la nouvelle adresse.
   wait(1);

   char cmd4[] = {'o'};  // Arrete le script de Demo.
   i2c.write(0x01,cmd4,1);// Arrete le script de Demo.
   wait(0.1);

   while(1) 
   {          
        //  Affiche lumiere Verte sur une BlinkM.
        i2c.write(0x01,cmd1,4); // Allume la LED en vert.
        wait(1);
        
        i2c.write(0x01,cmd2,4); // Eteind la LED.         
        wait(1);
   }
}