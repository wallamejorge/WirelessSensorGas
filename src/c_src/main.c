/*
Proyecto DistribuitedCattleSensor Vestibulum Sensorem Pulchra-0

Nombres:Jorge Luis Mayorga-Monica Tuta Fajardo-Juan Felipe Martinez Ramos

Descripcion:
 El codigo main.c ejecuta el programa para la tarjeta de desarrollo BeagleBoneBlack para tomar muestras de gases con un sensor termico y    computarlo junto con la posicion GPS tomada de un puerto serial. Inmediatamente se pulse el boton correspondiente al puerto GPIO 44 el sistema para la recoleccion de datos y los grafica usando GNUplot para a su vez generar un portal HTML5 con la grafica y la posicion del animal.
*/
//-----------------------------------------------------//
//--------------Declaracion de Librerias---------------//
//-----------------------------------------------------//
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "BBBio.h" 
//-----------------------------------------------------//
//-----------------------------------------------------//
//-----------------------------------------------------//




//-----------------------------------------------------//
//-------------------Codigo Principal------------------//
//-----------------------------------------------------//
int main(void)
{
  printf("BEAGLEBONE BLACK.....is alive!\n");
  printf("..............................\n");
  double lat= 0.0 ;
  double lon= 0.0 ;
  double analog=0.0;
  int i=0;
  int j=0; 
  int k=0;
  int port=0;
  int Stop=0;
  printf("...Se inicializaron las variables...\n");
         initAnalogPort();
  printf("...Se inicializo los puertos analogos\n");
  	 initDigitalPort(44);
  printf("...Se inicializo el puerto digital 44:P8-12..\n");
  	Stop=PIN_VALUE(44);
  printf("...Arrancamos el Ciclo While de lectura analoga....\n");
  printf("....................................................\n");
  printf(" \n");

  

  printf(" \n");	
     while(Stop==0){
      printf("\n \n Cargando Data%d.txt \n \n",j);
                while(k<10){
  		analog=readADC(port);
		escribirxy_txt_number(i,(analog),j);
  		escribirxy_txt(i,(analog));
                plot();
  		printf("El valor de la concentracion de Metano es %f ppm en el sensor !\n",analog);
  		i=i+1;
		k=k+1;

  		sleep(1);
		Stop=PIN_VALUE(44);
		if(Stop==1){break;}
		}
	  plot_number(j);
	   Stop=PIN_VALUE(44);
           k=0;
          j=j+1;
          plot();
 		 }
  printf("...Se cerro el ciclo...graficando...\n");
 	 plot();
  printf("...Termino la grafica....\n");
  /*
  printf("...Comenzando codigos de GPS...\n");
 	lat=Read_latGPS(1);
 	lon=Read_latGPS(0);
  printf("la latitud es: %f \n", lat );
  printf("la longitud es: %f \n", lon );
  */
 	 HTML_LatLongWrite(lat,lon);
  printf("...Generando archivo de HTML con los Mapas....\n");
  //	updateGoogleMaps();
  printf("...Abriendo Firefox....\n");
  return 0;
}

//-----------------------------------------------------//
//-----------------------------------------------------//
//-----------------------------------------------------//
