// multiplicarMatrice.h

#pragma once

#include <new> // operator new/operator delete
#include <iostream>

class IMatriz {
public:
    virtual void segmentar() = 0;
    virtual void encerar() = 0;
    virtual void ingresar() = 0;
    virtual void imprimir() = 0;
    virtual void multiplicar(IMatriz* m1, IMatriz* m2, IMatriz* m3) = 0;
    virtual ~IMatriz() {}
};

class Matriz : public IMatriz {
private:
    float** datos;
    int dimension;
public:
    Matriz(int dim = 3) : dimension(dim), datos(nullptr) {}

    void segmentar() override {
        datos = new float*[dimension];
        for (int i = 0; i < dimension; ++i)
            datos[i] = new float[dimension];
    }

    void encerar() override {
        for (int i = 0; i < dimension; ++i)
            for (int j = 0; j < dimension; ++j)
                *(*(datos + i) + j) = 0; // Sin []
    }

    void ingresar() override {
        for (int i = 0; i < dimension; ++i)
            for (int j = 0; j < dimension; ++j) {
                std::cout << "Ingrese valor [" << i << "][" << j << "]: ";
                std::cin >> *(*(datos + i) + j);
            }
    }

    void imprimir() override {
        for (int i = 0; i < dimension; ++i) {
            for (int j = 0; j < dimension; ++j)
                std::cout << *(*(datos + i) + j) << " ";
            std::cout << std::endl;
        }
    }

    void multiplicar(IMatriz* m1, IMatriz* m2, IMatriz* m3) override {
        // Cast IMatriz* a Matriz* para acceder a "datos"
        Matriz* A = dynamic_cast<Matriz*>(m1);
        Matriz* B = dynamic_cast<Matriz*>(m2);
        Matriz* C = dynamic_cast<Matriz*>(m3);

        for (int i = 0; i < dimension; ++i)
            for (int j = 0; j < dimension; ++j) {
                *(*(C->datos + i) + j) = 0;
                for (int k = 0; k < dimension; ++k)
                    *(*(C->datos + i) + j) += (*(*(A->datos + i) + k)) * (*(*(B->datos + k) + j));
            }
    }

    ~Matriz() {
        if (datos != nullptr) {
            for (int i = 0; i < dimension; ++i)
                delete[] datos[i];
            delete[] datos;
        }
    }
};
