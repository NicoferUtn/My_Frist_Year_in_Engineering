/*Dada una pila programe una función swap que inverta los dos elementos tope. Si la pila tiene 1,
2, 3 luego de llamar a esta función tendrá 2, 1 , 3. Si la pila tiene menos de dos elementos la
función la deja inalterada*/

#include<iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo * sig;
};

void push(Nodo *& cola, int dato){
   Nodo * nuevo = new Nodo; 
    nuevo ->dato = dato;
    nuevo ->sig = cola;
    cola = nuevo;
}

void mostrar(Nodo *cola){

 while (cola != nullptr) {
		cout << cola->dato << endl;
		cola = cola->sig;
	}


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

int pop(Nodo* &pila)
{
	int valor = pila->dato;
	Nodo* aux_elim = pila;
	pila = pila->sig;
	delete aux_elim;
	return valor;
}
void invertir(Nodo *& cola){
    if (cola != nullptr && cola ->sig != nullptr)
    {
      swap(cola->dato, cola->sig->dato);    
    }
}



int main(){

    Nodo * cola = nullptr;
    agregar(cola,1);
    agregar(cola,2);
    agregar(cola,3);
    
    mostrar(cola);

    cout<<endl;

    invertir(cola);

    mostrar(cola);









    return 0;
}


