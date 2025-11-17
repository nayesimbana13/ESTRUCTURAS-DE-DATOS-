Proyecto: Lista Simple (C++)

Descripción
-----------
Ejemplo orientado a objetos de una lista enlazada simple que permite insertar enteros al frente, al final y en una posición dada. Incluye métodos para imprimir, buscar y limpiar la lista.

Archivos
-------
- ListaSimple.h: Implementación (header-only) de las clases Nodo y ListaSimple.
- main.cpp: Programa de demostración que inserta elementos y muestra la lista.

Compilación (PowerShell / Windows)
---------------------------------
En la carpeta `tarea12` ejecutar:

```powershell
g++ main.cpp -o lista.exe
.\lista.exe
```

Notas
-----
- Esta implementación es sencilla y deliberadamente didáctica. Para producción se pueden añadir operadores, manejo de excepciones más detallado, y soporte para plantillas (generics).
- ListaSimple evita la copia por asignación para mantener el ejemplo corto; si necesitas copia profunda puedo añadirla.
