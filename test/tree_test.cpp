#include "gtest/gtest.h"
#include <iostream>
#include "BinaryTree.h"
#include <string>
using std::cout;
using std::endl;
using std::string;

TEST(TreeTest, Constructor) {
    BinaryTree<int>* it = new BinaryTree();
    delete it;

    BinaryTree<double>* dt = new BinaryTree();
    delete dt;
    
    BinaryTree<string>* st = new BinaryTree();
    delete st;
}

TEST(TreeTest, BasicGetSize) {
    BinaryTree<int>* it = new BinaryTree();
    EXPECT_EQ()
}

TEST(TreeTest, BasicInsert) {
    BinaryTree<int>* it = new BinaryTree();
    it->insert(5);
    it->insert(12);
    it->insert(15);
    delete it;
}
