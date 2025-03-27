#include "ArbolAVL.h"
#include <queue>


template <class T>
ArbolAVL<T>::ArbolAVL(){
    this->raiz=NULL;
}

template <class T>
ArbolAVL<T>::~ArbolAVL(){
    if(this->raiz!=NULL){
        delete this->raiz;
        this->raiz = NULL;
    }
}

template <class T>
bool ArbolAVL<T>::esVacio(){
    return this->raiz == NULL;
}


template <class T>
T ArbolAVL<T>::datoRaiz(){
    if (this->raiz == nullptr) {
        std::cout<<"Arbol vacio";
    }
    return this->raiz->obtenerDato();
}

template <class T>
int ArbolAVL<T>::altura(){
    if(this->esVacio()){
        return -1;
    }
    else{
        return this->altura(this->raiz);
    }
}

template <class T>
int ArbolAVL<T>::altura(NodoBinario<T>* nodo) {
    if (nodo == nullptr) {
        return -1;
    }
    return std::max(altura(nodo->obtenerHijoIzq()), altura(nodo->obtenerHijoDer())) + 1;
}


template <class T>
void ArbolAVL<T>::inOrden(){
    if(!this->esVacio()){
        this->inOrden(this->raiz);
    }
}

template <class T>
void ArbolAVL<T>::inOrden(NodoBinario<T>* nodo){
    if(nodo!=NULL){
        this->inOrden(nodo->obtenerHijoIzq());
        std::cout<<nodo->obtenerDato()<<" ";
        this->inOrden(nodo->obtenerHijoDer());
    }
}

template <class T>
bool ArbolAVL<T>::buscar(T val){
    NodoBinario<T>* nodo = this->raiz;
    bool encontrado = false;

    while(nodo!=NULL && !encontrado){
        if(val< nodo->obtenerDato()){
            nodo = nodo->obtenerHijoIzq();
        }else if( val > nodo->obtenerDato()){
            nodo = nodo->obtenerHijoDer();
        }else{
            encontrado = true;
        }
    }
    return encontrado;
}

template <class T>
bool ArbolAVL<T>::insertar(T val) {
    bool insertado = false;
    this->raiz = insertarRecursivo(this->raiz, val, insertado);
    return insertado;
}


template <class T>
NodoBinario<T>* ArbolAVL<T>::insertarRecursivo(NodoBinario<T>* nodo, T val, bool& insertado) {
    if (nodo == nullptr) {
        NodoBinario<T>* nuevo = new NodoBinario<T>();
        nuevo->fijarDato(val);
        insertado = true;
        return nuevo;
    }
    
    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(insertarRecursivo(nodo->obtenerHijoIzq(), val, insertado));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(insertarRecursivo(nodo->obtenerHijoDer(), val, insertado));
    } else {
        insertado = false;
        return nodo;
    }

    // Actualizar altura del nodo
    nodo->fijarAltura(std::max(altura(nodo->obtenerHijoIzq()), altura(nodo->obtenerHijoDer())) + 1);

    // Calcular balance
    int alturaIzq = (nodo->obtenerHijoIzq() != nullptr) ? altura(nodo->obtenerHijoIzq()) : -1;
    int alturaDer = (nodo->obtenerHijoDer() != nullptr) ? altura(nodo->obtenerHijoDer()) : -1;
    int balance = alturaIzq - alturaDer;

    // Rotaciones para balancear el árbol
    if (balance > 1) {
        NodoBinario<T>* hijoIzq = nodo->obtenerHijoIzq();
        if (hijoIzq && val < hijoIzq->obtenerDato()) {
            return rotacionDerecha(nodo);
        } else {
            return rotacionIzquierdaDerecha(nodo);
        }
    }
    if (balance < -1) {
        NodoBinario<T>* hijoDer = nodo->obtenerHijoDer();
        if (hijoDer && val > hijoDer->obtenerDato()) {
            return rotacionIzquierda(nodo);
        } else {
            return rotacionDerechaIzquierda(nodo);
        }
    }

    return nodo;
}

template <class T>
void ArbolAVL<T>::nivelOrden(){
    if(!this->esVacio()){
        std::queue <NodoBinario<T>*> cola;
        cola.push(this->raiz);
        NodoBinario<T>* nodo;
        while(!cola.empty()){
            nodo = cola.front();
            cola.pop();
            std::cout<<nodo->obtenerDato()<<" ";
            if(nodo->obtenerHijoIzq()!=NULL){
                cola.push(nodo->obtenerHijoIzq());
            }
            if(nodo->obtenerHijoDer()!=NULL){
                cola.push(nodo->obtenerHijoDer());
            }
        }
    }
}

template <class T>
int ArbolAVL<T>::tamano() {
    return tamano(this->raiz);
}


