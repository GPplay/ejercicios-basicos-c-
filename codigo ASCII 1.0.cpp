/*
escribir un programa que lea un caracter y muestre en pantalla su codifo ASCII
*/
#include<iostream>
using namespace std;
int main()
{
	char c;
	int cod;
	
	cout<<"ingrese un caracter: ";
	cin>>c;
	
	cod = c; // asigna el codigo ASCII del caracter
	
	cout<<"\n CODIGO ASCII: "<<cod<<endl;
	
	return 0;
}
