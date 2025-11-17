/***********************************************************************
 * Module:  Vector3D.h
 * Author:  Usuario
 * Modified: miércoles, 22 de octubre de 2025 5:05:22
 * Purpose: Declaration of the class Vector3D
 ***********************************************************************/

#if !defined(__tarea9OperadoresSobrecargados2_Vector3D_h)
#define __tarea9OperadoresSobrecargados2_Vector3D_h

class Vector3D
{
public:
   Vector3D operator__(Vector3D other);
   Vector3D operator-(Vector3D other);
   double operator(Vector3D other);
   bool operator___(Vector3D other);
   Vector3D operator____(void);
   int operator_int__(void);
   double operator[](int index);
   double operator__(int Param);
   Vector3D operator!__(void);

protected:
private:
   double x;
   double y;
   double z;


};

#endif