#include <iostream>
#include "Datos.h"

int main() {
    Datos d1(10, 5.75f);

    std::cout << "Numero entero: " << d1.getNumero() << std::endl;
    std::cout << "Numero decimal: " << d1.getDecimal() << std::endl;
    std::cout << "Suma de valores: " << d1.sumarValores() << std::endl;

    return 0;
}