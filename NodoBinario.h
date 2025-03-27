#ifndef NODOBINARIO_H
#define NODOBINARIO_H

template <class T>
class NodoBinario
{
protected:
    T dato;
    NodoBinario<T>* hijoIzq;
    NodoBinario<T>* hijoDer;
    int altura;
public:
    NodoBinario();
    NodoBinario(T val);
    ~NodoBinario();
    T obtenerDato();
    void fijarDato(T val);
    NodoBinario<T>* obtenerHijoIzq();
    NodoBinario<T>* obtenerHijoDer();
    void fijarHijoIzq(NodoBinario<T>* izq);
    void fijarHijoDer(NodoBinario<T>* der);
    bool esHoja();

    void fijarAltura(int altura);
    int obtenerAltura();
};


#include "NodoBinario.hxx"
#endif