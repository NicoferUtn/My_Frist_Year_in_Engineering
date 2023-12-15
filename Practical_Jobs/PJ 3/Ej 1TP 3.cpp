#include<iostream>
#include <fstream>

using namespace std;

int main(){
    float cant = 0,sum = 0, nro = 0;
    float x = 0;
    ifstream archivo;
    archivo.open("Archivo.txt");
    if(archivo.fail()){
        cout<<"No se pudo abrur el archivo";
        return 1;
    }
    while(archivo >> nro){ 
        cout<<"\nHay: "<<nro;
        cant++;
        sum += nro;
    }
    cout<<"\nhay "<<cant<<" productos";
    if ( cant > 0 )
    {
        x = sum/cant;
        cout<<"\nEl promedio de los numeros son "<<x;
    }else{
        cout<<"\nNo hay objetos suficientes";
    }
    
    archivo.close();
    return 0;
}