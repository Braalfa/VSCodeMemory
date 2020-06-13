//
// Created by usuario on 22/5/20.
//

#include "GarbageCollector.h"
#include "iostream"


/**
 * Instaiamiento sigelton de la clase GarbageCollector
 */
GarbageCollector* GarbageCollector::instance = 0;

GarbageCollector::GarbageCollector(){
    listGarbageCollector= new List;
}

/**
 * Funcion secundaria del garbageCollector para la obtecion del sigelton
 * @return retuna una misma instancia
 */
GarbageCollector* GarbageCollector::getInstance()
{
    if (instance == 0)
    {
        instance = new GarbageCollector;
    }
    return instance;
}
/**
 * Funcion con la cual puedo obtener la lista enlazada propia de GarbageCollector
 * @return una lista enlazada
 */
List * GarbageCollector::getList() {
    return this->listGarbageCollector;
}

// Factory method to create objects of different types.
// Change is required only in this function to create a new object type

/**
 * Metodo factory que funciona para la creacion de diferentes types de garbage collectro ya sea Local o remoto
 * @param newtype
 */
void GarbageCollector::setType(GarbageType newtype){
    type=newtype;
}

/**
 * FUncion secundaria para la creacion de los 2 diferentes tipos de Garbage
 * @param client
 */
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

/**
 * Funcion que añada una refenrencia a un VSPtr en especificp
 * @param ID utilizado para la busqueda dentro de la lista
 */
void GarbageCollector::addReferences(int ID){
    if(type == Remote){
        client->addRef(to_string(ID));
    }else if(type == Local){
        getList()->addReferences(ID);
    }
    Heap::getInstance()->addRef(to_string(ID));
};
/**
 *
 * @param ptr
 * @param type
 * @return el ID con el que fue creado
 */
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
/**
 * Cambia la direccion de memeoria el VSPtr
 * @param dirMemory la nueva direccion de memoria
 * @param ID el ID unico del VSPtr del cual voy a cambiar el dato
 * @param theType y el tipo de dato
 */
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
/**
 * Elimina un VSPtr de la lista
 * @param ID el ID unico del VSPtr el cual quiero eliminar
 */
void GarbageCollector::deleteVS(int ID){
    string id = to_string(ID);
    Heap::getInstance()->deleteVSptr(to_string(ID));

};
