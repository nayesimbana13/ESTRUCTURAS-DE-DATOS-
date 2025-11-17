#ifndef NODO_H
#define NODO_H

class Nodo {
private:
    int dato;
    Nodo* siguiente;
    Nodo* anterior;

public:
    explicit Nodo(int valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}

    // Permitir que la clase Cola acceda a los miembros privados
    friend class Cola;
};

#endif // NODO_H
