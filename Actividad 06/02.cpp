#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct libro{
    string name;
    string tipo;
};
typedef struct plato Libro;

int main(){
    stack<libro> pilaDeLibros;
    libro unLibro;

    cout << "Ingrese los datos de 3 libros" << endl;

    for(int i = 0; i < 3; i++){
        cout << "nombre: ";   getline(cin, unLibro.name);
        cout << "Tipo: ";  getline(cin, unLibro.tipo);

        pilaDeLibros.push(unLibro); 
    }
            
    cout << "\nDesapilando libros" << endl;
    while(!pilaDeLibros.empty()){
        libro libroEncima = pilaDeLibros.top();
        cout << "Nombre del libro: " << libroEncima.name << endl;
        cout << "Tipo: " << libroEncima.tipo << endl;
        pilaDeLibros.pop();
    }
    cout << "Pila de libros vacia." << endl;

    return 0;
}

