#include "Pila.h"
#include <iostream>

void mostrarMenu()
{
    std::cout << "\n--- Menu Pila ---\n";
    std::cout << "1) Insertar por cabeza\n";
    std::cout << "2) Insertar por cola\n";
    std::cout << "3) Eliminar por cabeza\n";
    std::cout << "4) Eliminar por cola\n";
    std::cout << "5) Buscar valor\n";
    std::cout << "6) Imprimir (cabeza->cola)\n";
    std::cout << "7) Imprimir reversa (cola->cabeza)\n";
    std::cout << "8) Mostrar tamanio\n";
    std::cout << "0) Salir\n";
    std::cout << "Elija una opcion: ";
}

int main()
{
    Pila pila;
    int opcion = -1;

    while (opcion != 0)
    {
        mostrarMenu();
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
            pila.insertarPorCabeza(v);
            pila.imprimir();
            break;
        }
        case 2:
        {
            std::cout << "Ingrese entero a insertar por cola: ";
            int v;
            std::cin >> v;
            pila.insertarPorCola(v);
            pila.imprimir();
            break;
        }
        case 3:
        {
            if (pila.eliminarPorCabeza())
                std::cout << "Eliminado por cabeza.\n";
            else
                std::cout << "La pila esta vacia.\n";
            pila.imprimir();
            break;
        }
        case 4:
        {
            if (pila.eliminarPorCola())
                std::cout << "Eliminado por cola.\n";
            else
                std::cout << "La pila esta vacia.\n";
            pila.imprimir();
            break;
        }
        case 5:
        {
            std::cout << "Ingrese entero a buscar: ";
            int v;
            std::cin >> v;
            std::cout << (pila.buscar(v) ? "Encontrado" : "No encontrado") << std::endl;
            break;
        }
        case 6:
            pila.imprimir();
            break;
        case 7:
            pila.imprimirReversa();
            break;
        case 8:
            std::cout << "Tamanio: " << pila.obtenerTamano() << std::endl;
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