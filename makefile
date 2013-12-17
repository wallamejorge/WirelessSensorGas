#----------------------------------------------------------------#
#------Makefile Proyecto Wireless Sensor Gas modelo Vitia-0------#
#----------------------------------------------------------------#

#----------------------------------------------------------------#
#----------Autor:Jorge Luis Mayorga Taborda----------------------#
#----------------------------------------------------------------#

#----------------------------------------------------------------#
#---------------------Set Up Makefile----------------------------#
#----------------------------------------------------------------#
COMPILER := arm-angstrom-linux-gnueabi-gcc
MODULOS = ventana.o gestion.o bd.o juego
.PHONY : clean install
#----------------------------------------------------------------#

#----------------------------------------------------------------#
#---------------------Comandos Make------------------ -----------#
#----------------------------------------------------------------#


#-----------------BBBcp:Copia a la Beagle------------------------#
#----------------------------------------------------------------#
BBBcp: BlinkingLed.c BBBio.h makefile
	scp -r BBBio.h main.c makefile main_html.html root@192.168.7.2:Desktop
#----------------------------------------------------------------#



#-----------------BBBcMain:Compila Main.c------------------------#
#----------------------------------------------------------------#	
BBBcMain: main.c
	arm-angstrom-linux-gnueabi-gcc -o  main.app main.c
#----------------------------------------------------------------#



#---------------BBBrm:Elimina todo el contenido------------------#
#----------------------------------------------------------------#
BBBrm:
	rm -r *
#----------------------------------------------------------------#



#------------BBBrun:Elimina temporales y corre main.app----------#
#----------------------------------------------------------------#
BBBrun:
	rm *.png *.txt 
	./main.app
#----------------------------------------------------------------#
