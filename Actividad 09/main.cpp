#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Agenda{
    string titulo;
    string hora;
    int Duracion;
};
typedef Agenda agenda;

queue<agenda> cola;

void menu();
void agregar();
void borrar1();
void borrarT();
void mostrar();

int main(){
    
    bool continuar = true;
    int opcion = 0;
    do
    {
        menu();
        cout << "Digite su opcion: "; cin >> opcion; cin.ignore();
        switch (opcion)
        {
        case 1: agregar(); cout <<  endl; break;
        case 2: borrar1(); cout <<  endl; break;
        case 3: borrarT(); cout <<  endl; break;
        case 4: mostrar(); cout <<  endl; break;
        case 5: continuar = false; break;
        default:
            cout << "Opcion erronea" << endl;
            break;
        }
    } while (continuar);
    

    return 0;
}

void menu(){
    cout << "1. Insertar actividad" << endl;
    cout << "2. Borrar una Actividad" << endl;
    cout << "3. Borrar todas las actividades" << endl;
    cout << "4. Ver todas las actividades del dia" << endl;
    cout << "5. Salir del programa" << endl;
}

void agregar(){
    agenda unaActividad;
    cout << "Digite el titulo de la actividad: "; getline(cin, unaActividad.titulo);
    cout << "Digite la hora de la actividad: "; cin >> unaActividad.hora;
    cout << "Digite la duracion de la actividad: "; cin >> unaActividad.Duracion;
    cola.push(unaActividad);
}

void borrar1(){
    cola.pop();
    cout << "Borrado exitosamente" << endl; 
}

void borrarT(){
    agenda unA;
    while (!cola.empty()){
    unA = cola.front();
    cola.pop();
    }
    
    cout << "Todos los datos han sido Borrados exitosamente" << endl; 
}

void mostrar(){
    queue<agenda> cola2;
    cola2 = cola;
   
    if(cola2.empty()){
        cout << "Cola Vacia" << endl;
    }else{
        while (!cola2.empty()){
            agenda unA = cola2.front();
            cout << "Nombre de la actividad: " << unA.titulo << endl;
            cout << "hora de la actividad: " << unA.hora << endl;
            cout << "Duracion de la actividad: " << unA.Duracion << endl;
            cola2.pop();
        }
    }
}
