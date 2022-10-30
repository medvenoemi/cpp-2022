//
// Created by Noemi on 10/24/2022.
//

#include "Polynomial.h"

Polynomial ::Polynomial(int degree, const double *coefficients) {
    capacity = degree +1;
    this->coefficients = new double [capacity];

    for(int i=0; i<capacity; i++){
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&that) {
    this->capacity = that.capacity;
    this->coefficients = that.coefficients;

    that.capacity = 0;
    that.coefficients = nullptr;
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

ostream & operator <<(ostream& out, const Polynomial& what){
    for(int i=0; i<what.capacity; i++){
        if(i==what.capacity-1){
            out<<what.coefficients[i];
        }
        else{
            out<<what.coefficients[i] <<"x^"<<what.capacity-1-i<<"+";
        }


    }
    return out;
}

double Polynomial::evaluate(double x) const {
    double p = coefficients[0];
    for(int i=1; i<capacity; i++){
       p = p*x+coefficients[i];
    }
    return p;
}


double Polynomial::operator[](int index) const {
    if(index < 0 || index >= capacity){
        throw out_of_range("Index out of bounds!");
    }
    return this->coefficients[index];
}

Polynomial Polynomial::derivative() const {
    double array[capacity - 1];
    for (int i = 0; i < this->capacity; ++i) {
        array[this->capacity - i - 1] = this->coefficients[this->capacity - i - 1] * i;
    }
    Polynomial temp(capacity - 2, array);
    return temp;
}

Polynomial operator-(const Polynomial &a) {
    for (int i = 0; i < a.capacity; ++i) {
        a.coefficients[a.capacity - 1 - i] *= -1;
    }
    Polynomial temp(a.capacity - 1, a.coefficients);
    return temp;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    double degree, *array;
    if (a.capacity > b.capacity) {
        array = a.coefficients;
        degree = a.degree();

        for (int i = 0; i < b.capacity; ++i) {

            array[b.capacity - i] += b.coefficients[b.capacity - i - 1];
        }
    } else {
        array = b.coefficients;
        degree = b.degree();

        for (int i = 0; i < a.capacity; ++i) {
            array[a.capacity - i] += a.coefficients[a.capacity - i - 1];
        }
    }
    Polynomial temp(degree, array);
    return temp;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    double degree, *array;
    if (a.capacity > b.capacity) {
        array = a.coefficients;
        degree = a.degree();
        for (int i = 0; i < b.capacity; ++i) {
            array[b.capacity - i] -= b.coefficients[b.capacity - i - 1];
        }
    } else {
        array = b.coefficients;
        degree = b.degree();

        for (int i = 0; i < a.capacity; ++i) {
            array[a.capacity - i] -= a.coefficients[a.capacity - i - 1];
        }
    }
    Polynomial temp(degree, array);
    return temp;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    int capacity = a.capacity + b.capacity - 1;
    double *array = new double[capacity]{0};
    for (int i = a.capacity; i > 0; --i) {
        for (int j = b.capacity; j > 0; --j) {
            array[i + j - 2] = array[i + j - 2] + a.coefficients[i - 1] * b.coefficients[j - 1];
        }
    }
    Polynomial temp(capacity - 1, array);
    return temp;
}
