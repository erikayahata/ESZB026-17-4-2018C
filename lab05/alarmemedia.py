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

# tempo de cada nota = 0,1 segundo
tempo=0.5
# frequencias das notas musicais:
# C4 = 261,6Hz; D4 = 293,7Hz; E4 = 329,6Hz; F4 = 349,2Hz ...
freqs=261.6
# eh possivel alterar a escala multiplicando as frequencias por um numero inteiro
escalas=1
# indice das notas: 0=>C4; 1=>D4; 2=>E4; 3=>F4 ...
notas=0
duracao=[1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 2]

for s in range(3):
    meuPWM.ChangeDutyCycle(50)
    meuPWM.ChangeFrequency(freqs)
    sleep(tempo)
    meuPWM.ChangeDutyCycle(0)
    sleep(tempo/5)

GPIO.cleanup()
