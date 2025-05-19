// Proyectofinal.cpp - Aron Carballido Paz - 13/05/2025

#include <iostream>
#include <string>
#include <locale>
#include <locale.h>
#include <vector>
using namespace std;


// CLASES


//clase item
class Item {
private:
    string nombre;
    string tipoDeArma;
    string informacionArma;
    int danio;

public:
    Item(string _nombre, string _tipoDeArma, int _danio_, string _informacionArma) //parametros 
    {
        nombre = _nombre;
        tipoDeArma = _tipoDeArma;
        danio = _danio_;
        informacionArma = _informacionArma;
    }

    string getDescripcion() const //constructor para tenr una descripcion de nuestro objeto
    {
        return nombre + " | Tipo : " + tipoDeArma + " | Daño :  " + to_string(danio) + " | Descripción : " + informacionArma;
    }

    string getName() const { //constructor para llamar al sistema y que nos de el nombre de nuestro objeto
        return nombre;
    }
};


// clase inventario
class Inventario {
private:
    int espacio;
    vector<Item> objetos; //vector para almacenar items

public:
    Inventario(int _mochila) {
        espacio = _mochila;
    }

    void agregarItem(const Item& item) {
        if (objetos.size() < espacio) {
            objetos.push_back(item);
            cout << "Item " << item.getName() << " ha sido agregado al inventario!" << endl;
        }
        else {
            cout << "El item " << item.getName() << " no se ha guardado en el inventario (espacio insuficiente)." << endl;
        }
    }

    void mostrarInventario() const {
        cout << "\n-- Inventario --" << endl;
        if (objetos.empty()) {
            cout << "Inventario vacío." << endl;
        }
        for (size_t i = 0; i < objetos.size(); ++i) {
            cout << i + 1 << ". " << objetos[i].getDescripcion() << endl;
        }
        cout << "Espacios usados: " << objetos.size() << "/" << espacio << "\n" << endl;
    }
};


// FUNCIONES


void mostrarDinero(int dinero) {
    cout << " Dinero: $" << dinero << endl;
    cout << "======================" << endl << endl;
}

void mostrarVida(int vida) {
    cout << "======================" << endl;
    cout << " Vida: " << vida << " hp" << endl;
}

void escenaDialogo(int dinero, int vida, Inventario& mochila) {
    system("cls");
    mostrarVida(vida);
    mostrarDinero(dinero);

    cout << "Has encontrado una tienda en medio de la ciudad" << endl;
    cout << "1. Entrar" << endl;
    cout << "2. Investigar alrededores" << endl;
    cout << "3. Ver Inventario" << endl;

    int opcion;
    cin >> opcion;

    if (opcion == 1) {
        system("cls");
        cout << "Entras a la tienda" << endl;
    }
    else if (opcion == 2) {
        cout << "Investigas los alrededores" << endl;
    }
    else if (opcion == 3) {
        system("cls");
        mochila.mostrarInventario();
        cout << "\n Regresar" << endl;
        cin.ignore();
        cin.get();
        escenaDialogo(dinero, vida, mochila);
    }
}

void escenaTienda(int& dinero) {
    system("cls");
    mostrarDinero(dinero);
    cout << "Has entrado a una tienda." << endl;
    cout << "1. Comprar un botiquin (30$)" << endl;
    cout << "2. Salir" << endl;

    int opcion;
    cin >> opcion;

    if (opcion == 1 && dinero >= 30) {
        dinero -= 30;
        cout << "Compraste el botiquin." << endl;
        mostrarDinero(dinero);

        cout << "¿Qué deseas hacer ahora?" << endl;
        cout << "1. Salir" << endl;
        cin >> opcion;
        if (opcion == 1) {
            system("cls");
            cout << "Sales de la tienda y continúas tu aventura..." << endl;
        }
    }
    else {
        system("cls");
        cout << "Sales de la tienda y continúas tu aventura..." << endl;
    }

    cin.ignore();
    cin.get(); // Pausa
}

