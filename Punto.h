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

class Punto {
private:
    int abscisa;
    int ordenada;
    std::vector<Punto> persist;
public:
    Punto();
    Punto(int x, int y);

    virtual ~Punto() {

    }
    
    Punto buscar(int x);
    bool alta(int x, int y);
    bool baja(int pos);

};

#endif /* PUNTO_H */

