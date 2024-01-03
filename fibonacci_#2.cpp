// Escribir un programa que genere en pantalla la serie fibonacci. 
// Serie Fibonacci: 0 1 1 2 3 5 8 13 21 34 ...
#include <iostream>
using namespace std;
void fibonacci(long N); //Prototipo de la función
int main()
{
	long num;
	cout<<"Ingrese # de terminos de la serie fibonacci: ";
	cin>>num;
	cout<<"\nSerie Fibonacci: ";
	fibonacci(num);
	
}

void fibonacci(long N)
{
	long long a = 0, b=1, c=0;
	
	for(long i=1; i<=N; i++)
	{
		cout<<c<<" ";
		a = b;
		b = c;
		c = a + b;	
	}
}

