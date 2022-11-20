//
// Created by Noemi on 11/17/2022.
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H

#include <vector>
#include "Alkalmazott.h"

class Manager: public Alkalmazott{
protected:
    vector<Alkalmazott*> beosztottak;

public:
    Manager(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor);
    void addAlkalmazott(Alkalmazott *alkalmazott);
    void deleteAlkalmazott(Alkalmazott *alkalmazott);
    void deleteAlkalmazottById(int id);
    int beosztottakSzama();
    virtual void print(ostream &os);

    static const string MANAGER_MUNKAKOR;
};


#endif //CPP_2022_MANAGER_H
