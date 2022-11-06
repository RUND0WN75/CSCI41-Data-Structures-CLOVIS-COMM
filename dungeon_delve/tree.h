#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cmath>
#include <set>
#include <numeric>
using namespace std;

template <class T>
class Tree {
	struct Node {
		T data = {};
		Node *left = nullptr, *right = nullptr; //Southwest is left, southeast is right
		Node(T new_data) : data(new_data) {}
	
		~Node() {
			delete left; 
			delete right;
		}
	} *root = nullptr;

	public:
    void insert(T new_data) {
        if (!root) { //If root is empty
            //Make a new node in root with the data and null kids
            root = new Node(new_data);
            return;
        }
        Node *temp = root;
        while (temp) {
            if (new_data == temp->data) return; //Duplicate
            else if (new_data < temp->data) {
                //Check to see if the spot is available, and if it is insert
                if (temp->left == nullptr) {
                    temp->left = new Node(new_data);
                    return;
                }
                //If not, we move temp down to the left and repeat
                temp = temp->left;
            }
            else {
                //Check to see if the spot is available, and if it is insert
                if (temp->right == nullptr) {
                    temp->right = new Node(new_data);
                    return;
                }
                //If not, we move temp down to the right and repeat
                temp = temp->right;
           	}
        }
    }
    bool printPath(const T data) const {
         if (!root) return false; //If the root is empty
         Node *temp = root;
         while (temp) {
    			//If the user reaches a spot where a letter is found.
				if (data == temp->data) { 
    				cout << "Found " << temp->data << ". Retrace your steps to the entrance.\n";
					return true;
			 	}
    			//If the room is at the left
				else if (data < temp->data) { 
    				cout << "Take the left door at the " << temp->data << "." << endl;
					temp = temp->left; //Goes down to the left side of the node. 
			 	}
    			//If the room is at the right
				else if (data > temp->data) { 
    				cout << "Take the right door at the " << temp->data << "." << endl;
					temp = temp->right;
			 	}
    			//If the password isn't solvable
				else {
    				cout << "NOT SOLVABLE\n";
					exit(1); 
			 	}
		 }
		 return false;
		//cout << "Exit the dungeon!\n";
    }
    bool search(const T data) const {
         if (!root) return false; //If the root is empty
         Node *temp = root;
         while (temp) {
    			//If the user reaches a spot where a letter is found.
				if (data == temp->data) { 
					return true;
			 	}
    			//If the room is at the left
				else if (data < temp->data) { 
					temp = temp->left; //Goes down to the left side of the node. 
			 	}
    			//If the room is at the right
				else if (data > temp->data) { 
					temp = temp->right;
			 	}
    			//If the password isn't solvable
				else {
					return 1; //return false 
			 	}
		 }
		 return false;
		//cout << "Exit the dungeon!\n";
	}

	~Tree() { delete root;}
};
			 //if (data == nullptr) return false;
			 //	else {
