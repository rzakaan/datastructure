#include "list.cpp"
#include <iostream>
using namespace std;

int main() {
    ArrayList<int> arr;
    arr << 3 << 1;
    arr.add(5);
    arr.add(7, 0);
    arr.remove(arr.size() - 1);

    for(int i = 0; i < arr.size(); i++) {
        cout << arr.get(i) << endl;
    }

    try {
        arr.get(10);    
    } catch (IndexOutOfBounds e){
        cerr << e.what() << endl;
    }

    arr.clear();
    arr << 33 << 11;

    cout << "arr empty    : " << (arr.empty() ? "true" : "false") << endl;
    cout << "arr size     : " << arr.size() << endl;
    cout << "arr capacity : " << arr.capacity() << endl;
    cout << "arr first    : " << arr.first() << endl;
    cout << "arr last     : " << arr.last() << endl;
    cout << "arr contains : " << (arr.contains(7) ? "true" : "false") << endl;
    cout << "arr find     : " << arr.index(2) << endl;

    for(int i = 0; i < arr.size(); i++) {
        cout << arr.get(i) << endl;
    }
}