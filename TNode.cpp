//
// Created by usuario on 10/6/20.
//

#include "TNode.h"
#include "iostream"

using namespace std;
/**
 * Inicalisa la funcion TNode
 */
TNode::TNode()
{
    next = nullptr;
}

/**
 * Se crea un nuevo TNode
 * @param data
 */
TNode::TNode(string data)
{
    next = nullptr;
    value = data;
}

/**
 * se obitiene el valor del Tnodo
 * @return valor del Tnodo
 */
string TNode::getValue()
{
    return  value;
}
/**
 * Se modifica el valor el node
 * @param data nuevo valor para TNode
 */
void TNode::setValue(string data) {
    this->value = data;
}
