/***********************************************************************
 * Module:  OperacionesFracciones.h
 * Author:  Usuario
 * Modified: martes, 21 de octubre de 2025 18:18:53
 * Purpose: Declaration of the class OperacionesFracciones
 ***********************************************************************/

#if !defined(__tarea1MultFraccion_OperacionesFracciones_h)
#define __tarea1MultFraccion_OperacionesFracciones_h

#include <Fraccion.h>

class OperacionesFracciones
{
public:
   virtual Fraccion multiplicar(Fraccion f1, Fraccion f2)=0;

protected:
private:

};

#endif