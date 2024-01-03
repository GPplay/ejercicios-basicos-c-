#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream salida("DELIMITADO.TXT");
    
    if(salida == 0)
    {
       cout << "\nERROR AL ABRIR EL ARCHIVO.\n\n";
       system("PAUSE");
       return 0;
    }
    salida<<"02221010032"<<";"<<"David Franco"<<";"<<4.56<<";"<<endl;
    salida<<"02221010035"<<";"<<"Carlos Perez"<<";"<<3.38<<";"<<endl;
    salida<<"02221010011"<<";"<<"Maria Jose"<<";"<<4.27<<";"<<endl;
    
    salida.close();  // CERRAR EL ARCHIVO
    cout<<"\nARCHIVO DE TEXTO CREADO CON EXITO!\n";
    return 0;
}
