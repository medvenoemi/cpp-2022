//
// Created by Noemi on 11/16/2022.
//

#include "Alkalmazott.h"

int Alkalmazott::counter {0};

Alkalmazott::Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor):Szemely(vezetekNev,keresztNev,szuletesiEv){
    this->munkakor=munkakor;
    this->id = counter;
    counter++;
}

void Alkalmazott::print(ostream &os) const{
    Szemely::print(os);
    os<<"Munkakor: "<<this->munkakor<<" Id: "<<getId()<<endl;
    os<<endl;
}


int Alkalmazott::getId() const {
    return id;
}



