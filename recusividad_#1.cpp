//recursividad== es cuando una funcion se llama asi misma 
/*escribir un programa que lea un enterio positivo y calcule su factorial. se debe implmentar
una funcion que reciba como parametro el valor leido y retorne su factorial*/ 
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

long long factorial(long N)
{
	long long fact=1; 
	for(long i=1; i<=N; i++)
	{
		fact = fact * i; 
	}
	return fact; 
}
