//
// Created by usuario on 22/5/20.
//

#ifndef VSCODEMEMORY_GARBAGECOLLECTOR_H
#define VSCODEMEMORY_GARBAGECOLLECTOR_H


#include "VSPtr.h"
#include "List.h"
/*
 * Aqui arriba va la clase sujeto del GarbageCollector, pero me puse a programar esa lista de mierda.
 *
 */

using namespace std;
#include <string>



enum GarbageType {
    Local,    Remote
};


class GarbageCollector
{
private:
    GarbageCollector();
    static GarbageCollector *instance;

    List *listGarbageCollector;
public:
    static GarbageType type;
    List * getList();
    void deleteReferences(int ID);
    void addReferences(int ID);
    int addNode( void* ptr, string value, string type);
    void setMemory(void *dirMemory, int ID, string value);
    static GarbageType getType();
    static GarbageCollector* setType(GarbageType type);

    static GarbageCollector* Create();
    static GarbageCollector* getInstance();

};


#endif //VSCODEMEMORY_GARBAGECOLLECTOR_H
