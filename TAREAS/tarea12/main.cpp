#include "ListaSimple.h"
#include <iostream>

int main() {
    ListaSimple lista;

    std::cout << "Lista inicial: ";
    lista.imprimir();

    std::cout << "Insertar al frente: 10\n";
    lista.insertarFrente(10);
    lista.imprimir();

    std::cout << "Insertar al final: 20\n";
    lista.insertarFinal(20);
    lista.imprimir();

    std::cout << "Insertar al frente: 5\n";
    lista.insertarFrente(5);
    lista.imprimir();

    std::cout << "Insertar en posición 1 (índice 1): 99\n";
    lista.insertarEn(1, 99); // queda: 5 -> 99 -> 10 -> 20
    lista.imprimir();

    std::cout << "Tamaño de la lista: " << lista.size() << "\n";

    int buscarVal = 10;
    int idx = lista.buscar(buscarVal);
    if (idx >= 0) std::cout << "Valor " << buscarVal << " encontrado en índice " << idx << "\n";
    else std::cout << "Valor " << buscarVal << " no encontrado\n";

    std::cout << "Limpiando lista...\n";
    lista.limpiar();
    lista.imprimir();

    return 0;
}
