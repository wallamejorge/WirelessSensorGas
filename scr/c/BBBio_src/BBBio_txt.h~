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
void escribirxy_txt(float x,float y);
void escribirxy_txt_number(float x,float y,int numbername);
//-----------------------------------------------------//


//-----------------------------------------------------//
//--------------Funciones de la libreria---------------//
//-----------------------------------------------------//
void escribirxy_txt(float x,float y){
  time_t tiempo = time(0);
  struct tm *tlocal = localtime(&tiempo);
  char output[128];
  strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
  FILE *fileout;
  int i=0;
  char filename[26]="Data";
  char format[5]=".txt";

  strcat(filename,format);
  
  fileout=fopen(filename,"a");
  fprintf(fileout,"%f %f %s \n",x,y,output);
  fclose(fileout);

}

void escribirxy_txt_number(float x,float y,int numbername){
  time_t tiempo = time(0);
  struct tm *tlocal = localtime(&tiempo);
  char output[128];
  strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
  FILE *fileout;
  int i=0;
  char filename[26]="Data";
  char indice[3]="";
  char format[5]=".txt";
  intToChar(numbername,indice);
  strcat(filename,indice);
  strcat(filename,format);
  fileout=fopen(filename,"a");
  fprintf(fileout,"%f %f %s \n",x,y,output);
  fclose(fileout);
}

