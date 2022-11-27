//
// Created by Noemi on 11/21/2022.
//

#ifndef CPP_2022_ORDEREDLIST_H
#define CPP_2022_ORDEREDLIST_H

#include <functional>
#include <iostream>
using namespace std;

// Class declaration
template< class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator;

// Class definition
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

    friend class Iterator<T, LessComp, Equal>;

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

    void insert(const T& what);

    void remove(const T& what);

    int size(){
        return numElements;
    }

    bool find(const T& what);

    void listItems(ostream&);
};

// Class definition
template<class T, class LessComp, class Equal>
class Iterator {
private:
    OrderedList<T, LessComp, Equal> &list;
    typename OrderedList<T, LessComp, Equal>::Node *act;

public:
    Iterator(OrderedList<T, LessComp, Equal> &orderedList);

    bool hasNext();

    T next();

};

template<class T, class LessComp, class Equal>
Iterator<T, LessComp, Equal>::Iterator(OrderedList<T, LessComp, Equal> &orderedList) :list(orderedList), act(orderedList.first) {}

template<class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() {
    if ( act->next == nullptr ) {
        return false;
    }
    return true;
}

template<class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() {
    act = act->next;
    return act->value;
}

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
void OrderedList<T, LessComp, Equal>::insert(const T &what) {
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

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(const T &what) {
   Node *previous = first;
   Node *act = first;

   while( act != nullptr ){
       if( act->value == what && act == first ) {
           first = act->next;
           delete act;
           act = first;
           continue;
       }

       if ( act->value == what ) {
           previous->next = act->next;
           delete act;
           act = previous->next;
           continue;
       }

       previous = act;
       act = act->next;
   }
   previous = nullptr;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(const T &what) {
    Node *act;

    while ( act != nullptr ) {
        if ( act->value ==what){
            return true;
            act = act->next;
        }
    }

    return false;

}

#endif //CPP_2022_ORDEREDLIST_H
