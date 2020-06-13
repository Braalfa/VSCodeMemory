//
// Created by usuario on 10/6/20.
//

#include "TList.h"
/**
 * Se intancia el TList
 */
TList::TList()
{
    first = nullptr;
    largo=0;
}
/**
 * Se obtiene el primer vnodo de la TList
 * @return
 */
TNode TList::getFirst()
{
    return *this->first;
}
/**
 *
 * @param  string en su matoria el string de id
 * @return el nodo segun un valor
 */
TNode TList::getNodoVal(string val) {
    TNode *present = this->first;
    while (present != nullptr) {
        if(present->getValue() == val)
            return *present;
        else{
            present = present->next;
        }
    }
    exit(1);
}
/**
 * @param pos la posicion del nodo que quiero recivir
 * @return Obtiene el nodo segun su posicion
 */
TNode TList::getNodoPos(int pos) {
    TNode *present = this->first;
    int i=0;
    while (i != pos){
        present = present->next;
        i+=1;
    }
    return *present;
}
/**
 * Obtiene la posicion donde se encuentra el valor
 * @param value el valor del cual deseo su posicion
 * @return un entero
 */
int TList::getPos(string value) {
    TNode *present = this->first;
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
/**
 * Agrega unn valor al final de la lista
 * @param data el valor que deseo agregar
 */
void TList::addLast(string data)
{
    if(this->first == nullptr){
        this->first = new TNode(data);
        largo =+1;
    }
    else{
        TNode *present =  this->first;
        while(present->next != nullptr){
            present = present->next;
        }
        present->next = new TNode(data);
        largo =+1;
    }
}
/**
 * Elimina un nodo segun su posicion
 * @param pos la posicion del nodo que deseo eliminar
 */
void TList::deletePos(int pos) {
    TNode *temp1 = this->first;
    TNode *temp2 = this->first->next;
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
        TNode *aux = temp2;
        temp1->next = temp2->next;
        delete aux;
        largo =-1;
    }
}
/**
 * imprime la lista solo se usa con fines ilustrativos
 */
void TList::printList()
{
    TNode *present = this->first;
    cout<<"{";
    while (present != nullptr) {
        cout<<present->getValue();
        cout<<",";
        present = present->next;
    }
    cout<<"}"<<endl;
}
