// Programa de ejemplo: sobrecarga de métodos con parámetros int, float y double
// Se implementan las 6 permutaciones posibles de (int, float, double) como parámetros
// Cada sobrecarga realiza una operación (suma) y muestra qué versión fue llamada.

#include <iostream>
#include "metodosSobrecargados.h"

using namespace std;

// Definiciones
double operar(int a, float b, double c)
{
    cout << "Llamado: operar(int, float, double) -> ";
    double res = a + b + c;
    cout << res << "\n";
    return res;
}

double operar(int a, double b, float c)
{
    cout << "Llamado: operar(int, double, float) -> ";
    double res = a + b + c;
    cout << res << "\n";
    return res;
}

double operar(float a, int b, double c)
{
    cout << "Llamado: operar(float, int, double) -> ";
    double res = a + b + c;
    cout << res << "\n";
    return res;
}

double operar(float a, double b, int c)
{
    cout << "Llamado: operar(float, double, int) -> ";
    double res = a + b + c;
    cout << res << "\n";
    return res;
}

double operar(double a, int b, float c)
{
    cout << "Llamado: operar(double, int, float) -> ";
    double res = a + b + c;
    cout << res << "\n";
    return res;
}

double operar(double a, float b, int c)
{
    cout << "Llamado: operar(double, float, int) -> ";
    double res = a + b + c;
    cout << res << "\n";
    return res;
}

int main()
{
    cout.setf(std::ios::fixed);
    cout.precision(4);

    cout << "Demostracion de sobrecarga con int, float y double (todas las permutaciones)\n";

    // Leer valores desde teclado
    int i;
    float f;
    double d;

    cout << "Introduce un entero (int): ";
    if (!(cin >> i))
    {
        cerr << "Entrada invalida para entero.\n";
        return 1;
    }

    cout << "Introduce un float: ";
    if (!(cin >> f))
    {
        cerr << "Entrada invalida para float.\n";
        return 1;
    }

    cout << "Introduce un double: ";
    if (!(cin >> d))
    {
        cerr << "Entrada invalida para double.\n";
        return 1;
    }

    cout << "\nResultados:\n";

    // Llamadas a cada sobrecarga usando los valores ingresados
    operar(i, f, d);
    operar(i, d, f);
    operar(f, i, d);
    operar(f, d, i);
    operar(d, i, f);
    operar(d, f, i);

    return 0;
}