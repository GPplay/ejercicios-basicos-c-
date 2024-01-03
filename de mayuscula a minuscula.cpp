/*  convirtiendo letras de minuscula a mayuscula con codifo acsii*/ 

#include<iostream>
#include<string.h>
using namespace std;
void mayusculas(char *c);
int main()
{
	char cad[40];
	cout<<"ingrese palabra o frease; ";
	gets(cad);
	
	mayusculas(cad);
	
	cout<<"\nPALABRA O FRASE: "<<cad<<endl;
	return 0;
	
}
void mayusculas(char *c)
{
	for(int i=0; i<strlen(c); i++)
	{
		if(c[i]>=97 && c[i]<=122)
		{
			c[i] -= 32; // c[i] = c[i] - 32;
		}
	}
}
