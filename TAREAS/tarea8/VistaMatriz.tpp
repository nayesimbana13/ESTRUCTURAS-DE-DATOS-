#include "VistaMatriz.h"
template <typename T>
void VistaMatriz<T>::mostrarMensaje(const std::string& msg) const {
    std::cout << msg << std::endl;
}
template <typename T>
void VistaMatriz<T>::mostrarMatriz(const Matriz<T>& m) const {
    m.imprimir();
}
