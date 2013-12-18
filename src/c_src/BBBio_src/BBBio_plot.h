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
void plot(void);
void plot_number(int j);
//---------------------------------------------//


//-----------------------------------------------------//
//--------------Funciones de la libreria---------------//
//-----------------------------------------------------//

void plot(void){
FILE *gplot = popen("gnuplot -persist","w");
  fprintf(gplot, "set term png\n");
  fprintf(gplot, "set output 'Plot_Data.png'\n");
  fprintf(gplot, "set xlabel 'Segundos\n");
  fprintf(gplot, "set ylabel 'Concentracion de Metano [ppm]'\n");
  
  fprintf(gplot, "set title 'Gas(t)'\n");
  fprintf(gplot, "unset key\n");
  fprintf(gplot, "plot 'Data.txt' using 1:2 \n");
  fclose(gplot);
}

void plot_number(int j){
 char filename[50]="";
 char format[17]=".txt'  using 1:2\n";
 char indice[2]="";
 intToChar(j,indice);

 strcat(filename,"plot 'Data");
 strcat(filename,indice);
 strcat(filename,format);

 char plotname[50]="";
 char formatplot[17]=".png '\n";
 char indiceplot[2]="";
 intToChar(j,indiceplot);

 strcat(plotname,"set output 'Plot_Data ");
 strcat(plotname,indiceplot);
 strcat(plotname,formatplot);
   FILE *gplot = popen("gnuplot -persist","w");
  fprintf(gplot, "set term png\n");
  fprintf(gplot, plotname);
  fprintf(gplot, "set xlabel 'Segundos\n");
  fprintf(gplot, "set ylabel 'Concentracion de Metano [ppm]'\n");
  
  fprintf(gplot, "set title 'Gas(t)'\n");
  fprintf(gplot, "unset key\n");
  fprintf(gplot,filename);
  fclose(gplot);
}


