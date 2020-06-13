//
// Created by usuario on 22/5/20.
//

#ifndef VSCODEMEMORY_GARBAGECOLLECTOR_H
#define VSCODEMEMORY_GARBAGECOLLECTOR_H


#include "VSPtr.h"
#include "List.h"
#include "client.h"



using namespace std;
#include <string>

/**
 *  * GarbageCollector es una clase la cual controla la cantidad de refenencias cuando se crea una varibale cuano se cambia
 * el valor de una varibale , cuando se elimina las variables.
 * Eete Grabage collector puede variar por un metodo facade que se utiliza para la creacion de garbageCollecotrs locales o
 * remotos segun la preferencia del usuario
 */

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

    void setClient(Client client);
    void deleteReferences(int ID);
    void addReferences(int ID);
    int addNode( void* ptr, string type);
    void setMemory(void *dirMemory, int ID, string type);
    void deleteVS(int ID);

    static GarbageType type;
    static void setType(GarbageType newtype);
    static GarbageCollector* Create();
    static GarbageCollector* getInstance();
};


#endif //VSCODEMEMORY_GARBAGECOLLECTOR_H
