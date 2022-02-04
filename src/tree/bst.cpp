#include <iostream>

template <typename T>
class BinarySearchTree {
public:
    class Node {
    public:
        T data;
        Node* left;
        Node* right;
    };

    BinarySearchTree();
    ~BinarySearchTree();
    int size();
    bool empty();
    void clear();
    void print();
    void insert(const T data);
    void print_node(const std::string &prefix, const Node *node, bool isLeft);

    BinarySearchTree<T>& operator <<(const T& data);

private:
    Node* root;
    int m_size;
    Node* create_node(T data);
    Node* insert(Node* node, const T data);
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree () {
    m_size = 0;
    root = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree () {
}

template <typename T>
int BinarySearchTree<T>::size() {
    return m_size;
}

template <typename T>
typename  BinarySearchTree<T>::Node* BinarySearchTree<T>::create_node(T data) {
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

template <typename T> 
void BinarySearchTree<T>::insert(const T data) {
    root = insert(root, data);
}

template <typename T>
typename  BinarySearchTree<T>::Node* BinarySearchTree<T>::insert(Node* node, const T data) {
    if (nullptr == node) {
        m_size++;
        return create_node(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);

    } else {
        node->right = insert(node->right, data);
    }

    return node;
}

template <typename T>
void BinarySearchTree<T>::print_node(const std::string &prefix, const Node *node, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << " " << node->data << std::endl;

        print_node(prefix + (isLeft ? "│   " : "    "), node->left, true);
        print_node(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

template <typename T>
void BinarySearchTree<T>::print() {
    std::cout << "TREE" << std::endl;
    print_node("", root, false);
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator <<(const T& data) {
    insert(data);
    return *this;
}