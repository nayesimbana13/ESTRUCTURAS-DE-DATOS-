#include <iostream>
#include <functional>
using namespace std;

int main() {
    int filas = 3, columnas = 4;
    int* matriz = new int[filas * columnas];

    // Inicialización (sin [])
    for (int i = 0; i < filas * columnas; ++i)
        *(matriz + i) = i + 1; // valores del 1 al 12

    // Mostrar matriz (opcional, para referencia)
    cout << "Matriz:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j)
            cout << *(matriz + (i * columnas) + j) << " ";
        cout << "\n";
    }
    cout << "\n";

    // --- Recursividad múltiple ---
    // Calcula suma de [i, j] + suma de [i-1, j] + suma de [i, j-1]
    function<int(int, int)> sumaMultiple = [&](int i, int j) -> int {
        // condición base
        if (i < 0 || j < 0)
            return 0;
        // recursividad múltiple: se llama dos veces
        return *(matriz + (i * columnas) + j) + sumaMultiple(i - 1, j) + sumaMultiple(i, j - 1);
    };

    // Ejemplo: suma múltiple del último elemento (2,3)
    int resultado = sumaMultiple(filas - 1, columnas - 1);
    cout << "Suma múltiple recursiva desde el último elemento: " << resultado << "\n";

    delete[] matriz;
    return 0;
}
