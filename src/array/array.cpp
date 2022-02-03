#include <exception>
#include <climits>

#define DEFAULT_CAPACITY 100

struct IndexOutOfBounds : public std::exception {
	const char* what () const throw () {
    	return "ArrayIndexOutOfBounds";
    }
};

struct ElementNotFound : public std::exception {
	const char* what () const throw () {
    	return "ElementNotFound";
    }
};

template <typename T>
class ArrayList {
    T* m_data;
    int m_capacity;
    int m_index;
    void init();
    bool is_valid_index(int index);
    bool needs_expansion();
    void expand_array();
public:
    ArrayList();
    ~ArrayList();
    int size();
    int capacity();
    bool empty();
    void clear();

    void add(T value);
    void add(T value, int index);
    bool remove(int index);
    T first();
    T last();
    T get(int index);
    int index(const T&);
    bool contains(const T& value);
    void merge(ArrayList<T> array);

    ArrayList<T>& operator <<(const T& value);
};

template <typename T>
bool ArrayList<T>::is_valid_index(int index) {
    return index > -1 && index < size();
}

template<typename T> 
bool ArrayList<T>::needs_expansion() {
    return size() >= m_capacity;
}

template<typename T> 
void ArrayList<T>::expand_array() {
    m_capacity *= 2;
    T* new_data = new T[m_capacity];
    for (int i = 0; i < size(); i++) {
        new_data[i] = m_data[i];
    }
    delete [] m_data;
    m_data = new_data;
}


template <typename T>
void ArrayList<T>::init() {
    m_index = -1;
    this->m_capacity = DEFAULT_CAPACITY;
    m_data = new T[m_capacity];
    // int size = sizeof(T) * m_capacity;
    // m_data = (T*) malloc(size);
}

template <typename T>
ArrayList<T>::ArrayList () {
    init();
}

template <typename T>
ArrayList<T>::~ArrayList () {
    delete[] m_data;
}

template <typename T>
int ArrayList<T>::capacity() {
    return m_capacity;
}

template <typename T>
int ArrayList<T>::size() {
    return (m_index + 1);
}

template <typename T>
bool ArrayList<T>::empty() {
    return (size() > 0) ? false : true;
}

template <typename T>
void ArrayList<T>::clear() {
    m_index = -1;
    delete[] m_data;
    m_data = new T[capacity()];
}

template <typename T>
void ArrayList<T>::add(T value) {
    m_data[++m_index] = value;
}

template <typename T>
void ArrayList<T>::add(T value, int index) {
    if (!is_valid_index(index)) return;

    for (int i = size() - 1; i >= 0; i--) {
        if (i >= index) {
            m_data[i + 1] = m_data[i];
        }
    }

    m_data[index] = value;
    this->m_index++;
}

template <typename T>
bool ArrayList<T>::remove(int index) {
    if (!is_valid_index(index)) return false;

    for (int i = index + 1; i < size() - 1; i++) {
        m_data[i - 1] = m_data[i];
    }

    // m_data[--index] = nullptr;
    m_index--;
    return true;
}

template <typename T>
T ArrayList<T>::first() {
    if (!empty())
        return m_data[0];
    
    throw ElementNotFound();
}

template <typename T>
T ArrayList<T>::last() {
    if (!empty())
        return m_data[m_index];
    
    throw ElementNotFound();
}

template <typename T>
T ArrayList<T>::get(int index) {
    if (is_valid_index(index))
        return m_data[index];

    throw IndexOutOfBounds();
}

template <typename T>
int ArrayList<T>::index(const T& value) {
    for (int i = 0; i < size(); i++) {
        if (m_data[i] == value) {
            return i;
        }
    }

    return INT_MIN;
}

template <typename T>
bool ArrayList<T>::contains(const T& value) {
    return index(value) >= 0;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator <<(const T& value) {
    add(value);
    return *this;
}