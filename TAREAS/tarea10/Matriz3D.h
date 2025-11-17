#ifndef MATRIZ3D_H
#define MATRIZ3D_H

#include <iostream>
using namespace std;

template <typename T>
class Matriz3D {
private:
    T*** datos;
    int dimX, dimY, dimZ;
public:
    Matriz3D(int x, int y, int z);
    ~Matriz3D();

    void segmentar();
    void encerar();
    void ingresar();
    void imprimir() const;

    T getDato(int i, int j, int k) const;
    void setDato(int i, int j, int k, T val);

    Matriz3D<T> operator+(const Matriz3D<T>& b) const;
};

#include "Matriz3D.tpp" // Implementación de templates

#endif
