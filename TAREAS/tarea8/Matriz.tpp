// Matriz.tpp
#include <iostream>
#include "Matriz.h"
using namespace std;

template <typename T>
Matriz<T>::Matriz(int dim) : datos(nullptr), dimension(dim) {}

template <typename T>
Matriz<T>::~Matriz() {
    delete[] datos;
}

template <typename T>
void Matriz<T>::segmentar() {
    datos = new T[dimension * dimension];
}

template <typename T>
void Matriz<T>::encerar() {
    for (int i = 0; i < dimension * dimension; ++i)
        *(datos + i) = 0;
}

template <typename T>
void Matriz<T>::ingresar() {
    for (int i = 0; i < dimension * dimension; ++i) {
        cout << "Dato [" << i / dimension << "][" << i % dimension << "]: ";
        cin >> *(datos + i);
    }
}

template <typename T>
void Matriz<T>::imprimir() const {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j)
            cout << *(datos + i * dimension + j) << " ";
        cout << endl;
    }
}

template <typename T>
T Matriz<T>::getDato(int idx) const {
    return *(datos + idx);
}

template <typename T>
void Matriz<T>::setDato(int idx, T val) {
    *(datos + idx) = val;
}

template <typename T>
Matriz<T> Matriz<T>::operator*(const Matriz<T>& b) const {
    Matriz<T> res(dimension);
    res.segmentar();
    res.encerar();
    for (int i = 0; i < dimension; ++i)
        for (int j = 0; j < dimension; ++j)
            for (int k = 0; k < dimension; ++k)
                *(res.datos + i * dimension + j) +=
                    (*(datos + i * dimension + k)) * (*(b.datos + k * dimension + j));
    return res;
}
