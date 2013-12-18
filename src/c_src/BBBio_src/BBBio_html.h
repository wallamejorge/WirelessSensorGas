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
void HTML_LatLongWrite(double lat , double lon);
void updateGoogleMaps(void);
//---------------------------------------------//


//-----------------------------------------------------//
//--------------Funciones de la libreria---------------//
//-----------------------------------------------------//

void HTML_LatLongWrite(double lat , double lon)
{

char str_latitud[500];
sprintf(str_latitud,"%f",lat);
char str_longitud[500];
sprintf(str_longitud,"%f",lon);

printf("la latitud (string) es: %s  N \n",str_latitud);
 printf("la longitud (string) es: %s  W \n",str_longitud);

FILE *in;
in = fopen("main_html.html","r+");
int fin=feof(in);
int i=0;
char caracteres[100];
char cadena1[200] = "center: new google.maps.LatLng( ";
char cadena3[200] = ",";
char cadena5[200] = "), \n";

strcat(cadena1,str_latitud);
strcat(cadena1,cadena3);
strcat(cadena1,str_longitud);
strcat(cadena1,cadena5);

while (feof(in) == 0){
    fgets(caracteres,100,in);
    i=i+1;
if(i==101){fputs( cadena1, in );break;}
  }
}

void updateGoogleMaps(void){
char command[100]="firefox main_html.html &";
FILE *TestConsole= popen(command,"r");
fclose(TestConsole);
}

