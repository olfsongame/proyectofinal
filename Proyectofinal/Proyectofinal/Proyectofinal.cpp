// Proyectofinal.cpp - Aron Carballido Paz - 13/05/2025
//Nomenclaturas: Clases: Pascalcase ejemplo class Inventario, class ItemMetodos: camelCase ejemplo : agregarItem(), usarItem().Atributos : camelCase ejemplo : nombre, tipo, curación.Parametros : _camelCase ejemplo : _nombre, _tipo, _curacion.Listas / Colecciones : camelCase en Plural ejemplo : objetos:

#include <iostream>
#include <string>
#include <locale>
#include <locale.h>
#include <vector>
using namespace std;


// CLASES
class Enemigo {
private:
    string tipo;     // "zombie" o "ladron"
    int vida;
    int danio;

public:
    // Constructor de enemigos 
    Enemigo(const string& _tipo, int _vida, int _danio) {
        this->tipo = _tipo; // con el this nos referimos a la funcion o parametro que se esta utilizando dentro de esta clase en especifico 
        this->vida = _vida;
        this->danio = _danio;
    }

    // Aqui tenemos los getters para buscar la informacion de nuestros enemigos
    string getTipo() const { return tipo; }
    int getVida() const { return vida; }
    int getDanio() const { return danio; }

    // Recibir daño
    void recibirDanio(int cantidad) {
        vida -= cantidad;
        if (vida < 0) vida = 0;
    }

    // Confirmamos si esta muerto el enemigo y mostramos que ya no tiene vida
    bool estaMuerto() const {
        return vida <= 0;
    }

    //  Ataque y regresa el daño infligido
    int atacar() const {
        return danio;
    }

    // Mostramos la informacion del enemigo para el debug
    void mostrarInfo() const {
        cout << "Tipo: " << tipo << ", Vida: " << vida << ", Daño: " << danio << endl;
    }
};

//clase Jugador
class Jugador {
private:
    int vida;
    int danioCuerpo;
    int danioDistancia;
    int balas;

public:
    Jugador(int _vida, int _danioCuerpo, int _danioDistancia, int _balas)
        : vida(_vida), danioCuerpo(_danioCuerpo), danioDistancia(_danioDistancia), balas(_balas) {
    }

    int getVida() const { return vida; }
    int getBalas() const { return balas; }

    void recibirDanio(int cantidad) {
        vida -= cantidad;
        if (vida < 0) vida = 0;
    }

    void atacarCuerpo(Enemigo& enemigo) {
        cout << "Atacas cuerpo a cuerpo al " << enemigo.getTipo() << " causando " << danioCuerpo << " de daño." << endl;
        enemigo.recibirDanio(danioCuerpo);
    }

    void atacarDistancia(Enemigo& enemigo) {
        if (balas > 0) {
            cout << "Disparas al " << enemigo.getTipo() << " causando " << danioDistancia << " de daño." << endl;
            enemigo.recibirDanio(danioDistancia);
            balas--;
        }
        else {
            cout << "¡No tienes balas!" << endl;
        }
    }

    void contraatacar(Enemigo& enemigo) {
        if (balas > 0) {
            cout << "¡Contraatacas rápidamente al " << enemigo.getTipo() << " con un disparo!" << endl;
            enemigo.recibirDanio(danioDistancia);
            balas--;
        }
        else {
            cout << "Intentas contraatacar... ¡pero no tienes balas!" << endl;
        }
    }

    bool estaMuerto() const {
        return vida <= 0;
    }

    void mostrarEstado() const {
        cout << "Jugador - Vida: " << vida << ", Balas: " << balas << endl;
    }
    
};

//clase enemigo




//clase item
class Item {
private:
    string nombre;
    string tipoDeArma;
    string informacionArma;
    int danio;
    int curacion;

public:
    Item(string _nombre, string _tipoDeArma,int _curacion, int _danio_, string _informacionArma) //parametros 
    {
        nombre = _nombre;
        tipoDeArma = _tipoDeArma;
        danio = _danio_;
        informacionArma = _informacionArma;
        curacion = _curacion;
    }

