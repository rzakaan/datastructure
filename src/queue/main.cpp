#include <iostream>
#include "queue.cpp"

using namespace std;
int main() {
    Queue<int> q(10);
    q.push(10);
    q << 20 << 30 << 50 << 70;

    cout << "size     : " << q.size() << endl;
    cout << "capacity : " << q.capacity() << endl;
    cout << "empty    : " << q.empty() << endl;
    cout << "full     : " << q.full() << endl;
    
    while (!q.empty()) {
        cout << "front: " << q.front() << " - back: " << q.back() << endl;
        q.pop();
    }
}