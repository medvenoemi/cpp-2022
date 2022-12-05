#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Ceg.h"

using namespace std;

int main() {
    Szemely szemely1("Fulop", "Anna", 2002);
    szemely1.print(cout);
    cout<<szemely1<<endl;

    Alkalmazott alkalmazott1("Fulop", "Anna", 2002, "informatikus");
    alkalmazott1.print(cout);

    Alkalmazott alkalmazott2("Fulop", "Istvan", 2002, "elado");
    alkalmazott2.print(cout);


    return 0;
}