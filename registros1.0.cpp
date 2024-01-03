/*
registros
escribir un programa que lea el registro de un empleado que guarde los datos en otra variable
registro y muestre en pantalla los datos del resgistro leido.
*/
#include<iostream>
using namespace std; 

struct empleado
{
	long cedula;
	char apellido1[30];
	char apellido2[30];
	char nombre[40];
	char cargo[30];
	long sueldo;
};

//varable global!!!!! si esta aca afuera bruto de mierda

int main()// si estan declaras dentro del main son variables locales
{
	empleado reg1, reg2;
	cout<<"INGRESE REGISTRO REGISTRO\n ";
	cout<<"CEDULA: ";
	cin>>reg1.cedula;
	fflush(stdin);
	cout<<"apellido 1: ";
	gets(reg1.apellido1);
	cout<<"apellido 2: ";
	gets(reg1.apellido2);
	cout<<"nombres: ";
	gets(reg1.nombre);
	cout<<"cargo: ";
	gets(reg1.cargo);
	cout<<"sueldo: ";
	cin>>reg1.sueldo;
	
	reg2 = reg1; 
	
	cout<<"\n\n DATOS DEL REGISTRO\n ";
	cout<<"CEDULA: "<<reg1.cedula<<endl;
	cout<<"apellido 1: "<<reg2.apellido1<<endl;
	cout<<"apellido 2: "<<reg2.apellido2<<endl;
	cout<<"nombres: "<<reg2.nombre<<endl;
	cout<<"cargo: "<<reg1.cargo<<endl;
	cout<<"sueldo: "<<reg1.sueldo<<endl;
	
	return 0;
}
