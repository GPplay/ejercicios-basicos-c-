/* Escribir un programa en C/C++ que almacene en un vector de registros los
datos de los clientes de una empresa, como son: la cedula, apellidos, nombres,
valor de cuota mensual, saldo de la deuda y número de meses en mora.  Se debe
implementar un menú en pantalla que permita: 

1. Introducir un registro
2. Borrar un registro
3. Listar los clientes en mora
4. Modificar un registro
5. Listar todos los clientes
6. Consulta de un cliente
7. Listado en orden alfabetico
8. Deuda total de todos los clientes
9. Salir

Se debe implementar una función para cada una de las opciones del menú. */

#include <conio.h>
#define MAX 1000
#include <string.h>
#include <iostream>
using namespace std;
 
struct datos   // datos ES UN TIPO DE DATO ESPECIAL (TIPO STRUCT O REGISTRO) CREADO POR EL PROGRAMADOR
{
	long cedula;
	char apellidos[40];
	char nombres[40];
	long cuota;
	long saldo;
	int mora;
};

datos reg[MAX];  // DECLARACION DEL VECTOR DE REGISTROS

void inic_lista();
int valida_ced(long c);
void intro();
void borrar();
void listar();
void listar_todos();
void orden_alfbetico();
void consulta();
void modificar();
long suma_deudas();
int menu();

int main()
{
	int opcion;
	datos a;
	inic_lista(); /* inicializar el array de estructuras */
	for(;;) 
	{
		opcion=menu();
		switch(opcion)
		{
			case 1: intro(); break;
			case 2: borrar(); break;
			case 3: listar(); break;
			case 4: modificar(); break;
			case 5: listar_todos(); break;
			case 6: consulta(); break;
			case 7: orden_alfbetico(); break;
			case 8: cout<<"\nSumatoria de todas las deudas: "<<suma_deudas()<<endl; system("pause"); break;
			case 9: return 0;
		}
	}
}

 /*inicializar la lista. */
void inic_lista()
{
	int t;

	for(t=0; t<MAX; ++t)
	{
		reg[t].apellidos[0] = '\0';
	}
}

/*validar cedula */
int valida_ced(long c)
{
	int t;

	for(t=0; t<MAX; ++t)
	{	 
		if(reg[t].cedula==c && reg[t].apellidos[0]!='\0')
		{   
			return 1;  // RETORNA 1 SI EXISTE UN REGISTRO CON ESA CEDULA
		}
	}
	return 0;  // RETORNA 0 SI NO EXISTE UN REGISTRO CON ESA CEDULA	 
}

/* seleccionar una operacion. */
int menu()
{
	int c;
	do
	{
		system("CLS");
		cout<<"1. Introducir un regisro\n";
		cout<<"2. Borrar un registro\n";
		cout<<"3. Listar el clientes en mora\n";
		cout<<"4. Modificar un registro\n";
		cout<<"5. Listar todos los clientes\n";
		cout<<"6. Consulta de un cliente\n";
        cout<<"7. Listado en orden alfabetico\n";
		cout<<"8. Deuda total de todos los clientes\n";
		cout<<"9. Salir\n";
		cout<<"\nIntroduzca su opcion: ";
		cin>>c;
	}while(c<1 || c>9);
	return c;
}

void intro()
{
	int t,ced;
	cout<<"\nIntroduzca cedula: ";
	cin>>ced;
	if(valida_ced(ced)) // if(valida_ced(ced)==1)  // PARA C++ 0 ES FALSO, Y UN VALOR DIFERENTE DE CERO ES VERDADERO
	{  
		cout<<"Ya existe un registro con esa cedula!"<<endl;
		system("pause");
		return;
	}
	for(t=0; t < MAX; t++)
	{
		if(reg[t].apellidos[0] == '\0')
		{
			reg[t].cedula = ced;
			
			cout<<"Introduzca apellidos: ";
			fflush(stdin);
			gets(reg[t].apellidos);
			strupr(reg[t].apellidos);

			cout<<"Introduzca nombres: ";
			gets(reg[t].nombres);
			strupr(reg[t].nombres);

			cout<<"Introduzca cuota: ";
			cin>>reg[t].cuota;

			printf("Introduzca saldo: ");
			cin>>reg[t].saldo;

            printf("Introduzca meses en mora: ");
			cin>>reg[t].mora;
				
			break;
		}
	}
}

void borrar()
{
	int t;
	long ced,sw=0;

    cout<<"\nIntroduzca cedula de registro a eliminar: ";
    cin >> ced;
    for(t=0; t < MAX; t++)
    {
		if(reg[t].cedula==ced && reg[t].apellidos[0]!='\0')
  		{  
        	reg[t].apellidos[0] = '\0';
            cout<<"\nRegistro borrado!\n";
			system("pause");
			sw=1;
			break;
        }
	}
	if(sw==0)
	{
		cout<<"\nRegistro no encontrado!"<<endl;
		system("pause");
	}   
}

void listar() // MOSTRAR TODOS LOS CLIENTES EN MORA
{    
	int t;

	for(t=0; t < MAX; t++)
	{
		if(reg[t].apellidos[0] != '\0' && reg[t].mora>0)
		{
			cout<<"\nCEDULA: "<<reg[t].cedula<<endl;
            printf("APELLIDOS: %s\n", reg[t].apellidos);
			printf("NOMBRES: %s\n", reg[t].nombres);
			printf("MESES EN MORA: %d\n", reg[t].mora);

			printf("\nDigite una tecla para continuar"); 
            getch();
			printf("\n");
		}
	}
}

