//
// Created by Noemi on 10/16/2022.
//

#include "Stack.h"
#include "List.h"
#include <iostream>

using namespace std;

Stack::~Stack() {
    cout << "Stack Destruktor" << endl;
    while (top != 0) {
        pop();
    }

}

void Stack::push(int x) {

    if (x < SIZE) {
        stack[x++] = x;
    }
    else
        cout << "Tele a verem" << endl;

}

int Stack::pop(){
    if (top == 0) {
        cout << "Ures a verem " << endl;
    }
    else {
        return stack[--top];
    }
}

bool Stack::isEmpty() const
{
    if (top == -1)
        return true;
    else
        return false;
}

void Stack::print() const {
    for (int i = 0; i < top; i++) {
        list[i].print();
    }
}

