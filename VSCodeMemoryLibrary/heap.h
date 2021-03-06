#ifndef VSCODEMEMORYLIB_HEAP_H
#define VSCODEMEMORYLIB_HEAP_H


#include <string>
#include "TNode.h"
#include "TList.h"
#include <mutex>

using namespace std;

class Heap
{

private:
    Heap();
    static Heap*instance;
    static std::mutex mutex;
/**
 * El heap es una copia de la lista que nos permite un mejor manejo de los datos a visaluzar en la interfaz
 */
public:
    static Heap *getInstance();
    TList idList;
    TList addreesList;
    TList typeList;
    TList dataList;
    TList referencesList;
    void addVSptr(string id, string type, string data);
    void deleteVSptr(string id);
    void addRef(string id);
    void deleteRef(string id);
    void update(string id, string value, string address);

    string updatePanelList();
};


#endif //VSCODEMEMORYLIB_HEAP_H
