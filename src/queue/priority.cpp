#include <exception>
#include <climits>

struct EmptyQueue : public std::exception {
	const char* what () const throw () {
    	return "Queue empty !";
    }
};

template <typename T>
class PriorityQueue {
    class Item {
    public:
        T* data;
        int priority;
    };

    Item* m_data;
    int m_capacity;
    int m_size;

    // index
    int m_front, m_back;
    void init();
    int peek();

public:
    PriorityQueue(int size);
    ~PriorityQueue();
    int size();
    int capacity();
    bool empty();
    bool full();
    void clear();
    T& front();
    T& back();

    void push(const T value, const int priority);
    T pop();

    PriorityQueue<T>& operator <<(const T& value);
};

template <typename T>
void PriorityQueue<T>::init() {
    m_front = m_size = 0;
    m_back = m_capacity - 1;
    m_data = new Item[m_capacity];
}

template <typename T>
PriorityQueue<T>::PriorityQueue (int capacity) {
    this->m_capacity = capacity;
    init();
}

template <typename T>
PriorityQueue<T>::~PriorityQueue () {
    delete[] m_data;
}

template <typename T>
int PriorityQueue<T>::capacity() {
    return m_capacity;
}

template <typename T>
int PriorityQueue<T>::size() {
    return m_size;
}

template <typename T> bool PriorityQueue<T>::empty() { return m_size == 0; }

template <typename T> bool PriorityQueue<T>::full() { return m_size == m_capacity; }

template <typename T>
void PriorityQueue<T>::clear() {
    delete[] m_data;
    m_data = new Item[capacity()];
}

template <typename T>
void PriorityQueue<T>::push(const T value, const int priority) {
    // enqueue

    if (full())
      return;

    m_size++;    
    m_back = (m_back + 1) % m_capacity;
    m_data[m_back].data = value;
    m_data[m_back].priority = priority;
}

template <typename T>
int PriorityQueue<T>::peek() {
    int highestPriority = INT_MIN;
    int ind = -1;
    
    // check for the element with highest priority
    for (int i = 0; i <= m_size; i++) {
        if (highestPriority == m_data[i].priority && ind > -1 && m_data[ind].data < m_data[i].data) {
            highestPriority = m_data[i].priority;
            ind = i;
        } else if (highestPriority < m_data[i].priority) {
            highestPriority = m_data[i].priority;
            ind = i;
        }
    }

    return ind;
}

template <typename T>
T PriorityQueue<T>::pop() {
    // dequeue

    if (empty()) {
      throw EmptyQueue();
    }

    m_size--;
    int ind = peek();
    
    T value = m_data[ind].data;
    // m_front = (m_front + 1) % m_capacity;
    return value;
}

template <typename T>
T& PriorityQueue<T>::front() {
  if (empty()) {
    throw EmptyQueue();
  }

    return m_data[m_front];
}

template <typename T> 
T& PriorityQueue<T>::back() {
  if (empty()) {
    throw EmptyQueue();
  }

    return m_data[m_back];
}

template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator <<(const T& value) {
    push(value);
    return *this;
}