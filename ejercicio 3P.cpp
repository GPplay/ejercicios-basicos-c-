#include<iostream>
using namespace std;

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

void factores_primos(long a)
{	
	while(a != 1)
	{
		for(long i=2; a>=i; i++)
		{
			if(a%i ==0)
			{
    			a/=i;
	   			cout<<i<<" ";
	   			break;// se sale del for y se mantienen en el while 
			}
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
/* For(int i=2; a>=i; i++)
{
 while(a%i ==0)
{
    a/=i;
    cout<<i<<" ";
}
}*/ 
