// main.cpp
// Programa que demuestra el uso de SmartPtr con diferentes tipos de datos

#include <iostream>
#include "sobrecargaSumaPunteros.h"

using namespace std;

int main()
{
    Puntero<int> a(56);
    Puntero<int> b(25);

    Puntero<int> resultado = a + b;
    resultado.mostrar();

    return 0;
}