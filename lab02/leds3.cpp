# include <iostream>
# include <fstream>
# include <string>
# include <unistd.h>
using namespace std ;
# define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIO (string path,string filename,string value ){
fstream fs;
fs.open ((path + filename).c_str(),fstream::out );
fs << value ;
fs. close ();
}

int main () {
char GPIO_NUMBER
char GPIO_PATH

cout << "Iniciando o programa em C++ para alterar a gpio" << endl ;

cout << " Habilitando a gpio " << endl ;
GPIO_NUMBER="16"
writeGPIO (string (GPIO_SYSFS),"export",GPIO_NUMBER);
usleep (100000) ;

GPIO_NUMBER="20"
writeGPIO (string (GPIO_SYSFS),"export",GPIO_NUMBER);
usleep (100000) ;

GPIO_NUMBER="21"
writeGPIO (string (GPIO_SYSFS),"export",GPIO_NUMBER);
usleep (100000) ;


writeGPIO (string(GPIO_PATH), "direction", "out");

for( int i=1; i<5; i=i+1){
	cout << " Acendendo o LED" << endl ;
	GPIO_PATH "/sys/class/gpio/gpio20/"
	writeGPIO (string(GPIO_PATH),"value","1");
	usleep (200000) ;

	cout << "Desligando o LED" << endl ;
	writeGPIO(string(GPIO_PATH),"value","0");

	GPIO_PATH "/sys/class/gpio/gpio21/"
	writeGPIO (string(GPIO_PATH),"value","1");
	usleep (100000) ;

	cout << "Desligando o LED" << endl ;
	writeGPIO(string(GPIO_PATH),"value","0");

	GPIO_PATH "/sys/class/gpio/gpio16/"
	writeGPIO (string(GPIO_PATH),"value","1");
	usleep (100000) ;

	cout << "Desligando o LED" << endl ;
	writeGPIO(string(GPIO_PATH),"value","0");
	}

cout << "Desabilitando a gpio" << endl ;
GPIO_NUMBER="16"
writeGPIO(string(GPIO_SYSFS),"unexport",GPIO_NUMBER);

GPIO_NUMBER="20"
writeGPIO(string(GPIO_SYSFS),"unexport",GPIO_NUMBER);

GPIO_NUMBER="21"
writeGPIO(string(GPIO_SYSFS),"unexport",GPIO_NUMBER);

cout << "Fim do programa em C ++." << endl ;
return 0;
}