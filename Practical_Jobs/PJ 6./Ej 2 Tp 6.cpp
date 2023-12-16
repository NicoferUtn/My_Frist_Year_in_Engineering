#include<iostream>
#include<fstream>
#include "listasutil.hpp"
#include "listasorde.hpp"
#include "listas.hpp"


using namespace std;
struct compras
{
    int id;
    char cliente[8];
    char producto[10];
    int cantidad;

};


int criterio2(compras a,compras b){
    string c= a.cliente;
    string d = b.cliente;
    string e = a.producto;
    string f = b.producto;
    for (int i = 0; i < 8; i++)
    {
        if (c[i] > d[i])
        {
            return 1;
        }else{
             return -1;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (e[i] > f[i])
        { 
            return 1;
        }else{
             return -1;
        }
    }
    return 0;
}

int criterio1(compras a,compras b){
    return(a.id > b.id)? 1 : -1;
}
int criterio3(int a, compras b){
    return(a == b.id)? 1: -1;
}

int criterio4(char cliente[8], char producto[10], compras a){

    return(cliente[8] == a.cliente[8] && producto[10] == a.producto [10])? 1 :-1;
}

ostream& operator<<(ostream & a,compras& compra){
  a << "ID: " <<compra.id << ", Cliente: " << compra.cliente << ", Producto: " << compra.producto << ", Cantidad: " << compra.cantidad;
  return a;
}



int main(){

ifstream archi;
archi.open("G06E02.bin",ios::binary);
if (!archi)
{
    cout<<"No se puedo abrir el archivo "<<endl;
    return 1;
};

archi.seekg(0, ios::end);
int longitudFichero = archi.tellg();
archi.seekg(0, ios::beg);

const int dim = longitudFichero/((2*sizeof(int))+10+8);

compras v[dim]{};

cout << "Leyendo Archivo" << endl;
for (int i = 0; i < dim; i++) {
        archi.read(reinterpret_cast<char*>(&v[i].id), sizeof(int));
        archi.read(v[i].cliente, sizeof(v[i].cliente));
        archi.read(v[i].producto, sizeof(v[i].producto));
        archi.read(reinterpret_cast<char*>(&v[i].cantidad), sizeof(int));
    }
archi.close();

cout<<"---------------------------------------------------------------------";
cout<<endl;
for (int i = 0; i < dim; i++) {
        cout << "ID: " << v[i].id << ", Cliente: " << v[i].cliente << ", Producto: " << v[i].producto << ", Cantidad: " << v[i].cantidad << endl;
}
cout<<"---------------------------------------------------------------------";
cout<<endl;
Nodo<compras>*Lclientes = nullptr;
Nodo<compras>*Lid = nullptr;
for (int i = 0; i < dim; i++)
{
    insertar(v[i],Lid, criterio1);
    insertar(v[i],Lclientes, criterio2);
    
}

mostrar(Lid);
cout<<"*********************************************************************"<<endl;
mostrar(Lclientes);
cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;





//buscar id
compras a;
    Nodo<compras>* id = nullptr;

    cout << "Dime qué valor de ID quieres mostrar: ";
    int i{};
    while (i >= 0 && cin >> i)
    {
        int criterio = criterio3(i, a);
        id = buscar(i, Lid, criterio);
        if (id != nullptr)
        {
            cout << "Encontramos a " << id->dato << endl;
        }
        else
        {
            cout << "No encontramos a este ID" << endl;
        }
        cout << "Dime qué valor de ID quieres mostrar: ";
    }

//buscar cliente y prod
char cliente[8], producto[10];
cout<<"Dinos un cliente que quieras eliminar y un producto";
cin>>cliente>>producto;
while (cliente != "EOF" && producto != "EOF" )
{
    int criterio1 = criterio4(cliente, producto , a);

   if (borrar(a,Lclientes,criterio1) && borrar(a,Lid,criterio1))
   {
    cout<<"se borro correctamente";
   }else{cout<<"No poertenece a el archivo";}
   
}



    return 0;
}