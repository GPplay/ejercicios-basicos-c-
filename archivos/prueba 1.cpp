#include <string.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#define MAX 1000
using namespace std;
struct empleado
{
long cedula;
char nombres[60];
long sueldo;
long transporte;
long aporte_salud;
long aporte_pension;
long fondo_solidaridad;
long neto;
};
empleado reg[MAX];// esto hace parte del estruct 

	//esto no tiene nada que ver con lo de arriba 
	void listar();
	void leer_archivo();
	void escribir_archivo();

 int main()
 {
	leer_archivo();
	listar();
	
 }



 void listar()
 {    int t;

		for(t=0; t < MAX; t++)
				if(reg[t].nombres[0] != '\0')
				{
                     printf("\nCEDULA: %d\n", reg[t].cedula);
					 printf("NOMBRES: %s\n", reg[t].nombres);
					reg[t].sueldo = 1;
					cout<<reg[t].sueldo; 
					 
					 
					 printf("\nDigite una tecla para continuar"); getch();
					 printf("\n");
				}
 }
         
void escribir_archivo()
{
    ofstream salida("NOMINA.DAT", ios::out | ios::binary);
    if(salida == 0)
    {
       cout << "ERROR AL ABRIR EL ARCHIVO";
       return;
    }

    for(int i=0; i < MAX; i++)
    {
        if(reg[i].nombres[0] != '\0')
           salida.write(reinterpret_cast<char *> (&reg[i]), sizeof(empleado));
    }
    
    salida.close();
}

void leer_archivo()
{
    ifstream entrada("NOMINA.DAT", ios::in | ios::binary);

    if(entrada == 0)
    {
       cout << "ERROR AL ABRIR EL ARCHIVO\n";
       system("PAUSE");
       return;
    }
    
    entrada.read(reinterpret_cast<char *> (&reg[0]), sizeof(empleado));
    
    int i=1;
    while(!entrada.eof())
    {
        entrada.read(reinterpret_cast<char *> (&reg[i]), sizeof(empleado));
        i++;
    }
    
    entrada.close();
}
