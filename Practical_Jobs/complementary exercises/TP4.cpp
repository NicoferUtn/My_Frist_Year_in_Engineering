#include <iostream>
#include "arboles.hpp"

using namespace std;

struct Producto {
    string Producto;
    float precio;
};

ostream& operator<<(ostream& os, Producto & prod){  
    os<<" Producto: "<<prod.Producto<<" Precio: "<<prod.precio;
    return os;
}

int critrio(Producto a, Producto b) {
    return a.Producto.compare(b.Producto);
}

int main() {
    NodoAr<Producto>* Arbol = nullptr;
    Producto prod;
    NodoAr<Producto>* pndo = nullptr;


    insertar({"fideos", 6.6},Arbol,critrio);
    insertar({"arroz", 3.3},Arbol,critrio);
    insertar({"conejo", 5.5},Arbol,critrio);
    insertar({"aceite", 2.2},Arbol,critrio);
    insertar({"papa", 10.1},Arbol,critrio);
    insertar({"harina", 8.8},Arbol,critrio);
    insertar({"pollo", 14.4},Arbol,critrio);

    cout << "************* PREORDEN **********" << endl;
    preorden(Arbol, ver);
    cout << "************* POSTORDEN **********" << endl;
    postorden(Arbol,ver);
    cout << "************* INORDEN **********" << endl;
    inorden(Arbol,ver);


    
    cout << "Ingrese el nombre del producto a buscar: "<<endl;
    if (cin>>prod.Producto && prod.Producto != "EOF")
    {
        pndo = buscararbol(prod, Arbol, critrio);
    if (pndo != nullptr) {
        cout<<"Producto fue encontrado"<<endl;
        cout<<"Producto --->: "<<pndo->dato.Producto<<endl;
        cout<<"Precio --->: "<<pndo->dato.precio<<endl;
    } else {
        cout << "Producto no encontrado." << endl;
    }
    }
    
    return 0;
}