using namespace std;
nodo_lista *inicio = NULL, *final = NULL, *temp = NULL, *aux = NULL;
void agregar(int i);
void presentar();
void buscar(int i);
void eliminarNodo(int i);
void insertarInicio(int i);
int opcion, x;
int main(int argc, char **argv)
{
    do
    {
        cout << "Menu de opciones\n";
        cout << "1. Agregar nodo al final\n";
        cout << "2. Agregar nodo por la cabeza\n";
        cout << "3. Presentar\n";
        cout << "4. Buscar elemento\n";
        cout << "5. Editar elemento\n";
        cout << "6. Eliminar nodo \n";
        cout << "7. Salir\n";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Ingrese un numero: ";
            cin >> x;
            agregar(x);
            break;
        case 2:
            cout << " Ingrese un numero: " << endl;
            cin >> x;
            insertarInicio(x);
            break;
        case 3:
            cout << "  Lista" << endl;
            presentar();
            break;
        case 4:
            cout << "  Ingrese elemento a buscar" << endl;
            cin >> x;
            buscar(x);
            break;
        case 5:
            cout << "Ingrese el elemento a modificar: ";
            cin >> x;
            buscar(x);
            if (temp != NULL)
            {
                cout << "Elemento encontrado. Ingrese el nuevo valor" << endl;
                cin >> x;
                temp->id = x;
                cout << "Elemento modificado exitosamente" << endl;
            }
            break;
        case 6:
            cout << "Ingrese el elemento a eliminar: ";
            cin >> x;
            eliminarNodo(x);
            break;
        case 7:
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (opcion != 7);
    return 0;
}

void agregar(int i)
{
    temp = new nodo_lista();
    temp->id = i;
    temp->sig = NULL;
    if (inicio == NULL)
    {
        inicio = temp;
    }
    else
    {
        final->sig = temp;
    }
    final = temp;
}
void presentar()
{
    temp = inicio;
    while (temp != NULL)
    {
        cout << temp->id << endl;
        temp = temp->sig;
    }
}
void buscar(int i)
{
    bool encontrar = false;
    temp = inicio;
    aux = NULL;
    while (temp != NULL)
    {
        if (temp->id == i)
        {
            encontrar = true; 
            break;
        }

        aux = temp;
        temp = temp->sig;
    }
    if (encontrar)
    {
        cout << "Elemento " << i << " encontrado!" << endl;
    }
    else
    {
        cout << "No se encontro el elemento " << i << endl;
        temp = NULL;
    }
}

void eliminarNodo(int i)
{
    nodo_lista *actual = inicio;
    nodo_lista *anterior = NULL;
    bool encontrado = false;
    while (actual != NULL)
    {
        if (actual->id == i)
        {
            encontrado = true;
            break;
        }

        anterior = actual;
        actual = actual->sig;
    }

    if (!encontrado)
    {
        cout << "No se encontro el elemento " << i << " para eliminar." << endl;
        return;
    }

    cout << "Elemento " << i << " encontrado y sera eliminado." << endl;

    // Caso 1: Eliminar el primer nodo (cabeza)
    if (actual == inicio)
    {
        inicio = inicio->sig;
        if (inicio == NULL) // Si la lista queda vacía
        {
            final = NULL;
        }
    }
    // Caso 2: Eliminar el último nodo (cola)
    else if (actual == final)
    {
        anterior->sig = NULL;
        final = anterior;
    }
    // Caso 3: Eliminar un nodo en el medio
    else
    {
        anterior->sig = actual->sig; // Saltamos el nodo 'actual'
    }

    // Paso CRUCIAL: Liberar la memoria del nodo eliminado
    delete actual;
}
void insertarInicio(int i)
{
    temp = new nodo_lista();
    temp->id = i;
    if (inicio == NULL)
    {
        inicio = temp;
        temp->sig = NULL;
    }
    else
    {
        temp->sig = inicio;
        inicio = temp;
    }
    cout << "Elemento " << i << " insertado correctamente\n";
}