//
// Created by Noemi on 9/26/2022.
//

#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H


class Point {
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
    void getData(int x,int y);
};


#endif //CPP_2022_POINT_H
