//
// Created by brayan on 13/6/20.
//
#include "VSPtr.h"
#include "List.h"
#include "heap.h"
#include "thread"
int main(){

    VSPtr<int> a=VSPtr<int>::New();
    a=7;

    VSPtr<int> c=VSPtr<int>::New();
    c=9;

    VSPtr<int> b=VSPtr<int>::New();
    b=8;

    VSPtr<string> s=VSPtr<string>::New();
    s="qq";

    VSPtr<bool> bo=VSPtr<bool>::New();
    bo=true;

    b=a;
    c=a;

    int i=0;
}