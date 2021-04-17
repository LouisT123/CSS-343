#ifndef BINTREE_H
#define BINTREE_H
#include "nodedata.h"
using namespace std;

class BinTree {				// you add class/method comments and assumptions
	friend ostream& operator<<(ostream& out, const BinTree& object);  //ostream
public:
	BinTree();							// constructor
	BinTree(const BinTree&);			// copy constructor
	~BinTree();							// destructor, calls makeEmpty	
	bool isEmpty() const;			// true if tree is empty, otherwise false		//DONE
	void makeEmpty();			// make the tree empty so isEmpty returns true
	
	BinTree& operator=(const BinTree&);

	bool operator==(const BinTree&);
	bool operator!=(const BinTree&);
	bool insert(NodeData* data);													//DONE
	bool retrieve(const NodeData &, NodeData* &) const;
	void displaySideways() const; // displays the tree sideways
	//may need more

	//bstreeToArray
	//arrayToBst
	//get height of tree REGARDLESS OF BST OR NOT
	int getHeight(const NodeData&) const;

private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

// utility functions
	void inorderHelper(Node*) const;
	void sideways(Node*, int) const;		// helper for displaySideways()
	//may need more
	void makeEmptyHelper(Node*&);
	void assignHelper(Node*&, Node*);
	bool equalHelper(Node*&, Node*) const;
	void bstreeToArray(NodeData* []);
	void arrayToBSTree(NodeData* []);
};





#endif // !BINTREE_H
