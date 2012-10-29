#include "Node.h"
#include <string>
using std::string;

template <typename T>
Node<T>::Node(T v) {
    value = v;
    leftChild = 0;
    rightChild = 0;
}

template <typename T>
Node<T>::~Node() {
}

template <typename T>
T Node<T>::getValue() {
    return value;
}

template <typename T>
Node<T>* Node<T>::getLeftChild() {
    return leftChild;
}

template <typename T>
Node<T>* Node<T>::getRightChild() {
    return rightChild;
}

template <typename T>
void Node<T>::setLeftChild(Node* n) {
    leftChild = n;
    return;
}

template <typename T>
void Node<T>::setRightChild(Node* n) {
    rightChild = n;
    return;
}


template class Node<int>;
template class Node<double>;
template class Node<string>;
