//
// Created by usuario on 14/6/20.
//

#include "Reader.h"
#include "client.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;
/**
 * La funcion setData modifica la informacion que se encuentra en el archivo txt
 * @param data la informacionque quiero que adquiera
 */
void Reader::setData(string data) {
    ofstream file;
    file.open("/home/brayan/Documents/Projects/VSCodeMemory/Library/data.txt");
    file <<data;
    file.close();
}
/**
 *IsLocal evalua si el garbageCollector es de typo remote o local segun sel boleando que retorne
 * @return boleano que retorna true  o false seguna la informcion que lee en el txt
 */
bool Reader::isLocal() {
    ifstream archivo;
    string texto;
    archivo.open("/home/brayan/Documents/Projects/VSCodeMemory/Library/local.txt",ios::in); //Abrimos el archivo en modo lectura
    getline(archivo,texto);
    archivo.close();

    return texto == "local";
}
/**
 *Lee la informacion necesaria para que el cliente se conecte con el servidor
 * @param client
 */
void Reader::setClientSettings(Client* client) {
    ifstream archivo;
    string texto;

    archivo.open("/home/brayan/Documents/Projects/VSCodeMemory/Library/clientsettings.txt",ios::in);
    int i=0;
    string* data= new string[4];
    while(i<4) {
        string a;
        getline(archivo, a);
        data[i] = a;
        i++;
    }
    client->setServer(data[0],data[1],data[2],data[3]);
}