//
// Created by Noemi on 9/26/2022.
//

#include "Point.h"
#include <iostream>



Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

void Point::print() const {
    std::cout<<"("<<this->x<<","<<this->y<<")";
}

void Point::getData(int x,int y){
    this->x=x;
    this->y=y;
}