/*
 * TP4E.c
 *
 * Created: 24/7/2024 16:24:41
 * Author : LENOVO
 */ 

#include "main.h"
volatile uint8_t nuevoComando=0;
// Define un mensaje de inicio
char msg[] = "Introduzca R para cambiar la intensidad de rojo, G para la del verde, B para la del azul. Una vez ajustada la intensidad, presione S \n\r";

int main(void)
{
	DDRB |= (1 << PORTB5) | (1 << PORTB2) | (1 << PORTB1);// Configuro como salidas
	Terminal_Init();//Inicializo terminal
	Timer0_Init();//Inicializo Timer0
	Timer1_Init();//Inicializo Timer1
	uint8_t color=0; //Indica el color que se va a modificar 1:Rojo,2:Verde,3:Azul,4:Terminar
	uint8_t rojo=128,azul=128,verde=128; //Intesidad media de los colores
	OCR1A=azul;
	OCR1B=verde;
	
	SerialPort_Send_String(msg);//Envia mensaje de inicio al puerto serie
	while (1)
	{
		if (nuevoComando)
		{
			color=Terminal_color();//obtengo color a modificar
			//Si es el rojo 
			if (color==1){
				//while(color==1){
					//_delay_ms(100);
					rojo=ADC_LEER();//obtengo posicion del potenciometro
					Terminal_imprimirValor(rojo);
					//if (nuevoComando)
					//{
						//color=Terminal_color();
						//if(color !=4) color=1;
					//}
				//}
				OCR0A=255-rojo;
				SerialPort_Send_String(msg);
			}
			//Si es el verde
			else if (color==2){
					//while(color==2){
						//_delay_ms(100);
						verde=ADC_LEER();//obtengo posicion del potenciometro
						Terminal_imprimirValor(verde);
						//if (nuevoComando)
						//{
							//color=Terminal_color();
							//if(color !=4) color=2;
						//}
					//}
					OCR1B=255-verde;
					SerialPort_Send_String(msg);//
			}
			//Si es el Azul
			else if (color==3) {
					//while(color==3){
						//_delay_ms(100);
						azul=ADC_LEER();//obtengo posicion del potenciometro
						Terminal_imprimirValor(azul);
						//if (nuevoComando)
						//{
							//color=Terminal_color();
							//if(color !=4) color=3;
						//}
					//}
					OCR1A=255-azul;
					SerialPort_Send_String(msg);//
			}
		}
	}
}

