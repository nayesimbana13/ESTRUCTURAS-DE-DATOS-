/***********************************************************************
 * Module:  MultiplicadorDeFracciones.h
 * Author:  Usuario
 * Modified: martes, 21 de octubre de 2025 18:38:58
 * Purpose: Declaration of the class MultiplicadorDeFracciones
 ***********************************************************************/

#if !defined(__tarea1MultFraccion_MultiplicadorDeFracciones_h)
#define __tarea1MultFraccion_MultiplicadorDeFracciones_h

class Fraccion;

#include <OperacionesFracciones.h>
#include <Fraccion.h>

class MultiplicadorDeFracciones : public OperacionesFracciones
{
public:
   Fraccion multiplicar(Fraccion f1, Fraccion f2);

   Fraccion** fracciones;

protected:
private:

};

#endif