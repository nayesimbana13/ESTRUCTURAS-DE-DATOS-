
// fraccionTryCatch.h
// Implementación de un TDA Fraccion como plantilla (template)
// Incluye constructor, set/get, validación y multiplicación.

#pragma once

#include <stdexcept>
#include <iostream>

template <typename T>
class Fraccion {
private:
	T numerador;
	T denominador;
public:
	// Constructores
	Fraccion() : numerador(0), denominador(1) {}
	Fraccion(T n, T d) {
		setNumerador(n);
		setDenominador(d);
	}

	// Setters
	void setNumerador(T n) { numerador = n; }
	void setDenominador(T d) {
		if (d == (T)0) throw std::invalid_argument("Denominador no puede ser 0");
		denominador = d;
	}

	// Getters
	T getNumerador() const { return numerador; }
	T getDenominador() const { return denominador; }

	// Multiplicación de fracciones
	Fraccion<T> operator*(const Fraccion<T>& other) const {
		Fraccion<T> res;
		res.numerador = numerador * other.numerador;
		res.denominador = denominador * other.denominador;
		return res;
	}

	// Mostrar
	void print(std::ostream& os = std::cout) const {
		os << numerador << "/" << denominador;
	}
};

// Función template para leer un valor de tipo T desde std::cin con manejo de errores
template<typename T>
T leerValor(const std::string& prompt) {
	T value;
	std::cout << prompt;
	if (!(std::cin >> value)) {
		// limpiar el estado de std::cin y descartar la línea
		std::cin.clear();
		std::string dummy;
		std::getline(std::cin, dummy);
		throw std::invalid_argument("Entrada invalida para el tipo solicitado");
	}
	return value;
}
