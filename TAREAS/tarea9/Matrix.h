/***********************************************************************
 * Module:  Matrix.h
 * Author:  Usuario
 * Modified: miércoles, 22 de octubre de 2025 5:05:22
 * Purpose: Declaration of the class Matrix
 ***********************************************************************/

#if !defined(__tarea9OperadoresSobrecargados2_Matrix_h)
#define __tarea9OperadoresSobrecargados2_Matrix_h

class Matrix
{
public:
   double operador[](int index);
   Matrix operator_(Matrix other);
   bool operator__(Matrix other);

protected:
private:
   double* data;
   int filas;
   int columnas;


};

#endif