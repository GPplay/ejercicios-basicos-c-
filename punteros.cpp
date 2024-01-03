#include <locale.h>
#include <iostream>
using namespace std;

int main()
{

	int a, b=50, *p,*q;
	setlocale(LC_ALL,"spanish");
	
	a = 10;
	p = &a; //&a: Direccion de a
	
	cout<<"El valor de a es: "<<*p<<endl;
	cout<<"la dirección de a es: "<<p<<endl;
	
	q = &b;
	*p = 20;
	*q = 80;
	
	cout<<"\na = "<<a<<endl;
	cout<<"\nb = "<<b<<endl;

	
}
