//Desarrolle una función que dada una temperatura (float) en grados fahrenheit los convierta a
//grados celcius. Nota: En fahrenheit el punto de congelación del agua es 32° y la temperatura de
//ebullición del agua es 212°.
#include<iostream>
using namespace std;


float grados(float a, float& cel){
    cel = ((a-32)/1.8);

    return 0;
}

int main(){
    float temp,cel = 0;
    cout<<"decime un numeor en fahrenheit para que lo pase a celcuis";cin>>temp;
    grados(temp,cel);
    cout<<"Tu temp en celcius es "<<cel;

    return 0;
}

