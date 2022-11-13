#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class IntSequence{
private:
    int value;
public:
    IntSequence (int initialValue) : value((initialValue % 2 == 0) ?(initialValue) : (initialValue+1)) {
    }
    int operator() () {
        return value+=2;
    }
};

int main() {

    //1. exercise//

    cout<<"****1. exercise****"<<endl;

    vector<string> fruits {
            "melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"
    };

    string what_to_find = "berry";

    auto result1 = find_if(fruits.begin(),fruits.end(), [&what_to_find ] (const string& f){
        return f.contains(what_to_find);
    });

//    if(result1!= fruits.end()){
//        cout<< *result1<<endl;
//    }
//    else{
//        cout<<"Does not exist!"<<endl;
//    }

    cout << (result1 != fruits.end() ? (*result1) : ("Does not exist!"))<<endl;

    //2. exercise//

    cout<<"****2. exercise****"<<endl;

    vector<int> numbers;
    generate_n(back_inserter(numbers), 10, IntSequence(5));

    for_each(numbers.begin(), numbers.end(), [] (const int& e){
      cout<<e<<" ";
    });
    cout<<endl;

    auto result2 = all_of(numbers.begin(), numbers.end(), [ ] (const int& e){
       return e%2==0;
    });

    cout << ((result2) ? ("Mind paros") : ("Nem mind paros"))<<endl;

    //3. exercise//

    cout<<"****3. exercise****"<<endl;

    for_each(numbers.begin(), numbers.end(), [] ( int& i){
       i = i*2;
    });

    for_each(numbers.begin(), numbers.end(), [] (const int& e){
        cout<<e<<" ";
    });
    cout<<endl;

    //4. exercise//

    cout<<"****4. exercise****"<<endl;

    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };



    int n= 5;
    int counter = 0;

    auto result3 = for_each(months.begin(), months.end(), [&n, &counter ] (const string& m){
       if(m.length() == n){
           counter++;
       }
    });

    cout<<"Azon honapok szama amelyek 5 betubol allnak: "<<counter<<endl;

    //5. exercise//
    cout<<"****5. exercise****"<<endl;

    //Lambda kifejezéssel
    vector<float> numbers2{14.3, 3.12, 26.23, 2.53, 23.43};
    sort(numbers2.begin(), numbers2.end(), [](float a, float b){return a>b;});
    cout<<"A rendezett sor lambdaval: ";
    for (auto n:numbers2) {
        cout << n << ' ';
    }
    cout << endl;

    //greater<> funktor
    sort(numbers2.begin(), numbers2.end(), greater<>());
    cout<<"A rendezett sor greater funktorral: ";
    for (auto n:numbers2) {
        cout << n << ' ';
    }
    cout << endl;

    //6.exercise//
    cout<<"****6. exercise****"<<endl;

    vector<pair<string,int>> homerseklet{ {"January",1},{"February",3}, {"March",4}, {"April",5}, {"May",5}, {"June",6},
                                          {"July",10}, {"August",15}, {"September",8}, {"October",7}, {"November",5}, {"December",2}};

    sort(homerseklet.begin(), homerseklet.end(), [](const pair<string,int>& a, const pair<string,int>& b){return a.second < b.second;});
    for (const auto& h:homerseklet ) {
        cout << h.first << ' ' << h.second << ", ";
    }
    cout << endl;

    //7.exercise//
    cout<<"****7. exercise****"<<endl;

    vector<float> numbers3{-45.3, -3.12, -1.3, 15.23, 7.35, -4.23};
    sort(numbers3.begin(), numbers3.end(), [](float a, float b){return abs(a) < abs(b);});
    for (auto n:numbers3) {
        cout << n << ' ';
    }
    cout << endl;

    //8.exercise//
    cout<<"****8. exercise****"<<endl;

    for_each(months.begin(), months.end(),[](string &a){return a.at(0)+=32;});
    for (auto m:months) {
        cout << m << ' ';
    }
    cout << endl;

    //9.exercise//
    cout<<"****9. exercise****"<<endl;

    vector<char> abc{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','z'};
    shuffle(abc.begin(), abc.end(), std::mt19937(std::random_device()()));
    for (char &a: abc){
        cout << a << ' ';
    }
    cout << endl;


    return 0;
}