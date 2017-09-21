/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
#include <thread>
using std::fstream;
using std::string;
using std::thread;
Punto::Punto() {
    abscisa = 0;
    ordenada = 0;
    persist = std::vector<Punto>();
    try {
        thread t(&Punto::leer, this);
        t.join();
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
    thread t(&Punto::grabar, this);
    t.join();
    return true;

}

bool Punto::baja(const unsigned pos) {
    persist.erase(persist.begin() + pos);
    thread t(&Punto::grabar, this);
    t.join();
    return true;

}

void Punto::leer() {
    fstream archivo;
    archivo.open("punto.txt", std::ios::in);
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
    archivo.open("punto.txt", std::ios::out);

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