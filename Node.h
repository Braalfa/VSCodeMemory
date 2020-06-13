//
// Created by usuario on 25/5/20.
//

#ifndef VSCODEMEMORY_NODE_H
#define VSCODEMEMORY_NODE_H

/**
 * La clase nodo donde guradaremos los datos del vsptr y donde hremos modificaciones en la lsita del
 * GarbageCollecotr
 */
class Node {
private:
    void* dirMemory ;
    int references;
    int ID;

public:
    static int generateID();

    Node *next;
    Node();
    Node(void *dirMemory);

    void *getDirMemory();
    void setDirMemory(void *dirMemory);

    int getID();
    int getReferences();

    void deleteReferences();
    void addReferences();

};

#endif //VSCODEMEMORY_NODE_H
