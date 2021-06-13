//
//  pomocneFunkci.hpp
//  orientovanyGraf
//
//  Created by Paul Ekishev on 11/06/2021.
//

#define pomocneFunkci_hpp

#include <stdio.h>
#include "graph.hpp"

int number_of_lines = 0;
string fileName = "/Users/Imcheldon/Documents/spojovy seznam c++/trida/orientovanyGraf/orientovanyGraf/adjacencyMatice.txt";

void nactiDataZeSouboru(string &souborDat, int pole[]);
int kolikHran(string &fileName, int number_of_lines);
