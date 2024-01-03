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
void calculando();
void promedios();
void porcentaje();
void crear_archivo();
void ordenarS();
void ordenarC();
void actualizar_nomina();

 int main()
{
	leer_archivo();
	calculando();
	promedios();
	porcentaje();
	listar();
	crear_archivo();
	ordenarC();
	listar();
	actualizar_nomina();
	listar();
}



 void listar()
 {    int t;

		for(t=0; t < MAX; t++)
		{
			if(reg[t].nombres[0] != '\0')
				{
                     printf("\nCEDULA: %d\n", reg[t].cedula);
					 printf("NOMBRES: %s\n", reg[t].nombres);
					 cout<<"sueldo: "<<reg[t].sueldo<<endl;
					 cout<<"transporte: "<<reg[t].transporte<<endl;
					 cout<<"aporte a salud: "<<reg[t].aporte_salud<<endl;
					 cout<<"aporte a pension: "<<reg[t].aporte_pension<<endl;
					 cout<<"fondo solidario: "<<reg[t].fondo_solidaridad<<endl;
					 cout<<"neto: "<<reg[t].neto<<endl;
					 
					 
					 printf("\nDigite una tecla para continuar"); getch();
					 printf("\n");
				}	
		}				
 }
         
void escribir_archivo()
{
    ofstream salida("NOMINA.DAT", ios::out | ios::binary); // para leer un archivo binario
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
        entrada.read(reinterpret_cast<char *> (&reg[i]), sizeof(empleado));// lee lo que de nomina.dat y lo pone en el reg (osea en el struct)
        i++;
    }
    
    entrada.close();
}
void calculando()
{
	int trans = 0, solid = 0;
	for(int t=0; t < MAX; t++)
	{
		if(reg[t].nombres[0] != '\0')
			{
				if(reg[t].sueldo <= 1817052)
				{
					reg[t].transporte = 106454;
					trans++;
				}
				
				reg[t].aporte_salud = reg[t].sueldo * 4 / 100;
				
				reg[t].aporte_pension = reg[t].sueldo * 4 / 100;
				
				if(reg[t].sueldo >= 3634104)
				{
					reg[t].fondo_solidaridad = reg[t].sueldo * 1 / 100;
					solid++;
				}
				reg[t].neto = (reg[t].transporte + reg[t].sueldo) - (reg[t].aporte_salud + reg[t].fondo_solidaridad + reg[t].aporte_pension);
			}
	}
	cout<<"numero de empleados que ganan subsidio de transporte: "<<trans<<endl<<endl;
	cout<<"numero de empleados que se les descuenta Fondo de Solidaridad: "<<solid<<endl<<endl;
}
void promedios()
{
	long long prom=0, per= 0;
	for(int t=0; t < MAX; t++)
	{
		if(reg[t].nombres[0] != '\0')
		{
		 per++;
		 prom = prom + reg[t].neto;
		}
	}
	prom = prom / per;
	cout<<"el promedio de los salarios netos son: "<<prom<<endl<<endl;
}
void porcentaje()
{
	int porc = 0, porc2 = 0, porc3 = 0, proc=0, proc2 = 0, proc3=0; 
	long sumaTP = 0;
	for(int t=0; t < MAX; t++)
	{
		if(reg[t].nombres[0] != '\0')
		{
		 	if(reg[t].neto <= 1817052)
			{
			 porc+= 1;	
			}
			
			if(reg[t].neto >= 1817052 && reg[t].neto <= 2725578)
			{
				porc2 += 1;
			}
			if(reg[t].neto>= 2725578)
			{
				porc3 += 1;
			}
		sumaTP = sumaTP + 1;
		}
	}
	proc = (porc * 100) / sumaTP;
	
	proc2 = (porc2 *100) / sumaTP;
	
	proc3= (porc3 *100) /sumaTP;

	cout<<"porcentaje de empleados que tienen un neto hasta de dos salarios: "<<proc<<"%"<<endl<<endl;
	cout<<"porcentaje de empleados con un neto entre dos y tres salarios minimos: "<<proc2<<"%"<<endl<<endl;
	cout<<"porcentaje de empleados con un neto superior a tres salarios minimos: "<<proc3<<"%"<<endl<<endl;
}
void crear_archivo()
{
    ordenarS();
	ofstream salida("TRABAJADORES.TXT");
    
    if(salida == 0)
    {
       cout << "\nERROR AL ABRIR EL ARCHIVO.\n\n";
       system("PAUSE");
    }
    for(int t=0; t < MAX; t++)
	{
		if(reg[t].nombres[0] != '\0')
		{
			salida<<reg[t].nombres<<";"<<reg[t].cedula<<";"<<reg[t].sueldo<<";"<<reg[t].aporte_salud<<";"<<reg[t].aporte_pension<<";"<<reg[t].fondo_solidaridad<<";"<<reg[t].transporte<<";"<<reg[t].neto<<endl;
		}
	}
    
    salida.close();  // CERRAR EL ARCHIVO
    cout<<"\nARCHIVO DE TEXTO CREADO CON EXITO!\n";
	
}
void ordenarC()
{
	empleado p1;
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (reg[i].cedula > reg[j].cedula)
            {
                p1 = reg[i];
                reg[i] = reg[j];
                reg[j] = p1;
            }
        }
    }
    cout << "lsitadod e empleados por cedula (ascendente ) \n"<< endl;
	
}
void ordenarS()
{
	empleado p1;
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (reg[i].sueldo < reg[j].sueldo)
            {
                p1 = reg[i];
                reg[i] = reg[j];
                reg[j] = p1;
            }
        }
    }
    cout << "lsitadod e empleados por cedula (ascendente ) \n"<< endl;
}
void actualizar_nomina()
{
empleado p1;

 
 for (int i = 0; i < MAX - 1; i++)
    {
     if(reg[i].nombres[0] != '\0')
	 {
	 	
	 	ofstream out("NOMINA.DAT", ios::out | ios::binary);
         for (int i = 0; i < MAX; i++)
        {
        if (reg[i].nombres[0] != '\0')
            out.write(reinterpret_cast<char *>(&reg[i]), sizeof(empleado));
        }
    
    
	   for (int j = i + 1; j < MAX; j++)
        {
            if (strcmp(reg[i].nombres, reg[j].nombres) > 0)
            {
                p1 = reg[i];
                reg[i] = reg[j];
                reg[j] = p1;
            }
	   }
       
     }
    }
    cout<<"empleados ordenados por nombre (ascendente) "<<endl<<endl;
}
