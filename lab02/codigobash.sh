#!/bin/bash

echo 20 >> "/sys/class/gpio/export"
sleep 1
echo 16 >> "/sys/class/gpio/export"
sleep 1
echo 21 >> "/sys/class/gpio/export"
sleep 1

echo "out" >> "/sys/class/gpio/gpio20/direction"
echo "out" >> "/sys/class/gpio/gpio21/direction"
echo "out" >> "/sys/class/gpio/gpio16/direction"
function setLED

{
	echo $1 >> "/sys/class/gpio/gpio$led/value"
}
for i in $(seq 5)
do 
led=20
setLED 1
sleep 2
setLED 0
led=21
setLED 1
sleep 1
setLED 0
led=16
setLED 1
sleep 1
setLED 0
done

echo 16 >> "/sys/class/gpio/unexport"
sleep 1
echo 20 >> "/sys/class/gpio/unexport"
sleep 1
echo 21 >> "/sys/class/gpio/unexport"
sleep 1