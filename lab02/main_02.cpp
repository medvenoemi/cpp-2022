#include <iostream>
#include "Point.h"
#include "util.h"
#include <fstream>
using namespace std;

ifstream ifs("points.txt");

void test_distance();
void test_print();
void test_square(int t[]);
void test_randomGen();

int main(int argc, char** argv) {

    if(!ifs){
        cout<<"FIle open error" <<endl;
        return 1;
    }
    int x,y;
    int i=0;
    int t[8]={0};


    test_distance();
    test_print();
    test_square(t);
    test_randomGen();

    return 0;
}

void test_distance(){
    Point p1(0,0);
    Point p2(3,4);
    cout<<"Tavolsag: "<<distance(p1,p2)<<endl;

}

void test_print(){
    Point p1(1,0);
    p1.print();
    cout<<endl;
}

void test_square(int t[]){
    cout<<"isSquare"<<endl;
    bool ok=true;
    int i=0;
    int k=0;
    while(!ifs.eof()){
        ifs>>t[i]>>t[i+1];
        i=i+2;
        if(i==8){
            cout<<k<<":";
            k++;
            ok=isSquare(Point(t[0],t[1]),Point(t[2],t[3]),Point(t[4],t[5]),Point(t[6],t[7]));
            i=0;
            cout<<ok<<endl;
        }
        ok=false;
    }
    cout<<endl;
}

void test_randomGen(){
    cout<<"Random Num Generator"<<endl;
    int number=5;
    cout<<"How many elments do you want in the array?"<<endl;
    cin>>number;
    Point * points = createArray(number);
    printArray(points,number);
    cout<<endl;

    cout<<"closest points"<<endl;
    pair<Point , Point> closest = closestPoints(points,number);
    cout<<"("<<closest.first.getX()<<","<<closest.first.getY()<<"), ("<<closest.second.getX()<<", "<<closest.second.getY()<<")";
    closest= farthestPoints(points,number);
    cout<<endl;

    cout<<"Farthest points"<<endl;
    cout<<"("<<closest.first.getX()<<","<<closest.first.getY()<<"), ("<<closest.second.getX()<<", "<<closest.second.getY()<<")";

    sortPoints(points,number);
    cout<<endl;

    cout<<"Sorted points"<<endl;
    printArray(points,number);
    cout<<endl;

    //13
    delete [] points;

}