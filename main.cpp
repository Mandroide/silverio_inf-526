/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: aybar
 *
 * Created on September 14, 2017, 4:59 PM
 */

#include <iostream>
#include <map>
#include <fstream> // Para archivo
#include "Punto.h"
//-------------------------
using std::cout;
using std::cin;
using std::endl;
//-------------------------

enum class Menu {
    AGREGAR = 1, ELIMINAR, BUSCAR
};
// ------------------------
void agregarPunto(Punto&);
void eliminarPunto(Punto&);
void buscarPunto(Punto&);
void guardarPunto();
//------------------------

int main(int argc, char** argv) {
    
    std::map<unsigned short, Menu> mapeo;
    mapeo[1] = Menu::AGREGAR;
    mapeo[2] = Menu::ELIMINAR;
    mapeo[3] = Menu::BUSCAR;

    unsigned short opcion;
    bool esValida = false;
    while (!esValida) {
        cout << "\t\tElija la opcion que desea dentro del plano: \n";
        cout << "1. Agregar un punto.\n";
        cout << "2. Eliminar un punto.\n";
        cout << "3. Buscar un punto.\n\n";
        cin >> opcion;
        
        esValida = opcion >= 1 && opcion <=3;
    }

    cout << "\n\n";
    Punto punto();

    switch (mapeo[opcion]) {
        case Menu::AGREGAR:
            //agregarPunto(punto);
            break;
        case Menu::ELIMINAR:
            //eliminarPunto(punto);
            break;
        case Menu::BUSCAR:
            //buscarPunto(punto);
            break;
    }
    
    cout << "\n\n";
    cout << "Presione ENTER para cerrar el programa...";
    cin.ignore();
    cin.get();

    return 0;
}

void agregarPunto(Punto& punto) {
    int x, y;
    cout << "Ingrese valor de eje x: ";
    cin >> x;

    cout << "Ingrese valor de eje y: ";
    cin >> y;

    if (punto.alta(x, y)){
        cout << "El punto P(" << x << ", " << y << ") ha sido agregado correctamente." << endl;
    } else{
        throw "El punto P (" + std::to_string(x) + ", " + std::to_string(y) + ")"
                "no fue agregado correctamente. Intente de nuevo. ";
    }

}

void eliminarPunto(Punto& punto) {
    int pos;
    cout << "Ingrese la posicion del elemento que desea eliminar: ";
    cin >> pos;
    
    if (punto.baja(pos)){
        cout << "El punto de la posicion " << pos << " del vector ha sido eliminado";
    } else {
        throw "El punto no ha sido eliminado correctamente. Intente otra vez";
    }

}

void buscarPunto(Punto& punto) {
    int i;
    cout << "Ingrese indice de elemento a buscar: ";
    cin >> i;

}

void guardarPunto() {

}