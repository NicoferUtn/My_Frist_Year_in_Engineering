/* Dada una pila programe un función rot (por rotar) tal que si la lista tiene al menos 3 elementos
ponga el tercero al tope y sino deje inalterada la pila. Ejemplo, si la tiene 1, 2, 3, 4 luego de
llamar a esta función la pila quedará: 3, 1, 2, 4 */

#include <iostream>

using namespace std;

struct Nodo 
{
    int dato;
    Nodo * sig;
};

void push(Nodo *& cola, int dato){
    Nodo *nuevo = new Nodo;
    nuevo ->dato = dato;
    nuevo ->sig = cola;
    cola = nuevo;
}
int pop(Nodo *&cola){
    int valor = cola ->dato;
    Nodo * aux = cola;
    cola = cola->sig;
    delete aux;
    return valor;
}
void agregar(Nodo *& cola, int valor)
{
	Nodo* nuevo = new Nodo;
	nuevo->dato = valor;
	nuevo->sig = nullptr;
	if (cola == nullptr) {
		cola = nuevo;
	} else {
		Nodo* aux = cola;
		while (aux->sig != nullptr) 
		aux = aux->sig;  
		aux->sig = nuevo;
	}
}

void rot(Nodo *& cola){
    if (cola->sig->sig->sig != nullptr)
    {
        swap(cola->dato, cola->sig->sig->dato);    
    }
}



void mostrar(Nodo *cola){

    while (cola != nullptr)
    {
        cout<< cola->dato<<endl;
        cola = cola->sig;
    }

}




int main(){

Nodo *cola =nullptr;

agregar(cola,1);
agregar(cola,2);
agregar(cola,3);
agregar(cola,4);

mostrar(cola);

cout<<endl;

rot(cola);
mostrar(cola);




    return 0;
}
