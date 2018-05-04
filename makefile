all: bst clean

bst: BSTEngine.o BST.o Student.o
	g++ -o bst BST.o Student.o

BSTEngine.o: BSTEngine.cpp
	g++ -c BSTEngine.cpp

BST.o: BST.cpp
	g++ -c BST.cpp

Student.o:
	g++ -c Student.cpp

clean:
	rm -rf *o
