//
// Created by usuario on 22/5/20.
//

#include "GarbageCollector.h"
#include "iostream"



GarbageCollector* GarbageCollector::instance = 0;
GarbageCollector::GarbageCollector(){
    listGarbageCollector= new List;
}
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

class LocalGarbageCollector : public GarbageCollector {
public:
    LocalGarbageCollector(){
        listGarbageCollector= new List;
    };

    void deleteReferences(int ID) override{
        getList()->deleteReferences(ID);
    }

    int addNode(void* ptr, string value, string type) override{
        int id =getList()->addNode(ptr);
        Heap::getInstance()->addVSptr(to_string(id), *static_cast<std::string*>(ptr), type, value, "1" );
        return id;
    }
    void addReferences(int ID) override{
        getList()->addReferences(ID);
    }
    void setMemory(void *dir, int ID, string value) override {
        string ptrS;
        return getList()->getNode(ID).setDirMemory(dir);
    }
    void deleteVS(int ID)override{}
};

class RemoteGarbageCollector : public GarbageCollector {
public:
    RemoteGarbageCollector(){
        listGarbageCollector= new List;
    };

    void deleteReferences(int ID)override{
        client->delRef(to_string(ID));
    }
    void addReferences(int ID)override{
        client->addRef(to_string(ID));
    }
    int addNode(void *ptr, string value, string type)override{
        client->newVSptr(value, type);
    }
    void setMemory(void* dir, int ID, string value)override{
        client->update(to_string(ID), value);
    }
    void deleteVS(int ID)override
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
