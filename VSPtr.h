//
// Created by usuario on 22/5/20.
//

#ifndef VSCODEMEMORY_VSPTR_H
#define VSCODEMEMORY_VSPTR_H

#include "GarbageCollector.h"
#include "iostream"


using namespace std;

template <class T>
class VSPtr
{
private:
    T *ptr;
    int ID;
public:
    //Y new
    static VSPtr<T> New();
    static int genID();
    VSPtr();
    T* getPtr();
    void setPtr(T newPtr);


    int getID();
    void setID(int newID);

    T &operator * ();
    T *operator -> ();
    T operator &();
    void operator =(T newValue);
    void operator =(VSPtr vsptr);
    void updateList(int i);

};

#endif //VSCODEMEMORY_VSPTR_H
