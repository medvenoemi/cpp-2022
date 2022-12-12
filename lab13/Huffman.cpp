//
// Created by Noemi on 12/12/2022.
//

#include "Huffman.h"

Huffman::Huffman(const string &filename) {
    ifstream fin(filename);
    int c;
    while ((c = fin.get()) != -1){
        frequencies[c]++;
    }
    for(auto &it : frequencies) {
        cout<<it.first<<": "<< it.second <<endl;
    }
    createTree();
}

void Huffman::createTree() {
    for(auto& it : frequencies){
        priorityQueue.push(new node(it.first,it.second));
    }
    while(priorityQueue.size()>1){
        node* temp1 = priorityQueue.top();
        priorityQueue.pop();
        node* temp2 = priorityQueue.top();
        priorityQueue.pop();

        node* newNode = new node(' ',temp1->freq+temp2->freq,temp1,temp2);
        priorityQueue.push(newNode);

    }

    cout<<"Root: "<<priorityQueue.top()->freq<<endl;
}

void Huffman::printTree() {
    printNode(priorityQueue.top());
}

void Huffman::printNode(node* node) {
    if(node == nullptr){
        return;
    }
    cout<<node->data<<": "<<node->freq<<endl;
    printNode(node->left);
    printNode(node->right);

}
