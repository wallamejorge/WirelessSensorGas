BBBcp: BlinkingLed.c BBBio.h makefile
	scp -r BBBio.h main.c makefile main_html.html root@192.168.7.2:Desktop
	
BBBcMain: main.c
	arm-angstrom-linux-gnueabi-gcc -o  main.app main.c
BBBrm:
	rm -r *
BBBrun:
	rm *.png *.txt 
	./main.app
