//
// Created by usuario on 10/6/20.
//

#include "VSPtr.h"
#include <typeinfo>
GarbageCollector* garbageCollector = GarbageCollector::getInstance();

template<class T>
VSPtr<T> VSPtr<T>::New()
{
    VSPtr<T> newVSPtr= new VSPtr<T>;
    newVSPtr.references = 1;
    if(GarbageCollector::type==Local){
        newVSPtr.ptr = nullptr;
    }
    newVSPtr.ID = garbageCollector->addNode(newVSPtr.ptr, &newVSPtr.ptr,type_info(*newVSPtr.ptr).name());
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
    ptr = new T(newValue);

    garbageCollector->getList()->setMemory(ptr);
}

template<class T>
void VSPtr<T>::operator=(VSPtr vsptr) {
    if(references == 1){
        garbageCollector->deleteVS(getID());
    }
    garbageCollector->deleteReferences(ID);
    ptr = vsptr.ptr;
    ID = vsptr.ID;
    garbageCollector->addReferences(vsptr.ID);
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
