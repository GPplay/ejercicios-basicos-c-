/*Escribir un programa que lea dos n�meros enteros positivos y muestre un mensaje en pantalla
que indique si los n�meros son o no amigos. Se debe implementar una funci�n que reciba como
par�metros los dos n�meros le�dos y retorne uno si son amigos o cero si no los son. Adem�s, 
se debe implementar otra funci�n que debe ser llamada por la anterior que reciba un numero y
retorne la sumatoria de los divisores inferiores a el.
Se debe implementar otra funci�n que reciba como par�metros dos n�meros enteros y que retorne
uno si los n�meros son distintos o cero si son iguales. 

Dos n�meros enteros distintos son amigos si cada uno de ellos es igual a la suma de los
divisores del otro (sin incluir el mismo n�mero). Por ejemplo, 220 y 284 son amigos, ya que:
Suma de divisores de 284: 1+2+4+71+142 = 220
Suma de divisores de 220: 1+2+4+5+10+11+20+22+44+55+110 = 284
Tambi�n son amigos: 1184 y 1210, 6232 y 6368, 17296 y 18416
*/

#include <iostream>
using namespace std;
int validar_positivo(long a);
int validar_distintos(long a, long b);
int amigos(long a, long b);
long suma_divisores(long a);
int main()
{
	long N, M;
	do
	{
		cout<<"INGRESE DOS NUMEROS ENTEROS POSITIVOS DISTINTOS\n";
		do
		{
			cout<<"Ingese el primer valor: ";
			cin>>N;
		}while(validar_positivo(N)==0);
		do
		{
			cout<<"Ingese el segundo valor: ";
			cin>>M;
		}while(validar_positivo(M)==0);
	}while(validar_distintos(N,M)==0);
	
	if(amigos(N,M)==1)
	{
		cout<<"LOS NUMEROS SON AMIGOS\n";
	}
	else
	{
		cout<<"LOS NUMEROS NO SON AMIGOS\n";
	}
	return 0;
}
int amigos(long a, long b)
{
	if(suma_divisores(a)==b && suma_divisores(b)==a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

long suma_divisores(long a)
{
	long suma=0;
	for(int i=1; i<=a/2; i++)
	{
		if(a%i == 0)
		{
			suma+=i;  // suma = suma + i;
		}
	}
	return suma;
}
int validar_positivo(long a)
{
	if(a>0)
	{
		return 1;  // RETORNA UNO CUANDO EL NUMERO ES POSITIVO
	}
	else
	{
		return 0;  // RETORNA CERO CUANDO EL NUMERO ES CERO O NEGATIVO
	}
}

int validar_distintos(long a, long b)
{
	if(a!=b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
