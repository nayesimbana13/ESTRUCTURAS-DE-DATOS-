#include "Datos.h"

// Constructor
Datos::Datos(int num, float dec) {
    numero = num;
    decimal = dec;
}

// Getters
int Datos::getNumero() const {
    return numero;
}

float Datos::getDecimal() const {
    return decimal;
}

// Setters
void Datos::setNumero(int num) {
    numero = num;
}

void Datos::setDecimal(float dec) {
    decimal = dec;
}

// Función que suma el entero y el decimal
float Datos::sumarValores() const {
    return numero + decimal;
}