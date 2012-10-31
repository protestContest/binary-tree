BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
SRC_INCLUDES = -I$(SRC) -lm
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CC = g++
CFLAGS = -Wall -Wextra -ggdb


tree_test: $(TEST)/tree_test.cpp $(GTEST_MAINA) $(BUILD) $(SRC)/BinaryTree.o $(SRC)/Node.o
	$(CC) $(CFLAGS) $(GTEST_INCLUDES) $(GTEST_MAINA) $(SRC_INCLUDES) $(SRC)/BinaryTree.o $(SRC)/Node.o $(TEST)/tree_test.cpp -o $(BUILD)/tree_test -pthread


$(SRC)/BinaryTree.o: $(SRC)/BinaryTree.h $(SRC)/BinaryTree.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/BinaryTree.cpp -o $(SRC)/BinaryTree.o

$(SRC)/Node.o: $(SRC)/Node.h $(SRC)/Node.cpp
	$(CC) $(CFLAGS) -c $(SRC)/Node.cpp -o $(SRC)/Node.o

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make && $(MAKE)

$(BUILD):
	mkdir -p build/

clean:
	rm -rf $(BUILD)/*
	rm -rf $(SRC)/*.o
	cd $(GTEST)/make && $(MAKE) clean
