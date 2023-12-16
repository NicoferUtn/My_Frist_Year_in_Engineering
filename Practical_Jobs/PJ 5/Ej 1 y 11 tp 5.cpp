/* Dada una pila programe una función dup (por duplicar) que reciba la pila y duplique el
elemento que está en el tope (a menos que la pila esté vacía). Por ejemplo si la pila un 1 al tope
seguido más abajo de un 2 (Notación: 1, 2) luego de invocar esta función debe tener 1, 1, 2 */

#include <iostream>

using namespace std;
struct Nodo
{
    int dato{};
    Nodo *sig ;
};

void push(Nodo *& cola, int dato){
    Nodo * nuevonodo = new Nodo;
    nuevonodo ->dato = dato;
    nuevonodo -> sig = cola;
    cola = nuevonodo;
}

void dup(Nodo *& cola){
    if (cola != nullptr)
    {
       push(cola, cola -> dato);
    }
}

void mostrar(Nodo *& cola )
{

    while (cola != nullptr) {
		cout << cola->dato << endl;
		cola = cola->sig;
	}


}

int main (){

    Nodo * cola = nullptr;
    push(cola, 1);
    push(cola, 2);
    push(cola, 3);

    dup(cola);

    mostrar(cola);



    return 0;
}
