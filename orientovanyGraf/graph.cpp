//
//  graph.cpp
//  orientovanyGraf
//
//  Created by Paul Ekishev on 11/06/2021.
//

#include "graph.hpp"

int radky;
int sloupce;

string nazevSouboru = "/Users/Imcheldon/Documents/spojovy seznam c++/trida/orientovanyGraf/orientovanyGraf/adjacencyMatice.txt";


int kolikRadkuSloupce(string fileName){
    string line;
    int number_of_lines = 0;
    ifstream myfile(fileName);
    while(getline(myfile, line)){
            ++number_of_lines;
    }
    return number_of_lines;
}



bool vPoleNeboNe(bool pole[], int prvek){
    if(pole[prvek] == true){
        return true;
    }
    else{
        return false;
    }
}

int lenght(int u, int v){
    return u + v;
}

int deleteElement(int arr[], int n, int x){
    int i;
    for (i=0; i<n; i++){
        if (arr[i] == x){
            break;
        }
    }
    if (i < n){
        n = n - 1;
        for (int j=i; j<n; j++){
            arr[j] = arr[j+1];
        }
    }
    return n;
}

void printDelkuCesty(int pole[], int kam){
    int delka;
    for(int i = 0; i<kam; i++){
        delka += pole[i];
    }
    cout << "Delka cesty: " << delka << endl;
}


void printCestu(vector<int>Q,int &n){
    for(int i =0; i<n; i++){
        cout << Q[i];
        if(i==n-1){
            break;
        }
        cout << " -> ";
    }
    cout << endl;
}

int minDistance(int dist[], int uzelyProhlednute[]){
    int min = INT_MAX; //nekonecno ( velke cislo)
    int index_min;
    for(int i =0; i<sloupce; i++){
        if(uzelyProhlednute[i] == -1 && dist[i] <= min){
            min = dist[i];
            index_min = i;
        }
    }
    return index_min;
}


void dijkstraAlgoritm(int **pole, int od, int kam){
    int dist[sloupce], uzlyProhlednute[sloupce]; // dist = delka cesty // array vrcholu
    vector<int>Q;
    int u;
    for(int i =0; i<sloupce; i++){
        dist[i] = INT_MAX;
        uzlyProhlednute[i] = -1;
        Q.push_back(i);
    }
    dist[od] = 0;
    int n = Q.size();
    int alt,d;
    printCestu(Q,n);
    while(n!=0){
        //hlidam min distance l
            u = minDistance(dist, uzlyProhlednute);
            Q.erase(Q.begin() + u-1);
            //
        if(u == kam){
            vector<int>S;
            u = kam;
            if(uzlyProhlednute[u] != -1 || u == od){
                while(u != -1){
                    S.insert(S.begin(),u);
                    u = uzlyProhlednute[u];
                }
            }
            break;
        }
        for(int v = 0; v<sloupce; v++){
            if(pole[u][v] !=0){
                d = pole[u][v];
                alt = dist[u] + lenght(dist[u],dist[d]);
                if(alt<dist[d]){
                    dist[d] = alt;
                    uzlyProhlednute[d] = u;
                }
            }
        }
        n = Q.size();
    }

    printDelkuCesty(dist,kam);
    printCestu(Q,n);
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
        
        soubor.open(nazevSouboru);
        if(soubor.is_open()){
            soubor.close();
            break;
        }
        else{
            cout << "Chyba nesmohl otevrit,zadej znovu\n";
            soubor.clear();
            soubor.ignore(433443, '\n');
        }
    }
    for(i=0; i<radkySloupce; i++){
        for(j=0; j<radkySloupce; j++){
                pole[i][j] = 0;
        }
    }
    for (int i = 0; i <radkySloupce; ++i){
           for (int j = 0; j < radkySloupce; ++j){
               cout << pole[i][j] << ' ';
           }
           cout << endl;
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
    cout << "nove pole: " << endl;
    for (int i = 0; i <radkySloupce; ++i){
           for (int j = 0; j < radkySloupce; ++j){
               cout << pole[i][j] << ' ';
           }
           cout << endl;
       }
    int od, kam;
    while(true){
    cout << "Zadejte index zacatku cesty: ";
    cin >> od;
    if(od > radkySloupce && kam <=0){
        cout << "Chyba! zadejte znovu" << endl;
        cin.clear();
        cin.ignore(433443, '\n');
    }else{
        break;
    }
    }
    while(true){
    cout << "Zadejte index konce cesty: ";
    cin >> kam;
    if(kam > radkySloupce && kam <=0){
        cout << "Chyba! zadejte znovu" << endl;
        cin.clear();
        cin.ignore(433443, '\n');
    }
    else{
        break;
    }
    }
    dijkstraAlgoritm(pole, od, kam);
}

