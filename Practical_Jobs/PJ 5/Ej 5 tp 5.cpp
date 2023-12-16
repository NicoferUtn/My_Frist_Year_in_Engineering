/*Similar al ejercicio anterior (programe solo la variante a) pero en lugar de concatenar intercale.
Por ejemplo si la primer lista tiene 1, 2, 3 y la segunda lista tiene 5, 6, 7, 8, 9 la lista resultante
debe ser 1, 5, 2, 6, 3, 7, 8, 9*/
#include<iostream>

using namespace std;

struct Nodo 
{
    int dato;
    Nodo *sig;
};

int pop(Nodo *& cola){

int valor = cola->dato;
Nodo* aux = cola;
cola = cola->sig;
delete aux;
return valor;
}

void push(Nodo *&cola, int dato){
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo ->sig = cola;
    cola  = nuevo;
}


Nodo* concat(Nodo *& cola, Nodo *& puta){
    Nodo* lista =nullptr;

while (cola != nullptr && puta != nullptr)
{
    if (puta != nullptr)
    {
        push(lista,pop(puta));
    }
    if (cola != nullptr)
    {
        push(lista,pop(cola));
    }
}
    return lista;
}

void mostrar(Nodo* lista){

    while (lista != nullptr)
    {
        cout<<lista ->dato<<endl;
        lista = lista ->sig;
    }
    


}


int main(){

    Nodo* cola = nullptr;
    Nodo* pila = nullptr;
    Nodo* lista = nullptr;

    push(cola, 1);
    push(cola, 2);
    push(cola, 3);
    push(pila,4);
    push(pila,5);
    push(pila,6);

    lista = concat(cola, pila);

    mostrar(lista);
    return 0;
}