    string getDescripcion() const //constructor para tenr una descripcion de nuestro objeto
    {
        return nombre + " | Tipo : " + tipoDeArma + " | Daño :  " + to_string(danio) + " | Curacion: " + to_string(curacion) + "| Descripción : " + informacionArma;
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

    void agregarItem(const Item& item) { //funcion para agregar items en el inventario
        if (objetos.size() < espacio) {
            objetos.push_back(item);
            cout << "Item " << item.getName() << " ha sido agregado al inventario!" << endl;
        }
        else {
            cout << "El item " << item.getName() << " no se ha guardado en el inventario (espacio insuficiente)." << endl;
        }
    }
    bool eliminarItemPorIndice(int indice) //booleano que nos permite eliminar un objeto de acuerdo a su posicion dentro de nuestro indice o vector
    {
        if (indice >= 0 && indice < objetos.size())
        {
            cout << "Vendiste: " << objetos[indice].getName() << endl;
            objetos.erase(objetos.begin() + indice);
            return true;
        }
        else {
            cout << "Índice inválido." << endl;
            return false;
        }
    }

    void mostrarInventario() const {
        cout << "\n-- Inventario --" << endl;
        if (objetos.empty()) {
            cout << "Inventario vacío." << endl;
        }
        for (size_t i = 0; i < objetos.size(); ++i) //lista de almacenamiento para objetos de 10 espacios
        { 
            cout << i + 1 << ". " << objetos[i].getDescripcion() << endl;
        }
        cout << "Espacios usados: " << objetos.size() << "/" << espacio << "\n" << endl;
    }
};






// FUNCIONES


void mostrarDinero(int dinero) { //funcion para mostrar dinero en pantalla
    cout << " Dinero: $" << dinero << endl;
    cout << "======================" << endl << endl;
}

void mostrarVida(int vida) { //funcion para mostar vida en pantalla
    cout << "======================" << endl;
    cout << " Vida: " << vida << " hp" << endl;
}
void restarVida(int& vida, int cantidad) //funcion que nos resta vida al recibir daño
{
    vida -= cantidad;

    system("cls");
    mostrarVida(vida);

    cout << "perdiste " << cantidad << " de hp" << endl;
    cin.ignore();
    cin.get();

}
void curarVida(int& vida, int cantidad)
{
    vida += cantidad;

    system("cls");
    mostrarVida(vida);

    cout << "recuperaste" << cantidad << " de hp " << endl;
    cin.ignore();
    cin.get();
}


void venderObjeto(int& dinero, int vida, Inventario& mochila) {
    system("cls");
    mostrarVida(vida);
    mostrarDinero(dinero);

    cout << "-- Vender Objetos --" << endl;
    mochila.mostrarInventario();

    cout << "Selecciona el número del objeto que deseas vender (0 para cancelar): ";
    int eleccion;
    cin >> eleccion;

    if (eleccion == 0) return;

    // Este indice sirve que tak como esten acomodados los items en nuestra mochila y la cantidad que tenemos al momento de elegir esa posicion se vendera el item ya sea que querramos o no
    int indice = eleccion - 1;

    // Supongamos que todos los objetos se venden por 25$
    int precioVenta = 25;

    if (mochila.eliminarItemPorIndice(indice)) {
        dinero += precioVenta;
        cout << "Has recibido $" << precioVenta << " por la venta." << endl;
    }

    cin.ignore();
    cin.get();
}


void escenaDialogo(int dinero, int vida, Inventario& mochila) { //primera version sistema tienda
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

void escenaTienda(int& dinero, int vida, Inventario& mochila, Item Curacion, Item Vendaje, Item Gasolina) { //version final
    bool enTienda = true;
    while (enTienda) {
        system("cls");
        mostrarDinero(dinero);
        cout << "Has entrado a una tienda." << endl;
        cout << "1. Comprar un botiquín (30$)" << endl;
        cout << "2. Comprar un vendaje (15$)" << endl;
        cout << "3. Comprar Gasolina (40$)" << endl;
        cout << "4. Vender objetos" << endl;
        cout << "5. Salir" << endl;

        int opcion;
        cin >> opcion;

        switch (opcion) {
        case 1:
            if (dinero >= 30) {
                dinero -= 30;
                cout << "Compraste el botiquín." << endl;
                mochila.agregarItem(Curacion);
               
            }
            else {
                cout << "No tienes suficiente dinero." << endl;
            }
            break;
        case 2:
            if (dinero >= 15) {
                dinero -= 15;
                cout << "Compraste un vendaje." << endl;
                mochila.agregarItem(Vendaje);
            }
            else {
                cout << "No tienes suficiente dinero." << endl;
            }
            break;
        case 3:
            if (dinero >= 40) {
                dinero -= 40;
                cout << "Compraste un galon de gasolina." << endl;
                mochila.agregarItem(Gasolina);
            }
            else {
                cout << "No tienes suficiente dinero." << endl;
            }
            break;
        case 4:
            venderObjeto(dinero, vida, mochila); //mostramos nuestro dinero vida y mochila en todo momento 
            break;
        case 5:
            enTienda = false;
            break;
        default:
            cout << "Opción inválida." << endl;
        }

        cin.ignore();
        cin.get();
    }
} // me base en el video de Hard Math y use ia para aprender que hace cada variable y funcion dentro de este https://www.youtube.com/watch?v=9S3jWltuNUY link del video sacdo el 3-06-2025


void recogerDinero(int& dinero, int cantidad) {
    dinero += cantidad; // agregamos la cantidad de dinero recogida a nuestro dinero inicial

    system("cls");
    mostrarDinero(dinero);

    cout << "¡Encontraste $" << cantidad <<  endl;
    cout << "Tu dinero ha sido actualizado." << endl;

    cin.ignore();
    cin.get(); // Pausa
}

//Sistema de combateeeeee
void combateEpico(Jugador& jugador, Enemigo& enemigo) //funcion para el sistema de comabte
{
    while (!jugador.estaMuerto() && !enemigo.estaMuerto()) 
    {
        jugador.mostrarEstado();
        enemigo.mostrarInfo();

        cout << "\nElige acción:\n1. Atacar cuerpo a cuerpo\n2. Atacar a distancia\n3. Curarse\n> ";
        int opcion;
        cin >> opcion;

        if (opcion == 1) 
        {
            jugador.atacarCuerpo(enemigo);
        }
        else if (opcion == 2) 
        {
            jugador.atacarDistancia(enemigo);
        }
        else if (opcion == 3) 
        {

        }
        else {
            cout << "Opción inválida." << endl;
            continue;
        }

        if (!enemigo.estaMuerto()) {
            int danoEnemigo = enemigo.atacar();
            cout << enemigo.getTipo() << " te ataca causando " << danoEnemigo << " de daño." << endl;
            jugador.recibirDanio(danoEnemigo);

            cout << "¿Intentar contraatacar? (s/n): ";
            char contra;
            cin >> contra;

            if (contra == 's' || contra == 'S') {
                jugador.contraatacar(enemigo);
            }
        }

        cout << "\n----------------------\n";
    }

    if (jugador.estaMuerto()) { 
        cout << "¡Has muerto!" << endl;
      
    }
    else {
        cout << "¡Has vencido al " << enemigo.getTipo() << "!" << endl; // el enemigo vencido aparece en pantalla
    }
}




// OBJETOS GLOBALES


Inventario mochila(10);

Item Curacion("Botiquín", "consumible", 1, 99, "Item de curación capaz de curar hasta 99 de vida, útil en momentos críticos.");
Item Coleccionable("Escalera de Metal", "herramienta", 1, 0, "Esta útil herramienta te ayudará a subir a lugares que no podías antes, es muy liviana para ser una escalera.");
Item llaveBodega("Llave bodega", "herramienta", 1, 0, "Esta util llave te permitira abrir la bodega y descubrir los tesoros que hay en ella ");
Item ManoplaDeBoxeo("Manopla de Boxeo", "arma cac", 35, 0, "Arma cuerpo a cuerpo con un gran daño decente de 35 puntos de vida con un brillo dorado muy bonito.");
Item Crowbar("Crowbar o palanca", "arma cac y herramienta", 45, 0, "Herramienta util capaz de levantar grandes cantidades de peso y muy util para romper cabezas.");
Item RevolverVacia("Revolver", "arma a distancia", 100, 0, "Arma a distancia muy util para matar enemigos ya que con su increible potencia de tiro solo se necesita un disparo para matarlos aunque este arma solo tiene 3 balas de momento.");
Item CocaCola("Una coquita asi bien fria", "Legendario", 1, 99, "Una coquita asi bien fria con su hielito ira nomas que delicia.");
Item Gasolina("Galon de Gasolina", "consumible", 0, 0, "Galon de gasolina que te podria ser util en el futuro?");
Item Vendaje("Vendaje", "consumible", 0, 25, "Item curatico que te puede salvar la vida en apuros a diferencia dle botiquin este solo te curara 25 de vida");


// FUNCIÓN PRINCIPAL


int main() 
{  // codigo reorganizado con chatgpt 15/05/2025
    setlocale(LC_ALL, "es_MX.UTF-8");

    // Crear items
   
    Item Curacion("Botiquín", "consumible", 1, 99,  "Item de curación capaz de curar hasta 99 de vida, útil en momentos críticos.");
    Item Coleccionable("Escalera de Metal", "herramienta", 1, 0, "Esta útil herramienta te ayudará a subir a lugares que no podías antes, es muy liviana para ser una escalera.");
    Item llaveBodega ("Llave bodega", "herramienta", 1,0,  "Esta util llave te permitira abrir la bodega y descubrir los tesoros que hay en ella ");
    Item ManoplaDeBoxeo("Manopla de Boxeo", "arma cac", 35,0, "Arma cuerpo a cuerpo con un gran daño decente de 35 puntos de vida con un brillo dorado muy bonito.");
    Item Crowbar("Crowbar o palanca", "arma cac y herramienta", 45,0, "Herramienta util capaz de levantar grandes cantidades de peso y muy util para romper cabezas.");
    Item RevolverVacia("Revolver", "arma a distancia", 50,0, "Arma a distancia muy util para matar enemigos ya que con su increible potencia de tiro solo se necesita un disparo para matarlos aunque este arma solo tiene 3 balas de momento.");
    Item CocaCola("Una coquita asi bien fria", "Legendario", 1,99, "Una coquita asi bien fria con su hielito ira nomas que delicia.");
    Item Gasolina("Galon de Gasolina", "consumible", 0, 0, "Galon de gasolina que te podria ser util en el futuro?");
    Item Vendaje("Vendaje", "consumible", 0, 25, "Item curatico que te puede salvar la vida en apuros a diferencia dle botiquin este solo te curara 25 de vida");
    //mochila.agregarItem(Cuchillo);
    //mochila.agregarItem(Curacion);
    //mochila.agregarItem(Coleccionable);

    int dinero = 100;
    int vida = 100;

    Jugador Adept(100, 35, 50, 3);
    Enemigo zombie("zombie", 70, 20);
    
    //escenaDialogo(dinero, vida, mochila);
    //recogerDinero(dinero, 50);
    //escenaTienda(dinero);
    mostrarVida(vida);
    system("cls");
    
    

    

        cout << "living in  the zombie apocalypse Parte 1. \n " << endl;
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
            cout << "- Que dia mas aburrido, me despidieron de mi trabajo la escuela es muy aburrida y mi ex sigue mandandome mensaje de odio por algo que no hice - \n" << endl;
            
           
            system("pause");
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
                cout << "Continuar" << endl;
                cin >> opcion;
                system("cls");
                cout << "no se siente como demasiado silencio ?" << endl;
                cout << "de la nada ves un camion petrolero que va a una velocidad extrema y muy rapida y, BOOM explota y empieza el caos" << endl;
                cout << "adept se queda viendo la escena sin decir ni una palabra y con una cara de harto hasta que le da el golpe de realidad " << endl;
                cout << "Espera esto en verdad esta pasando que hare no puede ser, ES EL MEJOR DIA DE MI VIDA, porfin algo interesante pasa en esta aburrida ciudad " << endl;
                cout << "continuar... " << endl;
                cin >> opcion;
                cout << "Cierto necesito alistarme y agarra cosas para sobrevivir, veamos..." << endl;
                cout << "Epico montaje no visible de adept agarrando sus cosas con la intro de kick buttowski de fondo*" << endl;
                cout << "continuar..." << endl;
                cin >> opcion;
                
                mochila.agregarItem(ManoplaDeBoxeo);
                mochila.agregarItem(Curacion);
                mochila.agregarItem(RevolverVacia);
                mochila.agregarItem(CocaCola);
                system("cls");
                cin >> opcion;
                cout << "Bien supongo que tengo todo listo para irme, solo le echare un ultimo vistazo a este lugar, Bueno me voy" << endl;
                cout << "sales corriendo y bajas las escaleras" << endl;
                cout << "APARECIO UN ENEMIGO" << endl;
                cout << "PELEA" << endl;
                cin >> opcion;
                system("cls");
                combateEpico(Adept, zombie);
                cin >> opcion;
                system("cls");
                mostrarVida(vida);
                mostrarDinero(dinero);
                cout << "Uff eso estuvo cerca bueno sera mejor que salga de aqui antes de que se junte una gran multitud. " << endl;
                cout << "adept se fue de la zona donde estaba su departamento y empezo a diambular por las calles de la ciudad por un tiempo..." << endl;
                cout << " 1 dia despues... " << endl;
                cout << "continuar " << endl;
                cin >> opcion;
                cout << "maldicion no debi ponerme a jugar con ese terreneitor en la tienda abandonada en verdad llame mucho la atencion " << endl;
                cout << " Y tampoco es como pueda CORRER PARA SIEMPRE " << endl;
                cin >> opcion;
                
                mostrarVida(vida);
                mostrarDinero(dinero);
                cout << "alcanzas a ver una escalera de metal en el piso la recoges? " << endl;
                cout << "1.si AHV\n2.No\n>" << endl;
                cin >> opcion;
                if (opcion == 1)
                {
                    system("cls");
                    mostrarVida(vida);
                    mostrarDinero(dinero);
                    mochila.agregarItem(Coleccionable);
                    cout << "Agarras la escalera de metal, frente a ti se encuentra una casa y estas rodeado subes al techo con la escalera?" << endl;
                    cout << "1.siiii 2.no, soy masoquista" << endl;
                    cin >> opcion;
                    if (opcion == 1)
                    {
                        cout << "usas la escalera de metal retractil y logras salvarte de los zombies" << endl;
                        cout << " Si aprendi algo hoy es a no jugar en situaciones apocalipticas, eso fue horrible, bueno ahora que hago" << endl;
                        cin >> opcion;
                        system("cls");
                        cout << "adept fue saltando de techo en techo hasta que escucho una explosion junto a el " << endl;
                        cout << " (explozion KBOOM) " << endl;
                        cin >> opcion;
                        system("cls");
                        cout << "este dia va de mejor en mejor ahora que DEMO-" << endl;
                        cout << " antes de terminar la frase vemos a una chica hermosa de pelo rubio volteando a ver a adept por su grito con la explosion de fondo y una katana en mano (esto es muy cliche fr)" << endl;
                        cout << "wow y esa " << endl;
                        cin >> opcion;
                        system("cls");
                        cout << "Quien es? " << endl;
                        cout << "continuara " << endl;
                        cin >> opcion;
                        return 0;

                            
                    }
                    else if (opcion == 2)
                    {
                        cout << "PORQUE NO ELEGIRIAS SALVARTE MALDITO LOCO FUERA DE AQUI" << endl;
                        return 0;
                    }
                }
                else if (opcion == 2)
                {
                    system("cls");
                    cout << "al no agarra la escalera te rodearon los zombies y te mataron obvio buena suerte a la proxima" << endl;
                    return 0;
                }
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
                cout << " Decides Investigar el departamento " << endl;
                
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
                    if (opcion == 1)
                    {
                        cout << "No tuviste exito.. " << endl;
                        cout << "intentaste buscar una manera mas segura de bajar pero al no contar con los objetos necesarios los zombies llegaron a ti y moriste :(" << endl;
                        return 0;
                    }
                    else if (opcion == 2)
                    {
                        system("cls");
                        cout << "intentaste buscar una manera mas segura de bajar pero al no contar con los objetos necesarios los zombies llegaron a ti y moriste :(" << endl;
                        return 0;
                    }
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
                   
                      
                        switch (opcion)
                        {
                        case 1:
                            system("cls");
                            cout << "Te diriges a la cocina. Hay bastantes cajones ( investigarlos? )." << endl;
                            cout << "1. si " "2. no " << endl;
                            cin >> opcion;
                            if (opcion == 1)
                            {
                                cout << "( obtuviste la llave de la bodega ! )" << endl;
                                mochila.agregarItem(llaveBodega);
                                cout << "Saliste de la cocina..." << endl;

                            }
                            else
                            {

                                break;
                            }
                        case 2:
                            system("cls");
                            cout << "Entras al cuarto. La cama está desordenada y hay una ventana abierta." << endl;
                            cout << "Checar los cajones que hay en el cuarto ? " << endl;
                            cin >> opcion;
                            if (opcion == 1)
                            {
                                system("cls");
                                cout << "Investigas los cajones y encuentras una manopla de box " << endl;
                                mochila.agregarItem(ManoplaDeBoxeo);
                                recogerDinero(dinero, 100);
                                mostrarDinero(dinero);
                                cout << "sales  de el cuarto..." << endl;
                                cin >> opcion;






                            }
                            else
                            {
                                break;
                            }
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
                    cout << "investigar cobertizo ?..." << endl;
                    cout << "1. si 2. no " << endl;
                    cin >> opcion;
                    if (opcion == 1)
                    {
                        cout << "Entras al cobertizo y encuentras una crowbar " << endl;
                        mochila.agregarItem(Crowbar);
                        cout << "Sales del cobertizo... " << endl;
                        cin >> opcion;
                        system("cls");
                        mostrarDinero(dinero);
                        mostrarVida(vida);
                        cout << "bien creo que podria usar esta palanca para abrirme paso que bueno que convencionalmente estaba a mi alcanze no?" << endl;
                        cout << "- Usas la palanca y mueves las cajas que bloqueaban el camino -" << endl;
                        cout << "sales del edificio y frente a ti un caos en todas las direcciones que mires y lo peor de todo..." << endl;
                        cout << "continuar..." << endl;
                        cin >> opcion;
                        system("cls");
                        mostrarDinero(dinero);
                        mostrarVida(vida);
                        cout << "NOOOOOOOO el sevennnnn me lleva queria comprar un refresco. " << endl;
                        cout << "Espera que ? ESO TE PREOCUPA YO HABLABA DE LOS ZOMBIES " << endl;
                        cout << "ahhh... bueno ok hmhmmm ZOMBIES!!!" << endl;
                        cout << "continuar... " << endl;
                        cin >> opcion;
                        system("cls");
                        mostrarDinero(dinero);
                        mostrarVida(vida);
                        cout << "Frente a ti se encuentra una enorme horda de zombies QUE HACES ???!!!?!" << endl;
                        cout << "1. Correr  2.Llamar a un adulto responsable " << endl;
                        cin >> opcion;
                        if (opcion == 1)
                        {
                            system("cls");
                            mostrarDinero(dinero);
                            mostrarVida(vida);
                            cout << "excelente eleccion vamos a CORRER " << endl;
                            cout << "con toda la orda zombies detras de ti estas muy cansado asi que buscas una alternativa para sobrevivir" << endl;
                            cout << " ves a lo lejos una tienda de juguetes gigante te refugias?  " << endl;
                            if (opcion == 1)
                            {
                                system("cls");
                                mostrarVida(vida);
                                mostrarDinero(dinero);
                                cout << "entras a la tienda de juguetes y esta completamente vacia " << endl;
                                cout << "Adept se queda dormido y decide pasar la noche ahi por el cansancio" << endl;
                                cout << "Al dia siguiente..." << endl;
                                cout << "Demonios me quede dormido creo que sera mejor investigar los alrededoresy buscar comida muero de hambre" << endl;
                                cout << "1. investigar?\n2.Ver Inventario\n> ..." << endl;
                                cin >> opcion;
                                if (opcion == 1)
                                {
                                    system("cls");
                                    cout << "Decides investigar el lugar " << endl;
                                }
                                else if (opcion == 2)
                                {
                                    mochila.mostrarInventario();
                                }
                                mostrarVida(vida);
                                mostrarDinero(dinero);
                                cout << "Avanzas un poco y encuentras distintas ubicaciones " << endl;
                                cout << "Hmmmm a donde deberia ir primero? " << endl;
                                cout << "1.Food court\n2.Jugueteria\n> " << endl;
                                cin >> opcion;
                                switch (opcion)
                                {
                                case 1:
                                    system("cls");
                                    cout << "decides ir por comida ya que tu estomago piensa antes que tu cerebro" << endl;
                                    cout << "que raro no recuerdo ver una tienda por aqui... oh bueno veamos que hay" << endl;
                                    cout << "entrar a la tienda ? 1.si\n2.no\n>" << endl;
                                    if (opcion == 1)
                                    {
                                        escenaTienda(dinero, vida, mochila, Gasolina, Vendaje, Curacion);
                                    }
                                    else
                                    {
                                        cout << "Mejor luego " << endl;
                                        cin >> opcion;
                                    }
                                    break;
                                case 2:
                                    system("cls");
                                    cout << "llegaste a la jugueteria y..." << endl;
                                    cout << "ohhhh que es esto un TERRENEITOR?????\n Siempre quize uno increible" << endl;
                                    cout << "El terreneitor hizo tanto ruido que alerto a todos los zombies de la zona, CUIDADO SE ACERCA UNO" << endl;
                                    cout << "FIGHT" << endl;
                                    combateEpico(Adept, zombie);
                                    cin >> opcion;
                                    system("cls");
                                    cout << "Deberia salir de aqui PERO YA" << endl;
                                    break;

                                default:

                                    cout << "Opción no válida. Intenta de nuevo." << endl;
                                    break;
                                }
                                cout << "maldicion no debi ponerme a jugar con ese terreneitor en la tienda abandonada en verdad llame mucho la atencion " << endl;
                                cout << " Y tampoco es como pueda CORRER PARA SIEMPRE " << endl;
                                cin >> opcion;
                                system("cls");
                                mostrarVida(vida);
                                mostrarDinero(dinero);
                                cout << "alcanzas a ver una escalera de metal en el piso la recoges? " << endl;
                                cout << "1.si AHV\n2.No\n>" << endl;
                                cin >> opcion;
                                if (opcion == 1)
                                {
                                    system("cls");
                                    mostrarVida(vida);
                                    mostrarDinero(dinero);
                                    mochila.agregarItem(Coleccionable);
                                    cout << "Agarras la escalera de metal, frente a ti se encuentra una casa y estas rodeado subes al techo con la escalera?" << endl;
                                    cout << "1.siiii 2.no, soy masoquista" << endl;
                                    if (opcion == 1)
                                    {
                                        cout << "usas la escalera de metal retractil y logras salvarte de los zombies" << endl;
                                        cout << " Si aprendi algo hoy es a no jugar en situaciones apocalipticas, eso fue horrible, bueno ahora que hago" << endl;
                                        
                                        cout << "adept fue saltando de techo en techo hasta que escucho una explosion junto a el " << endl;
                                        cout << " (explozion KBOOM) " << endl;
                                        cout << "este dia va de mejor en mejor ahora que DEMO-" << endl;
                                        cout << " antes de terminar la frase vemos a una chica hermosa de pelo rubio volteando a ver a adept por su grito con la explosion de fondo y una katana en mano (esto es muy cliche fr)" << endl;
                                        cout << "wow y esa " << endl;
                                        cin >> opcion;
                                        system("cls");
                                        cout << "Quien es? " << endl;
                                        cout << "continuara " << endl;
                                        cin >> opcion;
                                        return 0;
                                    }
                                    else if (opcion == 2)
                                    {
                                        cout << "PORQUE NO ELEGIRIAS SALVARTE MALDITO LOCO FUERA DE AQUI" << endl;
                                        return 0;
                                    }
                                }
                                else if (opcion == 2)
                                {
                                    system("cls");
                                    cout << "al no agarra la escalera te rodearon los zombies y te mataron obvio buena suerte a la proxima" << endl;
                                    return 0;
                                }



                            }
                        }
                        else if (opcion == 2)
                        {
                            system("cls");
                            cout << "llamas a un adulto responsable que le mete sus cachetadas a los zombies y hace que desaparezcan todos y salvas al mundo fin." << endl;
                            cout << "continuar ..." << endl;
                            cin >> opcion;
                            system("cls");
                            cout << "Final de mrd final Numero 2";
                            return 0;
                        }
                    }
                    else if (opcion == 2) //opcion del armario
                    {
                        cout << "no confiabas en lo que habia al otro lado del armario y al no encontrar otra forma de salir te quedaste en casa sin suministros y tras unos dias los zombies entraron a tu casa y moriste gg papa" << endl;
                        return 0;
                    }

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
