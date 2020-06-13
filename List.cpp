//
// Created by usuario on 25/5/20.
//

#include "List.h"
#include "iostream"

using namespace std;

/**
 *
 * @return el primer dato del Nodo
 */
Node *List::getFirst()  {
    return first;
}
/**
 *
 * @param dirMemory direccion de mememoria donde se encuentra el VSPtr
 * @return
 */
int List::addNode(void *dirMemory) {
    if(this->first == nullptr){
        this->first = new Node(dirMemory);
        return this->first->getID();
    }
    else{
        Node *present = this->first;
        while(present->next != nullptr){
            present = present->next;
        }
        present->next = new Node(dirMemory);
        return present->next->getID();

    }
}
/**
 * Imprime la lista en pantalla solo se utiliza de forma ilustratiba
 */
void List::printList() {
    Node *present = this->first;
    cout<<"{";
    while (present != nullptr) {
        cout<<present->getDirMemory();
        cout<<"->";
        cout<<present->getReferences();
        cout<<"->";
        cout<<present->getID();
        cout<<"/";
        present = present->next;
    }
    cout<<"}";
}
/**
 *Se sintancia la Lista
 */
List::List() {
    first= nullptr;
}
/**
 *Elimina un Nodo segun su ID
 * @param ID id del nodo que deseo eliminar
 */
void List::deleteNode(int ID) {
    Node *temp1 = this->first;
    Node *temp2 = this->first->next;
    if(temp1->getID() == ID){
        this->first = temp1->next;
    }
    else{
        while(temp2->getID() != ID){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        Node *aux = temp2;
        temp1->next = temp2->next;
        delete aux;
    }
}

/**
 *Otiene un nodo con su ID
 * @param ID el ID del VSPtr del nodo que quiero recibir
 * @return
 */
Node List::getNode(int ID) {
    Node *present = this->first;
    while (present != nullptr){
        if(present->getID() == ID){
            return present;
        } else{
            present = present->next;
        }
        exit(1);
    }
    return present;
}
/**
 *Se eliminar una referencia del VSPtr
 * @param ID el Id especifico del nodo que queiro eliminar la refenrcia
 */
void List::deleteReferences(int ID) {
    Node present = getNode(ID);
    present.addReferences();
}
/**
 *Se añade una referencias A UN VSPtr especifico
 * @param ID el paramento ID del VSPtr al cua quiero agregra una referencia
 */
void List::addReferences(int ID) {
    Node present = getNode(ID);
    present.deleteReferences();
}
/**
 *Se cambia el valo de la direcciond de Memoria en la Lista
 * @param dirMemory la nueva direccion de memoria
 * @param ID el ID qdel VSPtr que quiero cambiar
 */
void List::setMemory(void *dirMemory, int ID) {
    Node present = getNode(ID);
    present.setDirMemory(dirMemory);
}
