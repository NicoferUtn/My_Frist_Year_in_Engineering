#include<iostream>
#include<fstream>
#include<iomanip>
#include"rwstring.hpp"
#include "listasutil.hpp"
#include "listasorde.hpp"
#include "listas.hpp"
 
using namespace std;
//creamos la estructura
struct Inventario{

    string producto{}; 
    char pasillo{};
    int posicion{};
    int stockInicial{};
    int movimientos{};
    int stockFinal{};
};
//creamos la estructura movimientos
struct Movimientos {
    string producto{};
    char pasillo{};
    int posicion{};
    int movimientos{};
};
const int lproducto {10};
//sobrecargamos para la muestra de la lista mas tarde

fstream& operator >> (fstream &fs,Inventario &inv){
    inv.producto = readstring(fs, lproducto);
    fs.read(reinterpret_cast<char*>(&inv.pasillo),sizeof(inv.pasillo));
    fs.read(reinterpret_cast<char*>(&inv.posicion),sizeof(inv.posicion));
    fs.read(reinterpret_cast<char*>(&inv.stockInicial),sizeof(inv.stockInicial));
    return fs;
}

fstream& operator >> (fstream& fs,Movimientos& mov){
    mov.producto = readstring(fs, lproducto);
    fs.read(reinterpret_cast<char*>(&mov.pasillo),sizeof(mov.pasillo));
    fs.read(reinterpret_cast<char*>(&mov.posicion),sizeof(mov.posicion));
    fs.read(reinterpret_cast<char*>(&mov.movimientos),sizeof(mov.movimientos));
    return fs;
}
fstream& operator << (fstream& fs, const Inventario& inv){
    writestring(fs,inv.producto,lproducto);
    fs.write(reinterpret_cast<const char*>(&inv.pasillo),sizeof(inv.pasillo));
    fs.write(reinterpret_cast<const char*>(&inv.posicion),sizeof(inv.posicion));
    fs.write(reinterpret_cast<const char*>(&inv.stockInicial),sizeof(inv.stockInicial));
    return fs;
}
void ordenar(Inventario vec[], int dim, int (*criterio)(Inventario, Inventario))
{
	int i, j;
	Inventario temp;

	for (i = 1; i < dim ; i++) {
		temp = vec[i];
		j = i - 1;

		//&& vec[j] > temp
		while (j >= 0 && criterio(vec[j], temp) > 0) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = temp;
	}
}


int criterio1(Inventario a, Inventario b){
    if (a.producto == b.producto) {
        if (a.pasillo == b.pasillo) {
            return a.posicion - b.posicion;
        } else {
            return (a.pasillo > b.pasillo)? 1 : -1;// compara por el valor en ASCII
        }
    } else {
        return a.producto.compare(b.producto);// compara por el valor en ASCII
    }
}


void mostrarVector(Inventario vecDeExistencias[], int cantidadDeRegistrosExistencias) {
    for(int i = 0; i < cantidadDeRegistrosExistencias; i++) {// usamos el "setw" es una funcion para que se ordene de forma linda y correcta el vector
        cout << setw(10) << left << vecDeExistencias[i].producto << " "; 
        cout << setw(7) << left << vecDeExistencias[i].pasillo << " ";
        cout << setw(9) << left << vecDeExistencias[i].posicion << " ";
        cout << setw(6) << left << vecDeExistencias[i].stockInicial << " ";
        cout << setw(6) << left << vecDeExistencias[i].movimientos << " ";
        cout << setw(6) << left << vecDeExistencias[i].stockFinal << endl;
    }
}


void validarMovimiento(Movimientos movActual, Inventario vecDeExistencias[], int cantidadDeRegistrosExistencias) 
{
    
    for(int i = 0; i < cantidadDeRegistrosExistencias; i++) 
        //comparamos los archivos para grabar en el vector Inventario que despues sera el archivo final.
        if(movActual.producto == vecDeExistencias[i].producto && movActual.posicion == vecDeExistencias[i].posicion && movActual.pasillo == vecDeExistencias[i].pasillo) {
            vecDeExistencias[i].movimientos += movActual.movimientos;
            vecDeExistencias[i].stockFinal = vecDeExistencias[i].stockInicial + vecDeExistencias[i].movimientos;
            return ;
        }
cout << "No se encontro el producto " << movActual.producto << " en el pasillo " << movActual.pasillo << " en la posicion " << movActual.posicion << endl;  
}

void grabararchivofinal(fstream& final,Inventario vecDeExistencias[], int cantidadDeRegistrosExistencias){
    
    for (int i = 0; i < cantidadDeRegistrosExistencias; i++)
    {
        vecDeExistencias[i].stockInicial = vecDeExistencias[i].stockFinal;
        vecDeExistencias[i].movimientos = 0;
    }
    
//escribimos el archivo final.bin
 for (int i = 0; i < cantidadDeRegistrosExistencias ; ++i){
    final << vecDeExistencias[i]; //mostrar lista
 }
	
    //mostramos la lista actualizada para el dia siguiente
    cout<<"\n=========================================================="<<endl;
    cout<<"Lista actualizada"<<endl;
    cout<<"=========================================================="<<endl;
     cout << "Producto Pasillo  Posicion  Stock  mov    final" << endl;
    mostrarVector(vecDeExistencias, cantidadDeRegistrosExistencias);
    final.close();
}

int main() {
//abrimos los archivos y verificamos que se abran correctamente
    fstream archivoDeExistencias;
    archivoDeExistencias.open("Existencias.bin", ios::binary | ios::in);
    fstream archivoDeMovimientos;
    archivoDeMovimientos.open("Movimientos.bin", ios::binary | ios::in);
    fstream final;
    final.open("Final.bin",ios:: binary | ios :: out);

    if(!archivoDeExistencias || !archivoDeMovimientos || !final) {
        cout << "Error al abrir los archivos" << endl;
        return 1;
    }
        
        const int cantidadDeRegistrosExistencias{40};
        Inventario vecDeExistencias[cantidadDeRegistrosExistencias]{};//creamos el vector
        
        //hacemos la carga de datos
        Movimientos movimientos;
        
        //Punto 1
        for ( int i = 0; i < cantidadDeRegistrosExistencias ; ++i){
                archivoDeExistencias >> vecDeExistencias[i];//cargamos el vector
        } 
        archivoDeExistencias.close(); //cerramos los archivos
       
        //Punto 2
        while (archivoDeMovimientos >> movimientos){
            validarMovimiento(movimientos, vecDeExistencias, cantidadDeRegistrosExistencias);//encontramos el movimiento invalida      
        }
        archivoDeMovimientos.close(); //cerramos los archivos
        
//Ordenamos el vector
        ordenar(vecDeExistencias,cantidadDeRegistrosExistencias,criterio1);
    
//punto 4
    cout<<"Lista ordenada"<<endl;
    cout << "Producto Pasillo  Posicion  Stock  mov    final" << endl;
    mostrarVector(vecDeExistencias,cantidadDeRegistrosExistencias);//mostramos el vector ordenada, por sobrecarga

    grabararchivofinal(final,vecDeExistencias, cantidadDeRegistrosExistencias);

    return 0;

    }
