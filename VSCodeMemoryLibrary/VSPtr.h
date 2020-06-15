//
// Created by usuario on 22/5/20.
//

#ifndef VSCODEMEMORY_VSPTR_H
#define VSCODEMEMORY_VSPTR_H

#include "GarbageCollector.h"
#include "iostream"

using namespace std;

/**
 * La clase VSPtr va a simular el funcionamiento de un puntero,dicha clase va a almacenar un ID,el tipo de de dato que guarda
 * el ptr y el valor de este.
 * @tparam T este parametro determinar el tipo de dato con el que se va a trabajar ya sea int,bool,doubles,string ...
 */
template <class T>
class VSPtr
{
private:
    T *ptr;
    int ID;
    string type;
    string value;
public:
    //Y new
    static VSPtr<T> New();
    static int genID();
    VSPtr();
    T* getPtr();
    void setPtr(T newPtr);


    int getID();
    void setID(int newID);

    int getReferences();

    T &operator * ();
    T *operator -> ();
    T operator &();
    void operator =(T newValue);
    void operator =(VSPtr vsptr);
    void updateList(int i);

};

#endif //VSCODEMEMORY_VSPTR_H


