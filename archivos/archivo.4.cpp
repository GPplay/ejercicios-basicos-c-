#include <iostream>
#include <fstream>
using namespace std;

struct pagos
{
    char nombres[60];
    float valor;
    long n_cuenta;
};

int main()
{
    pagos registro;
    
    ifstream entrada("varios.txt", ios::in | ios::binary);

    if(entrada == 0)
    {
       cout << "\nERROR AL ABRIR EL ARCHIVO\n\n";
       system("PAUSE");
       return 0;
    }
    
    entrada.read(reinterpret_cast<char *> (&registro), sizeof(pagos));
    
    while(!entrada.eof())
    {
        cout << "Nombres Completos: " << registro.nombres << endl;
        cout << "Balance: " << registro.valor << endl;
        cout << "# de Cuenta: " << registro.n_cuenta << endl << endl;
        entrada.read(reinterpret_cast<char *> (&registro), sizeof(pagos));
    }
    
    entrada.close();
    cout << "\n\nPrograma Terminado Correctamente!  \n\n";
    
    system("pause");
    return 0;
}
    
     
