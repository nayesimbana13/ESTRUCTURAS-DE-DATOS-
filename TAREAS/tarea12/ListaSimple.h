#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include <iostream>
#include <stdexcept>

// Clase Nodo (encapsulada dentro del header)
class Nodo {
public:
    int dato;
    Nodo* siguiente;

    explicit Nodo(int v) : dato(v), siguiente(nullptr) {}
};

// Clase ListaSimple: lista enlazada simple de enteros (POO)
class ListaSimple {
private:
    Nodo* cabeza;
    size_t longitud;

    // Desactiva copia por simplicidad (puedes implementar si lo deseas)
    ListaSimple(const ListaSimple&) = delete;
    ListaSimple& operator=(const ListaSimple&) = delete;

public:
    ListaSimple() : cabeza(nullptr), longitud(0) {}

    ~ListaSimple() {
        limpiar();
    }

    // Insertar al frente
    void insertarFrente(int valor) {
        Nodo* n = new Nodo(valor);
        n->siguiente = cabeza;
        cabeza = n;
        ++longitud;
    }

    // Insertar al final
    void insertarFinal(int valor) {
        Nodo* n = new Nodo(valor);
        if (!cabeza) {
            cabeza = n;
        } else {
            Nodo* p = cabeza;
            while (p->siguiente) p = p->siguiente;
            p->siguiente = n;
        }
        ++longitud;
    }

    // Insertar en posición (0 = frente). Si pos == size(), se inserta al final.
    void insertarEn(size_t pos, int valor) {
        if (pos > longitud) throw std::out_of_range("posición fuera de rango");
        if (pos == 0) {
            insertarFrente(valor);
            return;
        }
        Nodo* p = cabeza;
        for (size_t i = 0; i + 1 < pos; ++i) p = p->siguiente; // avanzar hasta el nodo anterior
        Nodo* n = new Nodo(valor);
        n->siguiente = p->siguiente;
        p->siguiente = n;
        ++longitud;
    }

    // Obtener tamaño
    size_t size() const { return longitud; }

    // Imprimir lista
    void imprimir(std::ostream& os = std::cout) const {
        os << "[ ";
        Nodo* p = cabeza;
        while (p) {
            os << p->dato;
            if (p->siguiente) os << " -> ";
            p = p->siguiente;
        }
        os << " ]\n";
    }

    // Limpiar la lista (liberar memoria)
    void limpiar() {
        Nodo* p = cabeza;
        while (p) {
            Nodo* tmp = p;
            p = p->siguiente;
            delete tmp;
        }
        cabeza = nullptr;
        longitud = 0;
    }

    // Buscar un valor (retorna índice de la primera ocurrencia o -1 si no existe)
    int buscar(int valor) const {
        Nodo* p = cabeza;
        int idx = 0;
        while (p) {
            if (p->dato == valor) return idx;
            p = p->siguiente;
            ++idx;
        }
        return -1;
    }
};

#endif // LISTA_SIMPLE_H
