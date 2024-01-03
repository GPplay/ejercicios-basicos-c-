#include <string.h>
 #include <conio.h>
 #include <iostream>
 #include <fstream>
 #define MAX 1000
 
 using namespace std;

 struct datos 
 {
         long long cedula;
         char apellidos[40];
		 char nombres[40];
		 long cuota;
		 long saldo;
		 int mora;
 };

 datos reg[MAX];

 int valida_ced(long c);
 void inic_lista();
 void intro();
 void borrar();
 void listar();
 void listar_todos();
 void modificar();
 void ordenar();
 int menu();
 void leer_archivo();
 void escribir_archivo();
 

 int main()
 {
		 int opcion;
		 inic_lista(); /* inicializar el array de estructuras */
		 leer_archivo(); // llenar el vector con los datos del archivo binario
         for(;;) {
				opcion=menu();
				switch(opcion)  {
					case 1: intro(); break;
					case 2: borrar(); break;
					case 3: listar(); break;
                    case 4: modificar(); break;
                    case 5: listar_todos(); break;
                    case 6: ordenar(); break;
					case 7: escribir_archivo(); // Actualizar (re-escribir) el archivo binario con los datos del vector de registro
                            return 0;
				}
		 }
 }

 /*inicializar la lista. */
 void inic_lista()
 {
	 int t;

	 for(t=0; t<MAX; ++t)
			 reg[t].apellidos[0] = '\0';
 }

 /* seleccionar una operacion. */
 int menu()
 {
	 int c;
	 do
	 {      system("CLS");
			printf("1. Introducir un registro\n");
			printf("2. Borrar un registro\n");
			printf("3. Listar los clientes en mora\n");
            printf("4. Modificar un registro\n");
            printf("5. Mostrar todos los registros\n");
            printf("6. Listar clientes en orden de apellidos\n");
			printf("7. Salir\n");
			printf("\nIntroduzca su opcion: ");
			cin >> c;
	 } while(c<1 || c>7);
	 return c;
 }

 void intro()
 {
      int t;
      long ced;
      
      printf("\nIntroduzca cedula: ");
      cin >> ced;
      
      if(valida_ced(ced)==0)
      {
      for(t=0; t < MAX; t++)
      	if(reg[t].apellidos[0] == '\0')
			{
                reg[t].cedula = ced;

				printf("Introduzca apellidos: ");
				fflush(stdin);
				gets(reg[t].apellidos);

				printf("Introduzca nombres: ");
				fflush(stdin);
				gets(reg[t].nombres);

				printf("Introduzca cuota: ");
				cin >> reg[t].cuota;

				printf("Introduzca saldo: ");
				cin >> reg[t].saldo;

                printf("Introduzca meses en mora: ");
				cin >> reg[t].mora;
				
				break;
         }
         }
         else
         {
            cout << "\nYA EXISTE UN REGISTRO CON ESA CEDULA";
            getch();
         }
 }

 void borrar()
 {    int t;
 		long ced;

		printf("\nIntroduzca cedula de registro a eliminar: ");
      cin >> ced;
      for(t=0; t < MAX; t++)
	  {			if(reg[t].cedula == ced && reg[t].apellidos[0] != '\0')
  			    {  reg[t].apellidos[0] = '\0';
  			       cout << "\nREGISTRO ELIMINADO!";
  			       getch();
                   return;
                }
      }          
      cout << "\nNO EXISTE REGISTRO CON ESA CEDULA";
      getch();
 }

 void listar()
 {    int t;

		for(t=0; t < MAX; t++)
				if(reg[t].apellidos[0] != '\0' && reg[t].mora>0)
				{
                     printf("\nCEDULA: %d\n", reg[t].cedula);
            	     printf("APELLIDOS: %s\n", reg[t].apellidos);
					 printf("NOMBRES: %s\n", reg[t].nombres);
					 printf("MESES EN MORA: %d\n", reg[t].mora);

					 printf("\nDigite una tecla para continuar"); getch();
					 printf("\n");
				}
 }

void listar_todos()
 {    int t;

		ofstream salida("LISTA.TXT");
		
		salida<<"CEDULA|APELLIDOS|NOMBRES|MESES EN MORA|\n";
        for(t=0; t < MAX; t++)
				if(reg[t].apellidos[0] != '\0')
				{
                     printf("\nCEDULA: %d\n", reg[t].cedula);
            	     printf("APELLIDOS: %s\n", reg[t].apellidos);
					 printf("NOMBRES: %s\n", reg[t].nombres);
					 printf("MESES EN MORA: %d\n", reg[t].mora);
					 
					 salida<<reg[t].cedula<<"|"<<reg[t].apellidos<<"|"<<reg[t].nombres<<"|"<<reg[t].mora<<"|"<<endl;

					 printf("\nDigite una tecla para continuar"); getch();
					 printf("\n");
				}
		salida.close();		
 }

 void modificar()
 {
      int t;
      long ced;
      cout << "Digite la cedula del registro a modificar: ";
      cin >> ced;
      for(t=0; t < MAX; t++)
      	if(reg[t].cedula == ced && reg[t].apellidos[0] != '\0')
			{
         	    printf("Cedula: ");
      		    cout << reg[t].cedula;

				printf("Apellidos: ");
				puts(reg[t].apellidos);

				printf("Nombres: ");
				puts(reg[t].nombres);

				printf("Introduzca cuota: ");
				cin >> reg[t].cuota;

				printf("Introduzca saldo: ");
				cin >> reg[t].saldo;

                printf("Introduzca meses en mora: ");
				cin >> reg[t].mora;
                
                cout << "\nREGISTRO MODIFICADO!";
                getch();
                return; 
         }
      cout<<"\nNO EXISTE REGISTRO CON ESA CEDULA";
      getch();
 }

 int valida_ced(long c)
 {    
      for(int t=0; t < MAX; t++)
	  {
              if(reg[t].cedula==c && reg[t].apellidos[0] != '\0')
                {   return 1;}
      }          
      return 0;
}

void ordenar()
{
     datos aux;
     for (int t=0; t < MAX-1; t++)
     {
         for (int k=t+1; k < MAX; k++)
         {
             if (strcmp(reg[t].apellidos, reg[k].apellidos) > 0)
             {
                 aux = reg[t];
                 reg[t] = reg[k];
                 reg[k] = aux;
             }
         }
     }
     listar_todos();
}
          
void escribir_archivo()
{
    ofstream salida("datos1.dat", ios::out | ios::binary);
    if(salida == 0)
    {
       cout << "ERROR AL ABRIR EL ARCHIVO";
       return;
    }

    for(int i=0; i < MAX; i++)
    {
        if(reg[i].apellidos[0] != '\0')
           salida.write(reinterpret_cast<char *> (&reg[i]), sizeof(datos));
    }
    
    salida.close();
}

void leer_archivo()
{
    ifstream entrada("datos1.dat", ios::in | ios::binary);

    if(entrada == 0)
    {
       cout << "ERROR AL ABRIR EL ARCHIVO\n";
       system("PAUSE");
       return;
    }
    
    entrada.read(reinterpret_cast<char *> (&reg[0]), sizeof(datos));
    
    int i=1;
    while(!entrada.eof())
    {
        entrada.read(reinterpret_cast<char *> (&reg[i]), sizeof(datos));
        i++;
    }
    
    entrada.close();
}
