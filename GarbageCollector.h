//
// Created by usuario on 22/5/20.
//

#ifndef VSCODEMEMORY_GARBAGECOLLECTOR_H
#define VSCODEMEMORY_GARBAGECOLLECTOR_H


#include "VSPtr.h"
#include "List.h"
#include "client.h"

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
protected:
    Client* client;
    GarbageCollector();
    static GarbageCollector *instance;
    List *listGarbageCollector;

public:
    List * getList();

    virtual void setClient(Client client);
    virtual void deleteReferences(int ID);
    virtual void addReferences(int ID);
    virtual int addNode( void* ptr, string value, string type);
    virtual void setMemory(void *dirMemory, int ID, string value);
    virtual void deleteVS(int ID);

    static GarbageType type;
    static void setType(GarbageType newtype);
    static GarbageCollector* Create();
    static GarbageCollector* getInstance();
};



#endif //VSCODEMEMORY_GARBAGECOLLECTOR_H
