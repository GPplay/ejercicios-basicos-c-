/*Escribir un programa que calcule y muestre en pantalla el �rea de un rect�ngulo. Se debe
implementar una funci�n que reciba como par�metros las medidas del largo y ancho del
rect�ngulo, y que retorne su �rea.*/
#include <iostream>
using namespace std;
long area_rectangulo(long largo, long ancho); //Prototipo de la funci�n
int main()
{
	long l, a;
	cout<<"DIMENSIONES DEL RECTANGULO:\n";
	cout<<"Largo: ";
	cin>>l;
	cout<<"Ancho: ";
	cin>>a;
	cout<<"\nAREA DEL RECTANGULO: "<<area_rectangulo(l,a)<<endl;
	return 0;
}
long area_rectangulo(long largo, long ancho)
{
	return largo*ancho;
}
