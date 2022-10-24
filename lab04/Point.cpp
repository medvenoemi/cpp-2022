//
// Created by Noemi on 10/10/2022.
//

#include "Point.h"
#include <math.h>
#include <iostream>

int Point::counter{0};

Point::Point(int x, int y) {
    if((x>=0 && x<=M) && (y>=0 && y<=M)){
        this->x = x;
        this->y = y;
    }
    else {
        this->x = 0;
        this->y = 0;
    }
    counter++;
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow((this->x-point.getX()), 2)+pow(this->y-point.getY(),2));
}

void Point::print() const {
    std::cout << "( "<<getX()<<","<<getY()<<" )"<<std::endl;
}
 int Point::getCounter() {
    return counter;
}