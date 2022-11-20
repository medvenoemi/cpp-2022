//
// Created by Noemi on 11/18/2022.
//

#include "Ceg.h"

Ceg::Ceg(const vector<Alkalmazott *> &alkalmazottak) : alkalmazottak(alkalmazottak) {}


void Ceg::addAlklamazott(Alkalmazott *alkalmazott) {
    alkalmazottak.push_back(alkalmazott);
}

void Ceg::addAlkalmazottToManager(Manager *manager, Alkalmazott *alkalmazott) {

}