#include "mbed.h"
#include "rtos.h"
#define version "7.3 - Blink M - 2 THREAD" // Allume en vert une Diode LED BlinkM et lance l'initialisation d'une freebox avec un MBED NPC1768
// utilisation d'un double Thread

Serial pc(USBTX, USBRX);
I2C i2c(p28, p27); // SDA, SCL 


void LED(void const *args)
{
    pc.printf("Thread LED");              
                    //  R      G    B
   char cmd1[] = {'n', 0x00, 0xff, 0x00 }; // Permet d'eclairer en Vert.
   char cmd2[] = {'n', 0x00, 0x00, 0x00 }; // permet d'eteindre toute les LEDS.
     
   char cmd3[] = {'A', 0x01,0xd0,0x0d,0x01 }; // Ecrit la nouvelle adresse de la LED.  ici : 01
   i2c.write(0x00,cmd3,5); // Ecrit l'adresse sur la LED.
   
   Thread::wait(1000);// Attend 1 seconde.


   char adresse[] = {'a'}; // Lit l'adresse
   int add =  i2c.read(0x00,adresse,1); // Lit l'adresse de la led sur toute les adresses (broadcast sur 0x00)
   pc.printf("\n ADRESSE = %d ",add); // retourne a l'ecran la nouvelle adresse.
   Thread::wait(1000);

   char cmd4[] = {'o'};  // Arrete le script de Demo.
   i2c.write(0x01,cmd4,1);// Arrete le script de Demo.
   Thread::wait(100);

   while(1) 
   {          
        //  Affiche lumiere Verte sur une BlinkM.
        i2c.write(0x01,cmd1,4); // Allume la LED en vert.
        Thread::wait(1000);
        
        i2c.write(0x01,cmd2,4); // Eteind la LED.         
        Thread::wait(1000);
   }   

}

void freebox(void const *args)
{
   pc.printf(" Thread Freebox");  
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
            Thread::wait(500);
            i2c.write(0x70,cmd2,6);
            Thread::wait(500);
            i2c.write(0x70,cmd3,6);
            Thread::wait(500);
            i2c.write(0x70,cmd4,6);
            Thread::wait(500);
            i2c.write(0x70,cmd5,6);
            Thread::wait(500);
            i2c.write(0x70,cmd6,6);
            Thread::wait(500); 
            i2c.write(0x70,cmd7,6);
            Thread::wait(500);
            i2c.write(0x70,cmd8,6);
            Thread::wait(500); 
            i2c.write(0x70,cmd9,6);
            Thread::wait(500); 
            i2c.write(0x70,cmd10,6);
            Thread::wait(500);
            i2c.write(0x70,cmd11,6);
            Thread::wait(500);  
            i2c.write(0x70,cmd12,6);
            Thread::wait(500);    
        }
        
        Thread::wait(1000);
   }
}

int main()
{

   wait(1);    
   pc.printf("\n Version = %s \n",version); // Affiche la version du programme sur l'ordinateur (lisible via Putty, HyperTerminal  ou TeraTerm)
   wait(1);
   
   Thread thread1(LED);
   Thread thread2(freebox);
   while(1)
   {
        Thread::wait(200);
   }
}