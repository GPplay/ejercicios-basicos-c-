/*Elabore un programa en C++ que lea una cadena de caracteres y muestre
en pantalla la cantidad de palabras que contiene. Se debe implementar
una función que reciba mediante un parámetro por referencia la cadena
leída y retorne la cantidad de palabras.*/
#include <iostream>
#include <string.h>
using namespace std;
int Npalabras( string &p1);
int main()
{
	string cad;
	
	cout<<"ingrese su frase: "<<endl;
	getline(cin, cad);
	
	cout<<"el numero de palabras que tiene tu frase son: "<<Npalabras(cad)<<endl;
	
}
int Npalabras(string &p1)
{
	int count = 1;
	
	for(int i=0; i<=p1.length(); i++)
	{
		if(p1[i] == ' ' && i > 0 && p1[i - 1] != ' ')
		{
			count++;
		}
	}
	
	return count;
} 
