#include "BinaryTree.h"
#include <assert.h>
#include <string>
using std::string;

template <typename T>
BinaryTree<T>::BinaryTree() {
    root = 0;
    size = 0;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {

}

template <typename T>
void BinaryTree<T>::insert(T v) {
    assert(v == v);
}

template <typename T>
bool BinaryTree<T>::find(T v) {
    assert(v == v);
    return false;
}

template <typename T>
void BinaryTree<T>::print() {

}

template <typename T>
void BinaryTree<T>::remove(T v) {
    assert(v == v);
}

template <typename T>
int BinaryTree<T>::getSize() {
    return size;
}

template class BinaryTree<int>;
template class BinaryTree<double>;
template class BinaryTree<string>;
