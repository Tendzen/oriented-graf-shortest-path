//
//  graph.cpp
//  orientovanyGraf
//
//  Created by Paul Ekishev on 11/06/2021.
//

#include "graph.hpp"

int pocetUzlu;

string nazevSouboru; // promena v kterou jsem daval celou cestu


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

void nactiDataZeSouboruASpustAlgoritm(string &nazevSouboru, int pocetUzlu){
    ifstream soubor;
    int **adjacencyMatrice;
    int i,j;
    adjacencyMatrice = new int *[pocetUzlu];
    for(int i = 0; i <pocetUzlu; i++){
        adjacencyMatrice[i] = new int[pocetUzlu];
    }
    while(!soubor.is_open()){
        cout << "Zadej nazev souboru, v kterem mate datu: ";
        cin >> nazevSouboru;
        cout << endl;
        soubor.open(nazevSouboru);
        if(soubor.is_open()){
            soubor.close();
            break;
        }
        else{
            cinIgnore();
        }
    }
    for(i=0; i<pocetUzlu; i++){
        for(j=0; j<pocetUzlu; j++){
                adjacencyMatrice[i][j] = 0;
        }
    }
    soubor.open(nazevSouboru);
    if(soubor.is_open()){
        while (!soubor.eof()) {
            for (i=0; i<pocetUzlu; i++){
                for(j=0; j<pocetUzlu; j++){
                    soubor >> adjacencyMatrice[i][j];
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
        if(!cin.good() || (od > pocetUzlu || od <0)){
            cinIgnore();
        }else{
            od -= 1;
            break;}
    }
    while(true){
        cout << "Zadejte index koncového bodu: ";
        cin >> kam;
        if(!cin.good() || (kam > pocetUzlu || kam <0)){
            cinIgnore();
        }
        else{
            kam -= 1;
            break;
        }
    }
    dijkstraAlgoritm(adjacencyMatrice, od, kam);
    delete[] adjacencyMatrice;
}



void dijkstraAlgoritm(int **adjacencyMatice, int od, int kam){
    int dist[pocetUzlu], prev[pocetUzlu]; // dist = delka cesty // prev - predchozi nejblizsi uzel
    List* listUzlu = new List;
    vector<int>poleSCestou;
    int u;
    for(int i =0; i<pocetUzlu; i++){
        dist[i] = INT_MAX;
        prev[i] = -1;
        listUzlu->push(i);
    }
    dist[od] = 0;
    int alt,delkaHrany; // alt = is the length of the path from the root node to the neighbor node v if it were to go through u
    while(!listUzlu->isEmpty()){
        u = minDistance(dist, listUzlu);
        listUzlu->popByData(u);
            //
        if(u == kam){
            u = kam;
            while(u!=-1){
                if(prev[u] != -1 || u == od){
                    poleSCestou.insert(poleSCestou.begin(),u);
                    u = prev[u];
                }
                else{
                    cout << "Od " << od+1 << " do " << kam+1 << " nevede žádná z cest" << endl;
                    return;
                }
            }
            break;
        }
        for(int v = 0; v<pocetUzlu; v++){
            if(adjacencyMatice[u][v] !=0){
                if(listUzlu->containInt(v)){
                    delkaHrany = adjacencyMatice[u][v];
                    alt = dist[u] + delkaHrany;
                    if(alt<dist[v]){
                        dist[v] = alt;
                        prev[v] = u;
                    }
                }
            }
        }
    }
    
    int n = poleSCestou.size();
    printDelkuCesty(dist, kam);
    printCestu(poleSCestou,n);
    delete listUzlu;
}

int minDistance(int dist[], List *fronta){
    int min = INT_MAX; //nekonecno ( velke cislo)
    int indexMin = 0;
    for(int i =0; i<pocetUzlu; i++){
        if(fronta->containInt(i) && dist[i] <= min){
            min = dist[i];
            indexMin = i;
        }
    }
    return indexMin;
}


void printDelkuCesty(int poleSDelkamiHran[], int kam){
    cout << "Delka cesty: "  << poleSDelkamiHran[kam] << endl;
}

void printCestu(vector<int>poleSCestou,int &pocetUzluVPoleSCestou){
    int uzel;
    for(int i =0; i<pocetUzluVPoleSCestou; i++){
        uzel = poleSCestou[i];
        cout << uzel+1;
        if(i==pocetUzluVPoleSCestou-1){
            break;
        }
        cout << " -> ";
    }
    cout << endl;
}


