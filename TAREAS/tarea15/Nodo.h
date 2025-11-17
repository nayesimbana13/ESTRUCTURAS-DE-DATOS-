#ifndef NODO_H
#define NODO_H

class Nodo {
private:
    int dato;
    Nodo* siguiente;
    Nodo* anterior;

public:
    Nodo(int valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
    
    friend class Pila;  // Para que Pila pueda acceder a los miembros privados
};

#endif // NODO_H