#!/usr/bin/python3
# script baseado no c d i g o disponibilizado em:
# Derek Molloy , Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux ,
# Wiley 2016 , ISBN 978 -1 -119 -1868 -1 , http :// www. exploringrpi . com /

import sys
from time import sleep
LED_PATH="/sys/class/gpio/gpio"
SYSFS_DIR ="/sys/class/gpio/"
LED_NUMBER=""

def writeLED (filename,value,path=LED_PATH):
  fo=open(path+filename,"w")
  fo=(path+filename,"w")
  fo.write(value)
  fo.close()
  print(filename)
  return

print(" Iniciando o script Python para alterar a gpio " + LED_NUMBER + ".")

for i in ["16","20","21"]:
  print("inicio export")
  LED_NUMBER=i
  writeLED (filename="export",value=i,path=SYSFS_DIR)
  writeLED (filename ="direction",value ="out")
  print("fim export")

for j in range(1,5):
	print("Acendendo o LED vermelho")
	LED_NUMBER="20"
	writeLED(filename="value", value ="1",path=LED_PATH+LED_NUMBER+"/")
	sleep (2)
	print("Apagando o LED vermelho")
	writeLED(filename="value", value ="0",path=LED_PATH+LED_NUMBER+"/")
  
	print("Acendendo o LED verde")
	LED_NUMBER="21"
	writeLED(filename="value", value ="1",path=LED_PATH+LED_NUMBER+"/")
	sleep (1)
	print("Apagando o LED verde")
	writeLED(filename="value", value ="0",path=LED_PATH+LED_NUMBER+"/")

	print("Acendendo o LED amarelo")
	LED_NUMBER="16"
	writeLED(filename="value", value ="1",path=LED_PATH+LED_NUMBER+"/")
	sleep (1)
	print("Apagando o LED amrelo")
	writeLED(filename="value", value ="0",path=LED_PATH+LED_NUMBER+"/")
	
for i in ["16","20","21"]:
	LED_NUMBER=i
	print ("Desabilitando a gpio")
	writeLED(filename="unexport", value=LED_NUMBER, path=SYSFS_DIR)

print("Fim do script Python.")