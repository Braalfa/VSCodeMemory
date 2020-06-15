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
 *
 */
Client::Client(){
    sock=0;
}


/**
 *
 * @param type
 * @return
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
 *
 * @param id
 * @return
 */

bool Client::delRef(string id){
    this->sendStrMessage("delete-ref;"+id+";");
    string answer= askAnswer();
    return answer == "1";
}
/**
 *
 * @param id
 */
void Client::addRef(string id){
    this->sendStrMessage("new-ref;"+id+";");
    askAnswer();
}

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
 *
 * @param message
 * @return
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
 *
 * @param credentials
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
 *
 * @param messageSt
 */
void Client::sendStrMessage(string messageSt){
    char mess[messageSt.size()+1];
    strcpy(mess, messageSt.c_str());
    send(sock , mess , strlen(mess), 1024 );
}
/**
 *
 * @return
 */

string Client::askAnswer(){
    char buffer[1024] = {0};
    read( sock , buffer, 1024);
    return (string) buffer;
}
/**
 *
 * @param pass
 * @return
 */
string getmd5(string pass){
    md5wrapper md5=md5wrapper();
    pass=md5.getHashFromString(pass);
    return pass;
}
/**
 *
 * @param ip
 * @param port
 * @param user
 * @param password
 */
void Client::setServer(string ip, string port, string user, string password){
    this->ip=ip;
    this->port=port;
    this->user=user;
    this->password=password;
}
/**
 *
 * @return
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
