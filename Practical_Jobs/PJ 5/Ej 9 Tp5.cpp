/*Vuelva a programar la variante a del punto 4 (concatenar dos listas perdiendo las originales)
pero sin las restricciones de la primera parte.*/

#include<iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
};

void push(Nodo*& cola, int dato){
    Nodo* nuevo = new Nodo;
    nuevo ->dato = dato;
    nuevo ->sig = cola;
    cola = nuevo;
}


Nodo* concatenar(Nodo *& cola, Nodo *& lista){
Nodo *puta = nullptr;

while (lista != nullptr)
{
        push(puta,lista->dato);
        lista = lista->sig; 
}
while (cola != nullptr)
{
        push(puta,cola->dato);
        cola = cola->sig; 
}

    return puta;

}

void mostrar(Nodo *& puta){
    while (puta != nullptr)
    {
        cout<<puta->dato<<endl;
        puta = puta ->sig;
    }
    


}



int main(){

Nodo* cola = nullptr;
Nodo* lista = nullptr;
Nodo* puta = nullptr;

push(cola,1);
push(cola,2);
push(cola,3);
push(lista,4);
push(lista,5);
push(lista,6);

puta = concatenar(cola,lista);
mostrar(puta);
    return 0;
}



