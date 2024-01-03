#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream trabajo("TEXTO1.TXT");// ofstream es un tipo de variable especial de la librerira fstream, ofstream para crear archivosz sea de tipo TXT o del que sea
	
	if (trabajo == 0)
	{
		cout<<"\nERROR AL ABRIR EL ARCHIVO. \n\n";
		system ("pause");
		return 0;
	}
	trabajo <<"gybram_llamas "<<4.56<<endl;
	trabajo <<"dadvid_franco "<<3.38<<endl;
	trabajo <<"maria_jose "<< 4.27<<endl;
	
	trabajo.close(); //cerrar el archivo
	cout<<"\n ARCHIVO CREADO CON EXISTO PERRO HPTA!\n";
	return 0;
}
