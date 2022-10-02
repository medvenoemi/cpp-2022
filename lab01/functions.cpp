//
// Created by Noemi on 9/30/2022.
//

#include <cmath>
#include <sstream>
#include <string>
#include <iostream>
#include "functions.h"
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

    if(numElements <= 0){
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

pair<double ,double> max2(double array[],int numElements){
    pair<double,double> maxes (NAN,NAN);
    if(numElements == 1){
        maxes = make_pair(array[0],array[0]);
        return maxes;
    }
    if(numElements < 1){
        return maxes;
    }
    if(array[0] > array[1]){
        maxes.first = array[0];
        maxes.second = array[1];
    } else{
        maxes.first = array[1];
        maxes.second = array[0];
    }
    for (int i = 2; i < numElements; ++i) {
        if(maxes.first < array[i]){
            maxes.second = maxes.first;
            maxes.first = array[i];
        } else if(maxes.second < array[i]){
            maxes.second = array[i];
        }
    }
    return maxes;
}

double isNum(string text){
    double sum = 0;
    string words;
    getline(cin, words);
    istringstream iss(words);
    double num;
    while (iss){
        if(iss>>num){
            sum += num;
        }
    }
    return sum;
}

int countWords(const string& text){

    istringstream newr(text);
    string words;
    int count = 0;
    while (newr >> words){
        count++;
    }
    return count;
}

string code(string text){

    string stringBuilder;

    for(int i=0;text[i];i++){
        if(text[i] >= 'a' && text[i] <= 'z' || text[i] >='A' && text[i] <='Z'){
            if(text[i]=='z'){
                text[i] = 'a';

            } else if(text[i]=='Z'){
                text[i] = 'A';
            } else {
                text[i] += 1;
            }

        }
        stringBuilder += text[i];
    }

    return stringBuilder;
}

string decode(string text){

    string stringBuilder;

    for(int i=0;text[i];i++){
        if(text[i] >= 'a' && text[i] <= 'z' || text[i] >='A' && text[i] <='Z'){
            if(text[i]=='a'){
                text[i] = 'z';

            } else if(text[i]=='A'){
                text[i] = 'Z';
            } else {

                text[i] -= 1;
            }

        }
        stringBuilder+= text[i];
    }

    return stringBuilder;
}



string capitalizeWords(string text){
    if(text[0] >= 'a' && text[0] <= 'z'){
        text[0] -=32;
    }
    for (int i = 1;i < text.length(); ++i) {
        if(text[i - 1] == ' ' && text[i] >= 'a' && text[i] <='z'){
            text[i] -= 32;
        } else{
            if(text[i] >= 'A' && text[i] <= 'Z'){
                text[i] += 32;
            }
        }
    }
    cout<<endl;
    return text;


}

