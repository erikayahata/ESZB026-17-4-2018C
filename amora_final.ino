// Código criado a partir do exemplo le_pot_serial.ino de Erick Dario
// Disciplina ESZB026-17
#include <Wire.h>
#include <SFE_MMA8452Q.h>

MMA8452Q acel1(0x1C);   // Acelerometro de referência
MMA8452Q acel2(0x1D);   // Acelerometro mão
int vermelho=1;
int verde=2;
int botao=3;
float modacel1=0;
float modacel2=0;
float alfa=180;
int iniciaColeta = 0;
int i=0;
boolean ler=true;
char charRecebido;       // cria uma variavel para armazenar o caractere recebido

void setup(){
  // Inicia os leds
  pinMode(vermelho,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(botao,INPUT);
  // Configura a serial: baud rate de 115200, 8-bit, sem paridade, 1 stop bit
  Serial.begin(115200, SERIAL_8N1);
  digitalWrite(verde, HIGH);          //Equivalente ao "Teste de comunicação"
  //Inicializa o acelerometro com o valores padrao de +/-2g e
  //saida de 800 Hz
  acel1.init();
  acel2.init();
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, HIGH);       //Equivalente ao "Deu bom."
}

void loop(){
  if (ler==true){
    if (Serial.available()){           // verifica se recebeu algum comando
      charRecebido = Serial.read();    // le o caractere recebido
      switch ( charRecebido ){
        case 'i':                      // inicia coleta
           iniciaColeta = 1;
           break;
        case 'p':                      // para a coleta
           iniciaColeta = 0;
           break;
        default:                       // outro comando, ignora...
           break;
      }
    }
    if ( iniciaColeta == 1 ){
      if (acel1.available() && acel2.available() ){
        for(i;i<40;i++){
          digitalWrite(verde, LOW);
          digitalWrite(vermelho, LOW);
          delay(250);
          //Efetua a leitura dos dados do sensor
          acel1.read();
          acel2.read();
          // acel.read() atualiza dois grupos de variaveis:
          //* int x, y, e z armazena o valor de 12 bits lido do acelerometro
          //* float cx, cy, e cz armazena o calculo da aceleracao dos valores (unidades de 'g')
          //Mostra as coordenadas lidas do sensor
          printCalculatedAccels();
          int valor = alfa;
          Serial.write(valor & 0xFF);          // envia byte menos significativo
          Serial.write(valor >> 8);            // envia byte mais significativo*/
          digitalWrite(vermelho, HIGH);
          if (i==39){
            digitalWrite(verde, HIGH);
            ler=false;
            break;
          }
        }
      }
    }
  }else{
    delay(100);         // aguarda 100ms
  }
}


void printCalculatedAccels(){ 
  //Serial.print(acelerometro.cx, 3); //Não é o plano de interesse
  float modacel1=0;
  float modacel2=0;
  
  //Calculo de alfa:
  //cos(alfa)=(((a1.cy[0]*a2.cy[0])+(a1.cy[1]*a2.cy[1])+(a1.cy[2]*a2.cy[2]))/(moduloa1*moduloa2))
  modacel1 = sqrt((sq(acel1.cy))+(sq(acel1.cz))); //modulo resultante a1
  modacel2 = sqrt((sq(acel2.cy))+(sq(acel2.cz))); //modulo resultante a2
  alfa = (180/3.1415)*acos(((acel1.cy*acel2.cy)+(acel1.cz*acel2.cz))/(modacel1*modacel2)); //alfa
  if(acel2.cy>=0){
    alfa=alfa+180;
  }else{
    alfa=180-alfa;
  }
  //Serial.println(alfa);
}
