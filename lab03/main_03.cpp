#include <iostream>
#include "List.h"
#include "Stack.h"

using namespace std;


int main() {
    List list1;
    for (int i = 0; i < 10; ++i) {
        list1.insertFirst(i);
        list1.print();
    }

    cout<<"Letezik-e a listaban? "<<list1.exists(2)<<endl;
    cout<<"Merete: "<<size(list1)<<endl;
    cout<<"Ures-e a lista? "<<list1.empty()<<endl;
    cout<<"Kivesszuk az elso elemet a listabol? "<<list1.removeFirst()<<endl;
    list1.remove(10, List::DeleteFlag::EQUAL);
    cout<<"List: "<<endl;
    list1.print();

    Stack stack;
    for (int i = 0; i < 50; i++) {
        stack.push(i);
    }
    for (int i = 0; i < 51; i++) {
        cout << stack.pop() << " " << i << endl;
    }
    stack.isEmpty();
    return 0;
}
