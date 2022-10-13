//
// Created by Noemi on 10/10/2022.
//

#include <algorithm>
#include <iostream>
#include <random>
#include "PointSet.h"

PointSet::PointSet(int n) {
    this->n = n;
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); // return a number in the given range

    for (int i = 0; i < n; ++i) {
        int x = dist(mt);
        int y = dist(mt);

        Point point(x, y);
        points.push_back(point);
    }
    computeDistances();
}

void PointSet::computeDistances() {
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
           distances.push_back(points.at(i).distanceTo(points.at(j)));
        }
    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for (Point point : points) {
        point.print();
    }
}

void PointSet::printDistances() const {
    for(double dist : distances){
        std::cout << dist << std::endl;
    }
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), comparex);
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

bool PointSet::comparex(Point a, Point b) {
    return a.getX() < b.getX();
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), comparey);
}

bool PointSet::comparey(Point a, Point b) {
    return a.getY() < b.getY();
}

int PointSet::numDistinctDistances() {
    return (int)*unique(distances.begin(), distances.end());
}







