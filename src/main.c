//----------------------------------------------------------------------------------------//
//-----------------------------|CattleSensorWirelessProject|------------------------------//
//-----------------------------|SerialCommunicationAtmega16|------------------------------//
//----------------------------------Update:26/03/2014-------------------------------------//
//----------------------------------------------------------------------------------------//
/* Comments:

El codigo compila, sin embargo al probarlo en proteus los caracteres que lee 
y envia son diferentes e incoherentes.

*/
//----------------------------------------------------------------------------------------//



//----------------------------------------------------------------------------------------//
//---------Begin:Librerias----------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
//----------------------------------------------------------------------------------------//
//---------End:Librerias------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------//
//---------Begin:Constantes---------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
#define FOSC 100000000// Frecuency Clock Speed FOSC
#define BAUD 19200  //Bits Rate
#define MYUBRR FOSC/16/BAUD-1 // Ecuacion sacada del datasheet del Micro
//----------------------------------------------------------------------------------------//
//---------End:Constantes-----------------------------------------------------------------//
//----------------------------------------------------------------------------------------//



//----------------------------------------------------------------------------------------//
//---------Begin:Declaración de Funciones-------------------------------------------------//
//----------------------------------------------------------------------------------------//
void init_ports(void); //Inicializa los puertos
void select_ADC_port(int i);// Seleccion cual puerto de ADC leer
void USART_Init( unsigned int ubrr); // Inicializa serial
void USART_Transmit( unsigned char data ); //Envia letra por serial
void segment7Display(int valor);
void sendDataSerial(int data[]);
unsigned char USART_Receive( void ); //Lee letra por serial

//----------------------------------------------------------------------------------------//
//---------Begin:Declaración de Funciones-------------------------------------------------//
//----------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------------------//
//---------Begin:MAIN---------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
void main( void )
{
	
	init_ports(); // Inicializa puertos A=>ADC, B=Inputs ,C=Outputs , D=Outputs
	
	int i=0; // Inicializo la variable i=0 como entero
	int Stop=0; // Inicializo Stop=0;
	int gasValue=0; // Inicializo gasValue=0;
	int t=0; // Inicializa t=0;
	int data[24]; // Inicializa el vector de datos con 24 posiciones (24 horas )
	init_ports();
	USART_Init ( MYUBRR );
    while(Stop==0 && t<150){
		
		    //-------------------------------------//
			//Contando el tiempo                   //
		    //-------------------------------------//
			t=t+1;

			//-------------------------------------//
			
			//-------------------------------------//
			//Lectura del valor del Sensor         //
			//-------------------------------------//
			select_ADC_port(0);  // Selecciono pin A0
			gasValue=ADCH; // Asigno pin A0 a gasValue
	        //-------------------------------------//
			
			//-------------------------------------//
			//Generación del vector de Enteros     //
			//-------------------------------------//
			data[i]=gasValue;
			//-------------------------------------//
			

			 _delay_ms(1000);

	}
sendDataSerial(data);

	
}

//----------------------------------------------------------------------------------------//
//---------End:MAIN-----------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//






//-----------------------------------------------------------------------------------------//




//----------------------------------------------------------------------------------------//
//---------Begin:Funciones----------------------------------------------------------------//
//----------------------------------------------------------------------------------------//


// USART_init Inicializa los registros y los puertos para comunicacion serial
void USART_Init( unsigned int ubrr)
{
	/* Set baud rate */
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 1stop bit */
	UCSRC = (1<<URSEL)|(0<<USBS)|(3<<UCSZ0);
}


//USART_Transmit Envia una letra char por serial 
void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR = data;
}


//USART_Recieve Recibe una letra char por serial 
unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}

//Init_Port iniciliza los puertos : A input,B input,C output, D output.
void init_ports(void){

	MCUCSR|=(1<<JTD);
	MCUCSR|=(1<<JTD);
	DDRA=0x00;	//Defino Puerto A como Inputs
	PORTA=0x00;     //Habilito los puertos de A
	DDRB = 0x00;    //Defino Puerto B como Inputs
	PORTB=0x00;     //Habilito los puertos de B

	DDRC=0xff;		//Defino Puerto C como Outputs
	PORTC=0x00;     //Habilito los puertos de C
	DDRD = 0xff;    //Defino Puerto D como Outputs
	PORTD=0x00;     //Habilito los puertos de D

	ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); // Habilito preescaler para tener una buena resolucion de datos de ADC

}

//Select_ADC_port selecciona cual puerto ADC se va a leer.
void select_ADC_port(int i){
	ADMUX = _BV(ADLAR) + i; // Selecciona un pin de las entradas analogas ADC[i]
	ADCSRA |= _BV(ADSC); //Comienza conversion
	while (ADCSRA & _BV(ADSC) ) {}  // Esperar la conversion

	}

//7segmentDisplay utiliza el puerto p, e imprime el valor de 0-99
void segment7Display(int valor)
{
	PORTC=0x05;

}

//Enviar datos de un vector por serial
void sendDataSerial(int data[])
{
int l=strlen(data);
int i=0;
int sendData=0;
char c;
while(i<l)
{
if(data[i]<100 && data[i]>0){sendData=0;}
if(data[i]<200 && data[i]>100){sendData=1;}
if(data[i]<300 && data[i]>200){sendData=2;}
if(data[i]<400 && data[i]>300){sendData=3;}
if(data[i]<500 && data[i]>400){sendData=4;}
if(data[i]<600 && data[i]>500){sendData=5;}
if(data[i]<700 && data[i]>600){sendData=6;}
if(data[i]<800 && data[i]>700){sendData=7;}
if(data[i]<900 && data[i]>800){sendData=8;}
if(data[i]<1000 && data[i]>900){sendData=9;}
		
c = char(sendData[i]+'0');
USART_Transmit(c);
i=i+1;
}

}


//----------------------------------------------------------------------------------------//
//---------End:Funciones-----------------------------------------------------------------//
//---------------------------------------------------------------------------------------//
