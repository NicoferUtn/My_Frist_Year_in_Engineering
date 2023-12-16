#include<iostream>
#include <fstream>

using namespace std;


int main(){
    const int dim {10};
    int vec[dim]{};
    int aux{};
    
    ifstream archi;
    archi.open("datosG04E14.txt");
    if (!archi)
    {
        cout<<"Funciona como el orto";
        return 1;
    }
    while (archi>> aux)
    {
       vec[aux - 15]++;
    }
    archi.close();

    int max{};
    for (int i = 0; i < dim; i++)
    {
        if (vec[i]>vec[max])
        {
            max = i;
        }
        
    }
    cout<<"el numero mas repetido es "<<max+15<<" repitiendoce "<<vec[max];

    return 0;
    }
    