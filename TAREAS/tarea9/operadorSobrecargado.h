#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
using namespace std;

class Vector3D {
private:
    double x, y, z;
public:
    Vector3D(double _x=0, double _y=0, double _z=0);

    // Operadores aritméticos
    Vector3D operator+(const Vector3D& v) const;
    Vector3D operator-(const Vector3D& v) const;
    double operator*(const Vector3D& v) const;            // Producto escalar

    // Operadores unarios
    Vector3D operator-() const;
    Vector3D& operator++();                               // Preincremento
    Vector3D operator++(int);                             // Postincremento

    // Comparación
    bool operator==(const Vector3D& v) const;
    bool operator!=(const Vector3D& v) const;

    // Indexación
    double& operator[](int index);
    const double& operator[](int index) const;

    // Conversión de tipo
    operator double() const;    // Magnitud del vector

    // Llamada a función
    double operator()(int idx) const;

    // Entrada/salida
    friend ostream& operator<<(ostream& out, const Vector3D& v);
    friend istream& operator>>(istream& in, Vector3D& v);
};

#endif
