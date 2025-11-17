/***********************************************************************
 * Module:  Matriz.h
 * Author:  Usuario
 * Modified: martes, 21 de octubre de 2025 23:39:59
 * Purpose: Declaration of the class Matriz
 ***********************************************************************/

#if !defined(__tarea7MultiMatrices2_Matriz_h)
#define __tarea7MultiMatrices2_Matriz_h

#include <IMatriz.h>

class Matriz : public IMatriz
{
public:
   void segmentar(void);
   void encerar(void);
   void ingresar(void);
   void multiplicar(IMatriz* m1, IMatriz* m2, IMatriz* m3);
   void imprimir(void);

protected:
private:
   float** datos;
   int dimension;


};

#endif