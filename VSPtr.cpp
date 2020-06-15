//
// Created by usuario on 22/5/20.
//

#include "VSPtr.h"
#include <typeinfo>


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

template<class T>
int VSPtr<T>::genID()
{
    static int i;
    return  ++i;
}

template<class T>
VSPtr<T>::VSPtr()
{

}

template<class T>
T *VSPtr<T>::getPtr()
{
    return ptr;
}

template<class T>
void VSPtr<T>::setPtr(T newPtr)
{
    ptr = new T(newPtr);
}

template<class T>
int VSPtr<T>::getID()
{
    return this->ID;
}

template<class T>
void VSPtr<T>::setID(int newID)
{
    this->ID = newID;
}

template<class T>
T &VSPtr<T>::operator*() {
    return *ptr;
}

template<class T>
T *VSPtr<T>::operator->() {
    return ptr;
}

template<class T>
T VSPtr<T>::operator&() {
    return *ptr;
}

template<class T>
void VSPtr<T>::operator=(T newValue) {
    this->ptr = new T(newValue);
    *ptr;
    GarbageCollector::getInstance()->setMemory(ptr, ID, type);
}

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
