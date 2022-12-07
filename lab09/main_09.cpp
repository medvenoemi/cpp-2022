#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Ceg.h"

using namespace std;

int main() {
//    Szemely szemely1("Fulop", "Anna", 2002);
//    szemely1.print(cout);
//    cout<<szemely1<<endl;
//
//    Alkalmazott alkalmazott1("Fulop", "Anna", 2002, "informatikus");
//    alkalmazott1.print(cout);
//
//    Alkalmazott alkalmazott2("Fulop", "Istvan", 2002, "elado");
//    alkalmazott2.print(cout);

    Ceg ceg;
    Alkalmazott a1("Nagy", "Anna",2002,"It");
    Alkalmazott a2("Nagy", "Aron",1991,"It");
    Alkalmazott a3("Kiss", "Pista",2001,"HR");
    Alkalmazott a4("Veress", "Maria",1999,"It");
    Alkalmazott a5("Farkas", "Laszlo",1999,"HR");
    Alkalmazott a6("Fekete", "Hunor",2002,"It");
    Alkalmazott a7("Kiss", "Elemer",1996,"HR");
    Manager a8("Fulop", "Istvan",1998,"Manager");
    Manager a9("Kolcsar", "Maria",2000,"Manager");
    Manager a10("Nagy", "Zoltan",2003,"Manager");

    ceg.addAlkalamazott(&a1);
    ceg.addAlkalamazott(&a2);
    ceg.addAlkalamazott(&a3);
    ceg.addAlkalamazott(&a4);
    ceg.addAlkalamazott(&a5);
    ceg.addAlkalamazott(&a6);
    ceg.addAlkalamazott(&a7);
    ceg.addAlkalamazott(&a8);
    ceg.addAlkalamazott(&a9);
    ceg.addAlkalamazott(&a10);

    ceg.printAll(cout);

    ceg.addAlkalmazottToManager(&a1, &a8);
    ceg.addAlkalmazottToManager(&a2, &a8);
    ceg.addAlkalmazottToManager(&a3, &a9);
    ceg.addAlkalmazottToManager(&a4, &a9);
    ceg.addAlkalmazottToManager(&a5, &a10);
    ceg.addAlkalmazottToManager(&a6, &a10);
    ceg.addAlkalmazottToManager(&a7, &a10);

    ceg.printManagers(cout);

    ceg.deleteAlkalmazottFromManager(&a1, &a8);
    ceg.addAlkalmazottToManager(&a1, &a10);

    cout << "\nAthelyezes utan:"<<endl;
    ceg.printManagers(cout);

    return 0;



}