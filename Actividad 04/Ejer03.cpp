#include <iostream>
using namespace std;

void Search(int* arr, int size, int num, int aux);

int main(){
    int dat;
    int array[10]={15,1,21,50,4,100,64,7,33,9};

    cout << "En el arrelo se encuentran los siguientes datos: " << endl;
    for(int i = 0; i < 10; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    cout<<"Que dato busca en el arreglo: "<<endl;
    cin>>dat;
    Search(array, 10, dat, 0);
    cout << endl;
    
    return 0;
}

void Search(int* arr, int size, int num,  int aux){
    if(aux == size){
        return ;
    }else{
       if(num == arr[aux]){
           cout << "El numero: " << num << " si se encuentra en el arreglo" ;
           Search(arr, size, num, aux + 1);
       }else{
           Search(arr, size, num, aux + 1);
       } 
    }
    
}
