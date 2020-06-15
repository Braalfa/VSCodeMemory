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

void Reader::setData(string data) {
    ofstream file;
    file.open("/home/brayan/Documents/Projects/VSCodeMemory/Library/data.txt");
    file <<data;
    file.close();
}

bool Reader::isLocal() {
    ifstream archivo;
    string texto;
    archivo.open("/home/brayan/Documents/Projects/VSCodeMemory/Library/local.txt",ios::in); //Abrimos el archivo en modo lectura
    getline(archivo,texto);
    archivo.close();

    return texto == "local";
}

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