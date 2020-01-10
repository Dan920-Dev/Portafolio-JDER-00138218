#include <iostream>
using namespace std;
//Funciones que se utilizaran para calcular mediana
float median_pair(int *, int);
float median_odd(int *, int);

int main(){
// Declarando variables
float median=0;
int n=0;

//Solicitando tamaño del arreglo
cout<<"Digite el tamaño del arreglo"<<endl;
cin>>n;

//Declarando arreglo
int array[n];
cout<<"Ingrese datos al arreglo, tomando en cuenta el orden de los numeros"<<endl;

//Llenando el arreglo
for(int i=0;i<n;i++){
    cout<<"Ingrese el dato "<<i+1<<" en el arreglo"<<endl;
    cin>>array[i];
}

//Verificamos si el arreglo es par o impar
if(n%2==0){
    median=median_pair(array,n);
    cout<<"La mediana es: "<<median<<endl;
}else{
    median=median_odd(array,n);
    cout<<"La mediana es: "<<median<<endl;
}

    return 0;
}

//Funcion longitud par
float median_pair(int *pointer, int length){
    float median=0;
    int sum,data;

    data=length/2;
    sum= *(pointer+data-1)+ *(pointer+data); 
    median= (float) sum/2;
    return median;
}

//funcion longitud impar
float median_odd(int *pointer, int length){
     float median;
     int data;

     data=length/2;
     median= *(pointer+data);
     return median;
}