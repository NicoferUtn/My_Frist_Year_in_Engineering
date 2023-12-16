/*4. Dada los listas enlazadas programe una función que arme una nueva lista que contenga la
concatenación de los elementos de la primer lista, seguida de los de la segunda.
1. Variante a: las dos listas originales se pierden, es decir, nuestra rutina las vacía.
2. Variante b: las dos listas originales quedan inalteradas
*/

#include <iostream>

using namespace std;


struct Nodo
{
    int dato;
    Nodo*sig;

};


int pop (Nodo * &pila){

	int valor = pila->dato;
    Nodo *aux = pila;
    pila = pila->sig;
    delete  aux;
    return valor;

}

void push(Nodo *&cola,int dato){

    Nodo* nuevo = new Nodo;
    nuevo-> dato = dato;
    nuevo ->sig = cola;
    cola = nuevo;


}




Nodo * concat(Nodo *& cola, Nodo *& pila){

Nodo * lista = nullptr;
while (pila != nullptr)
{
    push(lista, pop(pila));
}
while (cola != nullptr)
{
    push(lista, pop(cola));
}


return lista;
}

void mostrar(Nodo *&lista){

    while (lista != nullptr)
    {
        cout<<lista->dato<< endl;
        lista = lista->sig;
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




    lista = concat(cola ,pila);


    mostrar(lista);












    return 0;
}
