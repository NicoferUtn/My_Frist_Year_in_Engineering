//llamamos a todas la librerias que usaremos mas tarde y a los Templates
#include<iostream>
#include<fstream>
#include<iomanip>
#include "listasutil.hpp"
#include "listasorde.hpp"
#include "listas.hpp"
#include"rwstring.hpp"
#include"listasordUni.hpp"

using namespace std;

struct Carga //stuct de cargas
{
    string ciudad{};
    int codigo{};
    string producto{};
    int unidades{};
    float monto{};
};
const int Lciudad{14}; //constante de longitud en caracterres de ciudades
const int Lproducto{10}; //constante de longitud de caracteres de productos

struct Cantidades
{
    string producto{};
    int unidades{};
    float monto{};
};

struct Trans
{
    int transportistas{};
    int totalenvios{};
    
};

struct Inventario
{
    string ciudad{};
    int totalunidades{};
    float totalmontos{};
    Trans trasportista[6]{};
    Nodo<Cantidades>* listcantidades = nullptr;
};

fstream& operator>>(fstream& fs, Carga& carga) //sobrecarga para la carga de datos del archivo binario
{
    carga.ciudad = readstring(fs, Lciudad);
    fs.read(reinterpret_cast<char*>(&carga.codigo), sizeof(carga.codigo));
    carga.producto = readstring(fs, Lproducto);
    fs.read(reinterpret_cast<char*>(&carga.unidades), sizeof(carga.unidades));
    fs.read(reinterpret_cast<char*>(&carga.monto), sizeof(carga.monto));
    return fs;
}

ostream& operator<<(ostream& os, Cantidades& cant) //Sobre carga en pra mostrar en Linea => 86
{
    os << cant.producto << "\t" << cant.unidades << "\t" << cant.monto;
    return os;
}

int criterio(Inventario a, Inventario b)
{//Criterio para comprara en base a las palabras:: Linea => 190
    return a.ciudad.compare(b.ciudad);
}

int criterio1(Cantidades a, Cantidades b) 
{//Criterio para comprara en base a las palabras :: Linea => 149
    return a.producto.compare(b.producto);
}


int puntocontrol(Nodo<Cantidades>* lista)
{
    //Hacemos un punto de control con los valores que necesitamos
    Nodo<Cantidades>* p = lista; //Creamos una nueva lista para no perdere la antigua
    int total_unidadesciudad{}; //Clave 0 y total de unidades por ciudad
    while (p!= nullptr)
    {
    int total_unidades{};// Total de unidades por producto
    float total_monto{};//Total de montos por producto
    string producto_anterior = p->dato.producto;//Clave 1
    while (p!= nullptr && producto_anterior == p->dato.producto)
    {
        cout<<p->dato<<endl; 
        total_monto += p->dato.monto; //sumamos totdos los montos por producto
        total_unidades +=p->dato.unidades;  //sumamos todos los unidades por producto
        p = p->sig; //pasamos al siguiente elemento
    }
    total_unidadesciudad += total_unidades;//sumamos todas las unidades por viudadd
    cout<<"Σ"<<producto_anterior<<": "<< total_unidades<<"\t"<<total_monto<<endl; //mostramos
    cout<<endl;
    }
    return total_unidadesciudad; //retornamos el total de unidades por ciudad pra comprarla para encontra a la ciudad con menos unidades producidas
}
string mostrarlista(Nodo<Inventario>* lista, string vecnombres[], const int dim)
{
    Nodo<Inventario>* aux = lista; // Creamos una lista auxiliar para no perder la lista original
    //Creamos una variable para guardar la ciudad de menor cantidad de unidades
    string ciudadmenor{}; 
    int menorciudadnum{}; 
    int a {INT_MAX};

    while (aux != nullptr) //mistras el aux tenga elementos
    {
        cout<<endl;
        cout<<aux->dato.ciudad;// mostramos la ciudad
        cout << "\nTotal unidades: " << aux->dato.totalunidades << "\t" << "Monto total: " << aux->dato.totalmontos << endl;//mostramos el total de unidades y monto
        cout << "Transportistas" << "\t\t" << "Envios" << endl;

        for (int i = 0; i < dim; i++)
        {
                    //vectornombre[Numero de trasportista]                              Cantidad de envios por trasportistas
            cout << vecnombres[aux->dato.trasportista[i].transportistas] << "\t" << aux->dato.trasportista[i].totalenvios << endl;
        }
        cout << endl;
        cout << "Producto" << "\t" << "Unidades" << "\t" << "Monto" << endl;
        menorciudadnum = puntocontrol(aux->dato.listcantidades);//llamamos al punto de control para mostrar por producto

        if(menorciudadnum< a ){ //calculamos la menor ciudad
            ciudadmenor = aux->dato.ciudad;
            a = menorciudadnum;
        }

        aux = aux->sig;
        cout << "\n======================================================";
    
}
//mostramos la menor ciduad y returnamos la menor ciudad
cout<<"\nLa menor ciudad es: "<<ciudadmenor<<endl; 
return ciudadmenor;
}
    
