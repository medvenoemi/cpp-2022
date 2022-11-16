//
// Created by Noemi on 11/16/2022.
//

#include "Szemely.h"

Szemely ::Szemely(std::string vezetekNev, std::string keresztNev, int szuletesiEv) {
    this->vezetekNev = vezetekNev;
    this->keresztNev = keresztNev;
    this->szuletesiEv = szuletesiEv;
}

void Szemely::print(std::ostream &os) const {
    os<<this->vezetekNev<<" "<< this->keresztNev<<" "<< this->szuletesiEv<<endl;

}

ostream &operator<<(ostream &out, const Szemely &szemely){
    szemely.print(out);
    return out;
}