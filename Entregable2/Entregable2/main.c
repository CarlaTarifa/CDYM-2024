/*
 * Entregable2.c
 *
 * Created: 5/5/2024 21:38:01
 * Author : LENOVO
 */ 


#include "main.h"

int main(void)
{
 //Inicializacion de equipo 
	_delay_ms(50);
   LCDinit();//Inicializo LCD
   LCDclr();
   KEYPAD_Init();
   JUEGO_Init();
   timer_init();
    while (1) 
    { 
		
		 JUEGO_Update();
		
    }
}

