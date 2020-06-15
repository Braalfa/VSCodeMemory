//
// Created by usuario on 22/5/20.
//

#include "GarbageCollector.h"
#include "iostream"
#include "Reader.h"

GarbageType GarbageCollector::type;
GarbageCollector* GarbageCollector::instance = 0;

GarbageCollector::GarbageCollector(){
    listGarbageCollector= new List;
    client=new Client;
    if(Reader::isLocal()){
       type=Local;
    }else{
        Reader::setClientSettings(client);
        if(client->logIn()==-1){
            type=Local;
        }else{
            type=Remote;
        }
    }
}


GarbageCollector* GarbageCollector::getInstance()
{
    if (instance == 0)
    {
        instance = new GarbageCollector;
        if(type==Local) {
            std::thread first(&GarbageCollector::threadRun, instance);
            first.detach();
        }
    }
    return instance;
}

List * GarbageCollector::getList() {
    return this->listGarbageCollector;
}

// Factory method to create objects of different types.
// Change is required only in this function to create a new object type


void GarbageCollector::setType(GarbageType newtype){
    type=newtype;
}

void GarbageCollector::deleteReferences(int ID){
    if(type == Remote){
        bool empty=client->delRef(to_string(ID));
        if(empty){
            Heap::getInstance()->deleteVSptr(to_string(ID));
        }
    }else if(type == Local) {
        getList()->deleteReferences(ID);
    }
    Heap::getInstance()->deleteRef(to_string(ID));

};

void GarbageCollector::addReferences(int ID){
    if(type == Remote){
        client->addRef(to_string(ID));
    }else if(type == Local){
        getList()->addReferences(ID);
    }
    Heap::getInstance()->addRef(to_string(ID));
};

int GarbageCollector::addNode( void* ptr, string type){
    int id=-1;
    if(GarbageCollector::type == Remote){
        id=stoi(client->newVSptr(type));

    }else if(GarbageCollector::type == Local){
        id =getList()->addNode(ptr, type);
    }
    Heap::getInstance()->addVSptr(to_string(id), type, "");
    return id;
};

void GarbageCollector::setMemory(void *dirMemory, int ID, string theType){

    string address;
    string value;
    if(theType=="b"){
        value = to_string(*static_cast<bool*>(dirMemory));
    }else if(theType=="d"){
        value = to_string(*static_cast<double*>(dirMemory));;
    }else if(theType=="i"){
        value = to_string(*static_cast<int*>(dirMemory));
    }else if(theType=="f"){
        value = to_string(*static_cast<float*>(dirMemory));
    }else{
        theType="string";
        value = *static_cast<std::string*>(dirMemory);
    }

    if(type ==Remote){
       address=client->update(to_string(ID), value, theType);
    }else if(type==Local){
       getList()->getNode(ID)->setDirMemory(dirMemory);

        std::ostringstream addressh;
        addressh<< dirMemory;
        address = addressh.str();
    }

    Heap::getInstance()->update(to_string(ID), value, address);
};

void GarbageCollector::deleteVS(int ID){
    string id = to_string(ID);
    string theType = getList()->getNode(ID)->getType();

    void* dirMemory= getList()->getNode(ID)->getDirMemory();
    if(theType=="b"){
        delete (static_cast<bool*>(dirMemory));
    }else if(theType=="d"){
        delete static_cast<double*>(dirMemory);;
    }else if(theType=="i"){
        delete static_cast<int*>(dirMemory);
    }else if(theType=="f"){
        delete static_cast<float*>(dirMemory);
    }else{
        delete static_cast<std::string*>(dirMemory);
    }

    getList()->deleteNode(ID);
    Heap::getInstance()->deleteVSptr(to_string(ID));
}

Client* GarbageCollector::getClient() {
    return this->client;
}

[[noreturn]] void GarbageCollector::threadRun() {
    Node *present = getList()->getFirst();
    while(true){
        while (present != nullptr) {
            if (present->getReferences() == 0) {
                    deleteVS(present->getID());
            }
            present = present->next;
        }
        present = getList()->getFirst();
        this_thread::sleep_for (chrono::milliseconds (250));
    }
};
