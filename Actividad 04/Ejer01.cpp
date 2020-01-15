#include <iostream>
using namespace std;

int sum(int );

int main(){
    int N, r;

    cout<<"Ingrese el valor de N: "<<endl;
    cin>>N;

    r= sum(N);
    cout<<"La suma es: "<<endl;
    cout<<r<<endl;
    return 0;
}

int sum(int valor){
    int sumt=0;
    if(valor==1){
        return 1;
    }else{
        sumt=valor+sum(valor-1);
        return sumt;
    }
}