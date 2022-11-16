//
// Created by Noemi on 11/16/2022.
//

#include "Alkalmazott.h"

Alkalmazott::Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor, int id):Szemely(vezetekNev,keresztNev,szuletesiEv){
    this->munkakor=munkakor;
    id++;
}

void Alkalmazott::print(ostream &os) const{
    Szemely::print(os);
    os<<"Munkakor: "<<this->munkakor<<"Id: "<<getId()<<endl;
    os<<endl;
}


int Alkalmazott::getId() {
    return id;
}



