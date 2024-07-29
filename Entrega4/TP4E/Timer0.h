/*
 * Timer0.h
 *
 * Created: 25/7/2024 00:32:24
 *  Author: LENOVO
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include <avr/io.h>
#include <avr/interrupt.h>

void Timer0_Init();
void PWM_soft_Update();



#endif /* TIMER0_H_ */