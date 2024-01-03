/* PUNTO 16 DE PROPUESTOS DE FUNCIONES
Escriba un procedimiento recursivo que escriba un número en base 10 convertido a una base 
entre 2 y 9
*/
#include <iostream>
using namespace std;
void conversor_b10_bN(long b, long n);
int main()
{
	long base10, baseN;
	cout<<"Ingrese valor en base 10: ";
	cin>>base10;
	do
	{
		cout<<"Ingresar base destino (Valor entre 2 y 9): ";
		cin>>baseN;
	}while(baseN<2 || baseN>9);
	
	cout<<"\nValor en base "<<baseN<<": ";
	conversor_b10_bN(base10,baseN);
	cout<<endl;
	return 0;
}

void conversor_b10_bN(long b, long n)
{
	long residuo;
	if(b<n)
	{
		cout<<b;
	}
	else
	{
		residuo = b % n;
		b = b / n;  // b /= n;
		conversor_b10_bN(b,n);
		cout<<residuo;
	}
}
