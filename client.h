#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "json.h"
#include "heap.h"

using namespace std;
/**
 * La clase cliente es la encargada de gestionar todo lo relacionado con el envio y recepcion de datos
 * desde el servidor. Comunica sus resultados a quienes le llamen.
 */
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
    bool delRef(string id);
    string update(string id, string value, string type);
    int logIn();
    string newVSptr(string type);
private:
    string password;
    string user;
    string ip;
    string port;
    int sock;

};

#endif // CLIENT_H
