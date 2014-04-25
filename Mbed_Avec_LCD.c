#include "mbed.h"
#define version "3.5" // affiche un nombre voulu sur un SAA1064 avec un MBED NPC1768

Serial pc(USBTX, USBRX);
I2C i2c(p28, p27); // SDA, SCL 

int main()
{

   wait(1);    
   pc.printf("\n Version = %s \n",version); // Affiche la version du programme sur l'ordinateur (lisible via Putty, HyperTerminal  ou TeraTerm)
   wait(1);
   
                    // 0      1       2      3      4      5      6       7     8      9
   char chiffre[] = { 0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D ,  0x7D , 0x07 , 0x7F, 0x6F};
     
   int nombre = 243; // Nombre Choisit par l'utilisateur.
   int unite = 0, dixaine = 0, centaine = 0, millier = 0;
   
   while(1) 
   {
        millier = nombre / 1000;  // 0
        centaine = (nombre % 1000) / 100; // 2
        dixaine = (nombre % 100) / 10; // 4
        unite = nombre % 10; // 3

        char cmd_autre[] = {0x00,0x37,chiffre[millier],chiffre[centaine],chiffre[dixaine],chiffre[unite]}; // Commande complete pour faire afficher le chiffre voulu (243).
        
        i2c.write(0x70,cmd_autre,6); // envoie sur le SAA Nouvelle Génération et sur l'ancien : Car Switch entre les 2. 
        // i2c.write(0x72,cmd,6); // envoie sur le SAA1064 ancienne génération.

        wait(1);
   }
}