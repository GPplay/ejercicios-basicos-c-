//cuando una funcion no retorna valor se llama procedimiento (en C++)(void se le llama) 
#include<iostream>
using namespace std; 

//prototipo de la funcion:
//tipo_dato nombre_funcion(tipo_dato parametro1, tipo_dato parametro2,.... Tipo_dato PrametroN)

void factores_primos(long a); 
int validar_positivo(long a); 
int main()
{
	long N;
	do
	{
		cout<<"ingrese un entero positivo: ";
		cin>>N;
	}while(validar_positivo(N)== 0);
	cout<<"\nLOS FACTORES PRIMOS DE "<<N<<" SON\n";
	factores_primos(N);//llamado a la funcion 
	
	return 0; 
}
//implementacion de la funcion
void factores_primos(long a)
{
	while (a != 1)
	{
		if (a%2 == 0)
		{
			a /= 2; 
			cout<<2<<" ";
			continue; 
		}
		if (a%3 == 0)
		{
			a /= 3; 
			cout<<3<<" ";
			continue;
		}
		if (a%5 == 0)
		{
			a /= 5; 
			cout<<5<<" ";
			continue;
		}
		if (a%7 == 0)
		{
			a /= 7; 
			cout<<7<<" ";
			continue;
		}
	}
}
int validar_positivo(long a)
{
	if(a>0)
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}
