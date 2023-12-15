//Se desea calcular el valor de π usando la serie de Liebniz, sin usar ninguna optimización.
//Debe iterar hasta que el valor de π se correcto en sus 6 primeros decimales (3,141592)

#include<iostream>
#include<iomanip>
using namespace std;
double serie()
{
    double x = 0, f = 0;
    while (x <=(0.785398)|| x >= (0.785399)) // El while esta capado para que busque un valor cercano a el numero buscado de pi
  {
    x += (1/(f+1))-(1/(f+3));
    f += 4; 
  }
  cout<<i;
    x *= 4; // depues lo multiplicamos por 4 ya que el ciclo while saca π/4 * 4 = π
  return x;
}
   
int main()
{    
    cout<<"Tu numero con la serie de Liebniz es: "<<setprecision(7)<<serie();

  return 0; 
}