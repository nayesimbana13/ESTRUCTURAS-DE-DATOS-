#include "ListaSimple.h"

// Constructor Nodo con lista inicialización
Nodo::Nodo(int d) : dato(d), siguiente(nullptr) {}

// Constructor ListaSimple vacío
ListaSimple::ListaSimple() : cabeza(nullptr) {}

void ListaSimple::insertarCabeza(int valor) {
    Nodo* nuevo = new Nodo(valor);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

void ListaSimple::insertarCola(int valor) {
    Nodo* nuevo = new Nodo(valor);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

void ListaSimple::eliminarCabeza() {
    if (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void ListaSimple::eliminarCola() {
    if (!cabeza) return;
    if (!cabeza->siguiente) {
        delete cabeza;
        cabeza = nullptr;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente->siguiente) {
            temp = temp->siguiente;
        }
        delete temp->siguiente;
        temp->siguiente = nullptr;
    }
}

void ListaSimple::imprimir() const {
    Nodo* temp = cabeza;
    while (temp) {
        std::cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    std::cout << std::endl;
}

bool ListaSimple::buscar(int valor) const {
    Nodo* temp = cabeza;
    while (temp) {
        if (temp->dato == valor)
            return true;
        temp = temp->siguiente;
    }
    return false;
}

nlohmann::json ListaSimple::aJson() const {
    Nodo* temp = cabeza;
    nlohmann::json j;
    int idx = 0;
    while (temp) {
        j[idx++] = temp->dato;
        temp = temp->siguiente;
    }
    return j;
}