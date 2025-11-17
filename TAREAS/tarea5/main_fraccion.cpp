// main_fraccion.cpp
// Interfaz simple por consola para multiplicar dos fracciones usando el TDA Fraccion<T>

#include <iostream>
#include <string>
#include "fraccionTryCatch.h"

using namespace std;

int main() {
    cout << "Multiplicador de fracciones (con templates y try/catch)\n";
    cout << "Elige el tipo para las fracciones (1=int, 2=float, 3=double): ";
    int opcion = 0;
    if (!(cin >> opcion)) {
        cerr << "Opcion invalida. Saliendo.\n";
        return 1;
    }

    try {
        if (opcion == 1) {
            using T = int;
            cout << "Ingresar primera fraccion:\n";
            T n1 = leerValor<T>("  numerador: ");
            T d1 = leerValor<T>("  denominador: ");
            Fraccion<T> f1(n1, d1);

            cout << "Ingresar segunda fraccion:\n";
            T n2 = leerValor<T>("  numerador: ");
            T d2 = leerValor<T>("  denominador: ");
            Fraccion<T> f2(n2, d2);

            Fraccion<T> r = f1 * f2;
            cout << "Resultado: "; r.print(); cout << "\n";

        } else if (opcion == 2) {
            using T = float;
            cout << "Ingresar primera fraccion:\n";
            T n1 = leerValor<T>("  numerador: ");
            T d1 = leerValor<T>("  denominador: ");
            Fraccion<T> f1(n1, d1);

            cout << "Ingresar segunda fraccion:\n";
            T n2 = leerValor<T>("  numerador: ");
            T d2 = leerValor<T>("  denominador: ");
            Fraccion<T> f2(n2, d2);

            Fraccion<T> r = f1 * f2;
            cout << "Resultado: "; r.print(); cout << "\n";

        } else if (opcion == 3) {
            using T = double;
            cout << "Ingresar primera fraccion:\n";
            T n1 = leerValor<T>("  numerador: ");
            T d1 = leerValor<T>("  denominador: ");
            Fraccion<T> f1(n1, d1);

            cout << "Ingresar segunda fraccion:\n";
            T n2 = leerValor<T>("  numerador: ");
            T d2 = leerValor<T>("  denominador: ");
            Fraccion<T> f2(n2, d2);

            Fraccion<T> r = f1 * f2;
            cout << "Resultado: "; r.print(); cout << "\n";

        } else {
            cerr << "Opcion no reconocida. Saliendo.\n";
            return 1;
        }
    }
    catch (const std::invalid_argument& e) {
        cerr << "Error de entrada: " << e.what() << "\n";
        return 1;
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
