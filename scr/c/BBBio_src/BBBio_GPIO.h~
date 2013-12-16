/*
Sub_Libreria de BBBio.h encargada de los puertos GPIO
Autor:Jorge Luis Mayorga Taborda
*/

//-----------------------------------------------------//
//--------------Declaracion de Librerias---------------//
//-----------------------------------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
//-----------------------------------------------------//
//-----------------------------------------------------//
//-----------------------------------------------------//




//-----------------------------------------------------//
//--------------Declaracion de Funciones---------------//
//-----------------------------------------------------//
int  PIN_VALUE(int n);
void PIN_ON(int n);
void PIN_OFF(int n);
void PIN_BLINKING(int pin);
void initDigitalPort(int  port);
void intToChar(int j,char indice[]);
//---------------------------------------------//


//-----------------------------------------------------//
//--------------Funciones de la libreria---------------//
//-----------------------------------------------------//

void PIN_ON(int n)
{
  char command[100]="echo high > /sys/class/gpio/gpio";
  char no_pin[2]="";
  char comman_end[11]="/direction";
  int j=n;
  intToChar(j,no_pin);
  strcat(command,no_pin);
  strcat(command,comman_end);
FILE *TestConsole= popen(command,"w");
fclose(TestConsole);
}

void PIN_OFF(int n)
{
  char command[100]="echo low > /sys/class/gpio/gpio";
  char no_pin[3]="";
  char comman_end[11]="/direction";
  int j=n;
  intToChar(j,no_pin);
  strcat(command,no_pin);
  strcat(command,comman_end);
FILE *TestConsole= popen(command,"w");
fclose(TestConsole);
}

void PIN_BLINKING(int pin)
{
  while(1==1){
  PIN_OFF(pin);
  sleep(1);
  PIN_ON(pin);
  sleep(1);
}
}

int PIN_VALUE(int n)
{
  FILE *in;
  char command[100]="/sys/class/gpio/gpio";
  char no_pin[2]="";
  int valuePin=0;
  char comman_end[11]="/value";
  int j=n;
  intToChar(j,no_pin);
  strcat(command,no_pin);
  strcat(command,comman_end);
  char caracteres[3];
  in = fopen(command,"r");
  fgets(caracteres,2,in);
  fclose(in);
  if(caracteres[0]=='1'){valuePin=1;}
  else {valuePin=0;}
   return valuePin;
}

void initDigitalPort(int port){
char command[100]="echo ";
  char no_pin[2]="";
  char comman_end[100]=" > /sys/class/gpio/export";
  int j=port;
  intToChar(j,no_pin);
  strcat(command,no_pin);
  strcat(command,comman_end);
FILE *TestConsole= popen(command,"w");
fclose(TestConsole);

}





