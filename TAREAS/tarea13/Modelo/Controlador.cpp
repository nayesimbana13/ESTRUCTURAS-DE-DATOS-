#include "Vista.h"
#include "Modelo/ListaSimple.h"

void ejecutarPrograma() {
    ListaSimple lista;
    Vista vista;
    int opcion, valor;

    while (true) {
        vista.mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Valor: ";
                std::cin >> valor;
                lista.insertarCola(valor);
                break;
            case 2:
                std::cout << "Valor: ";
                std::cin >> valor;
                lista.insertarCabeza(valor);
                break;
            case 3:
                lista.eliminarCola();
                break;
            case 4:
                lista.eliminarCabeza();
                break;
            case 5:
                vista.mostrarLista(lista);
                break;
            case 6:
                std::cout << "Valor: ";
                std::cin >> valor;
                vista.mostrarResultadoBusqueda(lista.buscar(valor));
                break;
            case 7:
                vista.mostrarJSON(lista.aJson());
                break;
            case 0:
                return;
            default:
                std::cout << "Opción no válida\n";
        }
    }
}
