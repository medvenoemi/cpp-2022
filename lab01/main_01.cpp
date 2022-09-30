#include <iostream>
#include <sstream>
#include "functions.h"

using namespace std;

int main() {
    int choice;

    cout<<"Please enter your choice from 1 to 9"<<endl;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "0-tol 127-ig a szamok egyes bitjeinek a szama" <<endl;
            for (int i = 0; i <= 127; i++) {
                cout << i << ": ";
                cout << countBits(i) << std::endl;
            }
            break;
        }

        case 2:{
            for (int i = 0; i < 35; ++i) {
                int n = 0;
                if(setBit(n, i)){
                   cout<<i<<" ---> " << n <<endl;
                }else{
                    cout<<"Impossible operation!" <<endl;
                }
            }
            break;
        }

        case 3:{
            int numElements ;
            double array[numElements];

             cout<<"Please enter the number of elements: "<<endl;
             cin>>numElements;
             cout<<"Please enter the elements of the array: "<<endl;

              for(int i=0; i<=numElements; i++){
                  cin>>array[i];
              }
            cout<<"The average is:" <<mean(array, numElements);
            break;
        }

        case 4:{
            double array[10];
            int numElements = 10;

            std::cout<<"Please enter the elements of the array: "<<std::endl;
            for(int i=0; i<10; i++){
                std::cin>>array[i];
            }

            std::cout<<"Standard devitation: "<<stddev(array, numElements);

            break;
        }

        case 5:{



            break;
        }

        case 6:{
            break;
        }

        case 7:{

            string text;
            cout<<"Enter a text: "<<"\n";
            getline(cin, text);
            cout<<"\n";
            cout<<countWords(text);
            break;
        }

        case 8:{
            string text;
            cout<<"Enter a text: "<<"\n";
            getline(cin, text);
            cout<<"\n";
            cout<<capitalizeWords(text);
            break;
        }

    }
    return 0;
}

