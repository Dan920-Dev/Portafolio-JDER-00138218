/* Reproduzca el ejemplo visto hoy pero con agregue:
Un campo que indique si el art´ıculo es perecedero o no.
Adem´as, agregue las siguientes opciones en el men´u:
Mostrar s´olo aquellos art´ıculos que tienen fecha de vencimiento.
Mostrar s´olo aquellos art´ıculos que pesan m´as de 300 gramos.
Mostrar s´olo aquellos art´ıculos que valen m´as de 50 d´olares.*/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Articulo{
    string nombre;
    int peso;
    float precio;
    int validar;
    string fechaV;
};
vector<Articulo> bodega;


bool compNombre(Articulo a, Articulo b){
    return a.nombre < b.nombre;
}
bool compPeso(Articulo a, Articulo b){
    return a.peso < b.peso;
}
bool compPrecio(Articulo a, Articulo b){
    return a.precio < b.precio;
}

void agregar(), buscar(), eliminar(), mostrar(), ordenar(), mostrarPerecederos(), mostrarM300g(), mostrarM50();

int main(){
    bool continuar = true;
    
    do{
        int opcion = 0;
        cout << "\n1) Agregar articulos a la bodega.\n";
        cout << "2) Buscar articulos.\n";
        cout << "3) Eliminar articulos.\n";
        cout << "4) Mostrar todo lo que contenga la bodega.\n";
        cout << "5) Mostrar Articulos perecederos.\n";
        cout << "6) Mostrar Articulos que pesan mas de 300g.\n";
        cout << "7) Mostrar Articulos que valen mas de $50.\n";
        cout << "8) Ordenar.\n";
        cout << "9) Salir.\n";
        cout << "Opcion: ";
        cin >> opcion; cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: buscar(); break;
            case 3: eliminar(); break;
            case 4: mostrar(); break;
            case 5: mostrarPerecederos(); break;
            case 6: mostrarM300g(); break;
            case 7: mostrarM50(); break;
            case 8: ordenar(); break;
            case 9: continuar = false; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    }while(continuar);

    return 0;
}

void agregar(){
    Articulo unArticulo;
    cout << "Nombre: "; getline(cin, unArticulo.nombre);
    cout << "Peso: "; cin >> unArticulo.peso; cin.ignore();
    cout << "Precio: "; cin >> unArticulo.precio; cin.ignore();

    // se pregunta si el producto es perecedero
    cout << "El producto es perecedero? (1 - si, 0 - no)"; cin >> unArticulo.validar; cin.ignore();
    // si el producto es perecedero, se le  agrega la fecha de vencimiento y se inserta el producto, sino solo se inserta el producto
    if(unArticulo.validar == 1){
        cout << "Digite la fecha de vencimiento del producto "; getline(cin, unArticulo.fechaV);
        bodega.insert(bodega.end(), unArticulo);
    }else{
        bodega.insert(bodega.end(), unArticulo);
    }
    cout << "Articulo ingresado exitosamente!\n";
}
void buscar(){
    string unNombre;
    cout << "Nombre del articulo que buscar: ";
    getline(cin, unNombre);
    
    bool encontrado = false;
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].nombre == unNombre){
            encontrado = true;
            break;
        }
    }
    
    if(encontrado)
        cout << "Articulo si se encuentra en la bodega.\n";
    else
        cout << "Articulo no se encuentra en la bodega.\n";
}
void eliminar(){
    string unNombre;
    cout << "Nombre del articulo que buscar: ";
    getline(cin, unNombre);
    
    for(auto iter = bodega.begin(); iter != bodega.end(); ++iter){
        if(iter->nombre == unNombre){
            iter = bodega.erase(iter);
            cout << "Articulo eliminado exitosamente.\n";
            break;
        }
    }
}
void mostrar(){
    for (int i = 0; i < bodega.size(); i++) {
        cout << bodega[i].nombre << " pesa " << bodega[i].peso;
        cout << " gramos y vale $" << bodega[i].precio << "\n";
    }
}

void mostrarPerecederos(){
    int existencias = 0;
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].validar == 1){
        cout << bodega[i].nombre << " pesa " << bodega[i].peso;
        cout << " gramos y vale $" << bodega[i].precio << "\n";  
        cout << "su fecha de vencimiento es: " << bodega[i].fechaV << "\n";
        existencias++;
        }
        
    } 
    if(existencias == 0){
            cout << "No se encontraron articulos perecederos";
        } 
}

void mostrarM300g(){
    int existencias = 0;
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].peso > 300){
        cout << bodega[i].nombre << " pesa " << bodega[i].peso;
        cout << " gramos y vale $" << bodega[i].precio << "\n";
        } 
        if(bodega[i].validar == 1){
        cout << "su fecha de vencimiento es: " << bodega[i].fechaV << "\n";
        } 
        existencias++;
    } 

    if(existencias == 0){
            cout << "No se encontraron articulos perecederos";
        } 
}

void mostrarM50(){
    int existencias = 0;
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].precio > 509){
        cout << bodega[i].nombre << " pesa " << bodega[i].peso;
        cout << " gramos y vale $" << bodega[i].precio << "\n";
        } 
        if(bodega[i].validar == 1){
        cout << "su fecha de vencimiento es: " << bodega[i].fechaV << "\n";
        } 
        existencias++;
    } 

    if(existencias == 0){
            cout << "No se encontraron articulos perecederos";
        } 
}

void ordenar(){
    int opcion = 0;
    cout << "Criterio de ordenamiento:\n";
    cout << "1) Alfabetico\n";
    cout << "2) Peso\n3)Precio\n";
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    
    if(opcion == 1)
        sort(bodega.begin(), bodega.end(), compNombre);
    else if(opcion == 2)
        sort(bodega.begin(), bodega.end(), compPeso);
    else if(opcion == 3)
        sort(bodega.begin(), bodega.end(), compPrecio);
        
    cout << "Bodega ordenada exitosamente\n";
}

