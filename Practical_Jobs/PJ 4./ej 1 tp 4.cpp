#include<iostream>

using namespace std;

 int main(){
    int suma = 0;
    const int fil {10};
    int v[fil]{2,4,6,8,10,12,14,16,18,20};

    for (int i = 0; i < fil; i++){
        suma +=v[i];
    }
    cout<<suma;
    return 0;
 }
