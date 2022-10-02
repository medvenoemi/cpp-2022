#include <iostream>
#include <fstream>
#include "Point.h"
#include "util.h"
using namespace std;

ifstream ifs("points.txt");

void test_f1();
void test_distance();
bool comparePoints(const Point& p1, const Point&p2);
void test_f5();
void test_function6();
void testFunctions();

int main(int argc, char** argv) {


    //test_f1();
    //test_distance();
    //test_f5();
    //test_function6();
     testFunctions();

    return 0;
}

void test_distance(){
    Point p1(0, 0);
    Point p2(3, 4);
    cout<<"dist(p1, p2): " << distance(p1, p2)<<endl;
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

void test_f5(){
    Point p1 = { 20, 10 }, p2 = { 10, 20 },
            p3 = { 20, 20 }, p4 = { 10, 10 };
    isSquare(p1, p2, p3, p4) ? cout << "Yes" : cout << "No";
}

void test_function6() {
    testIsSquare("points.txt");
}


void testFunctions(){
    int number;
    cout<<"Please give the number of elements: ";
    cin>>number;
    Point *points = createArray(number);
    printArray(points, number);
    cout<<endl;

    cout<<"closest points"<<endl;
    pair<Point , Point> closest = closestPoints(points,number);
    cout<<"("<<closest.first.getX()<<","<<closest.first.getY()<<"), ("<<closest.second.getX()<<", "<<closest.second.getY()<<")";
    cout<<endl;
    closest= farthestPoints(points,number);
    cout<<endl;

    cout<<"Farthest points"<<endl;
    cout<<"("<<closest.first.getX()<<","<<closest.first.getY()<<"), ("<<closest.second.getX()<<", "<<closest.second.getY()<<")";

    cout<<endl;
    sortPoints(points, number);
    cout<<endl;
    cout<<"Sorted points"<<endl;
    printArray(points, number);
}