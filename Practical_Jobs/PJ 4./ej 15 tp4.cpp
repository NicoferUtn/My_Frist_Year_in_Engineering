#include<iostream>
#include<fstream>

using namespace std;

int main(){
    
    ifstream archo;
    archo.open("datosG04E15nombres.txt");
    const int diml {6},coll{3};
    string vec[diml],vecc[coll];

   for (int i = 0; i < diml; i++)
   {
        archo>> vec[i];
   }
   for (int i = 0; i < coll; i++)
   {
        archo>> vecc[i];
   }
   
    archo.close();

    ifstream archi;
    archi.open("datosG04E15producc.txt");
    const int dim {6},col{3};
    int productos[dim][col]{};
    int aux{},aux1{},cod{};
    int ves[dim]{};
    int m[dim][col]{};

    while(archi){
    archi>>aux;
    archi>>aux1;
    archi>>cod;

    productos[aux][aux1] += cod;
    ves[aux] += cod;
    m[aux][aux1]++;
    
    }

    archi.close();

    int columna{},linea{}, mayor{};
    int mayc{},mayl{};
for (int i = 0; i < dim; i++)
{ 
  
    for (int j = 0; j < col; j++)
    {
      
        if (productos[i][j] > productos[mayc][mayl])
        {
            mayc = i;
            mayl = j;
        }

        if (productos[i][j]/m[i][j]> mayor)
        {
          mayor = productos[i][j]/m[i][j];
            columna = i;
            linea = j;
        }
        
        
    }
    
}
cout<<mayc<<mayl;
  cout<<"El producto que mas se producio fue: "<<vec[mayl]<<" del color "<<vecc[mayc]<<endl;
  cout<<"Se produjeron: "<<productos[mayc][mayl]<<endl;

cout<<".................................................................................."<<endl;

int min {}, prod{};
for (int i = 0; i < dim; i++)
{
   if (ves[i] < ves[min])
   {
        min = i;
        prod = i;

   }
}

  cout<<"\nEl producto que menos se produjo "<<vec[prod]<<endl;
  cout<<"Se produjeron: "<<ves[min]<<endl;
  
cout<<".................................................................................."<<endl;

cout<<"Con el producto "<<vec[columna]<<" y el color "<<vecc[columna]<<endl;
  cout<<"Se produjeron: "<<mayor<<endl;
  
    return 0;
}