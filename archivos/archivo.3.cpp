#include <iostream>
#include <fstream>
using namespace std;
struct contab
{
	char nombre[60];
	float valor;
	long n_cuenta;
};

int main()
{
	contab reg;
	int N;
	
	ofstream salida("varios.txt", ios::out | ios::binary);	
	if(salida == 0)
    {
       cout << "\nERROR AL ABRIR EL ARCHIVO\n\n";
       system("PAUSE");
       return 0;
    }
    
    cout<<"# de registros a ingresar: ";
	cin>>N;

    for(int i=0; i < N; i++)
    {
        fflush(stdin);
        cout << "\nNombres Completos: ";
        gets(reg.nombre);
        cout << "Valor: ";
        cin >> reg.valor;
        cout << "# de Cuenta: ";
        cin >> reg.n_cuenta;
        
        salida.write(reinterpret_cast<char *> (&reg), sizeof(contab));
    }
    
    salida.close();
    
    cout << "\n\nPrograma Terminado Correctamente! \n\n";

    return 0;

}
