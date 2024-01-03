/*
escribir un programa que lea dos cadenas de caracteres y muestre un mensaje en pantalla
que indique si son iguales, y si son diferente que indique cual cadena es mayor
*/
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char cad1[30], cad2[30];
	
	cout<<"ingrese cadena 1: ";
	gets(cad1);
	cout<<"ingrese cadena 2: ";
	gets(cad2);
	
	if(strcmp(cad1,cad2) == 0) // if(cad1== cad2) incorrecto
	{
		cout<<cad1<<" = "<<cad2<<endl;
	}
	else
	{
		if (strcmp(cad1,cad2) > 0)
		{
			cout<<cad1<<" > "<<cad2<<endl;
		}
		else
		{
			cout<<cad1<<" < "<<cad2<<endl;
		}
	}
	return 0;
}
