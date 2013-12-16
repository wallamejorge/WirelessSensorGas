   #!/usr/bin/python
import time, sys, subprocess,os
while True:
	time.sleep(2)
	comando = "scp -r root@192.168.7.2:~/Desktop/*.txt ./data" #Sustituir por el comando deseado
	proceso = subprocess.Popen(comando , shell=True,stdin=subprocess.PIPE,stdout=subprocess.PIPE)
	print '...copying data files from BeagleBone to Server'
	while True:
	    next_line = proceso.stdout.readline()
	    if next_line == '' and proceso.poll() != None:
		break
	    sys.stdout.write(next_line)
	    sys.stdout.flush()
	comando = "scp -r root@192.168.7.2:~/Desktop/*.png ./images/miniPlots" #Sustituir por el comando deseado
	proceso = subprocess.Popen(comando , shell=True,stdin=subprocess.PIPE,stdout=subprocess.PIPE)
	print '...copying plots from BeagleBone to Server'
	while True:
	    next_line = proceso.stdout.readline()
	    if next_line == '' and proceso.poll() != None:
		break
	    sys.stdout.write(next_line)
	    sys.stdout.flush()


