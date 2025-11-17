#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

template <typename T>
class Matriz {
private:
    T* datos;
    int dimension;
public:
    Matriz(int dim = 3);
    ~Matriz();

    void segmentar();
    void encerar();
    void ingresar();
    void imprimir() const;

    T getDato(int idx) const;
    void setDato(int idx, T val);

    int getDimension() const { return dimension; }

    // Operador sobrecargado para multiplicar matrices
    Matriz<T> operator*(const Matriz<T>& b) const;
};

#include "Matriz.tpp"   // Implementación template

#endif
