#include <iostream>
using namespace std;

void Sum_matrix(int *, int *, int, int);

int main(){
    //Declarando variables
    int a,b;

    cout<<"Digite el tamaño de ambas matrices "<<endl;
    cout<<"Filas: ";
    cin>>a;
    cout<<"Columnas: ";
    cout<<endl;
    cin>>b;

    //Asignando tamaño de lla matriz
    int array1[a][b], array2[a][b];

    //Llenando Matriz 1
    cout<<"Empieze a llenar la matriz 1: "<<endl;    
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout<<"Ingrese el dato en la matriz 1, posicion: ["<<i<<"]"<<"["<<j<<"]"<<endl;
            cin>>array1[i][j];
        }
    }
    
    //Llenando Matriz 2
    cout<<"Empieze a llenar la matriz 2: "<<endl;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout<<"Ingrese el dato en la matriz 2, posicion: ["<<i<<"]"<<"["<<j<<"]"<<endl;
            cin>>array2[i][j];
        }
    }
    
    cout<<"La matriz resultante es: "<<endl;
    Sum_matrix(*array1, *array2, a, b);

    //Parte 2 del ejercicio
    cout<<endl<<endl<<endl;
    cout<<"PARTE 2 DE LA ACTIVIDAD"<<endl;
    cout << "Posicion usando la formula *(*m+i*COLS+j) " << endl;
    cout << "a[0][0]=100" << endl;
    cout << "a[2][1]=141" << endl;
    cout << "a[5][1]=201" << endl;
    cout << "a[1][10]=130" << endl;
    cout << "a[2][10]=150" << endl;
    cout << "a[5][3]=203" << endl;
    cout << "a[9][19]=299" << endl;

    return 0;
}

void Sum_matrix(int *p, int *p2, int rows, int columns){
    int matrix_result[rows][columns];
    for (int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            matrix_result[rows][columns]=*(p+i*columns+j)+*(p2+i*columns+j);
            cout<< matrix_result[rows][columns]<<" ";
        }
        cout<<endl;
    }
    
}