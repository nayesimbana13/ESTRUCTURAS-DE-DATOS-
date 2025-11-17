#include <iostream>
#include <cstdarg>

int encontrarMaximo(int count, ...) {
    if(count < 1) return 0;
    
    va_list args;
    va_start(args, count);
    
    int maximo = va_arg(args, int);
    
    for(int i = 1; i < count; i++) {
        int valor = va_arg(args, int);
        if(valor > maximo) {
            maximo = valor;
        }
    }
    
    va_end(args);
    return maximo;
}

void imprimirConFormato(const char* formato, ...) {
    va_list args;
    va_start(args, formato);
    vprintf(formato, args);
    va_end(args);
}

int main() {
    imprimirConFormato("Buscando máximo entre números:\n");
    
    int max1 = encontrarMaximo(5, 10, 5, 15, 8, 12);
    imprimirConFormato("Máximo de (10, 5, 15, 8, 12): %d\n", max1);
    
    int max2 = encontrarMaximo(3, 100, 200, 300);
    imprimirConFormato("Máximo de (100, 200, 300): %d\n", max2);
    
    int max3 = encontrarMaximo(4, -5, -2, -10, -1);
    imprimirConFormato("Máximo de (-5, -2, -10, -1): %d\n", max3);
    
    return 0;
}