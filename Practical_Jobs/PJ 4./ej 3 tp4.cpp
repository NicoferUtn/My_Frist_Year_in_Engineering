#include<iostream>
#include<fstream>

using namespace std;
int main(){
    fstream archivo;
    archivo.open("datosG04E03.txt");
    if (!archivo)
    {
        cout<<"funciona mal flaco";
    }else{
    double prom=0,aprom=0,a=0;
    const int dim =10;
    double v[dim] {};
    for (int i = 0; i < dim; i++)
    {
        archivo>>v[i];
        prom += v[i];
    }
    a = prom/10;
 for (int j = 0; j < dim; j++)
 {
    archivo>>v[j];
    if (v[j]<a)
    {
        aprom++;
    }
    
 }
    cout<<"Promedio "<<a;
    cout<<"\nLos alumnos arriba del promedio son "<<aprom;
    archivo.close();
    return 0;
}}