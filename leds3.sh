#!/bin/bash
#
# Acender 3 leds 
#

function setLED
{ 
	echo $1 >> "/sys/class/gpio/gpio$2/value "
	sleep $3
}

for i in {16 20 21}
 do
	LED_GPIO=$i 
	echo " Habilitando a GPIO numero $LED_GPIO"
	echo $LED_GPIO >> "/sys/class/gpio/export"
	sleep 1 # esperar 1 segundo para garantir que a gpio foi ...,! exportada

	echo " out" >> "/sys/class/gpio/gpio$LED_GPIO/direction "
 done

for i in {1..5}
 do 
 	echo " Acendendo o LED vermelho"
 	setLED 1 20 2

	echo " Desligando o LED vermelho"
 	setLED 0 20 0

 	echo " Acendendo o LED verde"
 	setLED 1 21 1

	echo " Desligando o LED verde"
 	setLED 0 21 0

 	echo " Acendendo o LED amarelo"
 	setLED 1 16 1

	echo " Desligando o LED amarelo"
	setLED 0 16 0

done

for i in {16 20 21}
 do
	LED_GPIO=$i 
	echo " Desabilitando a GPIO numero $LED_GPIO"
	echo $LED_GPIO >> "/sys/class/gpio/unexport "
 done
