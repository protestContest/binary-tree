BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
SRC_INCLUDES = -I$(SRC)
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CC = g++
CFLAGS = -Wall -Wextra -ggdb

TREE = $(SRC)/BinaryTree.o



tree_test: $(TEST)/tree_test.cpp $(GTEST_MAINA) $(BUILD) $(TREE)
	$(CC) $(CFLAGS) $(GTEST_INCLUDES) $(GTEST_MAINA) $(SRC_INCLUDES) $(TREE) $(TEST)/tree_test.cpp -o $(BUILD)/tree_test -pthread


$(TREE): $(SRC)/BinaryTree.h $(SRC)/BinaryTree.cpp
	$(CC) $(CFLAGS) -c $(SRC)/BinaryTree.cpp -o $(SRC)/BinaryTree.o

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make && $(MAKE)

$(BUILD):
	mkdir -p build/

clean:

