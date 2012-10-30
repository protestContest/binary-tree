#include "gtest/gtest.h"
#include <iostream>
#include "BinaryTree.h"
#include <string>
using std::cout;
using std::endl;
using std::string;

TEST(TreeTest, Constructor) {
    BinaryTree<int>* it = new BinaryTree<int>();
    delete it;

    BinaryTree<double>* dt = new BinaryTree<double>();
    delete dt;
    
    BinaryTree<string>* st = new BinaryTree<string>();
    delete st;
}

TEST(getSize, BasicGetSize) {
    BinaryTree<int>* it = new BinaryTree<int>();
    EXPECT_EQ(0, it->getSize());
}

TEST(insert, BasicInsert) {
    BinaryTree<int>* it = new BinaryTree<int>();
    it->insert(5);
    it->insert(12);
    it->insert(15);
    delete it;

    BinaryTree<double>* dt = new BinaryTree<double>();
    dt->insert(3.54);
    dt->insert(0.00000192);
    dt->insert(100045.0000001);
    delete it;
}

TEST(find, BasicFind) {
    BinaryTree<int>* it = new BinaryTree<int>();
    EXPECT_EQ(false, it->find(0));
    EXPECT_EQ(false, it->find(100));
    delete it;

    BinaryTree<double>* dt = new BinaryTree<double>();
    EXPECT_EQ(false, dt->find(0.1005001));
    EXPECT_EQ(false, dt->find(100));
    delete dt;

    BinaryTree<string>* st = new BinaryTree<string>();
    EXPECT_EQ(false, st->find("hello"));
    EXPECT_EQ(false, st->find("world"));
    delete st;

}

TEST(multiple, FindAndInsert) {
    BinaryTree<int>* it = new BinaryTree<int>();
    EXPECT_EQ(false, it->find(12));
    EXPECT_EQ(false, it->find(10000));
    it->insert(12);
    EXPECT_EQ(true, it->find(12));
    EXPECT_EQ(false, it->find(10000));
    it->insert(10000);
    EXPECT_EQ(true, it->find(12));
    EXPECT_EQ(true, it->find(10000));
    it->insert(12);
    EXPECT_EQ(true, it->find(12));
    delete it;

    BinaryTree<double>* dt = new BinaryTree<double>();
    EXPECT_EQ(false, dt->find(1.12));
    EXPECT_EQ(false, dt->find(10000.01));
    dt->insert(1.12);
    EXPECT_EQ(true, dt->find(1.12));
    EXPECT_EQ(false, dt->find(10000.01));
    dt->insert(10000.01);
    EXPECT_EQ(true, dt->find(1.12));
    EXPECT_EQ(true, dt->find(10000.01));
    dt->insert(1.12);
    EXPECT_EQ(true, dt->find(1.12));
    delete dt;

    BinaryTree<string>* st = new BinaryTree<string>();
    EXPECT_EQ(false, st->find("asdf"));
    EXPECT_EQ(false, st->find("hello"));
    st->insert("asdf");
    EXPECT_EQ(true, st->find("asdf"));
    EXPECT_EQ(false, st->find("hello"));
    st->insert("hello");
    EXPECT_EQ(true, st->find("asdf"));
    EXPECT_EQ(true, st->find("hello"));
    st->insert("asdf");
    EXPECT_EQ(true, st->find("asdf"));
    delete st;
}
