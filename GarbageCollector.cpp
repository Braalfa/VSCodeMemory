//
// Created by usuario on 22/5/20.
//

#include "GarbageCollector.h"
#include "client.h"
GarbageCollector* GarbageCollector::instance = 0;

GarbageCollector::GarbageCollector(){}



GarbageCollector* GarbageCollector::getInstance()
{
    if (instance == 0)
    {
        instance = Create();
    }
    return instance;
}

GarbageCollector *GarbageCollector::setType(GarbageType newtype)
{
    type = newtype;
}

List * GarbageCollector::getList() {
    return this->listGarbageCollector;
}


class LocalGarbageCollector : public GarbageCollector {
public:
    LocalGarbageCollector();

    void deleteReferences(int ID){
        getList()->deleteReferences(ID);
    }
    int addNode(void* ptr, string value, string type){
        getList()->addNode(ptr);
    }
    void addReferences(int ID){
        getList()->addReferences(ID);
    }
    void setMemory(void *dir, int ID, string value){
        return getList()->getNode(ID).setDirMemory(dir);
    }
    void update(string ID, string value){}
};

class RemoteGarbageCollector : public GarbageCollector {
private:
    Client* client=new Client;
public:
    RemoteGarbageCollector();

    void deleteReferences(int ID){
        client->delRef(to_string(ID));
    }
    void addReferences(int ID){
        client->addRef(to_string(ID));
    }
    int addNode(void *ptr, string value, string type){
        client->newVSptr(value, type);
    }
    void setMemory(void* dir, int ID, string value){
        client->update(to_string(ID), value);
    }
};


// Factory method to create objects of different types.
// Change is required only in this function to create a new object type
GarbageCollector* GarbageCollector::Create() {
    if (type == Local)
        return new LocalGarbageCollector();
    else if (type= Remote)
        return new RemoteGarbageCollector();
    else return NULL;
}


GarbageType GarbageCollector::getType(){
    return type;
}
