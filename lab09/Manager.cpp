//
// Created by Noemi on 11/17/2022.
//

#include "Manager.h"

Manager::Manager( string vezetekNev,  string keresztNev, int szuletesiEv, string munkakor): Alkalmazott(vezetekNev, keresztNev, szuletesiEv, munkakor){
    this->vezetekNev = vezetekNev;
    this->keresztNev = keresztNev;
    this->szuletesiEv = szuletesiEv;
    this->munkakor = munkakor;
}

void Manager::addAlkalmazott(Alkalmazott *alkalmazott) {
    beosztottak.emplace_back(alkalmazott);
}

void Manager::deleteAlkalmazott(Alkalmazott *alkalmazott) {
    auto a = find(beosztottak.begin(), beosztottak.end(), alkalmazott);
    if(!(a==beosztottak.end())){
        beosztottak.erase(a);
    }
}

void Manager::deleteAlkalmazottById(int id) {
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

void Manager::print(std::ostream &os)  {
    os<<"Manager "<<getId()<<" "<<vezetekNev <<" "<<keresztNev<<" beosztottjai: "<<endl;
    for(auto &b: beosztottak){
        os<<b;
    }
}

const string Manager::MANAGER_MUNKAKOR = "manager";