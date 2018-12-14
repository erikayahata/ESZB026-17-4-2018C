#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg
import numpy as np
import serial
import atexit

win = pg.GraphicsWindow()
win.setWindowTitle('pyqtgraph example: Scrolling Plots')

conexaoSerial = serial.Serial('/dev/ttyACM0',115200)
conexaoSerial.write(b'i')

p1 = win.addPlot()
data1 = np.zeros(300)
curve1 = p1.plot(data1)
ptr1 = 0

def saindo():
    conexaoSerial.write(b'i')
    print('Saindo')

def update():
    global data1, curve1, ptr1, conexaoSerial
    #arquivo = open('dados.txt', 'w')
    if conexaoSerial.inWaiting() > 1:
        dado1 = conexaoSerial.read()
        dado2 = conexaoSerial.read()
        novodado = float( (ord(dado1) + ord(dado2)*256.0)*5.0/1023.0 )
        novodado = novodado*200
        arquivo = open('dados.txt', 'a')
        arquivo.write(str(novodado))
        arquivo.write('\n')
        arquivo.close()
        
        data1[:-1] = data1[1:]  # shift no vetor dados
        data1[-1] = novodado
        curve1.setData(data1)
    
# inicia timer rodando o mais rápido possível
timer = QtCore.QTimer()
timer.timeout.connect(update)
timer.start(300)

atexit.register(saindo)

## Start Qt event loop unless running in interactive mode or using pyside.
if __name__ == '__main__':
    QtGui.QApplication.instance().exec_()
