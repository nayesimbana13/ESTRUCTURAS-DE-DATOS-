#include <iostream>
#include <cstdarg>
#include <cstring>

char* concatenarCadenas(int count, ...) {
    va_list args;
    va_start(args, count);
    
    // Primero calculamos la longitud total necesaria
    size_t longitud_total = 1; // Para el caracter nulo
    va_list args_copia;
    va_copy(args_copia, args);
    
    for(int i = 0; i < count; i++) {
        const char* str = va_arg(args_copia, const char*);
        longitud_total += strlen(str);
    }
    va_end(args_copia);
    
    // Asignamos memoria para la cadena resultante
    char* resultado = new char[longitud_total];
    *resultado = '\0';
    
    // Concatenamos las cadenas
    for(int i = 0; i < count; i++) {
        const char* str = va_arg(args, const char*);
        strcat(resultado, str);
    }
    
    va_end(args);
    return resultado;
}

int main() {
    char* resultado1 = concatenarCadenas(3, "Hola ", "mundo ", "programador!");
    std::cout << "Concatenación 1: " << resultado1 << std::endl;
    
    char* resultado2 = concatenarCadenas(4, "C++", " es ", "muy ", "poderoso!");
    std::cout << "Concatenación 2: " << resultado2 << std::endl;
    
    // Liberamos la memoria
    delete[] resultado1;
    delete[] resultado2;
    
    return 0;
}