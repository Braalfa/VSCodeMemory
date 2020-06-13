//
// Created by brayan on 13/6/20.
//
#include "VSPtr.h"
#include "List.h"
#include "heap.h"
int main(){
    VSPtr<int> v=VSPtr<int>::New();
    v=7;
    VSPtr<int> j=VSPtr<int>::New();
    j=8;
    VSPtr<int> m=VSPtr<int>::New();
    m=9;

    v=j;
    m=v;

    v=10;

    int o= &v;
    int u= *v;

    Heap h=*Heap::getInstance();

    List l=*GarbageCollector::getInstance()->getList();

    cout<<"Heap"<<endl;
    h.idList.printList();
    h.addreesList.printList();
    h.dataList.printList();
    h.referencesList.printList();
    h.typeList.printList();
   cout<<h.idList.largo<<endl;
}