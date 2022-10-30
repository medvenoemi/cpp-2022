#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    double temp[] = {1, 1, 1, 1, 1, 1};
   Polynomial p = Polynomial(5, temp);

   cout<<"p(x)="<<p<<endl;
   cout<<"p(1)="<<p.evaluate(1)<< endl;
   cout<<"p(0)="<<p.evaluate(0)<<endl;

   for(int i=0; i<p.degree(); i++){
       cout<<"p["<<i<<"]="<<p[i]<<endl;
   }

    double cq[] = {5, 4, 3, 2, 1};
    Polynomial q(4, cq);

    cout << "p(x)'=" << p.derivative() << endl;
    cout << "q(x)=" << q << endl;
    cout << "p(x) after adding q(x) = " << p + q << endl;
    cout << "p(x) after subtracting q(x) = " << p - q << endl;
    cout << "negating p(x) = " << -p << endl;

    double pc[] = {1, 2, 3};
    Polynomial p1(2, pc);
    double qc[] = {4, 3, 2, 1};
    Polynomial q1(3, qc);
    cout << "p1(x)=" << p1 << endl;
    cout << "q1(x)=" << q1 << endl;
    cout << "p1*q1 = " << p1 * q1 << endl;

    return 0;
}