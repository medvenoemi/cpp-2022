//
// Created by Noemi on 9/30/2022.
//

#include <cmath>
#include <sstream>
#include <string>
using namespace std;

int countBits(int number){

    int counter = 0;
    while(number){
        counter += number&1;
        number >>= 1;
    }
    return counter;
}

bool setBit(int& number, int order){
    if(order<0 || order>31){
        return false;
    }
    if(order == 0){
        return true;
    }
    number |= 1UL << order - 1;
    return true;
}

double mean(double array[], int numElements){
    double average = 0;
    double sum=0;

    if(numElements == 0){
        return NAN;
    }
    else{
        for(int i=0; i<= numElements; i++){
            sum+=array[i];
        }
        average = sum/numElements;
        return average;
    }
}

double stddev(double array[], int numElements){
    double sum = 0, mean, stdv = 0;

    if(numElements == 0){
        return NAN;
    }

    for(int i=0; i<numElements; i++) {
        sum+= array[i];
    }

    mean = sum / numElements;

    for(int i=0; i<numElements; i++){
        stdv+= pow(array[i] - mean, 2);
    }

    return sqrt(stdv / 10);
}

int countWords(const string&text){

    istringstream newr(text);
    string words;
    int count = 0;
    while (newr >> words){
        count++;
    }
    return count;
}

string code(string text){

}

string capitalizeWords(string text){
    int length = text.length();

    for(int i=0; i<length; i++){
        if(i==0||i==(length-1)){
            text[i]=toupper(text[i]);
        }
        else if(text[i]==' ')
        {
            text[i-1]=toupper(text[i-1]);
            text[i+1]=toupper(text[i+1]);
        }
    }

    return text;

}

