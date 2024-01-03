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
empleado reg[MAX];

	
	void listar();
	void leer_archivo();
	void escribir_archivo();
	void calcular();
	void promediar_neto();
	void porcentuar();
	void ordenar_por_sueldo();
	void crear_archivo();
	void ordenar_por_cedula();
	void ordenar_por_saldo();
	void actualizar();
	

 int main()
 {
	leer_archivo();
	calcular();
	promediar_neto();
	porcentuar();
	listar();
	ordenar_por_sueldo();
	crear_archivo();
	ordenar_por_cedula( );
	listar();
	actualizar();
	listar();
	
 }



 void listar()
 {    int t;
		cout<<"*******EMPLEADOS*************";
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
					 system("cls");
				}	
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
void calcular(){
	int contador_trans = 0, contador_fondoSolid = 0;
	int slmlv= 908526;// Valor del salario minimo
	int slmlv2 =1817052; // dos salarios
	int slmlv4 = 3634104; // Cuatro salarios  
	int subsidio_transporte= 106454; //Subsidio de transporte.
	
	for(int i=0; i < MAX; i++)
	{
		if(reg[i].nombres[0] != '\0')
			{
				reg[i].aporte_salud = reg[i].sueldo * 4 / 100;//-Se calcula el aporte de salud= 4% del sueldo.
				reg[i].aporte_pension = reg[i].sueldo * 4 / 100;//-Se calcula el aporte de pension= 4% del sueldo.
				
				if(reg[i].sueldo <= slmlv2)//-Si el sueldo es menor o igual a dos salarios minimos entonces:
				{
					reg[i].transporte = subsidio_transporte;//-Se le asignara el valor del subsidio de transporte.
					contador_trans++;//-contamos las personas que se les entrega el subsidio de trasporte.
				}
												
				if(reg[i].sueldo >= slmlv4)//-Si el sueldo es menor o igual a dos salarios minimos entonces:
				{
					reg[i].fondo_solidaridad = reg[i].sueldo * 1 / 100;//-se le asigna el valor del 1% del sueldo.
					contador_fondoSolid++;//-cuenta las personas que se les va a cobrar el fondo solid.
				}
				//-Calcular el neto del trabajador.
				reg[i].neto = reg[i].transporte + reg[i].sueldo - (reg[i].aporte_salud + reg[i].aporte_pension+ reg[i].fondo_solidaridad);
			}
	}
	cout<<"***********REPORTE************\n"<<endl;
	cout<<"Numero de Empleados Que Ganan Subsidio de Transporte: ["<<contador_trans<<"]"<<endl;
	cout<<"Numero de Empleados Que Se Ses Descuenta Fondo de Solidaridad: ["<<contador_fondoSolid<<"]\n"<<endl;
}
void promediar_neto()
{
	int promedio_neto, contador= 0, acumulador=0;

	for(int i=0; i < MAX; i++)
	{
		if(reg[i].nombres[0] != '\0')
		{
			acumulador+=reg[i].neto;//-Suma-el-neto-de-cada-trabajador.
			contador++;//-Contar-personas. 			
		}								
	}

//-Calcular------------------------------------------------
	promedio_neto= acumulador/contador;//-promedio salarios neto.
	
//-Mostrar-en-pantalla--------------------------------------
	cout<<"promedio de Salarios Neto Son: ["<<promedio_neto<<"]"<<endl;
}

void porcentuar(){
	int personas=0,per_2_salarios=0, per_3_salarios=0, per_4_salarios=0;
	int porcentaje_2, porcentaje_2y3, porcentaje_4;
	
	
	for(int i=0; i < MAX; i++){
		
		if(reg[i].nombres[0] != '\0'){
			//-Porcentajes--------------------------------------------------------------------------			
			if(reg[i].neto <= 1817052){
			per_2_salarios+=1;//Personas que ganan hasta dos salarios.
			}
			
			if(reg[i].neto >= 1817052 && reg[i].neto <= 2725578){
			per_3_salarios+=1;//personas que ganan entre dos y tres salarios.
			}
				
			if(reg[i].neto>= 2725578){
			per_4_salarios+=1;//personas que ganan mas de 3 salarios.
			}
			personas++;	
		}
		
	}
//-Calcular-porcentajes
	porcentaje_2 = (per_2_salarios * 100) /personas;
	porcentaje_2y3 = (per_3_salarios * 100) / personas;
	porcentaje_4 = (per_4_salarios * 100) / personas;
	
//-Mostrar-en-pantalla
	cout<<"Personas con un neto hasta 2 salarios minimos: ["<<porcentaje_2<<"%]"<<endl;
	cout<<"Personas con un neto entre 2 y 3 salarios minimos:["<<porcentaje_2y3<<"%]"<<endl;
	cout<<"Personas con un neto de mas de 3 salarios minimos:["<<porcentaje_4<<"%]\n"<<endl;
	
}


void crear_archivo(){
	ofstream salida("NOMINA_REORDENADO.TXT"); 
    if(salida == 0)
    {
       cout << "ERROR AL ABRIR EL ARCHIVO";
       return;
    }
	salida<<"--------------LISTA REORDANA POR SUELDO--------------\n";
    for(int i=0; i < MAX; i++)
    {
        if(reg[i].nombres[0] != '\0')
		   salida<<"Nombre: ["<<reg[i].nombres<<"] ; Cedula["<<reg[i].cedula<<"];Sueldo["<<reg[i].sueldo<<"];Salud["<<reg[i].aporte_salud<<"];Pension["<<reg[i].aporte_pension<<"];F.Solidario["<<reg[i].fondo_solidaridad<<"];Transporte["<<reg[i].transporte<<"];Neto["<<reg[i].neto<<"]"<<endl;
    }
    
    salida.close();


}

void ordenar_por_cedula()
{
	empleado aux;
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (reg[i].cedula > reg[j].cedula)
            {
                aux = reg[i];
                reg[i] = reg[j];
                reg[j] = aux;
            }
        }
    }
    cout << "EMPLEADOS ORGANIZADOS POR CEDULA(ascendente) \n";
	
}
void ordenar_por_sueldo()
{
	empleado aux;
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (reg[i].sueldo < reg[j].sueldo)
            {
                aux = reg[i];
                reg[i] = reg[j];
                reg[j] = aux;
            }
        }
    }
}

void actualizar()
{
	empleado aux;
	for(int i=0; i < MAX; i++)
    {
        if(reg[i].nombres[0] != '\0'){
        	
        	for(int j = i + 1;j < MAX ; i++ ){
        		
        		if(strcmp(reg[i].nombres, reg[j].nombres)> 0 ){
        			aux = reg[i];
        			reg[i]= reg[j];
        			reg[j]= aux;
				}
			}
		}
           
    }
	
	/*ofstream out("NOMINA.DAT", ios::out | ios::binary);
    for (int i = 0; i < MAX; i++)
    {
        if (reg[i].nombres[0] != '\0')
            out.write(reinterpret_cast<char *>(&reg[i]), sizeof(empleado));
    }*/
	
	cout << "EMPLEADOS ORGANIZADOS POR Nombre(ascendente) \n";
}
