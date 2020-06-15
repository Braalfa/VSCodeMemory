//
// Created by brayan on 13/6/20.
//
#include "VSPtr.h"
#include "List.h"
#include "heap.h"
#include "thread"
int main(){

    GarbageCollector::getInstance()->getClient()->setServer("127.0.0.1","8888","pepe","myproyectpassword");
    GarbageCollector::getInstance()->getClient()->logIn();
    GarbageCollector::setType(Remote);
    VSPtr<string> v=VSPtr<string>::New();
    v="7";

    VSPtr<string> w=VSPtr<string>::New();
    w="8";

    VSPtr<string> k=VSPtr<string>::New();
    k="9";

    w=v;
    k=v;
    int i=0;
}