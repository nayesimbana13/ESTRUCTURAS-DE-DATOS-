#ifndef COLA_H
#define COLA_H

#include "Nodo.h"
#include <iostream>
#include <stdexcept>

class Cola {
private:
    Nodo* cabeza; // primer elemento
    Nodo* cola;   // último elemento
    size_t tamano;

    // Desactivar copia por simplicidad (puedes implementar si lo deseas)
    Cola(const Cola&) = delete;
    Cola& operator=(const Cola&) = delete;

public:
    Cola() : cabeza(nullptr), cola(nullptr), tamano(0) {}

    ~Cola() {
        while (cabeza) {
            eliminarPorCabeza();
        }
    }

    // Insertar por cabeza (nuevo elemento se convierte en primer elemento)
    void insertarPorCabeza(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (!cabeza) {
            cabeza = cola = nuevo;
        } else {
            nuevo->siguiente = cabeza;
            cabeza->anterior = nuevo;
            cabeza = nuevo;
        }
        ++tamano;
    }

    // Insertar por cola (enqueue clásico)
    void insertarPorCola(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (!cola) {
            cabeza = cola = nuevo;
        } else {
            nuevo->anterior = cola;
            cola->siguiente = nuevo;
            cola = nuevo;
        }
        ++tamano;
    }

    // Eliminar por cabeza (dequeue clásico)
    bool eliminarPorCabeza() {
        if (!cabeza) return false;
        Nodo* tmp = cabeza;
        cabeza = cabeza->siguiente;
        if (cabeza) cabeza->anterior = nullptr;
        else cola = nullptr; // quedó vacía
        delete tmp;
        --tamano;
        return true;
    }

    // Eliminar por cola (quitar último)
    bool eliminarPorCola() {
        if (!cola) return false;
        Nodo* tmp = cola;
        cola = cola->anterior;
        if (cola) cola->siguiente = nullptr;
        else cabeza = nullptr; // quedó vacía
        delete tmp;
        --tamano;
        return true;
    }

    // Eliminar la primera ocurrencia de un valor; devuelve true si se eliminó
    bool eliminarPorValor(int valor) {
        Nodo* actual = cabeza;
        while (actual) {
            if (actual->dato == valor) {
                if (actual->anterior) {
                    actual->anterior->siguiente = actual->siguiente;
                } else {
                    // es cabeza
                    cabeza = actual->siguiente;
                }
                if (actual->siguiente) {
                    actual->siguiente->anterior = actual->anterior;
                } else {
                    // es cola
                    cola = actual->anterior;
                }
                delete actual;
                --tamano;
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    // Buscar un valor; devuelve índice (0 = cabeza) o -1 si no encontrado
    int buscar(int valor) const {
        Nodo* actual = cabeza;
        int idx = 0;
        while (actual) {
            if (actual->dato == valor) return idx;
            actual = actual->siguiente;
            ++idx;
        }
        return -1;
    }

    // Imprimir de cabeza a cola
    void imprimir(std::ostream& os = std::cout) const {
        os << "[ ";
        Nodo* actual = cabeza;
        while (actual) {
            os << actual->dato;
            if (actual->siguiente) os << " <- ";
            actual = actual->siguiente;
        }
        os << " ]\n";
    }

    // Imprimir de cola a cabeza
    void imprimirReversa(std::ostream& os = std::cout) const {
        os << "[ ";
        Nodo* actual = cola;
        while (actual) {
            os << actual->dato;
            if (actual->anterior) os << " -> ";
            actual = actual->anterior;
        }
        os << " ]\n";
    }

    bool estaVacia() const { return cabeza == nullptr; }
    size_t size() const { return tamano; }
};

#endif // COLA_H
