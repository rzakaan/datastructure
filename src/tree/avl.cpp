#include <iostream>

template <typename T> 
class AVLTree {
public:
    class Node {
    public:
        T key;
        int height;
        Node* left;
        Node* right;
    };

    AVLTree();
    ~AVLTree();
    int size();
    bool empty();
    void clear();
    void print();
    void insert(const T key);
    void print_node(const std::string &prefix, const Node *node, bool isLeft);

    AVLTree<T> &operator<<(const T &key);

private:
    Node* root;
    int m_size;
    int height(Node* node);
    int max(int a, int b);
    Node* create_node(T key);    
    Node* insert(Node* node, const T key);
    Node* right_rotate(Node* node);
    Node* left_rotate(Node* node);
    int get_balance(Node* node);
};

template <typename T> AVLTree<T>::AVLTree() {
    m_size = 0;
    root = nullptr;
}

template <typename T> 
AVLTree<T>::~AVLTree() {}

template <typename T> 
int AVLTree<T>::size() { return m_size; }

template <typename T> 
int AVLTree<T>::height(Node* node) {
    if (nullptr == node) {
        return 0;
    }

    return node->height;
}

template <typename T> 
int AVLTree<T>::max(int a, int b) {
    return (a > b) ? a : b;
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::create_node(T key) {
    Node *node = new Node();
    node->key = key;
    node->height = 1;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

template <typename T> 
void AVLTree<T>::insert(const T key) {
    root = insert(root, key);
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::insert(Node *node, const T key) {
    if (nullptr == node) {
        m_size++;
        return create_node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);

    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else return node;
    
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = get_balance(node);

    // left left case
    if (balance > 1 && key < node->left->key)
        return right_rotate(node);
    
    // right right case
    if (balance < -1 && key > node->right->key)
        return left_rotate(node);

    // left right case
    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // right left case
    if (balance < -1 && key > node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

/* 
       y                           x
      / \     Right Rotation      /  \
     x   T3   - - - - - - - >    T1   y 
    / \       < - - - - - - -        / \
   T1  T2     Left Rotation        T2  T3
*/
template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::left_rotate(Node* node) {
    Node *y = node->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = node;
    node->right = T2;

    // Update heights
    node->height = max(height(node->left), height(node->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::right_rotate(Node* node) {
    Node *x = node->left;
    Node *T2 = x->right;
 
    // Perform rotation
    x->right = node;
    node->left = T2;
 
    // Update heights
    node->height = max(height(node->left), height(node->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
 
    return x;
}

template <typename T>
int AVLTree<T>::get_balance(Node* node) {
    if (nullptr == node) {
        return 0;
    }

    return height(node->left) - height(node->right);
}

template <typename T>
void AVLTree<T>::print_node(const std::string &prefix, const Node *node, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << " " << node->key << std::endl;

        print_node(prefix + (isLeft ? "│   " : "    "), node->left, true);
        print_node(prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

template <typename T> 
void AVLTree<T>::print() {
    std::cout << "TREE" << std::endl;
    print_node("", root, false);
}

template <typename T> 
AVLTree<T> &AVLTree<T>::operator<<(const T &key) {
    insert(key);
    return *this;
}