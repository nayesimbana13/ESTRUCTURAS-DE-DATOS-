#include "operadorSobrecargado.h"

int main() {
    Vector3D a(1, 2, 3), b(4, 5, 6), c;

    // Suma y resta
    c = a + b;
    cout << "a + b = " << c << endl;

    c = a - b;
    cout << "a - b = " << c << endl;

    // Producto escalar
    double prod = a * b;
    cout << "a * b = " << prod << endl;

    // Incremento
    ++a;
    cout << "++a = " << a << endl;
    b++;
    cout << "b++ = " << b << endl;

    // Indexación
    cout << "a[1] = " << a[1] << endl;

    // Conversión de tipo a double (magnitud)
    double mag = (double)a;
    cout << "||a|| = " << mag << endl;

    // Comparación
    cout << "a == b?: " << (a == b ? "true" : "false") << endl;

    // Llamada a función
    cout << "a(2) = " << a(2) << endl;

    // Entrada/salida
    Vector3D userVec;
    cin >> userVec;
    cout << "Ingresado: " << userVec << endl;

    return 0;
}
