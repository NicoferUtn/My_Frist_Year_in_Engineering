/*Dada una lista que contiene enteros programe una función que devuelva:
1. Variante a: el mayor valor en la lista
2. Variante b: un puntero al nodo que contiene el mayor elemento en la lista.*/

#include<iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo* sig;
};


void push(Nodo *& cola, int dato){
    Nodo* nuevo = new Nodo;
    nuevo ->dato = dato;
    nuevo ->sig = cola;
    cola = nuevo;
}

int pop(Nodo *& cola){
    int valor = cola->dato;
    Nodo* aux = cola;
    cola = cola -> sig;
    delete aux;
    return valor;
}

int mayor(Nodo *& cola){
    
int mayor = pop(cola);

while (cola != nullptr)
{
    if (mayor < (cola->dato))
    {
        mayor = pop(cola);
    }else{cola = cola->sig;}
}

    return mayor;
}

int main(){

    Nodo * cola = nullptr;

    push(cola, 7);
    push(cola, 5);
    push(cola, 4);
    push(cola,10);
    push(cola,5);
    push(cola,6);


    cout<<"El mayor numero "<<mayor(cola);




    return 0;
}
