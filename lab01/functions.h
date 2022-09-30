//
// Created by Noemi on 9/30/2022.
//

#ifndef CPP_2022_FUNCTIONS_H
#define CPP_2022_FUNCTIONS_H

#include <string>
using namespace std;

int countBits(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
int countWords(const string&text);
string code(string text);
string capitalizeWords(string text);
double isNum(string text);

#endif //CPP_2022_FUNCTIONS_H
