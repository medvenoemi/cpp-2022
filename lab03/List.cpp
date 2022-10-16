//
// Created by Noemi on 10/13/2022.
//

#include <iostream>
#include "List.h"

using namespace std;

List::List(){
    this->first = nullptr;
}

List::~List() {
    Node *temp = this->first;
    while (temp){
        temp = temp->next;
        delete this->first;
        this->first = temp;
    }
    temp = nullptr;
}

void List::insertFirst(int d) {
    Node *newNode = new Node(d, this->first);
    this->first = newNode;
    ++nodeCounter;
}

void List::print() const {
    Node *temp = this->first;
    while (temp){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    temp = nullptr;
}

bool List::exists(int d) const {
    Node *temp = this->first;
    while (temp){
        if(temp->value == d){
            return true;
        }
        temp = temp->next;
    }
    temp = nullptr;
    return false;
}

int List::size() const {
    return this->nodeCounter;
}

bool List::empty() const {
    if(nodeCounter==0){
        return true;
    }
    return false;
}

int List::removeFirst() {
    if(empty()){
        throw std::invalid_argument("The list is empty\n");
    }
    else if(nodeCounter == 1){
        int tempValue = this->first->value;
        delete this->first;
        this->first = nullptr;
        --nodeCounter;
        return tempValue;
    }
    Node *tempNode = this->first->next;
    int tempValue = this->first->value;
    delete this->first;
    this->first = tempNode;
    tempNode = nullptr;
    --nodeCounter;
    return tempValue;
}

void List::remove(int d, DeleteFlag df){
    switch (df) {
        case DeleteFlag::LESS:{
            Node *temp = this->first;

            while(temp){
                if(temp->value < d){
                    //torles
                }
                temp = temp->next;
            }
            temp = nullptr;
            break;
        }
        case DeleteFlag::EQUAL:{
            Node *temp = this->first;

            while(temp){
                if(temp->value == d){
                    //torles
                }
                temp = temp->next;
            }
            temp = nullptr;
            break;
        }
        case DeleteFlag::GREATER:{
            Node *temp = this->first;

            while(temp){
                if(temp->value > d){
                    //torles
                }
                temp = temp->next;
            }
            temp = nullptr;
            break;
        }
        default:{
            break;
        }
    }
}


