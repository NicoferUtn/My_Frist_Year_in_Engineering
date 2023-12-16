/*Dada una lista que contiene enteros programe una función que recorriendo la lista devuelva el
promedio (con decimales) de los valores guardados en la lista.*/

#include<iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
};

void push(Nodo *& cola, int dato){
    Nodo *nuevo = new Nodo;
    nuevo ->dato = dato;
    nuevo ->sig =cola;
    cola = nuevo;
}

int pop(Nodo *&cola){
    int valor = cola->dato;
    Nodo *aux = cola;
    cola = cola->sig;
    delete aux;
    return valor;
}

float promedio(Nodo *&cola){

float promedio = 0 ;
float sumatoria = 0;
float i{};

while (cola != nullptr)
{
    sumatoria += pop(cola);
    i++;
}

return sumatoria/i;
}

int main(){

Nodo *cola = nullptr;
push(cola, 1);
push(cola, 2);
push(cola, 3);
push(cola,4);
push(cola,5);
push(cola,6);

cout<<"El promedio "<<promedio(cola);


    return 0;
}