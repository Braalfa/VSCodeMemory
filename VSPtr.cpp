//
// Created by usuario on 22/5/20.
//

#include "VSPtr.h"
#include <typeinfo>
#include <GarbageCollector.h>

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
    newVSPtr.ID = g.addNode(newVSPtr.ptr, "",name);
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

    void *vp = static_cast<void*>(ptr);
    value = *static_cast<std::string*>(vp);
    ptr= &newValue;
    GarbageCollector::getInstance()->setMemory(ptr, ID, value);
}

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


template <class T>
int VSPtr<T>::getReferences()
{
    return this->references;
}

template<class T>
void VSPtr<T>::deleteReferences()
{
    this->references = references - 1;
}

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
