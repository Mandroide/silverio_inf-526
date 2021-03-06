/* 
 * File:   Punto.cpp
 * Author: Aybar
 * 
 * Created on September 14, 2017, 1:14 PM
 */
#include "Punto.h"
#include <fstream>
#include <stdexcept> 
#include <string>
using std::fstream;
using std::string;

Punto::Punto() : IOInterface("punto.txt"){
    abscisa = 0;
    ordenada = 0;
    persist = std::vector<Punto>();
    try {
        leer();
    } catch (string) {

    }
}

Punto::Punto(const int x, const int y) {
    abscisa = x;
    ordenada = y;
}

Punto Punto::buscar(const unsigned x) {
    try {
        Punto p = persist.at(x);
        return p;
    } catch (const std::out_of_range&) {
        string mensaje = "El elemento buscado no existe.";
        throw mensaje;
    }

}

bool Punto::alta(const int x, const int y) {
    persist.push_back(Punto(x, y));
    grabar();
    return true;

}

bool Punto::baja(const unsigned pos) {
    persist.erase(persist.begin() + pos);
    grabar();
    return true;

}

void Punto::leer() {
    fstream archivo;
    archivo.open(getNombreArchivo(), std::ios::in);
    char pipe;
    int x;
    int y;
    
    if (!archivo.fail()) {
        persist.clear(); // Limpia elementos del vector.
        while (archivo >> x) {
            archivo >> pipe;
            archivo >> y;
            alta(x, y);
        }
    } else {
        string mensaje = "El archivo no se abrio correctamente";
        throw mensaje;
    }

    archivo.close();

}

// Escribir en el archivo.

void Punto::grabar() {

    fstream archivo;
    archivo.open(getNombreArchivo(), std::ios::out);

    if (!archivo.fail()) {
        for (auto punto : persist) {
            archivo << punto.abscisa << "\t|\t" << punto.ordenada << "\r\n";
        }
    } else {
        string mensaje = "El archivo no se abrio correctamente";
        throw mensaje;
    }

    archivo.close();

}