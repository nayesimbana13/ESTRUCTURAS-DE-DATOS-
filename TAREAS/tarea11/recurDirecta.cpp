#include <iostream>
#include <functional>
using namespace std;

// Programa: Ejemplo de recursividad directa usando
// arreglos unidimensionales, lambdas y sin []

int main()
{
    int n = 5; // tamaño del arreglo
    int *arr = new int[n];

    // Inicializar arreglo sin usar []
    for (int i = 0; i < n; i++)
        *(arr + i) = (i + 1); // arr = {1, 2, 3, 4, 5}

    cout << "Contenido del arreglo: ";
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
    cout << "\n\n";

    // --- Recursividad directa ---
    // Una función que se llama a sí misma directamente
    function<void(int *)> mostrarRecursivo = [&](int *p)
    {
        if (p < arr + n)
        {                            // condición base: fin del arreglo
            cout << *p << " ";       // proceso del elemento actual
            mostrarRecursivo(p + 1); // llamada recursiva directa
        }
    };

    cout << "Recorrido del arreglo usando recursividad directa: ";
    mostrarRecursivo(arr);

    cout << "\nFin del programa.\n";

    delete[] arr; // liberar memoria
    return 0;
}