//
// Created by brayan on 13/6/20.
//
#include "VSPtr.h"
#include "List.h"
#include "heap.h"
int main(){
    VSPtr<int> v=VSPtr<int>::New();
    v=7;

    VSPtr<int> w=VSPtr<int>::New();
    w=8;

    VSPtr<int> k=VSPtr<int>::New();
    k=9;

    w=v;
    k=v;

}