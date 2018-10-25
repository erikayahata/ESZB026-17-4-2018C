#include<stdio.h>
#include<conio.h>
#define am "16"
#define vm "20"
#define vd "21"
#define gpioam "/sys/class/gpio/gpio16/"
#define gpiovm "/sys/class/gpio/gpio20/"
#define gpiovd "/sys/class/gpio/gpio21/"
#define gpioSysfs "/sys/class/gpio/"

void writeGPIO (char filename[], char value[]){
	FILE* fp;
	fp=fopen(filename, "w+");
	fprintf(fp, "%s", value);
	fclose(fp);
}

int main (void) {
	printf (" Iniciando o programa em C para LEDs. \n");
	writeGPIO (gpioSysfs "export", am);
	usleep (100);
	writeGPIO (gpioam "direction", "out");
	writeGPIO (gpioSysfs "export", vm);
	usleep (100);
	writeGPIO (gpiovm "direction", "out");
	writeGPIO (gpioSysfs "export", vd);
	usleep (100);
	writeGPIO (gpiovd "direction", "out");

	for (int i=0, i<5, i++){
	printf ("Acendendo o LED vermelho \n");
writeGPIO (gpiovm "value", "1");
	usleep(2000);
	printf ("Desligando o LED vermelho \n");
	writeGPIO (gpiovm " value ", "0");

printf ("Acendendo o LED verde \n");
writeGPIO (gpiovd "value", "1");
	usleep(1000);
	printf ("Desligando o LED verde \n");
	writeGPIO (gpiovd " value ", "0");

	printf ("Acendendo o LED amarelo \n");
	writeGPIO (gpioam "value", "1");
	usleep(1000);
printf ("Desligando o LED amarelo \n");
writeGPIO (gpioam "value", "0");
}
	printf (" Desabilitando a gpio \n");
	writeGPIO (gpioSysfs "unexport", am);
	usleep (100);
	writeGPIO (gpioSysfs "unexport", vm);
	usleep (100);
	writeGPIO (gpioSysfs "unexport", vd);
	usleep (100);
	printf (" Fim do programa em C.\n");
}