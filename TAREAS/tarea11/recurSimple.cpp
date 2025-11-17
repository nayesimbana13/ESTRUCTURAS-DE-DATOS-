#include <iostream>
#include <functional>
using namespace std;

int main() {
    int dim1 = 2, dim2 = 2, dim3 = 3; // dimensiones: 2x2x3
    int total = dim1 * dim2 * dim3;
    int* matriz3D = new int[total];

    // Inicialización sin []
    for (int i = 0; i < total; ++i)
        *(matriz3D + i) = i + 1; // matriz contiene 1..12 (para 2x2x3)

    // Visualización para referencia (no requiere [])
    cout << "Matriz 3D (linealizada):\n";
    for (int i = 0; i < dim1; ++i) {
        for (int j = 0; j < dim2; ++j) {
            for (int k = 0; k < dim3; ++k) {
                int idx = (i * dim2 * dim3) + (j * dim3) + k;
                cout << *(matriz3D + idx) << " ";
            }
            cout << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

    // --- Recursividad simple: suma de todos los elementos ---
    function<int(int)> sumaRecursiva = [&](int idx) -> int {
        if (idx >= total)
            return 0; // condición base
        return *(matriz3D + idx) + sumaRecursiva(idx + 1); // solo una llamada recursiva
    };

    int suma = sumaRecursiva(0);
    cout << "Suma recursiva de todos los elementos: " << suma << "\n";

    delete[] matriz3D;
    return 0;
}
