#include <iostream>
using namespace std;

int asd[8] = {1,3,4,5,17,18,31,33};

int buscar(int x, int low, int high){
    if(low > high){
        return -1;
    };
    
    int mid = (low + high) / 2;
    
    if(x == asd[mid]){
        return mid;
    };
    
    if(x < asd[mid]){
        return buscar(x, low, mid-1);
    }else{
        return buscar(x, mid+1, high);
    };
}

int main(){
    int number, i;
    
    cout << "Ingrese un numero entero positivo: "; cin >> number;
    i = buscar(number, 0, 8);
    
    if(i == -1){
        cout << "Numero no encontrado." << endl;
    }else{
        cout << "El numero esta en la casilla: " << i << endl;
    }
    
    return 0;
}