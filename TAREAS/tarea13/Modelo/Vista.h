#ifndef VISTA_H
#define VISTA_H

#include <iostream>
#include <nlohmann/json.hpp>
#include "ListaSimple.h"

class Vista {
public:
    void mostrarMenu();
    void mostrarLista(const ListaSimple& lista);
    void mostrarResultadoBusqueda(bool encontrado);
    void mostrarJSON(const nlohmann::json& json);
};

#endif
