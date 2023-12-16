#include<iostream>
#include "listasutil.hpp"
#include "listasorde.hpp"

using namespace std;

struct alumno
{
    string nombre;
    int legajo;
    double promedio;
};

int criterio( alumno a, alumno b)
{
	if (a.promedio == b.promedio)
    {
        return a.nombre.compare(b.nombre);
    }else{
        return a.promedio > b.promedio ? -1 : 1;
    }   
}
ostream& operator<<(ostream& os, const alumno& a)
{
    os << a.nombre<<"/";
    os << a.legajo<<"/" ;
    os << a.promedio ;
    cout<<endl;
    return os;
}
int main(){
const int dim {9};
alumno vec[dim]{"Maria", 721, 8.4,"Pedro",847,7.2,"Ana", 614, 9.1,
            "Jose", 578, 8.9, "Juan", 927, 8.4, "Unai", 325, 8.1,
             "Ramon", 418, 8.4, "Elaia", 892, 9.6, "Carlos", 733,8.5
             };
cout<<vec;
Nodo<alumno>* lista = nullptr;
for (int i = 0; i < dim; i++)
{
    insertar(vec[i],lista,criterio);
}
mostrar(lista);

const int dim1 {3};
alumno v[dim1]{"Pedro", 847, 7.2, "Ramon", 418, 8.4, "Unai", 325, 8.1};
cout<<"Los alumnos que se dan de baja son:"<<endl;

for (int i = 0; i < dim1; i++)
{
    cout<<v[i]<<endl;
}
for (int i = 0; i < dim1; i++)
{
    borrar(v[i],lista,criterio);
}
cout<<"los alumnos sobrantes son"<<endl;
mostrar(lista);
    return 0;
}