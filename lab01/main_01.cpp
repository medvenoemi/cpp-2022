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
            int numElements ;
            double array[numElements];

            cout<<"Please enter the number of elements: "<<endl;
            cin>>numElements;
            cout<<"Please enter the elements of the array: "<<endl;

            for(int i=0; i<=numElements; i++){
                cin>>array[i];
            }

            cout<<"Standard devitation: "<<stddev(array, numElements);

            break;
        }

        case 5:{

            int numElements ;
            double array[numElements];

            cout<<"Please enter the number of elements: "<<endl;
            cin>>numElements;
            cout<<"Please enter the elements of the array: "<<endl;

            for(int i=0; i<numElements; i++){
                cin>>array[i];
            }

            pair<double, double> maxes = max2(array, numElements);
            cout<<maxes.first<<" "<<maxes.second;


            break;
        }

        case 6:{

            istringstream iss("1 2 3 alma 4");
            double number;
            while(iss >> number){
                cout<<number<<endl;
            }

            break;
        }

        case 7:{

            string text = "osz tel tavasz nyar" ;
            //cout<<"Enter a text: "<<"\n";
            //getline(cin, text);
            //cout<<"\n";
            cout<<countWords(text);
            break;
        }

        case 8:{
            string text = "osz tel tavasz nyar" ;
            cout<<"The coded text: "<<code(text)<<endl;
            cout<<"The decoded text: " <<decode(code(text));
            break;
        }

        case 9:{
            string text = "osz tel tavasz nyar" ;
            cout << capitalizeWords(text);
            break;
        }

        default:{

        }
    }
    return 0;
}

