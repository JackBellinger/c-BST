all: bst timeBST clean

bst: 
	g++ -std=c++11 manualInstantiation.cpp -o bst -g

timeBST: 
	g++ -std=c++11 timeInstantiation.cpp -o timeBST -g -I../c-Heap -I../matplotlibcpp

clean:
	rm -rf *o
