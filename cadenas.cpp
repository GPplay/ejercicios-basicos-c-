//strlen(cad) == retorna la logintud de cad
//strcoy(cad, cad 2) == asigna cad2 en cad1
//strcat(cad1, cad2) == agrega cad2 al final de cad1
//strcmp(cad1, cad2) == retorna cero si cad1= cad2, retorna 0 si las cad1>cad2, retorna 0 si cad1<cad2

/*
escribir un programa que lea una cadena de caracteres y muestre en pantalla su longitud.*/
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char cad[30];
	
	cout<<"ingrese cadena de caracteres: ";
	gets(cad);
	
	cout<<"\nLongitud de la candena: "<<strlen(cad)<<endl;
	return 0;
}

