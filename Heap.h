//
// Created by usuario on 10/6/20.
//

#ifndef VSCODEMEMORYLIB_HEAP_H
#define VSCODEMEMORYLIB_HEAP_H


#include <string>
#include "TNode.cpp"
#include "TNode.h"
#include "TList.cpp"
#include "TList.h"
using namespace std;

class Heap
{

private:
    Heap();
    static Heap*instance;
public:
    static Heap *getInstance();

    TList<string> idList;
    TList<string> addreesList;
    TList<string> typeList;
    TList<string> dataList;
    TList<string> referencesList;
    void addVSptr(string id, string address, string type, string data,string references);
    void deleteVSptr(string id);
    void addRef(string id);
    void deleteRef(string id);
    void update(string id, string value);
    string updatePanelList();
};


#endif //VSCODEMEMORYLIB_HEAP_H
