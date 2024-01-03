/* Elabore un programa en C++ que calcule y muestre en pantalla el m�ximo com�n divisor de dos n�meros enteros mediante el m�todo
de Euclides. Para esto se debe implementar una funci�n que reciba como par�metro los dos n�meros enteros y retorne el m�ximo com�n
divisor. 

El m�todo de Euclides consiste en dividir el n�mero mayor entre el
menor, si el residuo es cero, el menor ser� el m�ximo com�n divisor,
de lo contrario, el n�mero mayor tomar� el valor del menor y el menor
tomar� el valor del residuo, se contin�a con el proceso hasta obtener
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