template <class T>
int ArbolAVL<T>::tamano(NodoBinario<T>* nodo) {
    if (nodo == NULL) {
        return 0;
    }
    return 1 + tamano(nodo->obtenerHijoIzq()) + tamano(nodo->obtenerHijoDer());
}
/*
template <class T>
bool ArbolAVL<T>::eliminar(T val) {
    NodoBinario<T>* nodo = this->raiz;
    NodoBinario<T>* padre = nullptr;

    // 1. Buscar el nodo a eliminar y su padre
    while (nodo != nullptr && nodo->obtenerDato() != val) {
        padre = nodo;
        if (val < nodo->obtenerDato()) {
            nodo = nodo->obtenerHijoIzq();
        } else {
            nodo = nodo->obtenerHijoDer();
        }
    }

    if (nodo == nullptr) {
        return false;  // No se encontró el valor
    }

    // Caso 1: El nodo es una hoja
    if (nodo->esHoja()) {
        if (padre == nullptr) {
            this->raiz = nullptr;
        } else if (padre->obtenerHijoIzq() == nodo) {
            padre->fijarHijoIzq(nullptr);
        } else {
            padre->fijarHijoDer(nullptr);
        }
        delete nodo;
    }
    // Caso 2: Nodo con un solo hijo
    else if (nodo->obtenerHijoIzq() == nullptr || nodo->obtenerHijoDer() == nullptr) {
        NodoBinario<T>* hijo = (nodo->obtenerHijoIzq() != nullptr) ? nodo->obtenerHijoIzq() : nodo->obtenerHijoDer();

        if (padre == nullptr) {
            this->raiz = hijo;  // Si eliminamos la raíz, el hijo se convierte en la nueva raíz
        } else if (padre->obtenerHijoIzq() == nodo) {
            padre->fijarHijoIzq(hijo);
        } else {
            padre->fijarHijoDer(hijo);
        }
        delete nodo;
    }
    // Caso 3: Nodo con dos hijos
    else {
        NodoBinario<T>* sucesor = nodo->obtenerHijoDer();
        NodoBinario<T>* padreSucesor = nodo;

        // Buscar el nodo más pequeño en el subárbol derecho (sucesor inorden)
        while (sucesor->obtenerHijoIzq() != nullptr) {
            padreSucesor = sucesor;
            sucesor = sucesor->obtenerHijoIzq();
        }

        // Reemplazar el valor del nodo a eliminar con el del sucesor
        nodo->fijarDato(sucesor->obtenerDato());

        // Ajustar punteros para eliminar el sucesor
        if (padreSucesor->obtenerHijoIzq() == sucesor) {
            padreSucesor->fijarHijoIzq(sucesor->obtenerHijoDer());
        } else {
            padreSucesor->fijarHijoDer(sucesor->obtenerHijoDer());
        }

        delete sucesor;
    }

    return true;
}
*/
template <class T>
void ArbolAVL<T>::preOrden() {
    preOrden(this->raiz);
    std::cout << std::endl;
}

template <class T>
void ArbolAVL<T>::preOrden(NodoBinario<T>* nodo) {
    if (nodo == NULL) {
        return;
    }
    std::cout << nodo->obtenerDato() << " (Altura: " << nodo->obtenerAltura() << ") ";
    preOrden(nodo->obtenerHijoIzq());
    preOrden(nodo->obtenerHijoDer());
}


template <class T>
void ArbolAVL<T>::posOrden() {
    posOrden(this->raiz);
    std::cout << std::endl;
}

template <class T>
void ArbolAVL<T>::posOrden(NodoBinario<T>* nodo) {
    if (nodo == NULL) {
        return;
    }
    posOrden(nodo->obtenerHijoIzq());
    posOrden(nodo->obtenerHijoDer());
    std::cout << nodo->obtenerDato() << " "; 
}


/*implementaciones arbol AVL*/

template <class T>
NodoBinario<T>* ArbolAVL<T>::rotacionDerecha(NodoBinario<T>* n2) {
    NodoBinario<T>* n1 = n2->obtenerHijoIzq();
    n2->fijarHijoIzq(n1->obtenerHijoDer());
    n1->fijarHijoDer(n2);
    
    n2->fijarAltura(std::max(altura(n2->obtenerHijoIzq()), altura(n2->obtenerHijoDer())) + 1);
    n1->fijarAltura(std::max(altura(n1->obtenerHijoIzq()), altura(n1->obtenerHijoDer())) + 1);
    
    return n1;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::rotacionIzquierda(NodoBinario<T>* n1) {
    NodoBinario<T>* n2 = n1->obtenerHijoDer();
    n1->fijarHijoDer(n2->obtenerHijoIzq());
    n2->fijarHijoIzq(n1);
    
    n1->fijarAltura(std::max(altura(n1->obtenerHijoIzq()), altura(n1->obtenerHijoDer())) + 1);
    n2->fijarAltura(std::max(altura(n2->obtenerHijoIzq()), altura(n2->obtenerHijoDer())) + 1);
    
    return n2;
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::rotacionIzquierdaDerecha(NodoBinario<T>* nodo) {
    nodo->fijarHijoIzq(rotacionIzquierda(nodo->obtenerHijoIzq()));
    return rotacionDerecha(nodo);
}

template <class T>
NodoBinario<T>* ArbolAVL<T>::rotacionDerechaIzquierda(NodoBinario<T>* nodo) {
    nodo->fijarHijoDer(rotacionDerecha(nodo->obtenerHijoDer()));
    return rotacionIzquierda(nodo);
}