//
// Created by Noemi on 9/30/2022.
//

#include "Point.h"
#include "util.h"
#include <cmath>
using namespace std;



double util::distance(const Point& a, const Point& b){

    return sqrt(pow(a.getX()-b.getX(),2)+pow(a.getY()-b.getY(),2));

}
