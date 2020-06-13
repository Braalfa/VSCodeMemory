//
// Created by usuario on 22/5/20.
//

#ifndef VSCODEMEMORY_VSPTR_H
#define VSCODEMEMORY_VSPTR_H

#include "GarbageCollector.h"
#include "iostream"


using namespace std;
/**
 * /**
 * La clase VSPtr se encarga de la creacion de puteros,esta maneja un valor T* de direccion de mememoria,le genera un ID
 * la cantidad de referencias  y el tipo de dato que este ocupa.
 * @tparam T tipo template para la creacion de parametros
 */
template <class T>
class VSPtr
{
private:
    T *ptr;
    int ID;
    int references;
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
    void deleteReferences();
    void addReferences();

    T &operator * ();
    T *operator -> ();
    T operator &();
    void operator =(T newValue);
    void operator =(VSPtr vsptr);
    void updateList(int i);

};

#endif //VSCODEMEMORY_VSPTR_H


