#include <iostream>
#include "myifstream.h"
#include "Huffman.h"

int main() {
//      myifstream f("be.txt");
//      cout<<f.filesize()<<endl;
//    for( int i=0; i <f.filesize(); ++i){
//        cout << f[i] ;
//    }
//    cout << endl;


   Huffman huff("be.txt");
    cout<<endl;
    huff.printTree();


    return 0;
}