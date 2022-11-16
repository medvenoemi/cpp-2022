//
// Created by Noemi on 11/16/2022.
//

#ifndef CPP_2022_SZEMELY_H
#define CPP_2022_SZEMELY_H

#include <iostream>

using namespace std;

class Szemely {
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesiEv;

public:
    Szemely(string vezetekNev, string keresztNev, int szuletesiEv);
    virtual void print(ostream& os) const;

};

ostream & operator<<(ostream& os, const Szemely& sz);


#endif //CPP_2022_SZEMELY_H
