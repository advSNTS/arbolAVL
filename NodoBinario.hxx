#include "NodoBinario.h"

template <class T>
NodoBinario<T>::NodoBinario() {
    this->dato = T();
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
    this->altura = 0;
}

template <class T>
NodoBinario<T>::NodoBinario(T val) {
    this->dato = val;
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
    this->altura = 0;
}

template <class T>
NodoBinario<T>::~NodoBinario() {
    delete this->hijoIzq;
    delete this->hijoDer;
}

template <class T>
T NodoBinario<T>::obtenerDato(){
    return this->dato;
}

template <class T>
void NodoBinario<T>::fijarDato(T val){
    this->dato = val;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq(){
    return this->hijoIzq;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer(){
    return this->hijoDer;
}

template <class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T>* izq){
    this->hijoIzq = izq;
}

template <class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T>* der){
    this->hijoDer = der;
}

template <class T>
bool NodoBinario<T>::esHoja(){
    return (this->hijoDer==NULL && this->hijoIzq == NULL);
}

template <class T>
void NodoBinario<T>::fijarAltura(int altura){
    this->altura = altura;
}


template <class T>
int NodoBinario<T>::obtenerAltura(){
    return this->altura;
}