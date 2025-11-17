#ifndef VISTAMATRIZ_H
#define VISTAMATRIZ_H

#include <iostream>
#include "Matriz.h"

template <typename T>
class VistaMatriz {
public:
    void mostrarMensaje(const std::string& msg) const;
    void mostrarMatriz(const Matriz<T>& m) const;
};

#include "VistaMatriz.tpp"

#endif
