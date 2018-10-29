#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>
              
int main(){
	int valor=0;
	int pino = 23;                         // pwm por software na GPIO23
	int brilho, count, file;
	int range = 100;                           // periodo do PWM = 100us*range
        unsigned char receive[100];
	wiringPiSetupGpio();                       // usar a numeracao GPIO, nao WPi
	pinMode(pino,OUTPUT);	           // configura GPIO23 como saida
	softPwmCreate(pino, 1, range);         // inicializa PWM por software
	while (1) {
		if ((count=read(file, (void*)receive, 100))<0){
      		perror("Falha ao ler da entrada.\n");
      		return -1;
   		}
   		if (count==0) printf("Nao havia dados para led.\n");
   		else {
     		receive[count]=0;  // o Arduino nao envia o caractere nulo (\0=0)
      		printf("Foram lidos [%d] caracteres: %s\n",count,receive);
         	sscanf(receive,"%d",&valor);
         	printf("Valor ajustado: %d\n",valor);
      		
		softPwmWrite (pino, brilho); // altera o duty cycle do PWM
		delay (10) ;
		}
	}
}