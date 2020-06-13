//
// Created by usuario on 10/6/20.
//

#ifndef VSCODEMEMORYLIB_TLIST_H
#define VSCODEMEMORYLIB_TLIST_H


#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "TNode.h"
#include <string>
using namespace std;
/**
 * Lista que es instancida en la clase heap para el manejo de paramentros
 */
class TList
{
private:
    TNode *first;
public:
    int largo;
    TList();
    TNode getFirst();
    TNode getNodoPos(int pos);
    TNode getNodoVal(string val);
    int getPos(string value);
    void addLast(string data);
    void deletePos(int pos);
    void printList();
};


#endif //VSCODEMEMORYLIB_TLIST_H
