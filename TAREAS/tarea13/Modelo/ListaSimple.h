#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <iostream>
#include <nlohmann/json.hpp>

class Nodo {
public:
    int dato;
    Nodo* siguiente;
    Nodo(int d);
};

class ListaSimple {
private:
    Nodo* cabeza;
public:
    ListaSimple();
    void insertarCabeza(int valor);
    void insertarCola(int valor);
    void eliminarCabeza();
    void eliminarCola();
    void imprimir() const;
    bool buscar(int valor) const;
    nlohmann::json aJson() const;
};

#endif
