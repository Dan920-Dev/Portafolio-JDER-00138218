#include <iostream>
using namespace std;

// Funciones que dependen del tipo de dato de los nodos
int solicitarDato(){
    int unDato = 0;
    cin >> unDato; cin.ignore();
    return unDato;
}
void mostrarDato(int unDato){
    cout << unDato;
}

enum comparacion{menorque,mayorque,igualque};

bool comparar(int a, comparacion operador, int b){
    bool resultado = false;
    switch(operador){
        case menorque: resultado = a < b; break;
        case mayorque: resultado = a > b; break;
        case igualque: resultado = a == b; break;
    }
    return resultado;
}

//------ Creacion de nodo y de arbol ------
typedef int T;

struct Nodo{
    T info;
    struct Nodo *izq;
    struct Nodo *der;
};
typedef struct Nodo *Arbol;

// variable globales para calcular la prof
int profundidad = 0, aux = 0;
Arbol crearArbol(T x);

//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, T unDato);
void asignarDer(Arbol a, T unDato);
void agregarNodo(Arbol a);

//------ Recorrer un arbol (in, pre y post orden) ------
void preorden(Arbol a);
void inorden(Arbol a);
void postorden(Arbol a);
void recorrerArbol(Arbol a);
void calcularProfundidad(Arbol a);

int main(){

    cout<<"Inicializando arbol...\nValor contenido en la raiz: ";
    Arbol arbol = crearArbol(solicitarDato());
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\nMenu: \n";
        cout << "\t1) Agregar\n";
        cout << "\t2) Recorrer\n";
        cout << "\t3) Calcular profundidad\n";
        cout << "\t4) Salir\n";
        cout << "\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: agregarNodo(arbol); break;
            case 2: recorrerArbol(arbol); break;
            case 3: calcularProfundidad(arbol); cout << "Prof: "<< aux - 1 << endl; break;
            case 4: continuar = false; break;
            default: cout << "Opcion erronea!" << endl; break;
        }
    }while(continuar);
    
    return 0;
}

// Implementacion de funciones de arboles
Arbol crearArbol(T x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, T unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, T unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a){
    //solicitar informacion (dato a agregar)
    cout << "Dato a agregar: ";
    T unDato = solicitarDato();
    
    Arbol p = a;
    
    //desplazarse hasta el lugar adecuado
    while(true){
        if(comparar(unDato, igualque, p->info)){
            cout << "Error: dato ya existe!" << endl;
            return;
        }
        else if(comparar(unDato, menorque, p->info)){//ir a la izquierda
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{//ir a la derecha
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }
    
    //agregar el nuevo nodo
    if(comparar(unDato, menorque, p->info))
        asignarIzq(p, unDato);
    else
        asignarDer(p, unDato);
}

//------ Recorrer un arbol (in, pre y post orden) ------
void preorden(Arbol a){
    if(a != NULL){
        cout << " "; mostrarDato(a->info);
        preorden(a->izq);
        preorden(a->der);
    }
}
void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " "; mostrarDato(a->info);
        inorden(a->der);
    }
}
void postorden(Arbol a){
    if(a != NULL){
        postorden(a->izq);
        postorden(a->der);
        cout << " "; mostrarDato(a->info);
    }
}

void recorrerArbol(Arbol a){
    cout << "Recorrido PRE orden:"; preorden(a); cout << endl;
    cout << "Recorrido IN orden:"; inorden(a); cout << endl;
    cout << "Recorrido POST orden:"; postorden(a); cout << endl;
}

void calcularProfundidad(Arbol a){
     if(a!=NULL){
        profundidad++;
        calcularProfundidad(a->izq);
        calcularProfundidad(a->der);
        if(aux < profundidad){
                aux = profundidad;
        }
        profundidad--;
    }

}