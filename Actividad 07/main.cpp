#include <iostream>
#include <string>
using namespace std;

struct libro{
    string nombre;
    string tipo;
};
typedef struct libro Libro;

struct nodo{
    Libro elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;

void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, Libro e);
Libro pop(Pila *s);
Libro top(Pila *s);

int main(){
    Pila pilaLibros;
    initialize(&pilaLibros);

    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\nDesea apilar otro plato? (s/n): ";
        cin >> opcion; cin.ignore();
        
        if(opcion == 's'){
            Libro unLibro;
            cout << "Nombre del libro: ";      getline(cin, unLibro.nombre);
            cout << "Tipo: ";       getline(cin, unLibro.tipo);
            push(&pilaLibros, unLibro);
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);

     cout << "\nDesapilando platos..." << endl;
    while(!empty(&pilaLibros)){
        Libro libroDeEncima = top(&pilaLibros);
        cout << "Libro [" << libroDeEncima.nombre;
        cout << ", " << libroDeEncima.tipo << "]\n";

        pop(&pilaLibros);
    }
    cout << "Pila de Libros vacia." << endl;


    return 0;
}

void initialize(Pila *s){
    *s = NULL;
}

bool empty(Pila *s){
    return *s == NULL;
}

void push(Pila *s, libro e){
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;
    
    *s = unNodo;
}

Libro pop(Pila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        Libro e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else // Underflow!
        return {{" "},{" "}};
}

Libro top(Pila *s){
    if(!empty(s))
        return (*s)->elemento;
    else // Underflow!
        return {{" "},{" "}};
}