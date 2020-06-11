//
// Created by usuario on 10/6/20.
//

#include "TNode.h"
#include "iostream"

using namespace std;

template<typename  T>
TNode<T>::TNode()
{
    next = nullptr;
}


template<typename  T>
TNode<T>::TNode(T data)
{
    next = nullptr;
    value = data;
}


template<typename  T>
T TNode<T>::getValue()
{
    return  value;
}

template<typename  T>
void TNode<T>::setValue(T data) {
    this->value = data;
}