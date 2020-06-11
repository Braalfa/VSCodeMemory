//
// Created by usuario on 10/6/20.
//


#include "GarbageCollector.h"
#include "iostream"



GarbageCollector* GarbageCollector::instance = 0;
GarbageType GarbageCollector::type;




GarbageCollector::GarbageCollector(){}



GarbageCollector* GarbageCollector::getInstance()
{
    if (instance == 0)
    {
        instance = Create();
    }
    return instance;
}

List * GarbageCollector::getList() {
    return this->listGarbageCollector;
}


void GarbageCollector::setClient(Client *client){
    this->client = client;
}

class LocalGarbageCollector : public GarbageCollector {
public:
    LocalGarbageCollector(){};

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
    void deleteVS(int ID){}
};

class RemoteGarbageCollector : public GarbageCollector {
public:
    RemoteGarbageCollector(){};

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
    void deleteVS(int ID)
    {
        string id = to_string(ID);

    }

};

// Factory method to create objects of different types.
// Change is required only in this function to create a new object type

GarbageCollector* GarbageCollector::Create() {
    if (type == Local)
        return new LocalGarbageCollector();
    else if (type== Remote)
        return new RemoteGarbageCollector();
    else return NULL;
}

void GarbageCollector::setType(GarbageType newtype){
    if(instance!=nullptr){
        if(newtype==Local){
            instance = new LocalGarbageCollector();
        }else{
            instance = new RemoteGarbageCollector();
        }
    }
    type=newtype;
}

void GarbageCollector::runthread() {
    this_thread::sleep_for (chrono::seconds(2));
    Node *present = getList()->getFirst();
    while (present != nullptr){
        if(present->getReferences() == 0){
            getList()->deleteNode(present->getID());

        }
        present = present->next;
    }
}
