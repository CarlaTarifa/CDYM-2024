/*
 * Timer0.c
 *
 * Created: 25/7/2024 00:32:11
 *  Author: LENOVO
 */ 

#include "Timer0.h"
#define PWM_PERIOD 255
#define  PWM_DELTA 127
#define PWM_OFF PORTB&=~(1<<PORTB5)
#define  PWM_ON PORTB|=(1<<PORTB5)
#define  PWM_START DDRB |= (1<<PORTB5) 

void Timer0_Init(){
	//Configuracion timer0 en modo ctc para modo pwm por software
	TCCR0A = (1<<COM0A0) | (1<<WGM01);// MODO CTC 
	TCCR0B=(1<<CS02)|(1<<CS00);//preescaler 1024
	OCR0A=0;
	TIMSK0= (1 << OCIE0A); // Habilita la interrupción por comparación del temporizador 0
	sei();
}

ISR(TIMER0_COMPA_vect){
	PWM_soft_Update();
}

void PWM_soft_Update(){
	static uint16_t PWM_position=0;
	if(++PWM_position >= PWM_PERIOD){
		PWM_position=0;
	}
	if(PWM_position<PWM_DELTA){
		PWM_ON;	
	}
	else {
		PWM_OFF;
	}
}