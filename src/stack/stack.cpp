#include <iostream>
#include <string.h>

using namespace std;

#define MAX 3
class Stack {
    int index;
public:
    int data[MAX];

    Stack();
    bool push(int value);
    int pop();
    int peek();
    int size();
    bool is_empty();
    bool is_full();
};

Stack::Stack() {
    index = -1;
    bzero(&data, sizeof(data));
}

int Stack::size() {
    return index + 1;
}

bool Stack::is_full() {
    return (index >= MAX - 1) ? true : false;
}

bool Stack::is_empty() {
    return index < 0 ? true : false;
}

bool Stack::push(int value) {
    if(this->is_full()) {
        cerr << "stack overflow !" << endl;
        return false;
    }

    data[++index] = value;
    return true;
}

int Stack::pop() {
    if(this->is_empty()) {
        cerr << "stack is empty !" << endl;
        return -1;
    }

    return data[index--];
}

int Stack::peek() {
    if(this->is_empty()) {
        cerr << "stack is empty !" << endl;
        return -1;
    }

    return data[index];
}

int main() {
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "stack size : " << s.size() << endl;
    while (!s.is_empty()) {
        cout << "peek data : " << s.peek()  << endl;
        s.pop();
    }
}
