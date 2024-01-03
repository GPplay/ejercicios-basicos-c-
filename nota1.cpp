/*Escribir un programa que calcule la nota definitiva de un estudiante, la definitiva se debe
calcular teniendo en cuenta lo siguiente: 

- Actividad Individual: 30%
- Actividad Grupal: 30%
- Actividad de foros: 30%
- Autoevaluación: 10%. 

Se debe implementar una función que reciba como parámetros las notas leídas y retorne la
definitiva.*/
#include <iostream>
using namespace std;

//tipo_dato nombre_función(tipo_dato nombre_parametro, tipo_dato parametro2); SINTAXIS

float calcula_definitiva(float a, float b, float c, float d);  //Prototipo de la función

int main()
{
	float act_individual, act_grupal, act_foro, autoevaluacion, definitiva;
	cout<<"Actividad Individual: ";
	cin>>act_individual;
	cout<<"Actividad Grupal: ";
	cin>>act_grupal;
	cout<<"Actividad de Foro: ";
	cin>>act_foro;
	cout<<"Autoevaluacion: ";
	cin>>autoevaluacion;
    
    //definitiva = calcula_definitiva(4, 4.5, 5, 4.8);
	definitiva = calcula_definitiva(act_individual, act_grupal, act_foro, autoevaluacion);
	
	cout<<"\nNOTA DEFINITIVA: "<<definitiva<<endl;
	return 0;
}
//IMPLEMETACION DE LA FUNCION
float calcula_definitiva(float nota1, float nota2, float nota3, float nota4)
{
	float definitiva;
	
	definitiva = nota1*0.3 + nota2*0.3 + nota3*0.3 + nota4*0.1;
	
	return definitiva;
}
