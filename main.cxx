#include <iostream>
#include "ArbolAVL.h"

using namespace std;

int main() {
    ArbolAVL<int> avl;

    cout << "== PRUEBA DE INSERCIÓN ==" << endl;
    avl.insertar(30);
    avl.insertar(20);
    avl.insertar(40);
    avl.insertar(10);
    avl.insertar(25);
    avl.insertar(35);
    avl.insertar(50);

    cout << "Recorrido en orden (InOrden): ";
    avl.inOrden(); // Debe estar ordenado de menor a mayor
    cout << endl;

    cout << "Recorrido preorden (PreOrden): ";
    avl.preOrden(); // Verifica alturas
    cout << endl;

    cout << "Recorrido posorden (PosOrden): ";
    avl.posOrden();
    cout << endl;

    cout << "Recorrido por niveles (NivelOrden): ";
    avl.nivelOrden();
    cout << endl;

    cout << "\n== PRUEBA DE BALANCE ==" << endl;
    cout << "Altura del árbol: " << avl.altura() << endl;
    cout << "Tamaño del árbol: " << avl.tamano() << endl;

    cout << "\n== PRUEBA DE BÚSQUEDA ==" << endl;
    int valor = 25;
    cout << "Buscar " << valor << ": " << (avl.buscar(valor) ? "Encontrado" : "No encontrado") << endl;

    valor = 100;
    cout << "Buscar " << valor << ": " << (avl.buscar(valor) ? "Encontrado" : "No encontrado") << endl;

    cout << "\n== PRUEBA DE ELIMINACIÓN ==" << endl;
    avl.eliminar(10);
    avl.eliminar(25);
    avl.eliminar(40);

    cout << "Recorrido en orden tras eliminar (InOrden): ";
    avl.inOrden();
    cout << endl;

    cout << "Altura del árbol después de eliminar: " << avl.altura() << endl;
    cout << "Tamaño del árbol después de eliminar: " << avl.tamano() << endl;

    return 0;
}