#include <iostream>
#include <cstdarg>

class Calculadora {
public:
    static double operar(char operacion, int count, ...) {
        va_list args;
        va_start(args, count);
        
        double resultado = va_arg(args, double);
        
        for(int i = 1; i < count; i++) {
            double valor = va_arg(args, double);
            switch(operacion) {
                case '+': resultado += valor; break;
                case '-': resultado -= valor; break;
                case '*': resultado *= valor; break;
                case '/': 
                    if(valor != 0) resultado /= valor;
                    else {
                        std::cout << "Error: División por cero" << std::endl;
                        va_end(args);
                        return 0;
                    }
                    break;
            }
        }
        
        va_end(args);
        return resultado;
    }
};

int main() {
    std::cout << "Suma: " << Calculadora::operar('+', 4, 10.0, 20.0, 30.0, 40.0) << std::endl;
    std::cout << "Resta: " << Calculadora::operar('-', 3, 100.0, 20.0, 30.0) << std::endl;
    std::cout << "Multiplicación: " << Calculadora::operar('*', 3, 2.0, 3.0, 4.0) << std::endl;
    std::cout << "División: " << Calculadora::operar('/', 3, 100.0, 2.0, 2.0) << std::endl;
    return 0;
}