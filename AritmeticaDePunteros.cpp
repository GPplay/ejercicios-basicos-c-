//ARITMETICA DE PUNTEROS
#include<locale.h>
#include <iostream>
using namespace std;
int main()
{
	int M[2][3], *p;
	setlocale(LC_ALL,"spanish");
	for(int c=0; c<3; c++)
	{
		for(int f=0; f<2; f++)
		{
			cout<<"M["<<f<<"]["<<c<<"]: ";
			cin>>M[f][c];
		}	
	}
	
	cout<<"\nDATOS DE LA MATRIZ:\n";
	p = &M[0][0]; // p = M;
	for(int i=0; i<6; i++)
	{
		cout<<*p<<" ";
		p++;   //p = p + 1;	
	}
	cout<<endl;
	return 0;
}
