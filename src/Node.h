#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
  private:
    T value;
    Node* leftChild;
    Node* rightChild;

  public:
    Node<T>(T v);
    ~Node();

    T getValue();
    Node* getLeftChild();
    Node* getRightChild();
    void setLeftChild(Node* n);
    void setRightChild(Node* n);
};

#endif
