//
// Created by usuario on 10/6/20.
//

#include "TList.h"

template<typename  T>
TList<T>::TList()
{
    first = nullptr;
}

template<typename  T>
TNode<T> TList<T>::getFirst()
{
    return *this->first;
}

template<class T>
TNode<T> TList<T>::getNodoVal(T val) {
    TNode<T> *present = this->first;
    while (present != nullptr) {
        if(present->getValue() == val)
            return *present;
        else{
            present = present->next;
        }
    }
    exit(1);
}

template<class T>
TNode<T> TList<T>::getNodoPos(int pos) {
    TNode<T> *present = this->first;
    int i;
    while (i != pos){
        present = present->next;
        i+=1;
    }
    return *present;
}
template<class T>
int TList<T>::getPos(T value) {
    TNode<T> *present = this->first;
    int i = 0;
    while (present != nullptr) {
        if(present->getValue() == value)
            return i;
        else{
            present = present->next;
            i+=1;
        }
    }
    exit(1);
}

template<typename  T>
void TList<T>::addLast(T data)
{
    if(this->first == nullptr){
        this->first = new TNode<T>(data);
        largo =+1;
    }
    else{
        TNode<T> *present =  this->first;
        while(present->next != nullptr){
            present = present->next;
        }
        present->next = new TNode<T>(data);
        largo =+1;
    }
}
template<class T>
void TList<T>::deletePos(int pos) {
    TNode<T> *temp1 = this->first;
    TNode<T> *temp2 = this->first->next;
    if(pos == 0){
        this->first = temp1->next;
        largo =-1;
    }
    else{
        int  i = 0;
        while (i != pos){
            temp1 = temp1->next;
            temp2 = temp2->next;
            i=+1;
        }
        TNode<T> *aux = temp2;
        temp1->next = temp2->next;
        delete aux;
        largo =-1;
    }
}

template<typename  T>
void TList<T>::printList()
{
    TNode<T> *present = this->first;
    cout<<"{";
    while (present != nullptr) {
        cout<<present->getValue();
        cout<<",";
        present = present->next;
    }
    cout<<"}"<<endl;
}



