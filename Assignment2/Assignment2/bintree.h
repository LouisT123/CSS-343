#ifndef BINTREE_H
#define BINTREE_H
#include "nodedata.h"
using namespace std;

class BinTree {				// you add class/method comments and assumptions
	friend ostream& operator<<(ostream& out, const BinTree& object);		//ostream
public:
	BinTree();								// constructor
	BinTree(const BinTree&);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	
	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();						// make the tree empty so isEmpty returns true
	BinTree& operator=(const BinTree&);
	bool operator==(const BinTree&) const;
	bool operator!=(const BinTree&) const;
	bool insert(NodeData*);
	bool retrieve(...) const;
	void displaySideways() const;			// provided below, displays the tree sideways
	//may need more
private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

// utility functions
	void inorderHelper(...) const;
	void sideways(Node*, int) const;			// provided below, helper for displaySideways()
	//may need more
};





#endif // !BINTREE_H