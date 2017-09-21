/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punto.h
 * Author: Aybar
 *
 * Created on September 14, 2017, 1:14 PM
 */

#ifndef PUNTO_H
#define PUNTO_H

#include <vector>
#include <iostream>

class Punto {
private:
    int abscisa;
    int ordenada;
    std::vector<Punto> persist;

    void grabar();
    void leer();

public:
    Punto();
    Punto(const int x, const int y);

    virtual ~Punto() {

    }

    Punto buscar(const unsigned x);
    bool alta(const int x, const int y);
    bool baja(const unsigned pos);

    int getOrdenada() const {
        return ordenada;
    }

    int getAbscisa() const {
        return abscisa;
    }

};

#endif /* PUNTO_H */

