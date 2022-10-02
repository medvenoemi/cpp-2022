//
// Created by Noemi on 9/30/2022.
//

#include "Point.h"
#include "util.h"
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;
ifstream ifs("points.txt");

double distance(const Point& a, const Point& b){

    return sqrt(pow(a.getX()-b.getX(),2)+pow(a.getY()-b.getY(),2));

}


bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d){
    double  s2, s3, s4;

    s2 = distance(a, b);
    s3 = distance(a, c);
    s4 = distance(a, d);

    if(s2 == 0 || s3 == 0 || s4 == 0){
        return false;
    }

    if(s2 == s3 && 2*s2 == s4 && 2* distance(c, d) == distance(b, c)){
        return true;
    }

    if(s3 == s4 && 2*s3 == s2 && 2* distance(c, b) == distance(c, d)){
        return true;
    }

    if(s2 == s4 && 2*s2 == s3 && 2* distance(b, c) == distance(b, d)){
        return true;
    }
    return false;
}
/*
void  testIsSquare(const char * filename){

    int i=0;
    int d[8]={0};
    bool ok=true;

    int k=0;
    while(!ifs.eof()){
        ifs>>d[i]>>d[i+1];
        i=i+2;
        if(i==8){
            cout<<k<<":";
            k++;
            ok=isSquare(Point(d[0],d[1]),Point(d[2],d[3]),Point(d[4],d[5]),Point(d[6],d[7]));
            i=0;
            cout<<ok<<endl;
        }
        ok=false;
    }
    cout<<endl;
}
*/
Point* createArray(int numPoints){

    Point *points = new Point[numPoints];
    int randomX, randomY;
    srand(time(NULL));

    for(int i=0; i<numPoints; i++){
        randomX = rand() % 2000;
        randomY = rand() % 2000;
        points[i].getData(randomX, randomY);
    }
    return points;
}

void printArray(Point* points, int numPoints){
    for(int i=0; i<numPoints; i++){
        cout<<points[i].getX()<<" "<<points[i].getY()<<endl;
    }
}

pair<Point, Point> closestPoints(Point* points, int numPoints){
    int minDistance = 99999;
    Point min1;
    Point min2;

    for(int i=0; i<numPoints; i++){
        for(int j=1; j<numPoints; j++){
            if(distance(i, j) < minDistance && i!=j){
                minDistance = distance(i, j);
                min1.getData(points[i].getX(), points[i].getY());
                min2.getData(points[i].getX(), points[i].getY());
            }
        }
    }
    return make_pair(min1, min2);
}

pair<Point, Point> farthestPoints(Point* points, int numPoints){
    int maxDistance = 0;
    Point max1;
    Point max2;

    for(int i=0; i<numPoints; i++){
        for(int j=1; j<numPoints; j++){
            if(distance(i, j) < maxDistance && i!=j){
                maxDistance = distance(i, j);
                max1.getData(points[i].getX(), points[i].getY());
                max2.getData(points[i].getX(), points[i].getY());
            }
        }
    }
    return make_pair(max1, max2);
}

void sortPoints(Point* points, int numPoints){
    for(int i=0;i<numPoints;i++){
        for(int j=0;j<numPoints;j++){
            if(points[i].getX()<points[j].getX() && i!=j){
                int seged1=points[i].getX();
                int seged2=points[i].getY();
                points[i].getData(points[j].getX(),points[j].getY());
                points[j].getData(seged1,seged2);
            }
        }
    }
}

void deletePoints(Point* points){
    delete [] points;
}