all: BST clean

BST: instantiation.cpp BSTEngine.o BST.o Student.o
	g++ -o BST instantiation.cpp

Lab4.o: BSTEngine.cpp
	g++ -c BSTEngine.cpp BST.cpp Student.cpp

clean:
	rm -rf *o
