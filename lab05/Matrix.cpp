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

//copy constructor
Matrix::Matrix(const Matrix& what) {
    mRows = what.mRows;
    mCols = what.mCols;
    mElements = new double * [mRows];
    for(int i=0; i<mRows; i++){
        mElements[i] = new double [mCols];
        for(int j=0; j<mCols; j++){
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

//move constructor
Matrix::Matrix( Matrix&& what ){
    this->mRows=what.mRows;
    this->mCols=what.mCols;
    this->mElements=what.mElements;

    what.mRows=0;
    what.mCols=0;
    what.mElements= nullptr;
}

//destructor
Matrix::~Matrix(){
    for(int i=0; i<getRows(); i++){
       delete[] mElements[i];
    }
    delete[] mElements;
    mRows=0;
    mCols=0;
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

Matrix operator+(const Matrix &x, const Matrix &y) {
    if(x.mRows == y.mRows && x.mCols == y.mCols){
        Matrix temp(x.mRows, x.mCols);
        for (int i = 0; i < x.getRows(); ++i) {
            for (int j = 0; j < x.getCols(); ++j) {
                temp[i][j] = x[i][j] + y[i][j];
            }
        }
        return temp;
    }
    throw out_of_range("Dimension error\n");
}

Matrix operator*(const Matrix& x, const Matrix& y){
    if (x.mCols == y.mCols){
        Matrix temp(x.mRows, y.mCols);
        temp.fillMatrix(0);
        for (int i = 0; i < x.getRows(); ++i) {
            double tempSum =0 ;
            for (int j = 0; j < x.getCols(); ++j) {
                for (int k = 0; k < y.getRows(); ++k) {
                    temp[i][j] += x.mElements[j][k] * y.mElements[k][j];
                }

            }
        }
    }
    throw out_of_range("Dimension error");
}

istream & operator>>(istream& is, Matrix& mat){
    for(int i=0; i<mat.getRows(); i++){
        for(int j=0; j<mat.getCols(); j++){
            is>>mat.mElements[i][j];
        }
    }
    return is;
}

ostream & operator<<(ostream& os, const Matrix& mat){
    mat.printMatrix(os);
    return os;
}

double* Matrix::operator[] (int index){
    return this->mElements[index];
}

double* Matrix::operator[] (int index) const{
    return this->mElements[index];
}

Matrix &Matrix:: operator=(const Matrix& mat){
    if(this->getRows() == mat.getRows() && this->getCols()== mat.getCols()){
        for (int i = 0; i < getRows(); ++i) {
            for (int j = 0; j < getCols(); ++j) {
                this->mElements[i][j] = mat.mElements[i][j];
            }
        }
        return *this;
    }
    throw out_of_range("Dimension error\n");
}

Matrix &Matrix::operator=(Matrix &&mat) {

    for (int i = 0; i < getRows(); ++i) {
        delete []this->mElements[i];
    }
    delete []this->mElements;

    this->mRows = mat.mRows;
    this->mCols = mat.mCols;
    this->mElements = mat.mElements;

    mat.mRows = 0;
    mat.mCols =0;
    mat.mElements = nullptr;

    return *this;
}