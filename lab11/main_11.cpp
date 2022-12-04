#include <iostream>
#include "Index.h"

int main() {

    Index index ("input.txt");

    cout<<endl;
    cout << "Index words: " << endl;
    index.printIndexWords();
    cout << endl;

    cout << "Index: " << endl;
    index.printIndex();
    cout << endl;

    cout << " Word occurrences : " << endl;
    for (const auto line : index.getWordOccurencies("it")) {
        cout << line << " ";
    }
    cout << endl;


    return 0;
}