void buscarnuevo(Nodo<Inventario>* lista, string ciudadmenor) {
    //Nos movemos hasta la ciudad menor encontradas, esto lo hacemos para que el codigo pueda ser lo mas generico posible
    while (lista != nullptr && lista->dato.ciudad != ciudadmenor) { //moverme hasta Ciudad menor (Rosario)
        lista = lista->sig;
    }

    if (lista != nullptr) {
        Nodo<Cantidades>* listaCantidades = lista->dato.listcantidades; //Creamos una lista para no tener que recorrer en la busqueda TODA la lista nuevamente
        
        Cantidades cant;
        cout << "Dime qué producto quieres buscar (Se corta cuando se introduce EOF): ";
        while (cin >> cant.producto && cant.producto != "EOF") {  //asignamos la palabra "EOF" para parar el ciclo
            int cantidadprod{};
                //creamos un puntero             =   buscamos en la lista respetando el criterio
            Nodo<Cantidades>* productoEncontrado = buscar(cant, listaCantidades, criterio1);
            if (productoEncontrado != nullptr) {
                cout << "El producto que ingresaste es: " << cant.producto << endl; //mostramos el producto que ingreso
                while (productoEncontrado != nullptr) //hacemos la sumatoria de la cantidad de los producto que elijio el operador
                {
                    if (productoEncontrado->dato.producto == cant.producto)
                    {
                        cantidadprod ++;
                    }
                    productoEncontrado = productoEncontrado->sig;
                    
                }
                cout << "Tiene " << cantidadprod << " Envios" << endl; //mostramos la cantidad en caso de ser positiva la busqueda
            } else {
                cout << "Este producto no existe en " << ciudadmenor << endl; //Le decimos al operador que el producto no existe en la lista donde se cargo todo 
            }
        }
    }
}


int main()
{
    fstream archi; //Creamos el Archivo (archi)
    archi.open("Datos.bin", ios::binary | ios::in);
    if (!archi) //verificamos si el archivo fue abierto correctamente
    {
        cout << "El archivo datos no se pudo abrir correctamente";
        return 1;
    }

    Nodo<Inventario>* lista = nullptr; //Creamos la lista
    Nodo<Inventario>* pndo = nullptr; // y su puntero correspondiente
    //Cremso la variable spara cada struct correspondient6e
    Carga carga;
    Inventario inventario;
    Cantidades cantidades;

    while (archi >> carga)
    {
        inventario.ciudad = carga.ciudad; //igualamos la ciudad.
        pndo = insertar_unico(inventario, lista, criterio); 
        //Cargamos a al puntero los datos cargados de la carga
        pndo->dato.totalmontos += carga.monto; 
        pndo->dato.totalunidades += carga.unidades; 
        pndo->dato.trasportista[carga.codigo].totalenvios++; 
        pndo->dato.trasportista[carga.codigo].transportistas = carga.codigo;
        //Cargamos a la srtuct los datos de la carga 
        cantidades.monto = carga.monto;
        cantidades.producto = carga.producto;
        cantidades.unidades = carga.unidades;
        insertar(cantidades,pndo->dato.listcantidades,criterio1); //insrtamos a la lista los datos cargados a la stuct
        
    }

    archi.close(); //cerramos (archi)

    fstream nombres; //Creamos el Archivo (nombres)
    nombres.open("Nombres.txt");
    if (!nombres)//verificamos si el archivo fue abierto correctamente
    {
        cout << "El archivo nombres no se cargó correctamente";
        return 1;
    }

    const int dim {6}; //cremos la dimencio de un vector
    string vnom[dim]{}; // creamos el vector nombres
    string palabra1, palabra2; // Creamos las string donde se van a cargar los nombres 
   
    int i{};
    // Cargamos los nombres al vector
    while (nombres >> palabra1 >> palabra2 && i < dim)
    {
        vnom[i] = palabra1 + " " + palabra2;
        i++;
    }

    nombres.close(); //cerramos el Archivo (nombres)
    string ciudadmenor{};
 
    ciudadmenor = mostrarlista(lista, vnom, dim); //llamamos a la funcion mostrar
    buscarnuevo(lista, ciudadmenor);
    
    return 0;
}