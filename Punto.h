/* 
 * File:   Punto.h
 * Author: Aybar
 *
 * Created on September 14, 2017, 1:14 PM
 */

#ifndef PUNTO_H
#define PUNTO_H
#include "IOInterface.h"
#include <vector>

class Punto : IOInterface {
private:
    int abscisa;
    int ordenada;
    std::vector<Punto> persist;

    void grabar() override;
    void leer() override;

public:
    Punto();
    Punto(const int x, const int y);

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

