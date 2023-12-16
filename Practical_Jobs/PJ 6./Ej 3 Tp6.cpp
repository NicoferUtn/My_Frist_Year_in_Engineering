#include<iostream>
#include<fstream>
#include "listasutil.hpp"
#include "listasorde.hpp"
#include "listas.hpp"

using namespace std;

struct persona
{
    char cliente[8];
    int mes;
    int deuda;
};

int criterio1(persona a, persona b){
    string c = a.cliente;
    string d = b.cliente;
    if (c != d)
    {
    for (int i = 0; i < 8; i++)
{
    if (c[i] > d[i])
    {
        return 1;
    }else{return -1;}}
    }else{
}if (a.mes == b.mes)
{
    if (a.mes > b.mes){
        return 1;
    }else{return -1;}

}else{
    if (a.deuda > b.deuda){
        return 1;
    }else{return -1;}
}}
    
int criterio2(persona a, persona b){

if (a.mes == b.mes)
{
    if (a.mes > b.mes){
        return 1;
    }else{return -1;}

}else{
    if (a.deuda > b.deuda){
        return 1;
    }else{return -1;}
}
}

int criterio3(persona a , persona b){
    string c = a.cliente;
    string d = b.cliente;
 
    
   if (c == d && a.mes == b.mes)
   {
    if (a.deuda != b.deuda)
    {
        return 1;
    }else{return -1;}
      
   }else{return -1;}
   
}

ostream& operator<<(ostream& a, persona& s){
    a<<"Nombre: "<<s.cliente<<" mes: "<<s.mes<<" Deuda: "<<s.deuda;
    return a;
}

bool borrarsiguente(Nodo<persona> *& lista){
    if(lista->sig->sig != nullptr){
    Nodo<persona>* a = lista;
    Nodo<persona>* b = lista ->sig;
    
        if (a->dato.cliente == b->dato.cliente && a->dato.mes == b->dato.mes)
        {
           a->dato.deuda += b->dato.deuda;
           a->sig = a->sig->sig;
        return true;
        }
        return false;
    }
    
    return false;
}

void consolidar(Nodo<persona> *& lista){

    while (borrarsiguente(lista) == true){
        borrarsiguente(lista);
    }
    
}







int main(){
    ifstream archi;
    archi.open("G06E03.bin", ios :: binary);

    archi.seekg(0, ios::end);
    int longitudFichero = archi.tellg();
    archi.seekg(0, ios::beg);

    const int dim = (longitudFichero /(8 + 2*sizeof(int)));

    persona v[dim]{};

    for ( int i = 0; i < dim; i++)
    {
        archi.read(v[i].cliente,sizeof(v[i].cliente));
        archi.read(reinterpret_cast<char*>(&v[i].mes), sizeof(int));
        archi.read(reinterpret_cast<char*>(&v[i].deuda), sizeof(int));
    }

    for (int i = 0; i < dim; i++)
    {
        cout<<"Nombre: "<<v[i].cliente<<" mes: "<<v[i].mes<<" Deuda: "<<v[i].deuda<<endl;
    }
cout<<"---------------------------------------------------------------------"<<endl;
    Nodo<persona> * Lcliente = nullptr;
    Nodo<persona> * Lmes = nullptr;

    for (int i = 0; i < dim; i++)
    {
        insertar(v[i],Lcliente,criterio1);
        insertar(v[i],Lmes,criterio2);
    }

cout<<"---------------------------------------------------------------------"<<endl;
    mostrar(Lcliente);
cout<<"---------------------------------------------------------------------"<<endl;   
    mostrar(Lmes);

borrarsiguente(Lcliente);

   return 0;
}