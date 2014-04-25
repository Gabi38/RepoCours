#include "mbed.h"
#define version "3.0"

Serial pc(USBTX, USBRX);
I2C i2c(p28, p27); // SDA, SCL 

int main()
{

   wait(1);    
   pc.printf("\n Version = %s \n",version); // Affiche la version du programme sur l'ordinateur (lisible via Putty, HyperTerminal  ou TeraTerm)
   wait(1);
   
                    // 0      1       2      3      4      5      6       7     8      9
   char chiffre[] = { 0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D ,  0x7D , 0x07 , 0x7F, 0x6F};
   

   int i = 0, j = 0 , k = 0;
   
   while(1) 
   {
        if(i> 9 )
        {
            i = 0;
            j++;
            if(j>9)
            {
                k++;
                j=0;
                if(k>9)
                {
                    k=0;
                    j=0;
                    i=0;
                }
            }
        }
       
        char cmd[] = {0x00,0x37,0x3F,chiffre[k],chiffre[j],chiffre[i]}; // Commande complete pour faire afficher les chiffres.
        
        i2c.write(0x72,cmd,6); // envoie sur le SAA1064 ancienne génération.
        i2c.write(0x70,cmd,6); // envoie sur le SAA Nouvelle Génération

        wait(1);       
        i++;

   }
}