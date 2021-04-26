//file: bintree.h
//Class binarytree class
//Louis Taing

#ifndef BINTREE_H
#define BINTREE_H
#include "nodedata.h"
using namespace std;

//---------------------------------------------------------------------------
// Bintree class:  a binary search tree 
//   -- allows output of the object
//   -- allows for comparison of 2 bintree objects
//   -- allows for assignment of 2 bintree objects
//   -- size is part of the class (so no longer needs to be passed)
//
// Implementation and assumptions:
//   -- implemented using Nodes and NodeData 
//---------------------------------------------------------------------------

class BinTree {				
	friend ostream& operator<<(ostream& out, const BinTree& object);  //ostream
public:
	
	BinTree();							// constructor
	BinTree(const BinTree&);			// copy constructor
	~BinTree();							// destructor, calls makeEmpty	
	bool isEmpty() const;			// true if tree is empty, otherwise false		
	void makeEmpty();			// make the tree empty so isEmpty returns true
	
	BinTree& operator=(const BinTree&); //allows for assignment of 2 bintree objects

	bool operator==(const BinTree&); //equal comparison of 2 bintree objects
	bool operator!=(const BinTree&); //unequal comparison of 2 bintree objects
	bool insert(NodeData* data);	//insert for building tree										
	bool retrieve(const NodeData &, NodeData* &) const; //retrieve object in tree
	//get height of tree REGARDLESS OF BST OR NOT
	int getHeight(const NodeData&) const;
	void bstreeToArray(NodeData* arr[]); //bst to array
	void arrayToBSTree(NodeData* []); //array to bst
	void displaySideways() const;		// displays the tree sideways
	

private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

// utility functions
	void inorderHelper(Node*) const;		//helper for inorder print ostream
	int heightHelper(Node*, const NodeData&, int&) const; //helper height
	

	void makeEmptyHelper(Node*&);			//helper for emptying tree
	void assignHelper(Node*&, Node*);		//helper for equal comparison overload
	bool equalHelper(Node*&, Node*) const;	//helper for assignment overload
	
	int bsTreeToArrayHelper(Node*&, NodeData* arr[]);	//helper for bst to arr
	//helper for arr to bst
	void arrayToBSTreeHelper(NodeData* arr[], Node* current, int min, int max);
	void sideways(Node*, int) const;		// helper for displaySideways()
};

#endif // !BINTREE_H
