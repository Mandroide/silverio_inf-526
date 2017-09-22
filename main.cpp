/* 
 * File:   main.cpp
 * Author: aybar
 *
 * Created on September 14, 2017, 4:59 PM
 */
#include <iostream>
#include <map>  // Para coleccionar menu.
#include <fstream> // Para archivo punto.txt.
#include <string>
#include <cctype> // toupper();
#include <limits> // Valida entrada por teclado.
#include "Punto.h"
//-------------------------
using std::cout;
using std::cin;
using std::endl;
using std::toupper;
using std::string;
// Valida entrada por teclado.
using std::streamsize;
//-------------------------

enum class Menu {
    AGREGAR = 1, ELIMINAR, BUSCAR, SALIR = 0
};
// ------------------------
template <class T> void validarNumero(T& arg, string mensaje);
unsigned short mostrarMenu();
bool haSalido();
void agregarPunto(Punto&);
void eliminarPunto(Punto&);
void buscarPunto(Punto&);
//------------------------

int main(int argc, char** argv) {

    // Opciones a comparar con switch case;
    std::map<unsigned short, Menu> opciones;
    opciones[1] = Menu::AGREGAR;
    opciones[2] = Menu::ELIMINAR;
    opciones[3] = Menu::BUSCAR;
    opciones[0] = Menu::SALIR;
    unsigned short opcion;
    // ---------------------------------------

    Punto punto;

    bool haTerminado = false;
    while (!haTerminado) {
        try {
            opcion = mostrarMenu();

            switch (opciones[opcion]) {
                case Menu::AGREGAR:
                    agregarPunto(punto);
                    break;
                case Menu::ELIMINAR:
                    eliminarPunto(punto);
                    break;
                case Menu::BUSCAR:
                    buscarPunto(punto);
                    break;
                default:
                    haTerminado = haSalido();
            }
        } catch (string e) {
            cout << e;
        }

        cout << "\n\n";
        cout << "Presione ENTER para continuar...";
        cin.ignore();
        cin.get();
        cout << "\n\n";
    }

    return 0;
}

template <class T> void validarNumero(T& arg, string mensaje) {
    bool esValida = false;
    while (!esValida) {
        cout << mensaje;
        if (cin >> arg) {
            esValida = true;
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        }
        cout << "\n\n";        
    }

}

unsigned short mostrarMenu() {
    unsigned short opcion;
    const unsigned short SALIR = 0;
    const unsigned short ULTIMA = 4;
    bool esValida = false;
    string menu = "\t\tElija la opcion que desea dentro del plano: \n";
    menu.append("1. Agregar un punto.\n");
    menu.append("2. Eliminar un punto.\n");
    menu.append("3. Buscar un punto.\n");
    menu.append("0. Salir.\n\n");
    
    while (!esValida) {
        validarNumero(opcion, menu);
        esValida = opcion >=SALIR && opcion <= ULTIMA;
    }
         
    return opcion;
}

bool haSalido() {
    char salir;
    bool esValida = false; // Valida entrada por teclado del siguiente mensaje.
    while (!esValida) {
        cout << "Desea salir del programa?[S/N]: ";
        cin >> salir;

        salir = toupper(salir); // Convierte a mayuscula la opcion.
        esValida = salir == 'S' || salir == 'N'; // Condicion de entrada por teclado.
    }

    return (salir == 'S');

}

void agregarPunto(Punto& punto) {
    int x, y;
    string mensajeX = "Ingrese valor de eje x: ";
    validarNumero(x, mensajeX);

    string mensajeY =  "Ingrese valor de eje y: ";
    validarNumero(y, mensajeY);

    if (punto.alta(x, y)) {
        cout << "El punto P(" << x << ", " << y << ") ha sido agregado correctamente." << endl;
    } else {
        throw "El punto P (" + std::to_string(x) + ", " + std::to_string(y) + ")"
                "no fue agregado correctamente. Intente de nuevo. ";
    }

}

void eliminarPunto(Punto& punto) {
    int pos;
    string mensaje = "Ingrese la posicion del elemento que desea eliminar: ";
    validarNumero(pos, mensaje);

    int x = punto.buscar(pos).getAbscisa();
    int y = punto.buscar(pos).getOrdenada();

    punto.baja(pos);
    cout << "El punto P(" << x << ", " << y << ") del vector ha sido eliminado";

}

void buscarPunto(Punto& punto) {
    unsigned i;
    string mensaje = "Ingrese indice de elemento a buscar [0-n]: ";
    validarNumero(i, mensaje);

    const Punto p = punto.buscar(i);

    string x = std::to_string(p.getAbscisa());
    string y = std::to_string(p.getOrdenada());
    cout << "El punto #" << i << "  del vector corresponde al punto P(" + x + ", " + y + ")\n";

}
