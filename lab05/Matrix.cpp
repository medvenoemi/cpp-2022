//
// Created by Noemi on 10/17/2022.
//

#include "Matrix.h"
#include <algorithm>
#include <random>

//default constructor
Matrix::Matrix(int mRows, int mCols):mRows(mRows), mCols(mCols) {
    mElements = new double * [mRows];
    for(int i=0; i<mRows; i++){
        mElements[i] = new double [mCols];
    }
}

Matrix::Matrix(const Matrix& what) {
    
}

//destructor
Matrix::~Matrix(){
    for(int i=0; i<getRows(); i++){
       delete[] mElements[i];
    }
    delete[] mElements;
}


//feltolti a matrixot egy adott szammal
void Matrix::fillMatrix(double value) {
    for(int i=0; i<getRows(); i++){
        for(int j=0; j<getCols(); j++){
            this->mElements[i][j] = value;
        }
    }
}

//feltolti a matrixot random szamokkal
void Matrix::randomMatrix(int a, int b) {
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> random(a, b); // return a number in the given range

    for(int i=0; i<getRows(); i++){
        for(int j=0; j<getCols(); j++){
            this->mElements[i][j] = random(mt);
        }
    }
}

//kiirja a matrixot
void Matrix::printMatrix(std::ostream &os) const {
    for(int i=0; i<getRows(); i++){
        for(int j=0; j<getCols(); j++){
            os<< this->mElements[i][j]<<" ";
        }
        os<<endl;
    }
}