#include <iostream>
using namespace std;
int Search(int* arr, int size, int num);
int main(){
    int dat;
    int array[10]={0,1,2,3,4,5,6,7,8,9};
    int length=9;
    int *pointer=&array[0];
    cout<<"Que dato busca en el arreglo: "<<endl;
    cin>>dat;
    Search(pointer, length, dat);
    return 0;
}

int Search(int* arr, int size, int num){
}