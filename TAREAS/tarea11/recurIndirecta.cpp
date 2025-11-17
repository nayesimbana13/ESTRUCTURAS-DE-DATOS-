#include <iostream>
#include <functional>
using namespace std;

int main() {
    int filas = 3, columnas = 3;
    int* matriz = new int[filas * columnas];

    // Inicializamos la matriz bidimensional sin usar []
    for (int i = 0; i < filas * columnas; ++i)
        *(matriz + i) = i + 1; // valores del 1 al 9

    // Mostrar la matriz normalmente (sólo para ver cómo se almacena linealmente)
    cout << "Matriz:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j)
            cout << *(matriz + (i * columnas) + j) << " ";
        cout << "\n";
    }
    cout << "\n";

    // --- RECURRENCIA INDIRECTA ---

    // Definimos dos lambdas que se llaman mutuamente:
    function<void(int, int)> B;
    function<void(int, int)> A = [&](int i, int j) {
        if (i < filas && j < columnas) {
            cout << *(matriz + (i * columnas) + j) << " ";
            B(i, j + 1); // A llama a B, avanza por columnas
        }
    };

    B = [&](int i, int j) {
        if (j >= columnas) {
            // Cuando termina la fila, pasa a la siguiente
            if (i + 1 < filas)
                A(i + 1, 0); // B llama a A, inicia nueva fila
        }
        else {
            // Si aún hay columnas, llama a A normalmente
            // Solo para completar la recursión indirecta
            A(i, j);
        }
    };

    cout << "Recorrido recursivo indirecto de matriz: ";
    A(0, 0); // Empieza en la posición (0,0)
    cout << "\n";

    delete[] matriz;
    return 0;
}
