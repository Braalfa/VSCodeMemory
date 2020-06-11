#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "json.h"
#include "heap.h"

using namespace std;
class Client
{
public:
    Client();
    void sendStrMessage(string messageSt);
    string askAnswer();
    void getType(string id, string value);
    void saveCredentials(string credentials);
    void setServer(string ip, string port, string user, string password);
    void addRef(string id);
    void delRef(string id);
    void update(string id, string value);
    int logIn();

    void setHeap(Heap heap);
    string newVSptr(string data, string type);
    Heap* getHeap();

private:
    Heap *heap;
    string password;
    string user;
    string ip;
    string port;
    int sock;

};

#endif // CLIENT_H
