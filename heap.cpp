#include <thread>
#include "heap.h"
#include "Reader.h"

Heap* Heap::instance = nullptr;

Heap *Heap::getInstance() {
    if(!instance){
        instance = new Heap();
    }
    return instance;
}

void Heap::addVSptr(string id, string type, string data){
    idList.addLast(id);
    addreesList.addLast("null");
    typeList.addLast(type);
    dataList.addLast("");
    referencesList.addLast("1");
    updatePanelList();
}

void Heap::deleteVSptr(string id){
    int i = idList.getPos(id);
    idList.deletePos(i);
    addreesList.deletePos(i);
    typeList.deletePos(i);
    dataList.deletePos(i);
    referencesList.deletePos(i);
    updatePanelList();
}

void Heap::addRef(string id){
    int i  = idList.getPos(id);
    string actual = referencesList.getNodoPos(i)->getValue();
    int actualInt = stoi(actual);
    actualInt +=1;
    string newString = to_string(actualInt);
    referencesList.getNodoPos(i)->setValue(newString);
    updatePanelList();
}

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

void Heap::update(string id, string value, string address){
    int i = idList.getPos(id);
    dataList.getNodoPos(i)->setValue(value);
    addreesList.getNodoPos(i)->setValue(address);
    updatePanelList();
}

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

Heap::Heap() {
    idList = *new TList;
    addreesList = *new TList;
    typeList = *new TList;
    dataList = *new TList;
    referencesList = *new TList;
}
