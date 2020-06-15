#include <thread>
#include "heap.h"
#include "Reader.h"
#include <mutex>

Heap* Heap::instance = nullptr;
/**
 *Intstacia el heap
 * @return
 */
Heap *Heap::getInstance() {
    if(!instance){
        instance = new Heap();
    }
    return instance;
}
/**
 *Añade a cada tipo de lista la informacion de un nuevo nodo
 * @param id el ide delVSPtr
 * @param type el tipo de dato del VSPtr
 * @param data el valor de la direccion de memeoria
 */
void Heap::addVSptr(string id, string type, string data){
    idList.addLast(id);
    addreesList.addLast("null");
    typeList.addLast(type);
    dataList.addLast("");
    referencesList.addLast("1");
    updatePanelList();
}
/**
 *ELimina un nodo
 * @param id el ID del nodo que va a ser eliminado
 */
void Heap::deleteVSptr(string id){
    int i = idList.getPos(id);
    idList.deletePos(i);
    addreesList.deletePos(i);
    typeList.deletePos(i);
    dataList.deletePos(i);
    referencesList.deletePos(i);
    updatePanelList();
}
/**
 *suma una refenrencia a un nodp especifico
 * @param id el id del nodo que quiero agregar una referncia
 */
void Heap::addRef(string id){
    int i  = idList.getPos(id);
    string actual = referencesList.getNodoPos(i)->getValue();
    int actualInt = stoi(actual);
    actualInt +=1;
    string newString = to_string(actualInt);
    referencesList.getNodoPos(i)->setValue(newString);
    updatePanelList();
}
/**
 * ELimina una referencia
 * @param id el ID del nodo al cual quuiero eliminar una referencia
 */
void Heap::deleteRef(string id){
    int i  = idList.getPos(id);
    if(i==-1){
        return;
    }
    string actual = referencesList.getNodoPos(i)->getValue();
    int actualInt = stoi(actual);
    actualInt -=1;
    string newString = to_string(actualInt);
    referencesList.getNodoPos(i)->setValue(newString);
    updatePanelList();
}
/**
 * Llama a actualisa la lsita para dar nunva infromacion cuando se porduce un cambio en algun vsptr
 * @param id el id del nodo
 * @param value el valor de la direccion
 * @param address direccion de memeoria a actualizar
 */
void Heap::update(string id, string value, string address){
    int i = idList.getPos(id);
    dataList.getNodoPos(i)->setValue(value);
    addreesList.getNodoPos(i)->setValue(address);
    updatePanelList();
}
/**
 * Acutaliza la lista con nuevos parametros
 * @return returna un string con la informacion que alamecena
 */
string Heap::updatePanelList() {
    string newPanelList;
    int pos=0;
    while (pos != idList.largo) {
        newPanelList += idList.getNodoPos(pos)->getValue()+";";
        newPanelList += addreesList.getNodoPos(pos)->getValue()+";";
        newPanelList += typeList.getNodoPos(pos)->getValue()+";";
        newPanelList += dataList.getNodoPos(pos)->getValue()+";";
        newPanelList += referencesList.getNodoPos(pos)->getValue()+";";
        pos += 1;
    }
    Reader::setData(newPanelList);
    this_thread::sleep_for(chrono::milliseconds(500));
    return newPanelList;
}
/**
 * Incialisa la clase heap y las listas que este maneja
 */
Heap::Heap() {
    idList = *new TList;
    addreesList = *new TList;
    typeList = *new TList;
    dataList = *new TList;
    referencesList = *new TList;
}
