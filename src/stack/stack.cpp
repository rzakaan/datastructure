#include <iostream>
#include <cstring>
#include <cstdlib>
#define DEFAULT_CAPACITY 25

using namespace std;
template <typename T>
class Stack {
    int index;
    int m_capacity;
    T* data;
    void init(int capacity);

public:
    Stack();
    Stack(int capacity);
    int size();
    int capacity();
    bool empty() const;
    bool is_full();
    bool push(T value);
    T pop();
    T peek();
};

template <typename T>
void Stack<T>::init(int m_capacity) {
    index = -1;
    this->m_capacity = m_capacity;
    int size = sizeof(T) * m_capacity;
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
int Stack<T>::capacity() {
    return m_capacity;
}

template <typename T>
int Stack<T>::size() {
    return index + 1;
}

template <typename T>
bool Stack<T>::is_full() {
    return (index >= m_capacity - 1) ? true : false;
}

template <typename T> 
bool Stack<T>::empty() const {
  return index < 0 ? true : false;
}

template <typename T>
bool Stack<T>::push(T value) {
    if(is_full()) {
        cerr << "stack overflow !" << endl;
        return false;
    }
    
    data[++index] = value;
    return true;
}

template <typename T>
T Stack<T>::pop() {
    if(empty()) {
        cerr << "stack is empty !" << endl;
        return -1;
    }

    return data[index--];
}

template <typename T>
T Stack<T>::peek() {
    if(empty()) {
        cerr << "stack is empty !" << endl;
        return -1;
    }

    return data[index];
}

int main() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(40);

    cout << "stack empty    : " << (s.empty() ? "true" : "false") << endl;
    cout << "stack is_full  : " << (s.is_full() ? "true" : "false") << endl;
    cout << "stack size     : " << s.size() << endl;
    cout << "stack capacity : " << s.capacity() << endl;

    while (!s.empty()) {
      cout << "peek data : " << s.peek() << endl;
      s.pop();
    }
    
}
