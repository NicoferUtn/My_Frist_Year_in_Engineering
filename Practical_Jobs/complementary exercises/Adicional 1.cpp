#include <iostream>
#include <fstream>
#include <iomanip>
#include "listasutil.hpp"  
#include "listasorde.hpp"
#include "listas.hpp"
#include "rwstring.hpp"
#include "listasordUni.hpp"

using namespace std;

struct Producto {
    int id{};
    string zona{};
    string producto{};
    int cantidad{};
};

struct Productcant {
    string producto{};
    int cantidad{};
};

struct Tipoproducto {
    int id{};
    string zona{};
    int cantidadpedidos{};
    int sumacantidades{};
    Nodo<Productcant>* listaproductocant = nullptr;
};
const int lzona = 10;
const int lproducto = 15;

fstream& operator >> (fstream& fs, Producto& prod) {
    fs.read(reinterpret_cast<char*>(&prod.id), sizeof(prod.id));
    prod.zona = readstring(fs, lzona);  
    prod.producto = readstring(fs, lproducto);  
    fs.read(reinterpret_cast<char*>(&prod.cantidad), sizeof(prod.cantidad));
    return fs;
}

int criterio1(Tipoproducto a, Tipoproducto b) {
 
    return (a.id == b.id && a.zona == b.zona )? 0: 1;
}
int criterio2( Productcant a, Productcant b) {
 
    return a.cantidad - b.cantidad;
}

ostream& operator << (ostream& co, Tipoproducto& prod) {
    co << prod.id << "\t" << prod.zona << "\t" << prod.cantidadpedidos << "\t" << prod.sumacantidades;
    return co;
}



ostream& operator << (ostream& co, Productcant& prod) {
     co << prod.producto << "\t" << prod.cantidad;
    return co;
}

void mostratlista(Nodo<Tipoproducto>* puta) {
    Nodo<Tipoproducto>* aux = puta; 

    while (aux != nullptr) {
        cout << aux->dato << endl;

        Nodo<Productcant>* listaProductos = aux->dato.listaproductocant;
        while (listaProductos != nullptr) {
            cout << listaProductos->dato << endl;
            listaProductos = listaProductos->sig;
        }

        aux = aux->sig;
    }
}
void buscardatos(Nodo<Tipoproducto>* cola){
Nodo<Tipoproducto>* lista  = cola;
Nodo<Tipoproducto>*pndo = nullptr;
Tipoproducto prod;
string producto{};
cout<<"Dime una id y  una zona  a buscar las combinaciones "<<endl;
   while (cin>>prod.id>>prod.zona && prod.zona != "EOF")
   {
    pndo = buscar(prod,lista,criterio1);
    if(pndo != nullptr){
        cout<<"Decime que producto queres buscar "<<endl;
        cin>>producto;
        while (pndo->dato.listaproductocant != nullptr)
        {
            if (pndo->dato.listaproductocant->dato.producto == producto)
            {
                cout<<pndo->dato.listaproductocant->dato.producto<<"\t "<<pndo->dato.listaproductocant->dato.cantidad<<endl;
            }
            
            
            pndo->dato.listaproductocant= pndo->dato.listaproductocant->sig;
        }
        
        
        
        
    }
   }
    
    
      
  
    }




int main(){
    fstream archi;
    archi.open("pedidos.bin", ios::binary | ios::in);

    if (!archi) {
        cout << "El archivo pedidos.bin no abre correctamente";
        return 1;
    }

    Productcant productcant;
    Producto producto;
    Tipoproducto tipoproducto;
    Nodo<Tipoproducto>* lista = nullptr;
    Nodo<Tipoproducto>* pnodo = nullptr;

    while (archi >> producto) {
        tipoproducto.id = producto.id;
        tipoproducto.zona = producto.zona;
        pnodo = insertar_unico(tipoproducto, lista, criterio1);  
        pnodo->dato.cantidadpedidos++;
        pnodo->dato.sumacantidades += producto.cantidad;
        productcant.cantidad = producto.cantidad;
        productcant.producto = producto.producto;
        agregar(pnodo->dato.listaproductocant,productcant); 
    }
    archi.close();
    
    mostratlista(lista);

cout<<"Que queres buscar??"<<endl;

    buscardatos(lista);
 

    return 0;
}
