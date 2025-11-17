#ifndef DATOS_H
#define DATOS_H

class Datos {
private:
    int numero;     // Variable entera
    float decimal;  // Variable flotante

public:
    // Constructor
    Datos(int num, float dec);

    // Getters
    int getNumero() const;
    float getDecimal() const;

    // Setters
    void setNumero(int num);
    void setDecimal(float dec);

    // Nueva función: suma del entero y el decimal
    float sumarValores() const;
};

#endif // DATOS_H