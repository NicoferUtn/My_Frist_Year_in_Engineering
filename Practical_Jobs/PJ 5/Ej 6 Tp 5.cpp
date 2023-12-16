/*Dado un string programe la función esCapicua que devuelve true si la cadena ingresada se lee
igual la derecho que al revés. Esta función debe usar las funciones de lista que estamos
practicando.
1. Variante: para poder comprobar frases palíndromas es necesario ignorar los espacios en
blanco.
*/

#include<iostream>

using namespace std;

struct Nodo{

    char dato;
    Nodo* sig;

};

void agregar(Nodo*&cola, int valor){

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


void push(Nodo*& cola, int valor){
    Nodo* nuevo = new Nodo;
    nuevo ->dato = valor;
    nuevo ->sig = cola;
    cola = nuevo;
}

bool esCapicua(Nodo *& cola){

    Nodo* lista = nullptr;
    Nodo* puta = nullptr;

    
    while (cola != nullptr) {
        push(lista, cola->dato);
        agregar(puta,cola->dato);
        cola = cola->sig; 
    }

    
    while (puta != nullptr) {
        if (puta->dato != lista->dato) {
            return false; 
        }
        puta = puta->sig;
        lista = lista->sig;
    }

    return true; 
}
char pop(Nodo*& cola ){

char valor = cola->dato;
Nodo * aux = cola ;
cola = cola->sig;
delete aux;
return valor;
}


int main(){
    Nodo *cola = nullptr;
    
    agregar(cola,char('a'));
    agregar(cola,char('n'));
    agregar(cola,char('a'));
    agregar(cola,char('n'));
    agregar(cola,char('a')); 

    cout<<"La palabra es capicua ";
    if (esCapicua(cola))
    {
        cout<<"Vedadero";
    }else{cout<<"Falso";
    };
    


}