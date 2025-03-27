#include <iostream>
#include "ArbolAVL.h"

int main(){
    ArbolAVL<int> arbol;
    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(70);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(60);
    arbol.insertar(80);
    arbol.preOrden();
    return 0;
}