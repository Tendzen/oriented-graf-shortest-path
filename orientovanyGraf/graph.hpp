//
//  graph.hpp
//  orientovanyGraf
//
//  Created by Paul Ekishev on 11/06/2021.
#define graph_hpp

#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

extern int pocetUzlu;
extern string nazevSouboru; // nazev filu v kterem mate matice
typedef int T;

struct Element {
    T data;
    Element* next;
};

Element* newElement(int d);

class List {
private:
    Element *head, *tail;
    int size;
public:
    List();
    ~List();
    void setHead(Element *h) { head = h; }
    void setTail(Element *t) { tail = t; }
    Element* getHead() { return head; }
    Element* getTail() { return tail; }
    int getSize() { return size; }
    Element* pop();
    bool containInt(int data);
    void popByData(int data);
    void push(int data);
    bool isEmpty();
    void clean();
};


void nactiDataZeSouboruASpustAlgoritm(string &souborDat, int uzly);

int kolikUzlu(string fileName);

void dijkstraAlgoritm(int **adjacencyMatice, int od, int kam);

int minDistance(int dist[], List *fronta);

void printCestu(vector<int>poleSCestou,int &pocetUzluVPoleSCestou);

void printDelkuCesty(int poleSDelkamiHran[], int kam);

void cinIgnore();
