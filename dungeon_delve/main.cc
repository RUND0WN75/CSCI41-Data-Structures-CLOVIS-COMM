#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cctype>
#include <cstdlib>
#include "tree.h" //Tree header file
#include "Bridges.h" 
#include "BSTElement.h" 
using namespace std;
using namespace bridges;
using namespace bridges::dataset;

	// inserts a record into the tree
	BSTElement<char,char> *insert (BSTElement<char,char> *rt, BSTElement<char,char> *new_el) {
		if (rt == nullptr) return new_el;
		else if (new_el->getKey() < rt->getKey()) rt->setLeft(insert(rt->getLeft(), new_el));
		else rt->setRight(insert(rt->getRight(), new_el));
	return rt;
}

int main() {
Bridges *bridges =  new Bridges(326, "RUND0WN",
                                "1266555064775");
	bridges->setTitle("Dungeon Delve");	
	BSTElement<char,char> *root = nullptr;


	Tree<char> bst;
	vector<char> vec;

	//Inputting the dungeon layout
	while (cin) {
		char c1;
		cin >> c1;
		c1 = toupper(c1);
		if (isdigit(c1)) break;
		bst.insert(c1);
		root = insert(root, new BSTElement<char,char> (c1,c1));
	}

	//Inputting the password 
	while (cin) {
		char c2;
        cin >> c2;
		c2 = toupper(c2);
		if (cin.eof()) break;
		vec.push_back(c2);
	}
	
	//Searching for matching characters in the tree. 
	for (char c1 : vec) {
		bool result = bst.search(c1);
		if (!result) { 
			cout << "NOT SOLVABLE\n";
			exit(1);
		}
	}

	for (char c2 : vec) { 
		//bst.search(c2);
		bst.printPath(c2);

	}

	cout << "Exit the dungeon!\n";
bridges->setDataStructure(root);
bridges->visualize();
}
