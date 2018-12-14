#!/bin/bash

ARQUIVODADOS=/home/pi/sist_embarcados_git/Amora/dados.txt
echo "Content-type: text/html"
echo ""
echo '<HTML><HEAD><meta charset="UTF-8">'
echo '<TITLE>Projeto Amora - Grupo 4 (ESZB026-17)</TITLE></HEAD>'
echo '<BODY style="background-color:#FFAA00"><H1>Leitura de angulação de punho.</H1>'
echo 'Estou no diretório '
pwd
echo ', logado como o usuário '
whoami
echo '.<br>'
echo '<h2>DADOS:</h2>'
echo '<pre>'
cat $ARQUIVODADOS
echo '</pre>'
echo '<br>'
echo '<br>'
echo '<h2>LEITURA:</h2>'
echo 'Referenciando a imagem como "/cgi-bin/leitura.cgi":<br>'
echo '<img src="/cgi-bin/leitura.cgi">'
echo '<br>'
echo 'Fim da leitura. Aperte o botão para reiniciar.'
echo '</HTML>'