//
// Created by usuario on 10/6/20.
//

#include "Heap.h"

Heap* Heap::instance = nullptr;

Heap *Heap::getInstance() {
    if(!instance){
        instance = new Heap();
    }
    return instance;
}

void Heap::addVSptr(string id, string address, string type, string data,string references){
    idList.addLast(id);
    addreesList.addLast(address);
    typeList.addLast(type);
    dataList.addLast(data);
    referencesList.addLast(references);
}

void Heap::deleteVSptr(string id){
    int i = idList.getPos(id);
    idList.deletePos(i);
    addreesList.deletePos(i);
    typeList.deletePos(i);
    dataList.deletePos(i);
    referencesList.deletePos(i);
}

void Heap::addRef(string id){
    int i  = idList.getPos(id);
    string actual = referencesList.getNodoPos(i).getValue();
    int actualInt = stoi(actual);
    actualInt +=1;
    string newString = to_string(actualInt);
    referencesList.getNodoPos(i).setValue(newString);
}

void Heap::deleteRef(string id){
    int i  = idList.getPos(id);
    string actual = referencesList.getNodoPos(i).getValue();
    int actualInt = stoi(actual);
    actualInt -=1;
    string newString = to_string(actualInt);
    referencesList.getNodoPos(i).setValue(newString);
}

void Heap::update(string id, string value){
    int i = idList.getPos(id);
    dataList.getNodoPos(i).setValue(value);
}

string Heap::updatePanelList() {
    string newPanelList;
    int pos;
    while (pos != idList.largo-1){
        newPanelList += idList.getNodoPos(pos).getValue();
        newPanelList += ";";
        pos +=1;
    }
    pos = 0;
    while (pos != idList.largo-1){
        newPanelList += addreesList.getNodoPos(pos).getValue();
        newPanelList += ";";
        pos +=1;
    }
    pos = 0;
    while (pos != idList.largo-1) {
        newPanelList += typeList.getNodoPos(pos).getValue();
        newPanelList += ";";
        pos +=1;
    }
    pos = 0;
    while (pos != idList.largo-1){
        newPanelList += dataList.getNodoPos(pos).getValue();
        newPanelList += ";";
        pos +=1;
    }
    pos = 0;
    while (pos != idList.largo-1) {
        newPanelList += referencesList.getNodoPos(pos).getValue();
        newPanelList += ";";
    }
    return newPanelList;
}

Heap::Heap() {

}


#include "Heap.h"
