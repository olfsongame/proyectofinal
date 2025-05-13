// Proyectofinal.cpp Aron Carballido Paz 13/05/2025

#include <iostream>
#include <string>
#include <locale>
#include <locale.h>
using namespace std;

//Sistema tienda
// Mostrar dinero del jugador
void mostrarDinero(int dinero ) 
{
   
    cout << " Dinero: $" << dinero << endl;
    cout << "======================" << endl << endl;
}

void mostrarVida(int vida) //funcion para mostar vida del jugador en pantalla
{
    cout << "======================" << endl;
    cout << " vida: " << vida << "hp" << endl;
}

void escenaDialogo(int dinero, int vida) {
    system("cls"); 
    mostrarVida(vida); //mostramos la vida del jugador mientras progresa
    mostrarDinero(dinero); //mostramos el dinero del jugador 
    cout << "Has encontrado una tienda en medio de la ciudad " << endl;
    cout << "1. Entar" << endl;
    cout << "2. Investigar alrededores" << endl;

    int opcion;
    cin >> opcion;
    // Lo que el jugador elija...
    if (opcion == 1) {
        system("cls");
        cout << "entras a la tienda " << endl;
    }
    else 
    {
        cout << "investigas los alrededores" << endl;
    }
}

void escenaTienda(int& dinero) {
    system("cls");
    mostrarDinero(dinero);
    cout << "Has entrado a una tienda." << endl;
    cout << "1. Comprar poción de vida (30$)" << endl;
    cout << "2. Salir" << endl;

    int opcion;
    cin >> opcion;

    if (opcion == 1 && dinero >= 30) {
        dinero -= 30;
        cout << "Compraste la poción de vida." << endl;
        
        mostrarDinero(dinero);
       
        cout << "que deseas hacer ahora ? " << endl;
        cout << "1. Salir" << endl;
        cin >> opcion;
        if (opcion == 1)
        {
            system("cls");
         
            cout << "Sales de la tienda y continuas tu aventura..." << endl;
        }
        
    }
    else {
        system("cls");
        cout << "Sales de la tienda y continuas tu aventura..." << endl;
        cout << "Sales de la tienda y continuas tu aventura..." << endl;
    }

    cin.ignore();
    cin.get(); // Espera para que el jugador vea el resultado
}
void recogerDinero(int& dinero, int cantidad)
{
    dinero += cantidad;

    system("cls"); // En Windows usa "cls"
    mostrarDinero(dinero);

    cout << "¡Encontraste $" << cantidad << " en el suelo!" << endl;
    cout << "Tu dinero ha sido actualizado." << endl;

    cin.ignore();
    cin.get(); // Pausa para que el jugador vea el cambio
}











int main() {
    setlocale(LC_ALL, "es_MX.UTF-8");
    int dinero = 100; // cant inicial de dinero
    int vida = 100; // cant inicial de hp
    escenaDialogo(dinero, vida);  // Aquí solo se ve el dinero
    recogerDinero(dinero, 50);
    escenaTienda(dinero);   // Aquí puedes comprar
    
    return 0;
}

