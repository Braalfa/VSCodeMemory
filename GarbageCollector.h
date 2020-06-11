//
// Created by usuario on 10/6/20.
//

#ifndef VSCODEMEMORYLIB_GARBAGECOLLECTOR_H
#define VSCODEMEMORYLIB_GARBAGECOLLECTOR_H

#include "Client.h"
#include "VSPtr.h"
#include "List.h"
#include <string>
#include "thread"
#include "chrono"


using namespace std;



enum GarbageType {
    Local,    Remote
};

class GarbageCollector
{
protected:
    GarbageCollector();
    static GarbageCollector *instance;
    Client *client;

private:
    List *listGarbageCollector;
public:

    List * getList();
    void setClient(Client *client);

    void deleteReferences(int ID);
    void addReferences(int ID);
    int addNode( void* ptr, string value, string type);
    void setMemory(void *dirMemory, int ID, string value);
    void deleteVS(int ID);

    static GarbageType type;
    static void setType(GarbageType newtype);
    static GarbageCollector* Create();
    static GarbageCollector* getInstance();

    void runthread();
};

 

#endif //VSCODEMEMORYLIB_GARBAGECOLLECTOR_H
