/*Se dispone del archivo binario G07E02.bin que contiene una lista no ordenada de ventas,
similar al ejercicio anterior, pero agrega como primer campo ciudad, un string guardado con 12
caracteres.
Se debe leer el archivo y las estructuras de datos necesarias para:
1. Listar en forma ascendente cada ciudad, con la cantidad de ventas (registros) y la cantidad
total de unidades vendidas en dicha ciudad.
2. En un ciclo pedir ciudad y listar todas las ventas realizadas en dicha ciudad, en el mismo
orden en que figuraban en el archivo. El listado, como es para una ciudad, informa
solamente modelo y cantidad. Esto se hace en un ciclo hasta que se ingresa EOF.
3. En otro ciclo pedir ciudad y cantidad mínima, con ello informar cuantas ventas en dicha
ciudad superaron la cantidad mínima solicitada. Esto se hace en un ciclo hasta que se
ingresa EOF
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include "listasutil.hpp"
#include "listasorde.hpp"
#include "listas.hpp"
#include"rwstring.hpp"
#include"listasordUni.hpp"

using namespace std;


using namespace std;

struct Coches{
    string ciudad;
    string modelo;
    int cantidad{};
};

struct Ventas{
    string modelo;
    int cantidad{};
};

struct Ciudad{
    string ciudad;
    int ventas{};
    int cantidad{};
    Nodo<Ventas>* lisataventas = nullptr;
};


const int lciudad{12};
const int lmodelo {10};

fstream& operator >> (fstream &fs,Coches & coche){
    coche.ciudad = readstring(fs, lciudad);
    coche.modelo = readstring(fs, lmodelo);
    fs.read(reinterpret_cast<char*>(&coche.cantidad),sizeof(coche.cantidad));
    return fs;
}

ostream& operator<<(ostream& os, Ciudad& coches){
    os<<" Ciudad: "<<coches.ciudad<<" Ventas: "<<coches.ventas<<" Cantidad: "<<coches.cantidad;
    return os;
}

ostream& operator<<(ostream& os, Ventas & coches){
    os<<" Modelo: "<<coches.modelo<<" Cantidad: "<<coches.cantidad;
    return os;
}


int criterio(Ciudad a, Ciudad b){ 
    return a.ciudad.compare(b.ciudad);
}

int main(){
fstream archi;//ifstream = lectura y ofstream = escritura
archi.open("G07E02.bin", ios::binary |ios:: in);// ios :: in = lectura y ios:: out = escritura 
if(!archi){
    cout<<"El archivo G07E02.bin abre mal";
    return 1;
}
    Nodo<Ciudad>* lista = nullptr;
    Nodo<Ciudad>*pnodo;
    Coches coche;
    Ciudad ciudad;
    Ventas ventas;
    
        
    while (archi >> coche){
        ciudad.ciudad = coche.ciudad;
        pnodo = insertar_unico(ciudad,lista,criterio);
        pnodo->dato.ventas++;
        pnodo ->dato.cantidad += coche.cantidad;
        ventas.modelo = coche.modelo;
        ventas.cantidad = coche.cantidad;
        agregar(pnodo->dato.lisataventas,ventas);
    }

    archi.close();
    mostrar(lista);


Ciudad ciu;
Nodo<Ciudad>* cola = nullptr;
cout<<"Dime que ciudad quieres buscar, si pones 'EOF' se cancela el ciclo: ";

    while (cin>>ciu.ciudad && ciu.ciudad != "EOF")
    {
        cola = buscar(ciu,lista,criterio);
        if (cola)
        {
            cout<<"La ciudad es "<<ciu.ciudad<<endl;;
            cout<<"Modelo y cantidad"<<endl;
            mostrar(cola->dato.lisataventas);
        }else{cout<<"no se pudo encontrarar la ciudad";}
        
    }
    

Ciudad ciua;
Nodo<Ciudad>* puta = nullptr;  
int valor{};
cout<<"Dime que ciudad quieres buscar y decime una cantidad minima de ventas, si pones 'EOF' se cancela el ciclo: ";

    while (cin>>ciua.ciudad>>ciua.cantidad && ciua.ciudad != "EOF")
    {
        valor = ciua.cantidad;
        puta = buscar(ciua,lista,criterio);
        if (puta != nullptr)
        {
            cout<<"La ciudad es "<<ciua.ciudad<<endl;
            cout<<"la cantidad minima es "<<ciua.cantidad<<endl;
            cout<<"Modelo y cantidad"<<endl;
            Nodo <Ventas>* hola = puta->dato.lisataventas;
            while (hola != nullptr)
            {
                if(hola->dato.cantidad > valor){
            cout << hola->dato.modelo <<endl;
            cout << hola->dato.cantidad <<endl;
		    hola = hola->sig;
                
            }else{hola->sig;}
            }
        }else{cout<<"no se pudo encontrarar la ciudad";}
        
    }
    return 0;
}