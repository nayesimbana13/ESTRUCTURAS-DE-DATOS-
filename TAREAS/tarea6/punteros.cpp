#include <iostream>
#include <cstdio> 

int main() {
    int a = 10;      // variable normal
    int *p = &a;     // puntero a 'a'
    int **q = &p;    // puntero a puntero

    printf("Valor de a: %d\n", a);
    printf("Direccion de a: %p\n", (void*)&a);
    printf("Valor apuntado por p (*p): %d\n", *p);
    printf("Valor apuntado por q (**q): %d\n", **q);

    return 0;
}