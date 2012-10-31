#include "BinaryTree.h"
#include "Node.h"
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
    deleteSubtree(root);
}

template <typename T>
void BinaryTree<T>::deleteSubtree(Node<T>* r) {
    if (r == 0) return;

    deleteSubtree(r->getLeftChild());
    deleteSubtree(r->getRightChild());
    delete r;
    
    return;
}

template <typename T>
void BinaryTree<T>::insert(T v) {
    Node<T>** cur = &root;

    while (*cur != 0) {
        if (v < (*cur)->getValue()) {
            Node<T>* temp = (*cur)->getLeftChild();
            cur = &temp;
        }
        else if (v > (*cur)->getValue()) {
            Node<T>* temp = (*cur)->getRightChild();
            cur = &temp;
        }
        else {
            return;
        }
    }
    *cur = new Node<T>(v);
    ++size;

    return;
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
