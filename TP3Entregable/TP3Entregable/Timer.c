/*
 * Timer.c
 *
 * Created: 10/6/2024 11:25:36
 *  Author: LENOVO
 */ 

#include "Timer.h"
//Configuracion del timer0

static uint8_t contador=0;
void TimerInit(void){
	OCR0A=249;
	TCCR0A = (1<<COM0A0) | (1<<WGM01);// MODO CTC 
	TCCR0B=(1<<CS01) | (1<CS00); //CTC CLK/6
	TIMSK0 = (1<<OCIE0A);//Habilito interrupcion de compa
}

ISR(TIMER0_COMPA_vect){
	if(++contador ==2000){//llega a 2seg
		contador=0;
    }
}