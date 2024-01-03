/*
Elabore una función recursiva que calcule la potencia de un número entero positivo.
*/
#include <iostream>
using namespace std;
float potencia(float b, long e);

int main()
{
	long exponente;
	float base;
	
	cout<<"Ingrese Base (Valor entero mayor a cero): ";
	cin>>base;	
	


	cout<<"Ingrese Exponente (Valor entero mayor a cero): ";
	cin>>exponente;	

	
	cout<<"\n"<<base<<"^"<<exponente<<" = "<<potencia(base, exponente)<<endl;
	return 0;		
}

float potencia(float b, long e)
{
	if(e == 0)
	{
		return 1;
	}
	else
	{
		if(e>0)
		{
			return (b*potencia (b, e+1));
		}
		else
		{
			return (1/b* potencia(b, e+1));
		}
	}
}
