/*2. Un cajero electrónico dispone de billetes de $20.000, $10.000, $5.000, $2.000 y 
$1.000. Elabore un procedimiento que reciba como dato de entrada el monto de un 
retiro y que retorne (datos de salida) la cantidad de billetes, de cada denominación, 
que se deben entregar al cliente teniendo en cuanta que el número de billetes a 
entregar debe ser el menor posible.
Nota: Asuma que el monto del retiro es múltiplo de 1000.*/

#include<iostream>
#include<conio.h>
using namespace std;

//Prototipo de la funcion;
void cantidad_billetesDenominacion(int x, int& b20, int& b10, int& b5, int& b2, int& b1, int& sobrante);

int main()
{
	int x, b20=0, b10=0, b5=0, b2=0, b1=0, sobrante=0;
	cout<<"Ingrese el monto a retirar: ";
	cin>>x;
	
	cantidad_billetesDenominacion(x, b20, b10, b5, b2, b1, sobrante);
	
	cout<<"\nLa cantidad de billetes de 20000 mil a entregar es: "<<b20;
	cout<<"\nLa cantidad de billetes de 10000 mil a entregar es: "<<b10;
	cout<<"\nLa cantidad de billetes de 5000 mil a entregar es: "<<b5;
	cout<<"\nLa cantidad de billetes de 2000 mil a entregar es: "<<b2;
	cout<<"\nLa cantidad de billetes de 1000 mil a entregar es: "<<b1;
	cout<<"\nLa cantidad sobrante es: "<<sobrante<<endl;
	
	getch();
	return 0;
}

//implementacion de la funcion
void cantidad_billetesDenominacion(int x, int& b20, int& b10, int& b5, int& b2, int& b1, int& sobrante)
{
	b20 = x / 20000;
	x %= 20000;
	
	b10 = x / 10000;
	x %= 10000;
	
	b5 = x / 5000;
	x %= 5000;
	
	b2 = x / 2000;
	x %= 2000;
	
	b1 = x / 1000;
	x %= 1000;
	
	sobrante = x;
}
