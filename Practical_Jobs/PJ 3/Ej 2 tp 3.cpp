#include<iostream>
#include<fstream>

using namespace std;

int main (){
    int nro = 0,mayor = 0, i = 0, x = 0;
    ifstream archivo;
    archivo.open("archivo.txt");
    if(!archivo){
        cout<<"El archivo no abrio ";
    }
    if (archivo >> nro){
      
    }else{
        cout<< "no hay sufieicnete contendio";
    }
    
    {
        while ( archivo >> nro){
        i++;
        if (nro > mayor)
        {
            mayor = nro;
        }
        }
    }
   cout<<"El numero mayor es "<<mayor;
   cout<<"\nHay "<<i<<" productos";
    
    
    archivo.close();
    return 0;

    }
   