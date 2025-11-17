// sobrecargaSumaPunteros.h
// Implementación de una clase template para manejar punteros y sobrecargar el operador +

#pragma once
#include <iostream>
using namespace std;

// Clase plantilla que envuelve un puntero
template <typename T>
class Puntero {
private:
    T* ptr;
public:
    // Constructor
    Puntero(T valor) {
        ptr = new T(valor);
    }

    // Destructor
    ~Puntero() {
        delete ptr;
    }

    // Sobrecarga del operador + para sumar punteros
    Puntero operator+(const Puntero& otro) const {
        return Puntero(*ptr + *(otro.ptr));
    }

    // Función para mostrar el valor
    void mostrar() const {
        cout << "Valor: " << *ptr << endl;
    }
};

