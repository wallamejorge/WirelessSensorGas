/*
Sub_Libreria de BBBio.h encargada de los puertos analogos
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
int readADC(int port);
void initAnalogPort();
//---------------------------------------------//


//-----------------------------------------------------//
//--------------Funciones de la libreria---------------//
//-----------------------------------------------------//

void initAnalogPort(){
char command[100]="echo cape-bone-iio > /sys/devices/bone_capemgr.8/slots";
FILE *TestConsole= popen(command,"w");
fclose(TestConsole);
}

int readADC(int port)
{
    FILE *puerto;
    if(port==0){
     puerto = fopen("/sys/devices/ocp.2/helper.14/AIN0","r");
    }
    if(port==1){
     puerto = fopen("/sys/devices/ocp.2/helper.14/AIN1","r");
    }
    if(port==2){
     puerto = fopen("/sys/devices/ocp.2/helper.14/AIN2","r");
    }
    if(port==3){
     puerto = fopen("/sys/devices/ocp.2/helper.14/AIN3","r");
    }
    char valor[5];
    int totalADC,potencia,digitos;
    fread(&valor,5,5,puerto);
    int j;
    digitos = 3;
    for(j = 0 ; j < 4 ; j++)
    {
        if(valor[j] == 10)
        {
            digitos = j - 1;
        }
 
    }
    totalADC = 0;
    potencia = 1;
    for(j = digitos ; j >= 0 ; j--)
    {
        totalADC += (valor[j] - 48)*potencia;
        potencia*=10;
    }
 
    fclose(puerto);
 
    return totalADC;
}

