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

    return 0;
}