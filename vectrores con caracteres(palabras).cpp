/*
ESCRIBIR UN PROGRAMA QUE LEA UNA CADENA DE CARACTERES Y CALCULE SU LONGITUD. SE DEBE IMPLEMENTAR
UNA FUNCION QUE RECIBA COMO PARAMETRO LA CADENA LEIDA Y RETORNE SU LONGITUG
*/
#include <iostream>
using namespace std;
int longitud_cadena(char *c);
int main()
{
	char frase[100];
	cout<<"Ingrese una frase: ";
	cin.getline(frase,100,'\n');
	cout<<"\nLONGITUD DE LA CADENA: "<<longitud_cadena(frase)<<endl;
	return 0;
}

int longitud_cadena(char *c)
{
	int cont;
	for(cont=0; c[cont] != '\0'; cont++);
	return cont;
}

