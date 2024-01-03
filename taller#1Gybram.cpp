/* Elabore un programa en C++ que calcule y muestre en pantalla el máximo común divisor de dos números enteros mediante el método
de Euclides. Para esto se debe implementar una función que reciba como parámetro los dos números enteros y retorne el máximo común
divisor. 

El método de Euclides consiste en dividir el número mayor entre el
menor, si el residuo es cero, el menor será el máximo común divisor,
de lo contrario, el número mayor tomará el valor del menor y el menor
tomará el valor del residuo, se continúa con el proceso hasta obtener
un residuo igual a cero.
*/

#include<iostream>
using namespace std;
int mcd(int a, int b);
int main()
{
	int num1, num2;
	do
	{
	cout<<"ingrese el numero mayor: "<<endl;
	cin>>num1;	
	
	cout<<"ingrese el menor: "<<endl;
	cin>>num2;
	}while(num1<num2);
	
	cout<<"el maximo comun divisor es: "<<mcd(num1, num2);
	
	return 0;
}
int mcd(int a, int b) 
{
    if(b == 0) return a;
    return mcd(b, a%b);
}
