/*Escribir un programa que calcule y muestre en pantalla el salario de un empleado teniendo 
el número de horas trabajadas en el mes y el valor de la hora. Se debe implementar una 
función que reciba como parámetros el número de horas y el valor de la hora, además debe
retornar el salario. */
#include <iostream>
using namespace std;
long calcula_salario(long a, long b);  //Prototipo de la función
int main()
{
	long nhoras, valor_hora;
	
	cout<<"# de horas trabajadas en el mes: ";
	cin>>nhoras;
	cout<<"Valor de la hora: ";
	cin>>valor_hora;
	
	cout<<"Salario: "<<calcula_salario(nhoras, valor_hora)<<endl; //llamado de la función
	return 0;
}
//IMPLEMENTACION DE LA FUNCION:
long calcula_salario(long a, long b)
{
	//long salario;
	//salario = a*b;
	//return salario;
	return a*b;
}
