/*
 * Timer1.c
 *
 * Created: 25/7/2024 00:31:37
 *  Author: LENOVO
 */ 

#include "Timer1.h"

void Timer1_Init(){
	//Configuracion del timer1 en modo pwm fast 8bits ( WGM12 y WGM10 en 1 = modo 5 de la tabla)
	//COM1AX y COM1BX en 1 para modo invertido y por ultimo CS12 y CS10 en 1 para preescaler 1024
	TCCR1A=(1<<COM1A0) | (1<<COM1A1) | (1<<COM1B0) | (1<<COM1B1) | (1<<WGM10) ;
	TCCR1B =(1<<WGM12) | (1<<CS12) | (1<<CS10);
}