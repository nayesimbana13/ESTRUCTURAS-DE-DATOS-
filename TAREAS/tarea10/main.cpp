#include "Matriz3D.h"

int main()
{
    int dimX = 2, dimY = 2, dimZ = 2; // Prueba con matriz 2x2x2 por simplicidad

    Matriz3D<float> m1(dimX, dimY, dimZ), m2(dimX, dimY, dimZ);

    m1.segmentar();
    m2.segmentar();

    std::cout << "Ingresar datos para Matriz 1:" << std::endl;
    m1.ingresar();

    std::cout << "Ingresar datos para Matriz 2:" << std::endl;
    m2.ingresar();

    m1.encerar(); // Si quieres limpiar antes de usar
    m2.encerar();

    std::cout << "Matriz suma:" << std::endl;

    Matriz3D<float> suma = m1 + m2; // Usa operador sobrecargado

    suma.imprimir();

    return 0;
}