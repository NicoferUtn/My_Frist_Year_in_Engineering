#include<iostream>
#include<fstream>
#include<iomanip>
 
using namespace std;
//creamos la structura
struct Inventario{

    char producto[10]; //utilizamos char en lugar de string ya que en la consigna aclara la cantidad de tamaÃ±o en caracteres 
    char pasillo[1];
    int posicion;
    int stockInicial;
    int movimientos;
    int stockFinal;
};

struct Movimientos {
    char producto[10];
    char pasillo[1];
    int posicion;
    int movimientos;
};

void procesarArchivoDeExistencias(ifstream &archivo, Inventario vecDeExistencias[], int cantidadDeRegistrosExistencias);
void procesarArchivoDeMovimientos(ifstream& archivo, Inventario vecDeExistencias[], int cantidadDeRegistrosExistencias);
void mostrarVector(Inventario vecDeExistencias[], int cantidadDeRegistrosExistencias);
int cantidadDeRegistros(ifstream &archivo);
bool validarMovimiento(Movimientos movActual, Inventario vecDeExistencias[], int cantidadDeRegistrosExistencias);

int main() {
    ifstream archivoDeExistencias("Existencias.bin", ios::binary);
    ifstream archivoDeMovimientos("Movimientos.bin", ios::binary);

    if(!archivoDeExistencias.is_open() || !archivoDeMovimientos.is_open()) {
        cout << "Error al abrir los archivos" << endl;

        return 1;
    }
    else
    {
        int cantidadDeRegistrosExistencias = cantidadDeRegistros(archivoDeExistencias);
        Inventario vecDeExistencias[cantidadDeRegistrosExistencias]{};

        procesarArchivoDeExistencias(archivoDeExistencias, vecDeExistencias, cantidadDeRegistrosExistencias);
        procesarArchivoDeMovimientos(archivoDeMovimientos, vecDeExistencias, cantidadDeRegistrosExistencias);
        archivoDeExistencias.close();

        cout << "Producto Pasillo  Posicion  Stock  mov final" << endl;

        mostrarVector(vecDeExistencias, cantidadDeRegistrosExistencias);
    }

    return 0;
}

void procesarArchivoDeExistencias(ifstream &archivo, Inventario vecDeExistencias[], int cantidadDeRegistrosExistencias) {
    for(int i = 0; i < cantidadDeRegistrosExistencias; i++) {
        archivo.read(vecDeExistencias[i].producto, sizeof(vecDeExistencias[i].producto));
        archivo.read(vecDeExistencias[i].pasillo, sizeof(vecDeExistencias[i].pasillo));
        archivo.read(reinterpret_cast<char*>(&vecDeExistencias[i].posicion), sizeof(int));
        archivo.read(reinterpret_cast<char*>(&vecDeExistencias[i].stockInicial), sizeof(int));

        vecDeExistencias[i].movimientos = 0;
        vecDeExistencias[i].stockFinal = 0;
    }
}

void procesarArchivoDeMovimientos(ifstream& archivo, Inventario vecDeExistencias[], int cantidadDeRegistrosExistencias) {
    Movimientos movActual{};

for (int i = 0; i < 121; i++) {
        archivo.read(vecDeExistencias[i].producto, sizeof(vecDeExistencias[i].producto));
        archivo.read(vecDeExistencias[i].pasillo, sizeof(vecDeExistencias[i].pasillo));
        archivo.read(reinterpret_cast<char*>(&vecDeExistencias[i].posicion), sizeof(int));
            archivo.read(reinterpret_cast<char*>(&vecDeExistencias[i].movimientos), sizeof(int));
        
    }
        if(!archivo.eof()) {
            if(!validarMovimiento(movActual, vecDeExistencias, cantidadDeRegistrosExistencias))
                cout << "No se encontro el producto " << movActual.producto << " en el pasillo " << movActual.pasillo << " en la posicion " << movActual.posicion << endl;
        }
    }


void mostrarVector(Inventario vecDeExistencias[], int cantidadDeRegistrosExistencias) {
    for(int i = 0; i < cantidadDeRegistrosExistencias; i++) {
        cout << setw(10) << left << vecDeExistencias[i].producto << " ";
        cout << setw(7) << left << vecDeExistencias[i].pasillo << " ";
        cout << setw(9) << left << vecDeExistencias[i].posicion << " ";
        cout << setw(6) << left << vecDeExistencias[i].stockInicial << " ";
        cout << setw(6) << left << vecDeExistencias[i].movimientos << " ";
        cout << setw(6) << left << vecDeExistencias[i].stockFinal << endl;
    }
}

int cantidadDeRegistros(ifstream &archivo) {
    archivo. seekg(0, ios::end);
    int longitudFichero = archivo.tellg();
    archivo.seekg(0, ios::beg);

    return longitudFichero / (10 + 1 + 2 * sizeof(int));
}

bool validarMovimiento(Movimientos movActual, Inventario vecDeExistencias[], int cantidadDeRegistrosExistencias) {
    string productoActual = movActual.producto;
    string pasilloActual = movActual.pasillo;


    for(int i = 0; i < cantidadDeRegistrosExistencias; i++) {
        string productoExistencia = vecDeExistencias[i].producto;
        string pasilloExistencia = vecDeExistencias[i].pasillo;

        if(pasilloActual == pasilloExistencia && movActual.posicion == vecDeExistencias[i].posicion && productoActual == productoExistencia) {
            vecDeExistencias[i].movimientos += movActual.movimientos;
            vecDeExistencias[i].stockFinal = vecDeExistencias[i].stockInicial + vecDeExistencias[i].movimientos;

            return true;
        }
    }

    return false;
}