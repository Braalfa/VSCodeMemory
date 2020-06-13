//
// Created by usuario on 25/5/20.
//

#include "Node.h"
/**
 * returna la direccion de mmeoria  del VSPtr
 * @return
 */
void *Node::getDirMemory()  {
    return dirMemory;
}
/**
 * cambia el valor de la direccion de memeoria del VSPtr
 * @param dirMemory
 */
void Node::setDirMemory(void *dirMemory) {
    this->dirMemory = dirMemory;
}
/**
 * Obtiene la cantidad de referencias del VSPtr
 * @return
 */
int Node::getReferences() {
    return this->references;
}
/**
 * Elimina unareferencias dento del VSPtr
 */
void Node::deleteReferences() {
    this->references = references-1;
}
/**
 * Agrega una referenciaas dentro de VSPtr
 */
void Node::addReferences() {
    this->references = references+1;

}
/**
 * Se intancia el nodo
 */
Node::Node() {
    next = nullptr;
}
/**
 * Se intancia el nodo con una direccion de memoria
 * @param dirMemory
 */
Node::Node(void *dirMemory) {
    next = nullptr;
    this->dirMemory = dirMemory;
    this->ID = generateID();
    this->references = 1;
}
/**
 * Genera el ID
 * @return
 */
int Node::generateID() {
    static int i;
    return ++i;
}
/**
 * Obtiene el ID
 * @return
 */
int Node::getID() {
    return this->ID;
}