void modificar() 
{
    int t;
    long ced;
    cout << "Digite la cedula del registro a modificar: ";
    cin >> ced;
    if(valida_ced(ced)==1)
    {
    	for(t=0; t < MAX; t++)
    	{
      		if(reg[t].cedula==ced && reg[t].apellidos[0]!='\0')
			{
        		printf("Cedula: ");
      			cout << reg[t].cedula;
				
				printf("\nApellidos: ");
				puts(reg[t].apellidos);

				printf("Nombres: ");
				puts(reg[t].nombres);

				printf("Introduzca cuota: ");
				cin >> reg[t].cuota;

				printf("Introduzca saldo: ");
				cin >> reg[t].saldo;

            	printf("Introduzca meses en mora: ");
				cin >> reg[t].mora;
				
				break;
         	}
    	}
    }
    else
    {
        cout<<"\nNo existe registro con esa cedula!"<<endl;
        system("pause");
    }   
}

void listar_todos()
{    
	int t;

	for(t=0; t < MAX; t++)
	{
	    if(reg[t].apellidos[0] != '\0')
		{
            printf("\nCEDULA: %d\n", reg[t].cedula);
            printf("APELLIDOS: %s\n", reg[t].apellidos);
			printf("NOMBRES: %s\n", reg[t].nombres);
			printf("MESES EN MORA: %d\n", reg[t].mora);
			printf("CUOTA: %d\n", reg[t].cuota);
            printf("SALDO: %d\n", reg[t].saldo);
			system("pause");
        }
    }
}

void orden_alfbetico()
{
	datos aux;
    for(int i=0; i < MAX-1; i++)
    {
        for(int j=i+1; j<MAX; j++)
        {
            if(strcmp(reg[i].apellidos,reg[j].apellidos)>0)
            {
                aux = reg[i];
                reg[i] = reg[j];
                reg[j] = aux;
            }
        }
    }
    listar_todos();
}     
 
void consulta()
{
    long c, ced, flag;
    char aps[40],nom[40];
    for(;;)
    {
		do
		{	      
			system("CLS");
			printf("1. Consultar por cedula\n");
			printf("2. Consultar por apellidos\n");
			printf("3. Consultar por nombres\n");
			printf("4. Regresar al menu principal\n");
			printf("\nIntroduzca su opcion: ");
			cin >> c;
		}while(c<1 || c>4);
      
    	switch(c)
    	{
        	case 1: cout<<"Ingrese cedula: ";
                	cin>>ced;
                	if(valida_ced(ced))
                 	{
                    	for(int t=0; t < MAX; t++)
                    	{
      	               		if(reg[t].cedula==ced && reg[t].apellidos[0]!='\0')
      	               		{
                          		printf("\nCEDULA: %d\n", reg[t].cedula);
                          		printf("APELLIDOS: %s\n", reg[t].apellidos);
			              		printf("NOMBRES: %s\n", reg[t].nombres);
			              		printf("MESES EN MORA: %d\n", reg[t].mora);
			              		printf("CUOTA: %d\n", reg[t].cuota);
                          		printf("SALDO: %d\n", reg[t].saldo);
                          		break;
                       		}                   
                    	}
                 	}
                 	else
                 	{  
						cout<<"\nNO EXISTE REGISTRO CON ESA CEDULA"<<endl;
					}
                	system("pause");
                	break; 
        	case 2:	cout<<"Ingrese apellidos: ";
                	fflush(stdin); gets(aps);
                	strupr(aps);
                	flag = 0;
                	for(int t=0; t < MAX; t++)
                	{
      	            	if(strcmp(reg[t].apellidos,aps)==0 && reg[t].apellidos[0]!='\0')
      	            	{
                        	printf("\nCEDULA: %d\n", reg[t].cedula);
                        	printf("APELLIDOS: %s\n", reg[t].apellidos);
			            	printf("NOMBRES: %s\n", reg[t].nombres);
			            	printf("MESES EN MORA: %d\n", reg[t].mora);
			            	printf("CUOTA: %d\n", reg[t].cuota);
                        	printf("SALDO: %d\n", reg[t].saldo);
                        	flag = 1;
                    	}                   
                	}
                	if(!flag) //if(flag==0)  //if(flag!=1)
                		cout<<"\nNO EXISTE REGISTRO CON ESOS APELLIDOS"<<endl;
                	system("pause");
                	break;
        	case 3:	cout<<"Ingrese nombres: ";
            		fflush(stdin); gets(nom);
                	strupr(nom);
                	flag = 0;
                	for(int t=0; t < MAX; t++)
                	{
      	        		if(strcmp(reg[t].nombres,nom)==0 && reg[t].apellidos[0]!='\0')
      	            	{
                        	printf("\nCEDULA: %d\n", reg[t].cedula);
                        	printf("APELLIDOS: %s\n", reg[t].apellidos);
			            	printf("NOMBRES: %s\n", reg[t].nombres);
			            	printf("MESES EN MORA: %d\n", reg[t].mora);
			            	printf("CUOTA: %d\n", reg[t].cuota);
                        	printf("SALDO: %d\n", reg[t].saldo);
                        	flag = 1;
                    	}                   
                	}
                	if(!flag) //if(flag==0)  //if(flag!=1)
                		cout<<"\nNO EXISTE REGISTRO CON ESOS NOMBRES"<<endl;
                 	system("pause");
                	break;  
        	case 4: return;
    	}
	}
}

long suma_deudas()
{
    long suma = 0;
    for(int t=0; t < MAX; t++)
    {
    	if(reg[t].apellidos[0]!='\0')
    	{
    		suma = suma + reg[t].saldo;  // suma += reg[t].saldo;
    	}
	}
    return suma;
}

