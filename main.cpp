#include <iostream>
#include "GarbageCollector.h"
#include "Client.h"
#include "Heap.h"
#include <string>
#include "iostream"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

bool setClientSettings(string ip, string port, string pass, string user){
    Client client = *new Client();
    int result= client.logIn();
    return result == 0;
}

void setLocal(bool local){
    if(local){
        GarbageCollector::getInstance()->setType(Local);
    }else{
        GarbageCollector::getInstance()->setType(Remote);
    }
}

string getUpdate(){
    return Heap::getInstance()->updatePanelList();
}