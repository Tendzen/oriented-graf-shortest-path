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
#include <cstring>
#include <istream>
#include <sstream>
using namespace std;

extern int radky;
extern int sloupce;
extern string nazevSouboru; // nazev filu v kterem mate matice
typedef int T;

struct Element {
    T data;
    Element* next;
};

Element* newElement(int d);

class FIFO {
private:
    Element *head, *tail;
    int size;
public:
    FIFO();
    ~FIFO();
    void setHead(Element *h) { head = h; }
    void setTail(Element *t) { tail = t; }
    Element* getHead() { return head; }
    Element* getTail() { return tail; }
    int getSize() { return size; }
    Element* top();
    Element* pop();
    bool containInt(int data);
    void popByData(int data);
    void push(int data);
    bool isEmpty();
    void clean();
};


void nactiDataZeSouboru(string &souborDat, int radkySloupce);

int kolikRadkuSloupce(string fileName);

void dijkstraAlgoritm(int **pole, int od, int kam);

int minDistance(int dist[], FIFO *fronta);

void printCestu(vector<int>S,int &n);

int lenght(int u, int v);

void printDelkuCesty(int pole[], int kam);

void cinIgnore();

int returnNejmensiIndexHrany(int **pole, int radka);
