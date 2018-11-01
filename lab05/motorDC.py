#!/usr/bin/python3

# ESZB026-17: Produzindo sons com PWM por SOFTWARE.

import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
pinoPWM=18
PWM_freq_Hz=261.6

GPIO.setup(pinoPWM,GPIO.OUT)
meuPWM=GPIO.PWM(pinoPWM,PWM_freq_Hz)
meuPWM.start(0)

meuPWM.ChangeDutyCycle(10)
sleep(5)

meuPWM.ChangeDutyCycle(0)