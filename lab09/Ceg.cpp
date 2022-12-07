//
// Created by Noemi on 11/18/2022.
//

#include "Ceg.h"

void Ceg::addAlkalamazott(Alkalmazott *alkalmazott) {
    alkalmazottak.push_back(alkalmazott);
}

void Ceg::deleteAlkalmazottById(int id) {
    auto index = find_if(this->alkalmazottak.begin(),this->alkalmazottak.end(), [&id](Alkalmazott *szemely){
        return szemely->getId() == id;
    });

    this->alkalmazottak.erase(index);
}

void Ceg::addAlkalmazottToManager( Alkalmazott *alkalmazott, Manager *manager) {
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [alkalmazott, manager](Alkalmazott *alkalmazott1) {
        if (alkalmazott1 == manager) {
            manager->addAlkalmazott(alkalmazott);
        }
    });
}

void Ceg::deleteAlkalmazottFromManager( Alkalmazott *alkalmazott, Manager *manager) {
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [alkalmazott, manager](Alkalmazott *alkalmazott1) {
        if (alkalmazott1 == manager) {
            manager->deleteAlkalmazott(alkalmazott);
        }
    });
}

void Ceg::printAll(std::ostream &os) {
    os << "Ceg:" << endl;
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [&os](Alkalmazott *alkalmazott) {
        alkalmazott->print(os);
    });
}

void Ceg::printManagers(std::ostream &os) {
    os << "Managers:" << endl;
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [&os](Alkalmazott *alkalmazott) {
        Manager *tempManager;
        tempManager = dynamic_cast<Manager *>(alkalmazott);
        if (tempManager != nullptr) {
            alkalmazott->print(os);
        }
    });
}