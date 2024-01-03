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
	cout<<"\nLOS FACTORES PRIMOS DE "<<N<<"SON\n";
	factores_primos(N);
	return 0; 
}
//implementacion de la funcion
void factores_primos(long a)
{
	
}
