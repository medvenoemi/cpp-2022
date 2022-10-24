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

Polynomial::~Polynomial() {
    delete[] coefficients;
}

Polynomial::Polynomial(Polynomial &&that) {
    this->capacity = that.capacity;
    this->coefficients = that.coefficients;

    that.capacity = 0;
    that.coefficients = nullptr;
}

double Polynomial::operator[](int index) const {
    if(index < 0 || index >= capacity){
        throw out_of_range("Index out of bounds!");
    }
    return this->coefficients[index];
}

Polynomial Polynomial::derivative() const {
    double array[capacity-1];

    for(int i=0; i<capacity; i++){
        array[i] = this->coefficients[i]*i;
    }

    Polynomial temp(this->degree()-1, array);
    return temp;
}