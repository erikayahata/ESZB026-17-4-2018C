#!/bin/sh
ARQUIVODADOS=/home/pi/sist_embarcados_git/Amora/dados.txt
ARQUIVOSAIDA=/home/pi/sist_embarcados_git/Amora/dados.png

gnuplot << EOF
set title "Dados: "
set ylabel "Angulo (º)"
set xlabel "Tempo (s/4)"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#0060ad' \
     linetype 1 \
     linewidth 1 \
     pointtype 2 \
     pointsize 1.0 \
     title "Dados obtidos:" \
     with linespoints
EOF