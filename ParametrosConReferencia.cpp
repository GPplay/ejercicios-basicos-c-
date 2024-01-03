//FUNCIONES CON Parametros con Referencia 
/* escribir un programa que calcule la definitiva de un estudiante teniendo en cuenta que son 3 parciales, 
donde el 1er y 2do parcial valen el 30% cada uno y el 3er parcial vale 40%. se debe implemetar una funcion 
que reciba como parametros la definitiva y los 3 parciales, donde la definitiva sera un parametro por referencia 
y los parciales seran parametros por valor*/ 
#include<iostream>
using namespace std;
void calculo_definitiva(float *def, float p1, float p2, float p3);
int main()
{
	float  parcial1, parcial2, parcial3, Definitiva=0;
	cout<<"parcial 1: ";
	cin>>parcial1;
	cout<<"parcial 2: ";
	cin>>parcial2;
	cout<<"parcial 3: ";
	cin>>parcial3;
	calculo_definitiva(&Definitiva, parcial1, parcial2, parcial3);
	cout<<"\n DEFINTIVA: "<<Definitiva<<endl;
	return 0; 
}
void calculo_definitiva(float *def, float p1, float p2, float p3)
{
	//def = &p1 = esto es para guardar una direncion de una variable
	*def = p1*0.3 + p2*0.3 +p3*0.4;
}
