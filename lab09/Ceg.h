//
// Created by Noemi on 11/18/2022.
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H


#include "Manager.h"

class Ceg {
    vector<Alkalmazott *> alkalmazottak;

public:
    void addAlkalamazott(Alkalmazott *alkalmazott);
    void deleteAlkalmazottById(int id);
    void addAlkalmazottToManager( Alkalmazott *alkalmazott, Manager *manager);
    void deleteAlkalmazottFromManager( Alkalmazott *alkalmazott,Manager *manager);
    void printAll(ostream &os);
    void printManagers(ostream &os);
};


#endif //CPP_2022_CEG_H
