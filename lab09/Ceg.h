//
// Created by Noemi on 11/18/2022.
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H


#include "Manager.h"

class Ceg {
    vector<Alkalmazott *> alkalmazottak;

public:
    Ceg(const vector<Alkalmazott *> &alkalmazottak);
    void addAlklamazott(Alkalmazott *alkalmazott);
    void deleteAlkalmazottById(int id);
    void addAlkalmazottToManager(Manager *manager, Alkalmazott *alkalmazott);
    void deleteAlkalmazottFromManager(Manager *manager, Alkalmazott *alkalmazott);
    void printAll(ostream &os);
    void printManagers(ostream &os);
};


#endif //CPP_2022_CEG_H
