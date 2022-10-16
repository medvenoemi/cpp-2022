//
// Created by Noemi on 10/16/2022.
//

#ifndef CPP_2022_STACK_H
#define CPP_2022_STACK_H

#include "List.h"
#define SIZE 100

class Stack {
    int top;

public:
    Stack() {
        top = 0;
    }

    ~Stack();

    //betesz egy elemet
    void push(int e);

    //kivesz egy elemet
    int pop();

    //megnezi ha ures-e
    bool isEmpty() const;

    void print() const;

private:
    int stack[SIZE];
    List list[SIZE];
};


#endif //CPP_2022_STACK_H
