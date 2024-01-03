// serie fibonacci: 0 1 1 2 3 5 8 13 21 34.... (asi se hace la serie fibonacci) se suman los 
//dos numeros anteriores para proseguir 
#include<iostream>
using namespace std;
long fibonacci(long N);// prototipo de la funcion 
int main()
{
	long num;
	cout<<"ingrese el numero de terminos de la serie fibonacci: ";
	cin>>num;
	
	cout<<"resultado de la serie: "<<fibonacci(num)<<endl;
	return 0;
	
}

long fibonacci(long N)
{
	if(N <= 2 )
	{
		return N;
	}
	else
	{
		return (fibonacci (N-1) + fibonacci(N-2));
	}
}
//N = (N - 2) + (N - 1)
/*#include <iostream>
using namespace std;
long fibonacci(long N); //Prototipo de la función
int main()
{
	long num;
	cout<<"Ingrese # de terminos de la serie fibonacci: ";
	cin>>num;
//	cout<<"Resultado de la serie: "<<fibonacci(num)<<endl;
	for(int i=1; i<=num; i++)
	{
		cout<<fibonacci(i)<<"\t";
	}
	
	return 0;
}

long fibonacci(long N)
{
	if(N == 1 || N == 2)
	{
		return 1;
	}
	else
	{
		return (fibonacci(N-1) + fibonacci(N-2));
	}
}
*/
