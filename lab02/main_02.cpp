#include <iostream>
#include "Point.h"
#include "util.h"
using namespace std;

void test_f1();
void test_distance();
bool comparePoints(const Point& p1, const Point&p2);

int main(int argc, char** argv) {

    test_f1();
    test_distance();

    return 0;
}

void test_distance(){
    Point p1(2, 3);
    cout<<"dist(p1, p2): " << distance(p1, p1)<<endl;
}

void test_f1(){
    Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    delete pp1;
    delete pp2;
}

bool comparePoints(const Point& p1, const Point& p2){
    return p1.getX() < p2.getX();
}