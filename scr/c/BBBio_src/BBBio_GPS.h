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
double Read_latGPS(int lat_out);
//---------------------------------------------//


//-----------------------------------------------------//
//--------------Funciones de la libreria---------------//
//-----------------------------------------------------//

double Read_latGPS(int lat_out){
char command[500]="head -50 /dev/ttyO2 > ~/Desktop/jorgedatosgpsnuevoparquevean.txt";
FILE *TestConsole= popen(command,"w");
fclose(TestConsole);
printf("...Se hiso el cat..\n");
char command1[500]=" grep '$GPGLL' ~/Desktop/jorgedatosgpsnuevoparquevean.txt > ~/Desktop/jorgelatlong.txt";
FILE *TestConsole1= popen(command1,"w");
fclose(TestConsole);
printf("...Se hiZo el grep...\n");

FILE *in;
in = fopen("jorgelatlong.txt","r+");
char latlong[200];
int length=0;
    fgets(latlong,100,in);
     printf("... ya se guardó la primera línea...\n");
     
 char *s;
 int valido=0;
 int c=0;
  s = strchr (latlong, 'V');

  if (s != NULL){
    printf ("......found a 'V' at .......%s\n", s);
valido=0;
}else {printf(".....not found 'V' el dato es válido.........\n");
valido=1;}

// $GPGLL,0436.1094,N,07403.9133,W,200304.000,A,A*4

 c = fgetc(in); //$
 c = fgetc(in); //G
 c = fgetc(in); //P
 c = fgetc(in); //G
 c = fgetc(in); //L
 c = fgetc(in); //L
 c = fgetc(in); // comma

// North//
int g1N,g2N,m1N,m2N,m3N,m4N,m5N,m6N;

int gN=0;
int mN=0;
int norte=0;
//degrees 
 g1N = fgetc(in);  
 g2N = fgetc(in); 
//minutes
 m1N = fgetc(in); 
 m2N = fgetc(in); 
 c = fgetc(in); // punto
 m3N = fgetc(in); 
 m4N = fgetc(in); 
 m5N = fgetc(in); 
 m6N = fgetc(in);
 c = fgetc(in); // comma
// north or south
 norte= fgetc(in); // NORTE
 c = fgetc(in); // comma

// West//
int g1W,g2W,g3W,m1W,m2W,m3W,m4W,m5W,m6W;

int gW=0;
int mW=0;
int west=0;

//degrees
 g1W = fgetc(in);  
 g2W = fgetc(in); 
 g3W = fgetc(in); 
//minutes
 m1W = fgetc(in); 
 m2W = fgetc(in); 
 c = fgetc(in);  
 m3W = fgetc(in); 
 m4W = fgetc(in); 
 m5W = fgetc(in);
 m6W = fgetc(in); 

 c = fgetc(in);
 west= fgetc(in);
 c = fgetc(in); 

 printf("El dato norte es : %c %c %c %c . %c %c %c %c \n",g1N,g2N,m1N,m2N,m3N,m4N,m5N,m6N);
 printf("El dato oeste es : %c %c %c %c %c . %c %c %c %c \n",g1W,g2W,g3W,m1W,m2W,m3W,m4W,m5W,m6W);

double latitud=28.535219;
double longitud=(-1)*81.382456;

 printf("la latitud es: %f  N \n",latitud);
 printf("la longitud es: %f  W \n",longitud);

char str_latitud[500];
sprintf(str_latitud,"%f",latitud);
char str_longitud[500];
sprintf(str_longitud,"%f",longitud);

printf("la latitud (string) es: %s  N \n",str_latitud);
 printf("la longitud (string) es: %s  W \n",str_longitud);

if(lat_out==1){return latitud;}
else{return longitud;}

}

