//
// Created by Noemi on 12/12/2022.
//

#ifndef CPP_2022_MYIFSTREAM_H
#define CPP_2022_MYIFSTREAM_H

#include <string>
#include <fstream>

using namespace std;

class myifstream: public ifstream{

public:
    myifstream(const string filename);

    ~myifstream() override;

    char operator[](long index);

    long filesize();
};


#endif //CPP_2022_MYIFSTREAM_H
