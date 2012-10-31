#include "gtest/gtest.h"
#include <iostream>
#include "BinaryTree.h"
#include <string>
using std::cout;
using std::endl;
using std::string;

TEST(CONSTRUCTOR, Constructor) {
    BinaryTree<int>* it = new BinaryTree<int>();
    delete it;

    BinaryTree<double>* dt = new BinaryTree<double>();
    delete dt;
    
    BinaryTree<string>* st = new BinaryTree<string>();
    delete st;
}

TEST(GETSIZE, BasicGetSize) {
    BinaryTree<int>* it = new BinaryTree<int>();
    EXPECT_EQ(0, it->getSize());
    delete it;
}

TEST(INSERT, BasicInsert) {
    BinaryTree<int>* it = new BinaryTree<int>();
    it->insert(5);
    it->insert(12);
    it->insert(15);
    delete it;

    BinaryTree<double>* dt = new BinaryTree<double>();
    dt->insert(3.54);
    dt->insert(0.00000192);
    dt->insert(100045.0000001);
    delete dt;
}

TEST(INSERT, InsertGetSize) {
    BinaryTree<int>* it = new BinaryTree<int>();
    it->insert(12);
    it->insert(18);
    it->insert(-255);
    EXPECT_EQ(3, it->getSize());
    delete it;

    BinaryTree<double>* dt = new BinaryTree<double>();
    dt->insert(1.2);
    dt->insert(18.002);
    dt->insert(-255);
    dt->insert(372.16);
    EXPECT_EQ(4, dt->getSize());
    delete dt;

    BinaryTree<string>* st = new BinaryTree<string>();
    st->insert("adolf");
    st->insert("hipster");
    EXPECT_EQ(2, st->getSize());
    delete st;

}

TEST(FIND, BasicFind) {
    BinaryTree<int>* it = new BinaryTree<int>();
    EXPECT_FALSE(it->find(0));
    EXPECT_FALSE(it->find(100));
    delete it;

    BinaryTree<double>* dt = new BinaryTree<double>();
    EXPECT_FALSE(dt->find(0.1005001));
    EXPECT_FALSE(dt->find(100));
    delete dt;

    BinaryTree<string>* st = new BinaryTree<string>();
    EXPECT_FALSE(st->find("hello"));
    EXPECT_FALSE(st->find("world"));
    delete st;

}

TEST(FIND, FindAndInsert) {
    BinaryTree<int>* it = new BinaryTree<int>();
    EXPECT_FALSE(it->find(12));
    EXPECT_FALSE(it->find(10000));
    it->insert(12);
    EXPECT_TRUE(it->find(12));
    EXPECT_FALSE(it->find(10000));
    it->insert(10000);
    EXPECT_TRUE(it->find(12));
    EXPECT_TRUE(it->find(10000));
    it->insert(12);
    EXPECT_TRUE(it->find(12));
    delete it;

    BinaryTree<double>* dt = new BinaryTree<double>();
    EXPECT_FALSE(dt->find(1.12));
    EXPECT_FALSE(dt->find(10000.01));
    dt->insert(1.12);
    EXPECT_TRUE(dt->find(1.12));
    EXPECT_FALSE(dt->find(10000.01));
    dt->insert(10000.01);
    EXPECT_TRUE(dt->find(1.12));
    EXPECT_TRUE(dt->find(10000.01));
    dt->insert(1.12);
    EXPECT_TRUE(dt->find(1.12));
    delete dt;

    BinaryTree<string>* st = new BinaryTree<string>();
    EXPECT_FALSE(st->find("asdf"));
    EXPECT_FALSE(st->find("hello"));
    st->insert("asdf");
    EXPECT_TRUE(st->find("asdf"));
    EXPECT_FALSE(st->find("hello"));
    st->insert("hello");
    EXPECT_TRUE(st->find("asdf"));
    EXPECT_TRUE(st->find("hello"));
    st->insert("asdf");
    EXPECT_TRUE(st->find("asdf"));
    delete st;
}

TEST(REMOVE, Remove) {
    BinaryTree<int>* it = new BinaryTree<int>();
    EXPECT_FALSE(it->find(12));
    it->insert(12);
    EXPECT_TRUE(it->find(12));
    it->remove(12);
    EXPECT_FALSE(it->find(12));
    delete it;

    BinaryTree<double>* dt = new BinaryTree<double>();
    EXPECT_FALSE(dt->find(-7.12));
    dt->insert(-7.12);
    EXPECT_TRUE(it->find(-7.12));
    dt->remove(-7.12);
    EXPECT_FALSE(dt->find(-7.12));
    delete dt;

    BinaryTree<string>* st = new BinaryTree<string>();
    EXPECT_FALSE(st->find("test"));
    st->insert("test");
    EXPECT_TRUE(st->find("test"));
    st->remove("test");
    EXPECT_FALSE(st->find("test"));
    delete st;

}

TEST(PRINT, Print) {
    BinaryTree<int>* it = new BinaryTree<int>();
    it->insert(10);
    it->insert(5);
    it->insert(15);
    it->insert(17);
    it->insert(12);
    it->insert(10);
    it->insert(13);
    it->insert(18);
    it->print();
    delete it;
}
