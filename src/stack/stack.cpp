#include <iostream>
#include <cstring>
#include <cstdlib>
#define DEFAULT_CAPACITY 10

using namespace std;
template <typename T>
class Stack {
    int index;
    int capacity;
    T* data;
    void init(int capacity);

public:
    Stack();
    Stack(int capacity);
    int size();
    bool is_empty();
    bool is_full();
    bool push(T value);
    T pop();
    T peek();
    void show();
};

template <typename T>
void Stack<T>::init(int capacity) {
    index = -1;
    this->capacity = capacity;
    int size = sizeof(T) * capacity;
    data = (T*) malloc(size);
    if (NULL != data) {
        bzero(data, size);
    }
}

template <typename T>
Stack<T>::Stack() {
    init(DEFAULT_CAPACITY);
}

template <typename T>
Stack<T>::Stack(int capacity) {
    init(capacity);
}

template <typename T>
int Stack<T>::size() {
    return index + 1;
}

template <typename T>
bool Stack<T>::is_full() {
    return (index >= capacity - 1) ? true : false;
}

template <typename T>
bool Stack<T>::is_empty() {
    return index < 0 ? true : false;
}

template <typename T>
bool Stack<T>::push(T value) {
    if(this->is_full()) {
        cerr << "stack overflow !" << endl;
        return false;
    }
    
    data[++index] = value;
    return true;
}

template <typename T>
T Stack<T>::pop() {
    if(this->is_empty()) {
        cerr << "stack is empty !" << endl;
        return -1;
    }

    return data[index--];
}

template <typename T>
T Stack<T>::peek() {
    if(this->is_empty()) {
        cerr << "stack is empty !" << endl;
        return -1;
    }

    return data[index];
}

int main() {
    class Stack<int> s;
    s.push(20);
    s.push(20);
    s.push(40);

    cout << "stack size : " << s.size() << endl;
    while (!s.is_empty()) {
        cout << "peek data : " << s.peek()  << endl;
        s.pop();
    }
}
