#include <iostream>
#include <cstdarg>

double sumar(int count, ...) {
    va_list args;
    va_start(args, count);
    
    double suma = 0;
    for(int i = 0; i < count; i++) {
        suma += va_arg(args, double);
    }
    
    va_end(args);
    return suma;
}

int main() {
    std::cout << "Suma de 3 números: " << sumar(3, 1.5, 2.7, 3.2) << std::endl;
    std::cout << "Suma de 5 números: " << sumar(5, 1.0, 2.0, 3.0, 4.0, 5.0) << std::endl;
    std::cout << "Suma de 2 números: " << sumar(2, 10.5, 20.5) << std::endl;
    return 0;
}