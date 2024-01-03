#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char nombre[20];
	float nota;
	
	ifstream entrada ("TEXTO1.TXT");
	
	if(entrada ==0)
	{
		cout <<"\nERROR AL ABRIR EL ARCHIVO \n\n";
		system("pause");// colocar mensaje en pantalla
		return 0;
	}
	entrada >> nombre >> nota;
	cout<< nombre << " " <<nota<< endl;
	entrada>> nombre >> nota;
	cout<< nombre << " " <<nota<< endl;
	entrada>> nombre >> nota;
	cout<< nombre << " " <<nota<< endl;
	
	entrada.close();
	return 0;
}
