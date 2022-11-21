#include <iostream>
#include "OrderedList.h"

using namespace std;

int main() {
    // T → int
    OrderedList<int> l;
    for( int i=0; i<30; ++i ){
        int v = rand() % 10;
        l.insert( v );
    }
    l.listItems(cout);
    cout << endl;

    return 0;
}