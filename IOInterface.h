/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IOInterface.h
 * Author: Aybar
 *
 * Created on September 25, 2017, 9:49 PM
 */

#ifndef IOINTERFACE_H
#define IOINTERFACE_H
#include <string>

class IOInterface {
public:

    IOInterface() {
        nombreArchivo_ = "Default.txt";
    }

    IOInterface(std::string nombreArchivo) {
        nombreArchivo_ = nombreArchivo;
    }

    std::string getNombreArchivo() const {
        return nombreArchivo_;
    }

    virtual ~IOInterface() {

    }
    
    virtual void leer() = 0;
    virtual void grabar() = 0;

private:
    std::string nombreArchivo_;

};

#endif /* IOINTERFACE_H */

