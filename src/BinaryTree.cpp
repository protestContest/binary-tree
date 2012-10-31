#include "BinaryTree.h"
#include "Node.h"
#include <assert.h>
#include <math.h>
#include <string>
#include <list>
#include <iostream>
#include <sstream>
using std::string;
using std::list;
using std::stringstream;
using std::cout;
using std::endl;

template <typename T>
BinaryTree<T>::BinaryTree() {
    root = 0;
    size = 0;
    depth = 0;
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
    Node<T>* temp = new Node<T>(v);
    Node<T>** cur = &root;
    int curDepth = 1;

    while (*cur != 0) {
        if (v < (*cur)->getValue()) {
            Node<T>* temp = (*cur)->getLeftChild();
            cur = &temp;
            ++curDepth;
        }
        else if (v > (*cur)->getValue()) {
            Node<T>* temp = (*cur)->getRightChild();
            cur = &temp;
            ++curDepth;
        }
        else {
            return;
        }
    }
    *cur = temp;
    ++size;
    if (curDepth > depth) {
        depth = curDepth;
    }

    return;
}

template <typename T>
bool BinaryTree<T>::find(T v) {
    Node<T>** cur = &root;

    while (*cur != 0 && (*cur)->getValue() != v) {
        if (v < (*cur)->getValue()) {
            Node<T>* temp = (*cur)->getLeftChild();
            cur = &temp;
        }
        else if (v > (*cur)->getValue()) {
            Node<T>* temp = (*cur)->getRightChild();
            cur = &temp;
        }
        else {
            assert(1 == 0);
        }
    }
    if (*cur == 0) return false;

    return true;
}

template <typename T>
void BinaryTree<T>::print() {
    list< Node<T>* >* frontier = new list< Node<T>* >();
    frontier->push_back(root);
    int level = 0;
    int curLevelNodes = 0;
    //int fSlashPreSpace, fSlashPostSpace, bSlashPreSpace,
        //bSlashPostSpace;
    stringstream nodeString;

    while (frontier->empty() == false) {
        int levelNodes = pow(2, level);
        //int nodeSpace = pow(2, depth - level);
        int nodePreSpace = pow(2, depth - level - 1) - 1;
        int nodePostSpace = pow(2, depth - level - 1);
        //fSlashPostSpace = floor(nodePostSpace / 2);
        //fSlashPreSpace = nodeSpace - fSlashPostSpace - 1;
        //bSlashPreSpace = floor(nodePreSpace / 2);
        //bSlashPostSpace = nodeSpace - bSlashPreSpace - 1;

        for (int i = 0; i < nodePreSpace; ++i) {
            nodeString << " ";
        }

        Node<T>* curNode = frontier->front();
        frontier->pop_front();
        if (curNode != 0) {
            frontier->push_back(curNode->getLeftChild());
            frontier->push_back(curNode->getRightChild());
            nodeString << curNode->getValue();
        }
        else {
            nodeString << "X";
        }

        for (int i = 0; i < nodePostSpace; ++i) {
            nodeString << " ";
        }
        ++curLevelNodes;
        if (curLevelNodes == levelNodes) {
            nodeString << endl;
            curLevelNodes = 0;
            ++level;
        }

        cout << nodeString.str();
    }
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
