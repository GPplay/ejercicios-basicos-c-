/*Escribir un programa que calcule la nota definitiva de un estudiante, la definitiva se debe
calcular teniendo en cuenta lo siguiente: 

- Actividad Individual: 30%
- Actividad Grupal: 30%
- Actividad de foros: 30%
- Autoevaluación: 10%. 

Se debe implementar una función para calcular la definitiva.*/
#include <iostream>
using namespace std;

void calcula_definitiva();  //Prototipo de la función

float def, act_individual, act_grupal, act_foro, autoevaluacion; // VARIABLES GLOBALES

int main()
{
	cout<<"Actividad Individual: ";
	cin>>act_individual;
	cout<<"Actividad Grupal: ";
	cin>>act_grupal;
	cout<<"Actividad de Foro: ";
	cin>>act_foro;
	cout<<"Autoevaluacion: ";
	cin>>autoevaluacion;
    
	calcula_definitiva();
	
	cout<<"\nNOTA DEFINITIVA: "<<def<<endl;
	return 0;
}
//IMPLEMETACION DE LA FUNCION
void calcula_definitiva()
{
	def = act_individual*0.3 + act_grupal*0.3 + act_foro*0.3 + autoevaluacion*0.1;	
}
