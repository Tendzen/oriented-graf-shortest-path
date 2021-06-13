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
#include <stdio.h>
using namespace std;

extern int radky;
extern int sloupce;
extern string nazevSouboru; // nazev filu v kterem mate matice



void nactiDataZeSouboru(string &souborDat, int radkySloupce);


int kolikRadkuSloupce(string fileName);


void dijkstraAlgoritm(int **pole, int od, int kam);

int minDistance(int dist[], int uzelyProhlednute[]);

bool vArrayNeboNe(int pole[], int prvek);

void printCestu(vector<int>Q, int &n);

int lenght(int u, int v);

int deleteElement(int arr[], int n, int x);

void printDelkuCesty(int pole[], int kam);
