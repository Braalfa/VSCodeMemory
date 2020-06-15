//
// Created by usuario on 22/5/20.
//

#ifndef VSCODEMEMORY_GARBAGECOLLECTOR_H
#define VSCODEMEMORY_GARBAGECOLLECTOR_H


#include "VSPtr.h"
#include "List.h"
#include "client.h"
#include "thread"
#include "chrono"

using namespace std;
#include <string>



enum GarbageType {
    Local,    Remote
};
/**
 * El garbage collector es la clase donde se manejan mis VSPtr esta gurada informacion y esta al tanto sobre la modificacion
 * de la informacion de esta o en caso de que nadie este referenciado a un VSPtr en especifico lo elimina
 */
class GarbageCollector
{
protected:
    Client* client;
    GarbageCollector();
    static GarbageCollector *instance;
    List *listGarbageCollector;

public:
    List * getList();

    void setClient(Client client);
    void deleteReferences(int ID);
    void addReferences(int ID);
    int addNode( void* ptr, string type);
    void setMemory(void *dirMemory, int ID, string type);
    void deleteVS(int ID);

    [[noreturn]] void threadRun();
    Client *getClient();

    static std::mutex mutex;
    static GarbageType type;
    static void setType(GarbageType newtype);
    static GarbageCollector* Create();
    static GarbageCollector* getInstance();

    void deleteVS(int ID, List *l);
};


#endif //VSCODEMEMORY_GARBAGECOLLECTOR_H
