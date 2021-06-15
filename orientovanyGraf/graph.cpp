//
//  graph.cpp
//  orientovanyGraf
//
//  Created by Paul Ekishev on 11/06/2021.
//

#include "graph.hpp"

int uzly;

string nazevSouboru = "/Users/Imcheldon/Documents/spojovy seznam c++/trida/orientovanyGraf/orientovanyGraf/adjacencyMatice.txt";


void cinIgnore() {
    cin.clear();
    cin.ignore(433443, '\n');
    cout << "Spatne! Zadej znovu" << endl;
}

int kolikUzlu(string fileName){
    string line;
    int uzly = 0;
    ifstream myfile(fileName);
    while(getline(myfile, line)){
            ++uzly;
    }
    return uzly;
}

void nactiDataZeSouboru(string &nazevSouboru, int radkySloupce){
    ifstream soubor;
    int **pole;
    int i,j;
    pole = new int *[radkySloupce];
    for(int i = 0; i <10; i++){
        pole[i] = new int[radkySloupce];
    }
    while(!soubor.is_open()){
//        cout << "Zadej nazev souboru, v kterem mate datu: ";
//        cin >> nazevSouboru;
//        cout << endl;
        soubor.open(nazevSouboru);
        if(soubor.is_open()){
            soubor.close();
            break;
        }
        else{
            cinIgnore();
        }
    }
    for(i=0; i<radkySloupce; i++){
        for(j=0; j<radkySloupce; j++){
                pole[i][j] = 0;
        }
    }
    soubor.open(nazevSouboru);
    if(soubor.is_open()){
        int x;
        while (!soubor.eof()) {
            for (i=0; i<radkySloupce; i++){
                for(j=0; j<radkySloupce; j++){
                    soubor >> pole[i][j];
                    
                }
            }
            if(soubor.eof()){
                break;
            }
        }
    }
    else{
        cout << "Chyba, soubor nepodarilo otevrit" << endl;
    }
    soubor.close();
    int od, kam;
    while(true){
        cout << "Zadejte index výchozího bodu: ";
        cin >> od;
        if(!cin.good() || (od > radkySloupce || od <0)){
            cinIgnore();
        }else{
            od -= 1;
            break;}
    }
    while(true){
        cout << "Zadejte index koncového bodu: ";
        cin >> kam;
        if(!cin.good() || (kam > radkySloupce || kam <0)){
            cinIgnore();
        }
        else{
            kam -= 1;
            break;
        }
    }
    dijkstraAlgoritm(pole, od, kam);
    delete[] pole;
}



void dijkstraAlgoritm(int **pole, int od, int kam){
    int dist[uzly], prev[uzly]; // dist = delka cesty // prev - predchozi nejblizsi uzel
    FIFO* Q = new FIFO;
    vector<int>S;
    int u;
    for(int i =0; i<uzly; i++){
        dist[i] = INT_MAX;
        prev[i] = -1;
        Q->push(i);
    }
    dist[od] = 0;
    int alt,d;
    while(!Q->isEmpty()){
        u = minDistance(dist, Q);
        Q->popByData(u);
            //
        if(u == kam){
            u = kam;
            while(u!=-1){
                if(prev[u] != -1 || u == od){
                S.insert(S.begin(),u);
                u = prev[u];
                }
                else{
                    cout << "Od " << od+1 << " do " << kam+1 << " nevede žádná z cest" << endl;
                    return;
                }
            }
        break;
        }
        for(int v = 0; v<uzly; v++){
            if(pole[u][v] !=0){
                if(Q->containInt(v)){
                    d = pole[u][v];
                    alt = dist[u] + d;
                    if(alt<dist[v]){
                        dist[v] = alt;
                        prev[v] = u;
                    }
                }
            }
        }
    }
    
    int n = S.size();
    printDelkuCesty(dist, kam);
    printCestu(S,n);
    delete Q;
}

int minDistance(int dist[], FIFO *fronta){
    int min = INT_MAX; //nekonecno ( velke cislo)
    int index_min = 0;
    for(int i =0; i<uzly; i++){
        if(fronta->containInt(i) && dist[i] <= min){
            min = dist[i];
            index_min = i;
        }
    }
    return index_min;
}


void printDelkuCesty(int pole[], int kam){
    int delka = 0;
    cout << "Delka cesty: "  << pole[kam] << endl;
}

void printCestu(vector<int>S,int &n){
    int uzel;
    for(int i =0; i<n; i++){
        uzel = S[i];
        cout << uzel+1;
        if(i==n-1){
            break;
        }
        cout << " -> ";
    }
    cout << endl;
}


