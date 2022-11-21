//
// Created by Noemi on 11/21/2022.
//

#ifndef CPP_2022_ORDEREDLIST_H
#define CPP_2022_ORDEREDLIST_H

#include <functional>
#include <iostream>
using namespace std;

template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList{
private:
    struct Node{
        T value;
        Node* next;
        Node(T value, Node *next) : value(value), next(next){};
    };

    Node* first{nullptr};
    int numElements{0};

    //friend class Iterator<T, LessComp, Equal>;
// ...
public:
    OrderedList(){
        this->numElements = 0;
        this->first = nullptr;
    }
   virtual ~OrderedList();

    bool isEmpty(){
        if( first == nullptr ){
            return true;
        }
        else{
            return false;
        }
    }

    void insert(T& what);

    //void remove(T& what);
    int size(){
        return numElements;
    }

    //bool find(T&);

    void listItems(ostream&);
};

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream &os) {
    Node *act = first;

    while( act != nullptr ){
        os << act->value <<" ";
        act = act->next;
    }
    os << endl;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(T &what) {
    Node* newElement = new Node(what, nullptr);
    //ures lista
    if( first == nullptr ){
        first = newElement;
        ++numElements;
        return;
    }

    Node *prev = nullptr;
    Node *act = first;

    while( act != nullptr && LessComp()(act->value, what)){
        prev = act;
        act = act->next;
    }

    //Listafej ele
    if( prev == nullptr ){
        newElement->next = first;
        first = newElement;
        ++numElements;
        return;
    }

    prev->next = newElement;
    newElement->next = act;
    ++numElements;
}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
    numElements = 0;
    Node *act;
    while ( first != nullptr ){
        Node *temp = first;
        first = first->next;
        delete temp;
    }
}

#endif //CPP_2022_ORDEREDLIST_H
