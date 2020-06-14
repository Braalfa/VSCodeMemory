//
// Created by usuario on 14/6/20.
//

#ifndef READWRITE_READER_H
#define READWRITE_READER_H

#include "iostream"
#include "client.h"

using namespace std;
class Reader {
public:
    static bool isLocal();
    static void setClientSettings(Client *client);
    static void setData(string data);
};


#endif //READWRITE_READER_H
