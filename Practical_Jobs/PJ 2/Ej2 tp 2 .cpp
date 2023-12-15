#include<iostream>
using namespace std;
  
int cambiarFecha(int fecha,int & dia,int & mes,int & año){
    dia=fecha%100;
    mes=((fecha)%10000)/100;
    año=(fecha)/10000;

    return 0;
}



int main(){
   int fecha,dia,mes,año;
    cout<<"Ingrese una fecha con el formato AAAAMMDD: ";
    cin>>fecha;
    cambiarFecha(fecha,dia,mes,año);
    cout<<"Fecha con formato dia/mes/año: "<<dia<<"/"<<mes<<"/"<<año;

    return 0;
}