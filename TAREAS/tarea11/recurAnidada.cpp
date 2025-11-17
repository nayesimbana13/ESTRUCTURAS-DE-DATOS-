#include <iostream>
#include <functional>
using namespace std;

int main() {
    int filas = 3, columnas = 3;
    int* matriz = new int[filas * columnas];

    // Inicialización (sin [])
    for (int i = 0; i < filas * columnas; ++i)
        *(matriz + i) = i + 1; // valores del 1 al 9

    // Mostrar matriz (solo para referencia)
    cout << "Matriz:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j)
            cout << *(matriz + (i * columnas) + j) << " ";
        cout << "\n";
    }
    cout << "\n";

    // --- Recursividad anidada ---
    // Ejemplo: para una celda (i, j), multiplica el valor de la celda por el resultado de ejecutar la función sobre el resultado de otro llamado recursivo en j
    function<int(int, int)> anidada = [&](int i, int j) -> int {
        if (i < 0 || j < 0)
            return 1; // condición base
        return *(matriz + (i * columnas) + j) * anidada(i - 1, anidada(i, j - 1));
        // OJO: la llamada recursiva en el segundo parámetro es anidada
    };

    int resultado = anidada(filas - 1, columnas - 1);
    cout << "Recursividad anidada: resultado = " << resultado << "\n";

    delete[] matriz;
    return 0;
}
