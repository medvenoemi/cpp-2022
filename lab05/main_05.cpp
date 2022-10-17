#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix createSquareMatrix(int size) {
    Matrix m(size, size);
    m.fillMatrix(1);
    return m;
}

int main(int argc, char** argv) {

    cout<<"******************************************************************"<<endl;
    cout<<"Constructor "<<endl;
    cout<<"******************************************************************"<<endl;

    cout<<"Matrix filled with a specific number: "<<endl;
    Matrix m1(2, 3);
    m1.fillMatrix(5);
    m1.printMatrix();

    Matrix m2(3, 4);
    m2.randomMatrix(1, 10);
    cout<<"Matrix filled with random numbers: "<<endl;
    m2.printMatrix();
    return 0;
}