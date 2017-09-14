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

Punto::Punto() {
    abscisa = 0;
    ordenada = 0;
    persist = std::vector<Punto>();
}

Punto::Punto(int x, int y) {
    abscisa = x;
    ordenada = y;
    persist = std::vector<Punto>();
}

Punto Punto::buscar(int x) {

}


bool Punto::alta(int x, int y) {

}

bool Punto::baja(int pos) {

}


