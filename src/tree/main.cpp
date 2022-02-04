#include <iostream>
#include <ctime>
#include "bst.cpp"

using namespace std;
int main() {
    srand (time(NULL));

    int val;    
    BinarySearchTree<int> bst;
    for(int i = 0; i < 10; i++) {
        val = rand() % 250 + 1;
        bst << val;
    }

    cout << "bst size: " << bst.size() << endl << endl;
    bst.print();   
}