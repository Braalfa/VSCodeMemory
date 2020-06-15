//
// Created by usuario on 14/6/20.
//

#ifndef READWRITE_READER_H
#define READWRITE_READER_H

#include "iostream"
#include "client.h"
/**
 * Esta clase la utilizamos para leer y comparar datos e infomacion con los datos generados por la etenxion de VSCode
 */
using namespace std;
class Reader {
public:
    static bool isLocal();
    static void setClientSettings(Client *client);
    static void setData(string data);
};


#endif //READWRITE_READER_H
