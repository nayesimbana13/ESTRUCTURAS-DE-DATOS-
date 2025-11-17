#include "Cola.h"
#include <iostream>

void menu()
{
    std::cout << "\n--- Menu Cola ---\n";
    std::cout << "1) Insertar por cabeza\n";
    std::cout << "2) Insertar por cola\n";
    std::cout << "3) Eliminar por cabeza\n";
    std::cout << "4) Eliminar por cola\n";
    std::cout << "5) Eliminar por valor\n";
    std::cout << "6) Buscar valor\n";
    std::cout << "7) Imprimir (cabeza->cola)\n";
    std::cout << "8) Imprimir reversa (cola->cabeza)\n";
    std::cout << "9) Mostrar tamaioo\n";
    std::cout << "0) Salir\n";
    std::cout << "Elija una opcion: ";
}

int main()
{
    Cola cola;
    std::cout << "Estado inicial: ";
    cola.imprimir();

    int opcion = -1;

    while (opcion != 0)
    {
        menu();
        if (!(std::cin >> opcion))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada no valida. Intente de nuevo.\n";
            continue;
        }

        switch (opcion)
        {
        case 1:
        {
            std::cout << "Ingrese entero a insertar por cabeza: ";
            int v;
            std::cin >> v;
            cola.insertarPorCabeza(v);
            cola.imprimir();
            break;
        }
        case 2:
        {
            std::cout << "Ingrese entero a insertar por cola: ";
            int v;
            std::cin >> v;
            cola.insertarPorCola(v);
            cola.imprimir();
            break;
        }
        case 3:
        {
            if (cola.eliminarPorCabeza())
            {
                std::cout << "Eliminado por cabeza.\n";
            }
            else
            {
                std::cout << "La cola esta vacia.\n";
            }
            cola.imprimir();
            break;
        }
        case 4:
        {
            if (cola.eliminarPorCola())
            {
                std::cout << "Eliminado por cola.\n";
            }
            else
            {
                std::cout << "La cola esta vacia.\n";
            }
            cola.imprimir();
            break;
        }
        case 5:
        {
            std::cout << "Ingrese entero a eliminar (primera ocurrencia): ";
            int v;
            std::cin >> v;
            if (cola.eliminarPorValor(v))
                std::cout << "Valor eliminado.\n";
            else
                std::cout << "Valor no encontrado.\n";
            cola.imprimir();
            break;
        }
        case 6:
        {
            std::cout << "Ingrese entero a buscar: ";
            int v;
            std::cin >> v;
            int idx = cola.buscar(v);
            if (idx >= 0)
                std::cout << "Encontrado en indice " << idx << " (0 = cabeza)\n";
            else
                std::cout << "No encontrado\n";
            break;
        }
        case 7:
            cola.imprimir();
            break;
        case 8:
            cola.imprimirReversa();
            break;
        case 9:
            std::cout << "Tamanio: " << cola.size() << "\n";
            break;
        case 0:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opcion no valida.\n";
        }
    }

    return 0;
}