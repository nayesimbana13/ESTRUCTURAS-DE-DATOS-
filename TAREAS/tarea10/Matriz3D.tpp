#include "Matriz3D.h"
template <typename T>
Matriz3D<T>::Matriz3D(int x, int y, int z) : datos(nullptr), dimX(x), dimY(y), dimZ(z) {}

template <typename T>
Matriz3D<T>::~Matriz3D() {
    if (datos) {
        for (int i = 0; i < dimX; ++i) {
            for (int j = 0; j < dimY; ++j)
                delete[] datos[i][j];
            delete[] datos[i];
        }
        delete[] datos;
    }
}

template <typename T>
void Matriz3D<T>::segmentar() {
    datos = new T**[dimX];
    for (int i = 0; i < dimX; ++i) {
        datos[i] = new T*[dimY];
        for (int j = 0; j < dimY; ++j)
            datos[i][j] = new T[dimZ];
    }
}

template <typename T>
void Matriz3D<T>::encerar() {
    for (int i = 0; i < dimX; ++i)
        for (int j = 0; j < dimY; ++j)
            for (int k = 0; k < dimZ; ++k)
                *(*(*(datos + i) + j) + k) = 0; // aritmética de punteros ¡sin corchetes!
}

template <typename T>
void Matriz3D<T>::ingresar() {
    for (int i = 0; i < dimX; ++i)
        for (int j = 0; j < dimY; ++j)
            for (int k = 0; k < dimZ; ++k) {
                cout << "Dato [" << i << "][" << j << "][" << k << "]: ";
                cin >> *(*(*(datos + i) + j) + k);
            }
}

template <typename T>
void Matriz3D<T>::imprimir() const {
    for (int i = 0; i < dimX; ++i) {
        for (int j = 0; j < dimY; ++j) {
            for (int k = 0; k < dimZ; ++k)
                cout << *(*(*(datos + i) + j) + k) << " ";
            cout << " | ";
        }
        cout << endl;
    }
}

template <typename T>
T Matriz3D<T>::getDato(int i, int j, int k) const {
    return *(*(*(datos + i) + j) + k);
}

template <typename T>
void Matriz3D<T>::setDato(int i, int j, int k, T val) {
    *(*(*(datos + i) + j) + k) = val;
}

template <typename T>
Matriz3D<T> Matriz3D<T>::operator+(const Matriz3D<T>& b) const {
    Matriz3D<T> res(dimX, dimY, dimZ);
    res.segmentar();
    for (int i = 0; i < dimX; ++i)
        for (int j = 0; j < dimY; ++j)
            for (int k = 0; k < dimZ; ++k)
                *(*(*(res.datos + i) + j) + k) = *(*(*(datos + i) + j) + k) + *(*(*(b.datos + i) + j) + k);
    return res;
}
