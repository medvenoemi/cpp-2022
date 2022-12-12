//
// Created by Noemi on 12/12/2022.
//

#include "myifstream.h"

myifstream::myifstream(const string filename) {
    open(filename);
}

long myifstream::filesize() {
    int position = tellg();
    seekg(0,ios_base::end);
    int temp = tellg();
    seekg(position,ios_base::beg);
    return temp;
}

char myifstream::operator[](long index) {
    seekg(index, ios_base::beg);
    return get();
}

myifstream::~myifstream() {
    close();
}
