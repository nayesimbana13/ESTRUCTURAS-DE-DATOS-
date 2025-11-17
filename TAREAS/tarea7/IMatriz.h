/***********************************************************************
 * Module:  IMatriz.h
 * Author:  Usuario
 * Modified: martes, 21 de octubre de 2025 23:39:59
 * Purpose: Declaration of the class IMatriz
 ***********************************************************************/

#if !defined(__tarea7MultiMatrices2_IMatriz_h)
#define __tarea7MultiMatrices2_IMatriz_h

class IMatriz
{
public:
   virtual void segmentar(void)=0;
   virtual void encerar(void)=0;
   virtual void ingresar(void)=0;
   virtual void multiplicar(IMatriz* m1, IMatriz* m2, IMatriz* m3)=0;
   virtual void imprimir(void)=0;

protected:
private:

};

#endif