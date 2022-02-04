#include <exception>
#include <climits>

struct EmptyQueue : public std::exception {
	const char* what () const throw () {
    	return "Queue empty !";
    }
};

template <typename T>
class Queue {
    T* m_data;
    int m_capacity;
    int m_size;
    // index
    int m_front, m_back;
    void init();

public:
    Queue(int size);
    ~Queue();
    int size();
    int capacity();
    bool empty();
    bool full();
    void clear();
    T& front();
    T& back();

    void push(const T value);
    T pop();

    Queue<T>& operator <<(const T& value);
};

template <typename T>
void Queue<T>::init() {
    m_front = m_size = 0;
    m_back = m_capacity - 1;
    m_data = new T[m_capacity];
}

template <typename T>
Queue<T>::Queue (int capacity) {
    this->m_capacity = capacity;
    init();
}

template <typename T>
Queue<T>::~Queue () {
    delete[] m_data;
}

template <typename T>
int Queue<T>::capacity() {
    return m_capacity;
}

template <typename T>
int Queue<T>::size() {
    return m_size;
}

template <typename T> bool Queue<T>::empty() { return m_size == 0; }

template <typename T> bool Queue<T>::full() { return m_size == m_capacity; }

template <typename T>
void Queue<T>::clear() {
    delete[] m_data;
    m_data = new T[capacity()];
}

template <typename T>
void Queue<T>::push(const T value) {
    // enqueue

    if (full())
      return;

    m_size++;
    m_back = (m_back + 1) % m_capacity;
    m_data[m_back] = value;
}

template <typename T>
T Queue<T>::pop() {
    // dequeue

    if (empty()) {
      throw EmptyQueue();
    }

    m_size--;
    T value = m_data[m_front];
    m_front = (m_front + 1) % m_capacity;
    return value;
}

template <typename T>
T& Queue<T>::front() {
  if (empty()) {
    throw EmptyQueue();
  }

    return m_data[m_front];
}

template <typename T> 
T& Queue<T>::back() {
  if (empty()) {
    throw EmptyQueue();
  }

    return m_data[m_back];
}

template <typename T>
Queue<T>& Queue<T>::operator <<(const T& value) {
    push(value);
    return *this;
}