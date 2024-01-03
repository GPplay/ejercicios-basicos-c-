// usar recursividad para hayar los factoriales de los numeros 
#include<iostream>
using namespace std;
long long factorial (long N);
int main()
{
	long num;
	do
	{
		cout<<"ingresar un numero positivo: ";
		cin>>num;
	}while(num<=0);
	
	cout<<"\n"<<num<<"! = "<<factorial(num)<<endl;
	return 0;	
}
long long factorial (long n)
{
	if(n==1)
	{
		return 1;
	}
	else 
	{
		cout<<n<<" * factorial("<<n-1<<")"<<endl;
		return (n * factorial(n-1));
	}
}
