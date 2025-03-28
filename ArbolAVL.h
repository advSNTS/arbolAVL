#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "NodoBinario.h"
template <class T>
class ArbolAVL
{
protected:
    NodoBinario<T>* raiz;
public:
    ArbolAVL(/* args */);
    ~ArbolAVL();
    bool esVacio();
    T datoRaiz();
    int altura();
    int tamano();
    int altura(NodoBinario<T>* nodo);
    int tamano(NodoBinario<T>* nodo);
    bool insertar(T val);
    bool eliminar(T val);
    NodoBinario<T>* eliminarRecursivo(NodoBinario<T>* nodo, T val, bool& eliminado);
    bool buscar(T val);
    void preOrden();
    void preOrden(NodoBinario<T>* nodo);
    void inOrden();
    void inOrden(NodoBinario<T>* nodo);
    void posOrden();
    void posOrden(NodoBinario<T>* nodo);
    void nivelOrden();
    

    NodoBinario<T>* rotacionIzquierda(NodoBinario<T>* n1);
    NodoBinario<T>* rotacionDerecha(NodoBinario<T>* n2);
    NodoBinario<T>* rotacionIzquierdaDerecha(NodoBinario<T>* nodo);
    NodoBinario<T>* rotacionDerechaIzquierda(NodoBinario<T>* nodo);
    NodoBinario<T>* insertarRecursivo(NodoBinario<T>* nodo, T val, bool& insertado);
    NodoBinario<T>* nodoMinimo(NodoBinario<T>* nodo);
};


#include "ArbolAVL.hxx"
#endif