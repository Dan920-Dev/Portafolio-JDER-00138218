#include <iostream>
using namespace std;
void Add(int *a, int lim);
void funRec(int *arr, int size);

int main(){
    int size=0;
    cout<<"Cuantos datos desea agregar en el arreglo: "<<endl;
    cin>>size;
    int array[size];
    int length=size-1;
    int *pointer=&array[0];
    Add(array,length);
    cout<<"El contenido del arreglo es"<<endl;
    funRec(pointer,length);
    cout<<endl;
    return 0;
}

void Add(int *a, int lim){
    if(lim==0){
        cout<<"Ingrese Dato"<<endl;
        cin>>a[lim];
    }else{
        cout<<"Ingrese Dato"<<endl;
        cin>>a[lim];
        Add(a, lim-1);
    }
}

void funRec(int* arr, int size ){
    if(size == 0){
        cout<<arr[size]<<" ";
    }else{
        cout<<arr[size]<<" ";
        funRec(arr,size-1);
    }
}