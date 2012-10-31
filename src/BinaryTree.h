#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include "Node.h"

template <typename T>
class BinaryTree {
  private:
    int size;
    Node<T>* root;
    void deleteSubtree(Node<T>* r);

  public:
    BinaryTree<T>();
    ~BinaryTree<T>();

    void insert(T v);
    bool find(T v);
    void print();
    void remove(T v);
    int getSize();
};


#endif
