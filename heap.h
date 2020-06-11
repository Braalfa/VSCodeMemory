#ifndef HEAP_H
#define HEAP_H
#include <QTableWidget>
#include <string>
#include <QObject>

using namespace std;

class Heap
{

private:
    QTableWidget *tableWidget;

public:
    Heap(QTableWidget *tableWidget);
    void addVSptr(string id, string address, string type, string data);
    void deleteVSptr(string id);
    void addRef(string id);
    void deleteRef(string id);
    int findRow(string id);
    void update(string id, string value);

};

#endif // HEAP_H
