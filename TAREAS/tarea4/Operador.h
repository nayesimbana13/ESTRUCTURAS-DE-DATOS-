/***********************************************************************
 * Module:  Operador.h
 * Author:  Usuario
 * Modified: martes, 21 de octubre de 2025 22:14:23
 * Purpose: Declaration of the class Operador
 ***********************************************************************/

#if !defined(__tarea4SobrecargaMetodos2_Operador_h)
#define __tarea4SobrecargaMetodos2_Operador_h

class Operador
{
public:
   double operar1(int a, float b, double c);
   double operar2(int a, double b, float c);
   double operar3(float a, int b, double c);
   double operar4(float a, double b, int c);
   double operar5(double a, int b, float c);
   double operar6(double a, float b, int c);

protected:
private:

};

#endif