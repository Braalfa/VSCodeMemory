//
// Created by usuario on 10/6/20.
//

#ifndef VSCODEMEMORYLIB_TNODE_H
#define VSCODEMEMORYLIB_TNODE_H
/**
 * Clase secundaria TList que se utilisa para el manejo de informacion
 */
#include <string>
using namespace std;

class TNode {
private:
    string value;
public:
    TNode *next;
    TNode();
    TNode(string value);
    string getValue();
    void setValue(string value);
};


#endif //VSCODEMEMORYLIB_TNODE_H
