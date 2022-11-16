#include <iostream>
#include "Szemely.h"

using namespace std;

int main() {
    Szemely szemely1("Fulop", "Anna", 2002);
    szemely1.print(cout);
    cout<<szemely1<<endl;
    return 0;
}