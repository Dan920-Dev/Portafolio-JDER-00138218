#include <iostream>
#include <string>
using namespace std;

struct Pais{
    string name;
    string Capital;
    int habitantes;
};

void EvaluandoPoblacion(Pais* array, int size, string* c);


int main(){
    
    Pais* Array;
    string continente= "";
    

    cout << "Ingrese el nombre del continente: " << endl;
    cin >> continente; cin.ignore();
    string *c = &continente;
    Array = new Pais[5];
    for(int i = 0; i < 5; i++){
        cout << "Pais No." << i+1 << endl;
        cout << "Nombre: "; getline(cin, Array[i].name); 
        cout << "Capital: "; getline(cin, Array[i].Capital); 
        cout << "No. de habitantes: "; cin >> Array[i].habitantes; cin.ignore();
        cout << endl;
    }

    EvaluandoPoblacion(Array, 5, c);

    return 0;
}

void EvaluandoPoblacion(Pais* array, int size, string* c){
    int suma = 0, may =0, posmay= 0;
    cout << "Continente: " << *c << " " << endl;
    for(int i = 0; i < size; i++){
        suma = suma + array[i].habitantes;
    }
    for(int i = 0; i < size; i++){
        if(array[i].habitantes > may){
            may = array[i].habitantes;
            posmay = i;
        }
    }

    cout << "La cantidad de habitantes en el continente es de: " << suma << endl;
    cout << "La capital con mas habitantes es: " << array[posmay].Capital << " con " << may << " habitantes" << endl;
}

