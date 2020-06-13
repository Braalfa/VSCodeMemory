//
// Created by usuario on 22/5/20.
//

#include "VSPtr.h"
#include <typeinfo>
#include <GarbageCollector.h>

/**
 *Funcion estatica que sirve para instnciar un nuevo VSPtr, esta funcion tambien genera un ID y crear la primer refenrencia
 * del puntero como el typo de dato de este
 * @tparam T tipo de dato que entra generico
 * @return return un nuevo VSPtr
 */
template<class T>
VSPtr<T> VSPtr<T>::New()
{
    VSPtr<T> newVSPtr= *new VSPtr;
    newVSPtr.references = 1;
    GarbageCollector::setType(Local);
    if(GarbageCollector::type==Local){
        newVSPtr.ptr = nullptr;
    }
    string name = typeid(*newVSPtr.ptr).name();

    GarbageCollector g=* GarbageCollector::getInstance();

    newVSPtr.ID = g.addNode(newVSPtr.ptr, name);
    return newVSPtr;
}
/**
 * Genera iunicos para cada VSPtr
 * @return un valor que sera utilizado de ID
 */
template<class T>
int VSPtr<T>::genID()
{
    static int i;
    return  ++i;
}
/**
 *  *Incializacion del VSPtr
 */
template<class T>
VSPtr<T>::VSPtr()
{

}
/**
 *Envia la direccion en memeoria del ptr
 * @tparam T
 * @return returna el valpr de ptr
 */
template<class T>
T *VSPtr<T>::getPtr()
{
    return ptr;

}
/**
 *Cambia la direccion de memeoria del ptr
 * @tparam T
 * @param newPtr nuevo valor de ptr
 */
template<class T>
void VSPtr<T>::setPtr(T newPtr)
{
    ptr = new T(newPtr);
}
/**
 *
 * @tparam T
 * @return Retorna el valor del ID dentro del VSPtr
 */
template<class T>
int VSPtr<T>::getID()
{
    return this->ID;
}
/**
 * Cambia el valor del ID del ptr
 * @tparam T
 * @param newID nuveo valor de ID para el ptr
 */
template<class T>
void VSPtr<T>::setID(int newID)
{
    this->ID = newID;
}
/**
 *
 * @tparam T
 * @return Este operador enviar el valor cuando se hace una comparcion con un int,string o cualquier valor primitivo

 */
template<class T>
T &VSPtr<T>::operator*() {
    return *ptr;
}
/**
 * Este operador se utiliza para apuntar al valor ptr
 * @tparam T
 * @return un ptr
 */
template<class T>
T *VSPtr<T>::operator->() {
    return ptr;
}
/**
 * Este operador se utiliza para apuntar al valor ptr
 * @return el valor del ptr
 */
T VSPtr<T>::operator&() {
    return *ptr;
}

/**
 * ESte operado se utiliza cuando se comprar un VSPtr con algun valor primitivo y lo que hace es cambiar el valor que
 * poseia con anterioriridad por un nuevo valor
 * @tparam T
 * @param newValue el valot entraate por el cual se cambirara el ptr
 */
template<class T>
void VSPtr<T>::operator=(T newValue) {

    GarbageCollector::getInstance()->setMemory(&newValue, ID, type);

}
/**
 * Sobrecarga que se utiliza cuando existe una compracion de punteros,este copia la direecion de memoria, el valor y el ID
 * dentro de uno de ellos y agrega referencias al puntero recpetor, y elimina y revisa la cantidad de referencias del VSPtre
 * emisor
 * @tparam T
 * @param vsptr el puntero emisor de datos
 */
template<class T>
void VSPtr<T>::operator=(VSPtr vsptr) {
    if(references == 1){
        GarbageCollector::getInstance()->deleteVS(getID());
    }
    GarbageCollector::getInstance()->deleteReferences(ID);
    ptr = vsptr.ptr;
    ID = vsptr.ID;
    GarbageCollector::getInstance()->addReferences(vsptr.ID);
}
/**
 *
 * @tparam T
 * @return La cantidad de referencias del VSPtr
 */
template <class T>
int VSPtr<T>::getReferences()
{
    return this->references;
}
/**
 * Elimina el una referencia en el VSPtr
 * @tparam T
 */
template<class T>
void VSPtr<T>::deleteReferences()
{
    this->references = references - 1;
}
/**
 * Agrega una referencia del VSptr
 * @tparam T
 */
template<class T>
void VSPtr<T>::addReferences()
{
    this->references = references +1;
}

template class VSPtr<int>;
template class VSPtr<std::string>;
template class VSPtr<bool>;
template class VSPtr<float>;
template class VSPtr<double>;
