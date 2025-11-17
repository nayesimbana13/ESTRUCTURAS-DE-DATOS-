#include "operadorSobrecargado.h"
#include <cmath>

// Constructor
Vector3D::Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

// Suma y resta
Vector3D Vector3D::operator+(const Vector3D& v) const {
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D Vector3D::operator-(const Vector3D& v) const {
    return Vector3D(x - v.x, y - v.y, z - v.z);
}

// Producto escalar
double Vector3D::operator*(const Vector3D& v) const {
    return x*v.x + y*v.y + z*v.z;
}

// Unario negativo
Vector3D Vector3D::operator-() const {
    return Vector3D(-x, -y, -z);
}

// Preincremento (++v)
Vector3D& Vector3D::operator++() {
    ++x; ++y; ++z;
    return *this;
}
// Postincremento (v++)
Vector3D Vector3D::operator++(int) {
    Vector3D temp = *this;
    ++(*this);
    return temp;
}

// Comparaciones
bool Vector3D::operator==(const Vector3D& v) const {
    return x == v.x && y == v.y && z == v.z;
}

bool Vector3D::operator!=(const Vector3D& v) const {
    return !(*this == v);
}

// Indexación
double& Vector3D::operator[](int index) {
    if (index == 0) return x;
    else if (index == 1) return y;
    else return z;
}
const double& Vector3D::operator[](int index) const {
    if (index == 0) return x;
    else if (index == 1) return y;
    else return z;
}

// Conversión de tipo: magnitud
Vector3D::operator double() const {
    return sqrt(x*x + y*y + z*z);
}

// Llamada a función: devuelve el elemento indexado elevado al cuadrado
double Vector3D::operator()(int idx) const {
    double val = (*this)[idx];
    return val * val;
}

// Sobrecarga de << y >>
ostream& operator<<(ostream& out, const Vector3D& v) {
    return out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}
istream& operator>>(istream& in, Vector3D& v) {
    cout << "x: "; in >> v.x;
    cout << "y: "; in >> v.y;
    cout << "z: "; in >> v.z;
    return in;
}
