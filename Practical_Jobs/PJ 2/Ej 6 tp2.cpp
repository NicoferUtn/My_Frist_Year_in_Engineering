//Desarrolle una función que a partir de un parámetro entero calcule el factorial del mismo
//usando recursión.
//Variante: use iteración en lugar de recursión
#include<iostream>
using namespace std;
int factorial(int num,int&fact){
    
for (int i = 1;i <=num; i++)
{
    fact *= i;
}

    return 0;
}

int main(){
    int num,fact=1;
    cout<<"Decime un numero para calcular su factorial ";cin>>num;
    factorial(num,fact);
    cout<<"Tu factorail es "<<fact;

    return 0;
}

