// main_matrices.cpp
// Programa que utiliza multiplicarMatrice.h para multiplicar matrices 3x3

#include <iostream>
#include "multiplicarMatrice.h"

int main()
{
    Matriz m1(3), m2(3), m3(3);

    m1.segmentar();
    m2.segmentar();
    m3.segmentar();

    std::cout << "Ingreso datos matriz 1:" << std::endl;
    m1.ingresar();
    std::cout << "Ingreso datos matriz 2:" << std::endl;
    m2.ingresar();

    m3.encerar();
    m3.multiplicar(&m1, &m2, &m3);

    std::cout << "Resultado multiplicacion:" << std::endl;
    m3.imprimir();

    return 0;
}