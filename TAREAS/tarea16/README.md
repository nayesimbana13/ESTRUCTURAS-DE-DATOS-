Proyecto: Cola (C++)

Descripción
-----------
Implementación orientada a objetos de una Cola doblemente enlazada con operaciones:
- insertarPorCabeza(int)
- insertarPorCola(int)
- eliminarPorCabeza()
- eliminarPorCola()
- buscar(int) -> devuelve índice (0 = cabeza) o -1
- imprimir() e imprimirReversa()

Estructura de archivos
----------------------
- Nodo.h: definición de la clase Nodo (dato, siguiente, anterior).
- Cola.h: definición de la clase Cola (implementa las operaciones).
- main.cpp: ejemplo de uso y pruebas.

Compilación (PowerShell)
------------------------
En la carpeta `tarea16` ejecutar:

```powershell
g++ main.cpp -o cola.exe
.\cola.exe
```

Notas
-----
- No se implementó copia por valor; si se necesita, puedo añadir constructor de copia y operador= con copia profunda.
- La implementación usa memoria dinámica; el destructor libera todos los nodos.
