//
// Created by usuario on 22/5/20.
//

#include "VSPtr.h"
#include <typeinfo>

/**
 * La funcion new es utilizadda para la creacion de nuevos VSPtrs
 * @tparam T es el tipo de ptr que va ser creado en la funcion New
 * @return returna un VSPtr ya creado para el manejo de datos
 */
template<class T>
VSPtr<T> VSPtr<T>::New()
{
    VSPtr<T> newVSPtr= *new VSPtr;
    if(GarbageCollector::type==Local){
        newVSPtr.ptr = nullptr;
    }
    string name = typeid(*newVSPtr.ptr).name();
    if(name=="NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE"){
        name="s";
    }
    newVSPtr.type=name;
    GarbageCollector g=* GarbageCollector::getInstance();

    newVSPtr.ID = g.addNode(newVSPtr.ptr, name);
    return newVSPtr;
}
/**
 *Genera un ID unico para el valor de ID ppara mi vsptr
 * @tparam T
 * @return returna un valor unico para el ptr
 */
template<class T>
int VSPtr<T>::genID()
{
    static int i;
    return  ++i;
}
/**
 * Inicializa el VSPtr
 * @tparam T
 */
template<class T>
VSPtr<T>::VSPtr()
{

}
/**
 *FUncion que se utiliza cuando se necesita enviar la informacion del ptr
 * @tparam T
 * @return poiscionen qmemoria donde que gurada my VSPtr
 */
template<class T>
T *VSPtr<T>::getPtr()
{
    return ptr;
}
/**
 *Cuando myPtr necita cambiar de valor a este se le aplica un set
 * @tparam T
 * @param newPtr nuevo valor ptr que va a recibir el ptr
 */
template<class T>
void VSPtr<T>::setPtr(T newPtr)
{
    ptr = new T(newPtr);
}
/**
 * Retorna el valor del ID de my ptr
 * @tparam T
 * @return el ID que esta enlazado al VSPtr
 */
template<class T>
int VSPtr<T>::getID()
{
    return this->ID;
}
/**
 *Modifica el ID que se encuentre el ptr
 * @tparam T
 * @param newID valor por el cual va ser cambiado el ID del VSPtr
 */
template<class T>
void VSPtr<T>::setID(int newID)
{
    this->ID = newID;
}
/**
 *
 * @tparam T
 * @return returna el valor dentro gurdado dentro de my VSPtr
 */
template<class T>
T &VSPtr<T>::operator*() {
    return *ptr;
}
/**
 *
 * @tparam T
 * @return
 */
template<class T>
T *VSPtr<T>::operator->() {
    return ptr;
}
/**
 *
 * @tparam T
 * @return la direccion de memoria de myPtr
 */
template<class T>
T VSPtr<T>::operator&() {
    return *ptr;
}
/**
 *Esta funcion se utiliza para compar my VSPtr contra un valor primitivo
 * @tparam T
 * @param newValue el nuevo valor que va a aguarda mi ptr despues de la comparacion
 */
template<class T>
void VSPtr<T>::operator=(T newValue) {
    this->ptr = new T(newValue);
    *ptr;
    GarbageCollector::getInstance()->setMemory(ptr, ID, type);
}
/**
 *Esta funcion maneja las coparaciones entre VSPtr
 * @tparam T
 * @param vsptr returna el vsptr
 */
template<class T>
void VSPtr<T>::operator=(VSPtr vsptr) {

    GarbageCollector::getInstance()->deleteReferences(ID);
    ptr = vsptr.ptr;
    ID = vsptr.ID;
    GarbageCollector::getInstance()->addReferences(vsptr.ID);
}



template class VSPtr<int>;
template class VSPtr<std::string>;
template class VSPtr<bool>;
template class VSPtr<float>;
template class VSPtr<double>;
