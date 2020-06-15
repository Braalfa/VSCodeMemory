#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "client.h"
#include <netinet/in.h>
#include <iostream>
#include "hl_md5wrapper.h"
#include "GarbageCollector.h"


#include <string>
using namespace std;

/**
 * Metodo constructor del cliente que establece el socket en 0 al ser el socket de entrada
 */
Client::Client(){
    sock=0;
}


/**
 *  Metodo para solicitar la creacion de un nuevo puntero en el servidor
 * @param type Tipo del dato
 * @return ID generado
 */
string Client::newVSptr(string type){
    Json::Value root;
    root["data"] = "";
    root["type"] = type;

    Json::FastWriter fastwriter;
    std::string json = fastwriter.write(root);

    this->sendStrMessage("new-vs;"+json+";");
    string id = this->askAnswer();
    return id;
}
/**
 * Metodo para solicitar que se elimine una referencia del puntero indicado
 * @param id Id del puntero indicado
 * @return Booleano que indica si ya no quedan referencias de dicho dato
 */

bool Client::delRef(string id){
    this->sendStrMessage("delete-ref;"+id+";");
    string answer= askAnswer();
    return answer == "1";
}
/**
 * Metodo para agregar una referencia al puntero
 * @param id ID del puntero en el GarbageCollector
 */
void Client::addRef(string id){
    this->sendStrMessage("new-ref;"+id+";");
    askAnswer();
}

/**
 * Metodo para actualizar la informacion del puntero en el servidor
 * @param id ID del puntero
 * @param value Valor al que apuntara el puntero
 * @param type Tipo de dato del puntero
 * @return Retorna la direccion de memoria del dato creado
 */
string Client::update(string id, string value, string type){
    Json::Value root;
    root["data"] = value;
    root["type"] = type;

    Json::FastWriter fastwriter;
    std::string json = fastwriter.write(root);
    this->sendStrMessage("update;"+id+";"+json+";");

    return askAnswer();
}

/**
 * Metodo para convertir un String en Json Value
 * @param message Mensaje a convertir a json
 * @return Json Value con la informacion
 */

Json::Value toJson(string message){
    Json::Value val;
    Json::Reader reader;
    bool b = reader.parse(message, val);
    if (!b)
        cout << "Error: " << reader.getFormattedErrorMessages();
    return val;
}
/**
 * Metodo para guardar las credenciales generadas por el servidor en manera de formato json
 * @param credentials String con las credenciales enviadas por el servidor
 */
void Client::saveCredentials(string credentials){
    Json::Value value=toJson(credentials);

    std::ofstream file;
    file.open("credentials.json");
    Json::StyledWriter styledWriter;
    file << styledWriter.write(value);

    file.close();
}
/**
 *  Metodo para enviar mensajes al servidor
 * @param messageSt Mensaje a enviar al servidor
 */
void Client::sendStrMessage(string messageSt){
    char mess[messageSt.size()+1];
    strcpy(mess, messageSt.c_str());
    send(sock , mess , strlen(mess), 1024 );
}
/**
 *  Metodo para esperar una respuesta del servidor
 * @return Respuesta enviada por el servidor
 */

string Client::askAnswer(){
    char buffer[1024] = {0};
    read( sock , buffer, 1024);
    return (string) buffer;
}
/**
 *  Metodo para aplicar hash md5 a una string
 * @param pass String a codificar
 * @return String codificado
 */
string getmd5(string pass){
    md5wrapper md5=md5wrapper();
    pass=md5.getHashFromString(pass);
    return pass;
}
/**
 * Metodo para establecer los parametros del servidor
 * @param ip Direccion web a la cual conectarse
 * @param port Puerto del servidor
 * @param user Usuario para identificarse
 * @param password Contrasena del servidor
 */
void Client::setServer(string ip, string port, string user, string password){
    this->ip=ip;
    this->port=port;
    this->user=user;
    this->password=password;
}
/**
 *  Metodo para intentar loggearse
 * @return Retorna 0 si el intento fue exitoso, y -1 en caso contrario
 */
int Client::logIn()
{
    struct sockaddr_in serv_addr;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    try {
        serv_addr.sin_port = htons(std::stoi(port));
    } catch (std::invalid_argument e) {
        return -1;
    }
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    string password = getmd5(this->password);
    sendStrMessage("log-in;"+user+";"+password+";");
    string answer = this->askAnswer();

    if(answer=="connection failed"){
        return -1;
    }else{
        this->saveCredentials(answer);
        return 0;
    }
}
