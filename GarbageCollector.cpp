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
        instance = new GarbageCollector;
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


void GarbageCollector::setClient(Client client){

};
void GarbageCollector::deleteReferences(int ID){
    if(type == Remote){
        client->delRef(to_string(ID));
    }else if(type == Local){
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
        id =getList()->addNode(ptr);
    }
    Heap::getInstance()->addVSptr(to_string(id), "null", type);
    return id;
};

void GarbageCollector::setMemory(void *dirMemory, int ID, string theType){
    string address;
    string value;
    if(theType=="string"){
        value = *static_cast<std::string*>(dirMemory);
    }else if(theType=="bool"){
        value = to_string(*static_cast<bool*>(dirMemory));
    }else if(theType=="double"){
        value = to_string(*static_cast<double*>(dirMemory));;
    }else if(theType=="int"){
        value = to_string(*static_cast<int*>(dirMemory));
    }else if(theType=="float"){
        value = to_string(*static_cast<float*>(dirMemory));
    }

    if(type ==Remote){
       address=client->update(to_string(ID), value);
    }else if(type==Local){
       getList()->getNode(ID).setDirMemory(dirMemory);
       std::stringstream address;
       address << dirMemory;
       std::string str = address.str();
    }

    Heap::getInstance()->update(to_string(ID), value, address);

};

void GarbageCollector::deleteVS(int ID){
    string id = to_string(ID);
    Heap::getInstance()->deleteVSptr(to_string(ID));

};
