#include <iostream>
#include "ControladorMatriz.h"
template <typename T>
void ControladorMatriz<T>::proceso() {
    int dim = 3;
    Matriz<T> m1(dim), m2(dim), m3(dim);
    VistaMatriz<T> vista;

    // Segmentar memoria
    m1.segmentar();
    m2.segmentar();
    m3.segmentar();

    vista.mostrarMensaje("Ingrese datos para Matriz 1:");
    m1.ingresar();

    vista.mostrarMensaje("Ingrese datos para Matriz 2:");
    m2.ingresar();

    m1.encerar();
    m2.encerar();
    // Por ejemplo, podrías pedir un nuevo ingreso o continuar con matrices originales.

    vista.mostrarMensaje("Multiplicando...");
    m3 = m1 * m2;   // operador sobrecargado

    vista.mostrarMensaje("Resultado:");
    vista.mostrarMatriz(m3);
}
