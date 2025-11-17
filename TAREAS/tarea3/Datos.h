/***********************************************************************
 * Module:  Datos.h
 * Author:  Usuario
 * Modified: martes, 21 de octubre de 2025 21:10:22
 * Purpose: Declaration of the class Datos
 ***********************************************************************/

#if !defined(__tarea3Bytes_Datos_h)
#define __tarea3Bytes_Datos_h

class Datos
{
public:
   Datos(int num, float dec);
   ~Datos();
   int getNumero(void);
   void setNumero(int newNumero);
   float getDecimal(void);
   void setDecimal(float newDecimal);
   float sumarValores(void);

protected:
private:
   int numero;
   float decimal;


};

#endif