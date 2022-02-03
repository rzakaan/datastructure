#include <cstdint>
#include <exception>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <exception>

#define DEFAULT_CAPACITY 100

using namespace std;

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
    T* data;
    int m_capacity;
    int index;
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
    int find(const T&);
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
        new_data[i] = data[i];
    }
    delete [] data;
    data = new_data;
}


template <typename T>
void ArrayList<T>::init() {
    index = -1;
    this->m_capacity = DEFAULT_CAPACITY;
    data = new T[m_capacity];
    // int size = sizeof(T) * m_capacity;
    // data = (T*) malloc(size);
}

template <typename T>
ArrayList<T>::ArrayList () {
    init();
}

template <typename T>
ArrayList<T>::~ArrayList () {
    delete[] data;
}

template <typename T>
int ArrayList<T>::capacity() {
    return m_capacity;
}

template <typename T>
int ArrayList<T>::size() {
    return (index + 1);
}

template <typename T>
bool ArrayList<T>::empty() {
    return (size() > 0) ? false : true;
}

template <typename T>
void ArrayList<T>::clear() {
    index = -1;
    delete[] data;
    data = new T[capacity()];
}

template <typename T>
void ArrayList<T>::add(T value) {
    data[++index] = value;
}

template <typename T>
void ArrayList<T>::add(T value, int index) {
    if (!is_valid_index(index)) return;

    for (int i = size() - 1; i >= 0; i--) {
        if (i >= index) {
            data[i + 1] = data[i];
        }
    }

    data[index] = value;
    this->index++;
}

template <typename T>
bool ArrayList<T>::remove(int index) {
    if (!is_valid_index(index)) return false;

    for (int i = index + 1; i < size() - 1; i++) {
        data[i - 1] = data[i];
    }

    data[--index] = nullptr;
    return true;
}

template <typename T>
T ArrayList<T>::first() {
    if (!empty())
        return data[0];
    
    throw ElementNotFound();
}

template <typename T>
T ArrayList<T>::last() {
    if (!empty())
        return data[index];
    
    throw ElementNotFound();
}

template <typename T>
T ArrayList<T>::get(int index) {
    if (is_valid_index(index))
        return data[index];

    throw IndexOutOfBounds();
}

template <typename T>
int ArrayList<T>::find(const T& value) {
    for (int i = 0; i < size(); i++) {
        if (data[i] == value) {
            return i;
        }
    }

    return INT_MIN;
}

template <typename T>
bool ArrayList<T>::contains(const T& value) {
    return find(value) >= 0;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator <<(const T& value) {
    add(value);
    return *this;
}

int main() {
    ArrayList<int> arr;
    arr << 3 << 1;
    arr.add(5);
    arr.add(7, 0);

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
    cout << "arr find     : " << arr.find(2) << endl;

    for(int i = 0; i < arr.size(); i++) {
        cout << arr.get(i) << endl;
    }
}