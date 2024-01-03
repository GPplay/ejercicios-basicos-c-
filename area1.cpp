/*Escribir un programa que calcule y muestre en pantalla el área de un rectángulo. Se debe
implementar una función que reciba como parámetros las medidas del largo y ancho del
rectángulo, y que retorne su área.*/
#include <iostream>
using namespace std;
long area_rectangulo(long largo, long ancho); //Prototipo de la función
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
