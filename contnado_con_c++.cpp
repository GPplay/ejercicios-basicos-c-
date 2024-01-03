//prueba 
#include<iostream>
using namespace std;
int main()
{
	int N;
	do
	{
	cout<<"ingresa un numero positivo: "; 
	cin>>N;
	}while(N<=0);
	
	for(int i=1 ; i<=N; i++)
	{
		cout<<i<<" ";	
	}
}