void recogerDinero(int& dinero, int cantidad) {
    dinero += cantidad;

    system("cls");
    mostrarDinero(dinero);

    cout << "¡Encontraste $" << cantidad << " en el suelo!" << endl;
    cout << "Tu dinero ha sido actualizado." << endl;

    cin.ignore();
    cin.get(); // Pausa
}




// OBJETOS GLOBALES


Inventario mochila(10);


// FUNCIÓN PRINCIPAL


int main() 
{  // codigo reorganizado con chatgpt 15/05/2025
    setlocale(LC_ALL, "es_MX.UTF-8");

    // Crear items
    Item Cuchillo("Cuchillo bowie", "arma cac", 35, "Arma cuerpo a cuerpo con un gran daño de 35 de vida que es muy útil para abrirte paso contra los zombies.");
    Item Curacion("Botiquín", "consumible", 99, "Item de curación capaz de curar hasta 99 de vida, útil en momentos críticos.");
    Item Coleccionable("Escalera de Metal", "herramienta", 1, "Esta útil herramienta te ayudará a subir a lugares que no podías antes, es muy liviana para ser una escalera.");

    //mochila.agregarItem(Cuchillo);
    //mochila.agregarItem(Curacion);
    //mochila.agregarItem(Coleccionable);

    int dinero = 100;
    int vida = 100;

    //escenaDialogo(dinero, vida, mochila);
    //recogerDinero(dinero, 50);
    //escenaTienda(dinero);
    mostrarVida(vida);
    system("cls");
    bool tieneItem = false;
    int descicion1, descicion2, descicion3;

    

        cout << "living in  the zombie apocalypse \n " << endl;
        cout << "------Entrar ?------ \n" << endl;
        cout << "1. si" << endl;
        cout << "2. no" << endl;
        int opcionMenu;
        int opcion;
        cin >> opcionMenu;
        if (opcionMenu == 1)
        {
            system("cls");
            //escena 1
            cout << "-*Esta es la historia de adept un chico que tenia una vida aburrida y horrible hasta que un dia algo cambio todo ese aburrimiento y desgracia por completo-*\n" << endl;
            cout << "- Que dia mas aburrido, me despidieron de mi trabajo la escuela es muy aburrida y mi ex sigue mandandome mensaje de odio por algo que no hice - " << endl;
            cout << "--Continuar-- (presione 1)" << endl;
            cin >> opcion;
            system("cls");
            //escena 2
            cout << "(un silencio inmenso invade la habitacion)" << endl;
            cout << "- Bueno es hora de dejar de holgasanear tengo que ir a la escuela -\n" << endl;
            cout << " Levantarse de la cama? " << endl;
            cout << " 1. si " " 2. no" << endl;
            cin >> opcion;
            if (opcion == 1)
            {
                system("cls");
                mostrarVida(vida);
                mostrarDinero(dinero);
                cout << " *adept se para de la cama y se asoma a la ventana Barras Barras Pensalas* " << endl;
            }
            else  if (opcion == 2)
            {
                system("cls");

                cout << "Nah que son otras dos horas de sueño mas..." << endl;
                cout << "(... No se durmio 2 horas ... -_- ) " << endl;
                cout << " --Continuar-- " << endl;
                cin >> opcion;
                system("cls");
                cout << " - 4 horas despues - " << endl;
                cout << " Oh... PORQUE DEMONIOS NO TENGO LUZ, mejor dicho, PORQUE NO HAY INTERNETTTTTT " << endl;
                cout << " Supongo que deberia salir a ver que pasa igual que es lo peor que podria pasar " << endl;
                cout << " ( todo...) " << endl;
                cout << " --Continuar-- " << endl;
                cin >> opcion;
                system("cls");
                cout << " Deseas Salir de el departamento ? " << endl;
                cout << " 1. si " "2 .no " << endl;
                cin >> opcion;
                if (opcion == 1)
                {
                    system("cls");
                    mostrarVida(vida);
                    mostrarDinero(dinero);
                    cout << " * Sales de tu departamento y vas al pasillo principal y ves todas las entradas bloqueadas * " << endl;
                    cout << " Pero que demonios ?, Porque esta todo cerrado?, supongo que tendre que encontrar otra forma de salir " << endl;
                    cout << " --Continuar-- " << endl;
                    cin >> opcion;
                    system("cls");
                    cout << " Buscar otra salida o derribar la barrera ? " << endl;
                    cout << " 1. Al diablo derribemos la barrera. " " 2. Buscar una manera mas segura de bajar. " << endl;
                    cin >> opcion;
                }
                else if (opcion == 2)
                {
                    system("cls");
                    mostrarVida(vida);
                    mostrarDinero(dinero);
                    cout << "* Decides investigar un poco mas el departamento * " << endl;
                    cout << "* Hacia que parte de el cuarto quieres ir ? * " << endl;
                    cout << " 1. Cocina 2. Cuarto 3. Salir " << endl;
                    cin >> opcion;
                    system("cls");
                    switch (opcion)
                    {
                    case 1:
                        cout << "Te diriges a la cocina. Hay bastantes cajones ( investigarlos? )." << endl;
                        break;
                    case 2:
                        cout << "Entras al cuarto. La cama está desordenada y hay una ventana abierta." << endl;
                        break;
                    case 3:
                        cout << "Decides salir del departamento por ahora." << endl;
                        break;
                    default:
                        cout << "Opción no válida. Intenta de nuevo." << endl;
                        break;
                    }
                    system("cls");
                    mostrarVida(vida);
                    mostrarDinero(dinero);
                    cout << "hmmmmmmmmmmmmmmmmmmmmmmmmmm y como diabluras salgo de aqui si esta todo bloqueado ?" << endl;
                    cout << " Tal vez... " << endl;
                    cout << "* Usar alguna herramienta para abrirte paso ? *" << endl;
                    

                }
            }
        }
        else if (opcionMenu == 2)
        {
            system("cls");
            cout << "Ah seguro que no quieres jugar bueno tu lo pediste aguafiestas >:( \n" << endl;
            cout << "IP. 92.28.211.234 N: 43.7462 W: 12.4893 SS Number: 6979191519182016 IPv6: fe80::5dcd::ef69::fb22::d9888%12 UPNP: Enabled DMZ: 10.112.42.15 MAC: 5A:78:3E:7E:00 ISP: Ucom Universal DNS: 8.8.8.8 ALT DNS: 1.1.1.8.1 DNS SUFFIX: Dlink WAN: 100.23.10.15 GATEWAY: 192.168.0.1 SUBNET MASK: 255.255.0.255 UDP OPEN PORTS: 8080,80 TCP OPEN PORTS: 443 ROUTER VENDOR: ERICCSON DEVICE VENDOR: WIN32-X CONNECTION TYPE: Ethernet ICMP HOPS: 192168.0.1 192168.1.1 100.73.43.4 host-132.12.32.167.ucom.com host-66.120.12.111.ucom.com 36.134.67.189 216.239.78.111 sof02s32-in-f14.1e100.net TOTAL HOPS: 8 ACTIVE SERVICES: [HTTP] 192.168.3.1:80=>92.28.211.234:80 [HTTP] 192.168.3.1:443=>92.28.211.234:443 [UDP] 192.168.0.1:788=>192.168.1:6557 [TCP] 192.168.1.1:67891=>92.28.211.234:345 [TCP] 192.168.52.43:7777=>192.168.1.1:7778 [TCP] 192.168.78.12:898=>192.168.89.9:667 EXTERNAL MAC: 6U:78:89:ER:O4 MODEM JUMPS: 64" << endl;
            cout << "recomendaria que te volvieras a meter al juego bastardo " << endl;
        }
    
    return 0;
}
