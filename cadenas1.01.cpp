/* escribir un programa que lea dos cadenas de caracteres,en la primera se tendran los nombes de una persona y 
en las segunda los apeelidos. se debe almernca en otra cadena los nombres y apellidos completos
separados por un espacio*/ 

#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char nombres[40], apellidos[40], cad[80];
	
	cout<<"ingrese sus apellidos: ";
	gets(apellidos);
	cout<<"ingrese sus nombres: ";
	gets(nombres);
	
	strcpy(cad, nombres); // cad = nombres; INCORRECTO
	
	strcat(cad," ");
	
	strcat(cad, apellidos); 
	
	cout<<"\nNombres y apellidos completos: "<<cad<<endl;
	
	return 0;
}
