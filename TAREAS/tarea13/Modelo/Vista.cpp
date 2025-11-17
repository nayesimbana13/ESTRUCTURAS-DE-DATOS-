#include "Vista.h"

void Vista::mostrarMenu() {
    std::cout << "\n1. Insertar por cola\n2. Insertar por cabeza\n3. Eliminar por cola\n4. Eliminar por cabeza\n5. Imprimir\n6. Buscar\n7. Exportar a JSON\n0. Salir\n";
}

void Vista::mostrarLista(const ListaSimple& lista) {
    lista.imprimir();
}

void Vista::mostrarResultadoBusqueda(bool encontrado) {
    std::cout << (encontrado ? "Encontrado" : "No encontrado") << std::endl;
}

void Vista::mostrarJSON(const nlohmann::json& json) {
    std::cout << json.dump(4) << std::endl;
}
