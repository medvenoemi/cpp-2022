//
// Created by Noemi on 11/16/2022.
//

#ifndef CPP_2022_ALKALMAZOTT_H
#define CPP_2022_ALKALMAZOTT_H

#include "Szemely.h"

class Alkalmazott : public Szemely{
protected:
    string munkakor;
    int id;

public:
    Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor, int id);
    virtual void print(ostream& os) const;
    int getId();


    static int getGetId();
};

#endif //CPP_2022_ALKALMAZOTT_H
