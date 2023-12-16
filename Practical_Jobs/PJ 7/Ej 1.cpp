#include<iostream>
#include<fstream>
#include<iomanip>
#include "listasutil.hpp"
#include "listasorde.hpp"
#include "listas.hpp"
#include"rwstring.hpp"
#include"listasordUni.hpp"

using namespace std;

struct Coches{
    string modelo;
    int cantidad{};
};

const int lmodelo {10};

fstream& operator >> (fstream &fs,Coches & coche){
    coche.modelo = readstring(fs, lmodelo);
    fs.read(reinterpret_cast<char*>(&coche.cantidad),sizeof(coche.cantidad));
    return fs;
}
int criterio(Coches a, Coches b){

    return a.modelo.compare(b.modelo);

}
ostream& operator<<(ostream & a,Coches& compra){
  a << "Modelo: " <<compra.modelo << ", cantidad: " << compra.cantidad;
  return a;
}


int main(){
fstream archi;
archi.open("G07E01.bin", ios::binary |ios:: in);
if(!archi){
    cout<<"El archivo G07E01.bin abre mal";
    return 1;
}
    Nodo<Coches>* lista = nullptr;
    Nodo<Coches>*pnodo;

    Coches coche;
    Coches a;

    
    while (archi >>a)
    {
        coche.modelo = a.modelo;
        pnodo = insertar_unico(coche,lista,criterio);
        pnodo ->dato.cantidad += a.cantidad;
    }
    archi.close();
    mostrar(lista);

    return 0;
}