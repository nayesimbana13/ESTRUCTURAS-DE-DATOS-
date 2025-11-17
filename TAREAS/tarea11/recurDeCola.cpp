#include <iostream>
#include <functional>
using namespace std;

int main() {
    int filas = 3, columnas = 4;
    int* matriz = new int[filas * columnas];

    // Inicialización sin []
    for (int i = 0; i < filas * columnas; ++i)
        *(matriz + i) = i + 1; // valores del 1 al 12

    // Mostrar matriz para referencia
    cout << "Matriz:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j)
            cout << *(matriz + (i * columnas) + j) << " ";
        cout << "\n";
    }
    cout << "\n";

    // --- Recursividad de cola usando lambda ---
    // Recorre matriz linealmente acumulando la suma; uso bidimensional
    function<int(int, int, int)> sumaCola = [&](int i, int j, int acumulador) -> int {
        if (i == filas) // Si terminó las filas
            return acumulador;
        if (j == columnas) // Si terminó columnas, pasa a la siguiente fila
            return sumaCola(i + 1, 0, acumulador);

        // Suma el valor actual al acumulador y continúa
        return sumaCola(i, j + 1, acumulador + *(matriz + (i * columnas) + j));
    };

    int suma = sumaCola(0, 0, 0);
    cout << "Suma total recursiva de cola: " << suma << "\n";

    delete[] matriz;
    return 0;
}
