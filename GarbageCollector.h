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
private:
    List *listGarbageCollector;
public:
    const int LOCAL=0;
    const int REMOTE=1;
    static int gender;
    List * getList();
    void setClient(Client client);
    void deleteReferences(int ID);
    void addReferences(int ID);
    int addNode( void* ptr, string value, string type);
    void setMemory(void *dirMemory, int ID, string value);
    void deleteVS(int ID);

    int getType();
    static GarbageCollector* setType(int type);

    static GarbageCollector* Create();
    static GarbageCollector* getInstance();

};




#endif //VSCODEMEMORY_GARBAGECOLLECTOR_H
