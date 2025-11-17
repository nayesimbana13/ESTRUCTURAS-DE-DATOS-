#ifndef PILA_H
#define PILA_H

#include "Nodo.h"
#include <iostream>

class Pila {
private:
    Nodo* cabeza;
    Nodo* cola;
    int tamano;

public:
    // Constructor
    Pila() : cabeza(nullptr), cola(nullptr), tamano(0) {}

    // Destructor
    ~Pila() {
        while (cabeza != nullptr) {
            eliminarPorCabeza();
        }
    }

    // Insertar por cabeza
    void insertarPorCabeza(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            cabeza = cola = nuevo;
        } else {
            nuevo->siguiente = cabeza;
            cabeza->anterior = nuevo;
            cabeza = nuevo;
        }
        tamano++;
    }

    // Insertar por cola
    void insertarPorCola(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            cabeza = cola = nuevo;
        } else {
            nuevo->anterior = cola;
            cola->siguiente = nuevo;
            cola = nuevo;
        }
        tamano++;
    }

    // Eliminar por cabeza
    bool eliminarPorCabeza() {
        if (estaVacia()) {
            return false;
        }

        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        
        if (cabeza != nullptr) {
            cabeza->anterior = nullptr;
        } else {
            cola = nullptr;  // La pila quedó vacía
        }

        delete temp;
        tamano--;
        return true;
    }

    // Eliminar por cola
    bool eliminarPorCola() {
        if (estaVacia()) {
            return false;
        }

        Nodo* temp = cola;
        cola = cola->anterior;
        
        if (cola != nullptr) {
            cola->siguiente = nullptr;
        } else {
            cabeza = nullptr;  // La pila quedó vacía
        }

        delete temp;
        tamano--;
        return true;
    }

    // Buscar un valor
    bool buscar(int valor) const {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    // Imprimir la pila (de cabeza a cola)
    void imprimir() const {
        if (estaVacia()) {
            std::cout << "La pila está vacía" << std::endl;
            return;
        }

        std::cout << "Pila (Cabeza -> Cola): ";
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato;
            if (actual->siguiente != nullptr) {
                std::cout << " -> ";
            }
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    // Imprimir la pila en reversa (de cola a cabeza)
    void imprimirReversa() const {
        if (estaVacia()) {
            std::cout << "La pila está vacía" << std::endl;
            return;
        }

        std::cout << "Pila (Cola -> Cabeza): ";
        Nodo* actual = cola;
        while (actual != nullptr) {
            std::cout << actual->dato;
            if (actual->anterior != nullptr) {
                std::cout << " -> ";
            }
            actual = actual->anterior;
        }
        std::cout << std::endl;
    }

    // Verificar si la pila está vacía
    bool estaVacia() const {
        return cabeza == nullptr;
    }

    // Obtener el tamaño de la pila
    int obtenerTamano() const {
        return tamano;
    }
};

#endif // PILA_H
