//
// Created by Noemi on 11/17/2022.
//

#include "Manager.h"

Manager::Manager( string vezetekNev,  string keresztNev, int szuletesiEv, string munkakor): Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkakor){

}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    beosztottak.emplace_back(alkalmazott);
}

void Manager::deleteAlkalmazott(int id) {
    int pozition;
    for (int i = 0; i < beosztottak.size(); ++i) {
        if(beosztottak[i]->getId() == id){
            pozition = i;
        }
    }
    beosztottak.erase(beosztottak.begin() + pozition);
}

int Manager::beosztottakSzama() {
    return beosztottak.size();
}

void Manager::print(std::ostream &os) const {
    os<<"Manager "<<getId()<<" "<<vezetekNev <<" "<<keresztNev<<" beosztottjai: "<<endl;
    for(auto &b: beosztottak){
        os<<b;
    }
}

const string Manager::MANAGER_MUNKAKOR = "manager";